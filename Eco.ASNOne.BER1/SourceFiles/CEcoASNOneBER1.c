/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOneBER1
 * </сводка>
 *
 * <описание>
<<<<<<< HEAD
 *   Полная реализация BER (Basic Encoding Rules) для ASN.1
 *   Поддерживает все типы согласно X.690:
 *   - INTEGER, BOOLEAN, NULL, OCTET STRING, BIT STRING
 *   - OBJECT IDENTIFIER, PrintableString, UTF8String, IA5String
 *   - SEQUENCE, SET, CHOICE, SEQUENCE OF, SET OF
 *   - Длинная форма длины (Long Form)
 *   - Indefinite length
=======
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOneBER1
>>>>>>> a07e5e241146cb6af3ab0c263f13621f982cd839
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

<<<<<<< HEAD
/* Подключение заголовочных файлов системы Eco */
#include "IEcoSystem1.h"           /* Интерфейс системы Eco - для управления компонентами */
#include "IEcoInterfaceBus1.h"     /* Интерфейс шины - для регистрации и поиска компонентов */
#include "IEcoASNOne1.h"           /* Интерфейс ASN.1 - для создания значений и наборов */
#include "IdEcoASNOne1.h"          /* Идентификаторы интерфейсов ASN.1 (GUID) */
#include "ErrEcoASNOne1.h"         /* Коды ошибок для ASN.1 компонентов */
#include "CEcoASNOneBER1.h"        /* Заголовок нашего компонента */
#include <string.h>                /* Стандартная библиотека для memcpy, memset */

/* ============================================================================
 * ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
 * ============================================================================ */

/*
 * Функция: encode_length
 * Назначение: Кодирование длины в BER формате (X.690 раздел 8.1.3)
 * Параметры:
 *   length - кодируемая длина (количество октетов содержимого)
 *   out    - выходной буфер, куда записываются октеты длины
 * Возвращает: количество записанных октетов (1 для short form, больше для long form)
 */
static int encode_length(uint32_t length, uint8_t* out) {
    int octets;   /* Количество октетов для записи длины (при long form) */
    int i;        /* Счётчик для циклов */
    
    /* Проверка: если длина <= 127, используем short form (один октет) */
    if (length <= 127) {
        out[0] = (uint8_t)length;  /* Бит 8 = 0, биты 7-1 = значение длины */
        return 1;                   /* Вернули 1 октет */
    }
    
    /* Определяем, сколько октетов нужно для записи длины в big-endian формате */
    /* Длина может занимать 1, 2, 3 или 4 октета в зависимости от значения */
    if (length > 0xFFFFFF) octets = 4;      /* > 16 млн - 4 октета */
    else if (length > 0xFFFF) octets = 3;   /* > 65535 - 3 октета */
    else if (length > 0xFF) octets = 2;     /* > 255 - 2 октета */
    else octets = 1;                         /* 1 октет для long form */
    
    /* Первый октет длинной формы: бит 8 = 1, биты 7-1 = количество последующих октетов */
    out[0] = 0x80 | octets;                 /* 0x80 = 10000000, OR с octets даёт нужный байт */
    
    /* Записываем значение длины в последующие октеты (big-endian) */
    for (i = 0; i < octets; i++) {
        /* Сдвигаем длину на нужное количество бит и извлекаем старший байт */
        out[1 + i] = (uint8_t)((length >> ((octets - 1 - i) * 8)) & 0xFF);
    }
    return 1 + octets;  /* Возвращаем общее количество октетов длины (1 заголовочный + octets) */
}

/*
 * Функция: decode_length
 * Назначение: Декодирование длины из BER потока (X.690 раздел 8.1.3)
 * Параметры:
 *   p              - указатель на указатель на текущую позицию в буфере (изменяется)
 *   length         - указатель для сохранения декодированной длины
 *   is_indefinite  - указатель для флага indefinite length (1 - неопределённая длина)
 * Возвращает: 0 при успехе, -1 при ошибке
 */
static int decode_length(uint8_t** p, uint32_t* length, int* is_indefinite) {
    uint8_t* ptr = *p;   /* Локальная копия указателя для работы */
    int octets;          /* Количество октетов для записи длины (при long form) */
    int i;               /* Счётчик для циклов */
    
    /* Проверка: если бит 8 = 0, это short form */
    if ((*ptr & 0x80) == 0) {
        *length = *ptr++;      /* Просто читаем значение длины (биты 7-1) */
        *is_indefinite = 0;    /* Не неопределённая длина */
        *p = ptr;              /* Обновляем указатель */
        return 0;              /* Успех */
    }
    
    /* Иначе это long form: бит 8 = 1 */
    octets = *ptr++ & 0x7F;    /* Извлекаем количество последующих октетов (биты 7-1) */
    
    /* Если octets == 0, это признак indefinite length (неопределённая длина) */
    if (octets == 0) {
        *length = 0;           /* Длина не определена, будет определяться по EOC (00 00) */
        *is_indefinite = 1;    /* Устанавливаем флаг indefinite length */
        *p = ptr;              /* Обновляем указатель */
        return 0;              /* Успех */
    }
    
    /* Читаем значение длины из octets байт (big-endian) */
    *length = 0;               /* Обнуляем аккумулятор */
    for (i = 0; i < octets; i++) {
        *length = (*length << 8) | *ptr++;  /* Сдвигаем влево на 8 бит и добавляем следующий байт */
    }
    *is_indefinite = 0;        /* Не неопределённая длина */
    *p = ptr;                  /* Обновляем указатель */
    return 0;                  /* Успех */
}

/*
 * Функция: decode_tag
 * Назначение: Декодирование TAG из BER потока (X.690 раздел 8.1.2)
 * Параметры:
 *   p           - указатель на указатель на текущую позицию в буфере (изменяется)
 *   tag_class   - указатель для сохранения класса тега (Universal/Application/Context/Private)
 *   tag_pc      - указатель для сохранения флага primitive(0)/constructed(1)
 *   tag_number  - указатель для сохранения номера тега
 * Возвращает: 0 при успехе, -1 при ошибке
 */
static int decode_tag(uint8_t** p, uint8_t* tag_class, uint8_t* tag_pc, uint32_t* tag_number) {
    uint8_t* ptr = *p;         /* Локальная копия указателя для работы */
    
    /* Первый октет тега: биты 8-7 = класс, бит 6 = P/C, биты 5-1 = номер тега (для коротких) */
    *tag_class = (*ptr >> 6) & 0x03;   /* Извлекаем класс (сдвиг на 6, маска 0x03) */
    *tag_pc = (*ptr >> 5) & 0x01;      /* Извлекаем P/C бит (сдвиг на 5, маска 0x01) */
    *tag_number = *ptr & 0x1F;         /* Извлекаем номер тега (младшие 5 бит) */
    ptr++;                             /* Перемещаемся к следующему октету */
    
    /* Если номер тега == 0x1F (31), это длинный тег (>= 31) */
    if (*tag_number == 0x1F) {
        *tag_number = 0;               /* Обнуляем аккумулятор */
        /* Читаем последующие октеты, пока бит 8 = 1 (продолжение) */
        while ((*ptr & 0x80)) {
            *tag_number = (*tag_number << 7) | (*ptr & 0x7F);  /* Извлекаем 7 бит данных */
            ptr++;                      /* Переходим к следующему октету */
        }
        /* Читаем последний октет (бит 8 = 0) */
        *tag_number = (*tag_number << 7) | (*ptr & 0x7F);
        ptr++;                          /* Переходим к следующему октету */
    }
    
    *p = ptr;          /* Обновляем указатель */
    return 0;          /* Успех */
}

/* ============================================================================
 * КОДИРОВАНИЕ ПРИМИТИВНЫХ ТИПОВ
 * ============================================================================ */

/*
 * Функция: encode_integer
 * Назначение: Кодирование INTEGER по BER (X.690 раздел 8.3)
 * Параметры:
 *   value - целое число для кодирования (32-битное беззнаковое)
 *   out   - выходной буфер для BER-кодированного значения
 * Возвращает: количество записанных октетов
 */
static int encode_integer(uint32_t value, uint8_t* out) {
    uint8_t temp[4];   /* Временный массив для big-endian представления (4 байта) */
    int len;           /* Длина значимой части (сколько байт реально нужно) */
    int i;             /* Счётчик для циклов */
    int start;         /* Индекс первого ненулевого байта */
    
    /* Особый случай: значение 0 кодируется как 02 01 00 */
    if (value == 0) {
        out[0] = 0x02;    /* TAG INTEGER = 0x02 */
        out[1] = 0x01;    /* LENGTH = 1 октет */
        out[2] = 0x00;    /* VALUE = 0 */
        return 3;         /* Всего 3 октета */
    }
    
    /* Распаковываем 32-битное значение в big-endian порядок (старший байт первый) */
    temp[0] = (uint8_t)((value >> 24) & 0xFF);   /* Байт 3 (самый старший) */
    temp[1] = (uint8_t)((value >> 16) & 0xFF);   /* Байт 2 */
    temp[2] = (uint8_t)((value >> 8) & 0xFF);    /* Байт 1 */
    temp[3] = (uint8_t)(value & 0xFF);           /* Байт 0 (самый младший) */
    
    /* Ищем первый ненулевой байт (пропускаем ведущие нули) */
    start = 0;
    while (start < 4 && temp[start] == 0) {
        start++;    /* Увеличиваем индекс, пока не найдём ненулевой байт */
    }
    len = 4 - start;   /* Длина значимой части = общая длина - количество пропущенных нулей */
    
    /* Проверяем, нужно ли добавить ведущий ноль (если старший бит значимого байта = 1) */
    if (temp[start] & 0x80) {
        /* Добавляем ведущий ноль: сдвигаем все байты на 1 позицию вправо */
        out[2] = 0x00;   /* Ведущий ноль */
        for (i = 0; i < len; i++) {
            out[3 + i] = temp[start + i];  /* Копируем значимые байты */
        }
        out[0] = 0x02;                     /* TAG INTEGER */
        out[1] = (uint8_t)(len + 1);       /* LENGTH = len + 1 (с ведущим нулём) */
        return len + 3;                    /* Всего октетов = 2 (TL) + len + 1 */
    } else {
        /* Без ведущего нуля */
        out[0] = 0x02;                     /* TAG INTEGER */
        out[1] = (uint8_t)len;             /* LENGTH = len */
        for (i = 0; i < len; i++) {
            out[2 + i] = temp[start + i];  /* Копируем значимые байты */
        }
        return len + 2;                    /* Всего октетов = 2 (TL) + len */
    }
}

/*
 * Функция: decode_integer
 * Назначение: Декодирование INTEGER из BER потока (X.690 раздел 8.3)
 * Параметры:
 *   p     - указатель на указатель на текущую позицию в буфере (изменяется)
 *   value - указатель для сохранения декодированного значения
 * Возвращает: 0 при успехе, -1 при ошибке
 */
static int decode_integer(uint8_t** p, uint32_t* value) {
    uint8_t* ptr = *p;   /* Локальная копия указателя */
    int len;             /* Длина значения в октетах */
    int i;               /* Счётчик */
    
    /* Проверяем, что TAG = 0x02 (INTEGER) */
    if (*ptr != 0x02) return -1;   /* Не INTEGER, ошибка */
    ptr++;                         /* Переходим к Length */
    
    len = *ptr++;                  /* Читаем длину значения */
    
    /* Максимальная длина INTEGER для 32-битного значения - 5 байт (с ведущим нулём) */
    if (len > 5) return -1;        /* Слишком большая длина, ошибка */
    
    /* Восстанавливаем значение из len байт (big-endian) */
    *value = 0;                    /* Обнуляем аккумулятор */
    for (i = 0; i < len; i++) {
        *value = (*value << 8) | *ptr++;  /* Сдвигаем влево на 8 бит и добавляем следующий байт */
    }
    
    *p = ptr;          /* Обновляем указатель */
    return 0;          /* Успех */
}

/*
 * Функция: encode_boolean
 * Назначение: Кодирование BOOLEAN по BER (X.690 раздел 8.2)
 * Параметры:
 *   value - значение BOOLEAN (0 = FALSE, не 0 = TRUE)
 *   out   - выходной буфер
 * Возвращает: количество записанных октетов (всегда 3)
 */
static int encode_boolean(uint8_t value, uint8_t* out) {
    out[0] = 0x01;                     /* TAG BOOLEAN = 0x01 */
    out[1] = 0x01;                     /* LENGTH = 1 октет */
    out[2] = value ? 0xFF : 0x00;      /* VALUE: TRUE = 0xFF, FALSE = 0x00 (DER требование) */
    return 3;                          /* Всего 3 октета */
}

/*
 * Функция: decode_boolean
 * Назначение: Декодирование BOOLEAN из BER потока (X.690 раздел 8.2)
 * Параметры:
 *   p     - указатель на указатель на текущую позицию (изменяется)
 *   value - указатель для сохранения декодированного значения
 * Возвращает: 0 при успехе, -1 при ошибке
 */
static int decode_boolean(uint8_t** p, uint8_t* value) {
    /* Проверяем TAG = 0x01 (BOOLEAN) */
    if (**p != 0x01) return -1;
    (*p)++;                           /* Переходим к Length */
    
    /* Проверяем LENGTH = 0x01 */
    if (**p != 0x01) return -1;
    (*p)++;                           /* Переходим к Value */
    
    /* Читаем значение: любой ненулевой байт = TRUE, ноль = FALSE */
    *value = (**p != 0) ? 1 : 0;
    (*p)++;                           /* Переходим к следующему полю */
    return 0;                         /* Успех */
}

/*
 * Функция: encode_null
 * Назначение: Кодирование NULL по BER (X.690 раздел 8.8)
 * Параметры:
 *   out - выходной буфер
 * Возвращает: количество записанных октетов (всегда 2)
 */
static int encode_null(uint8_t* out) {
    out[0] = 0x05;    /* TAG NULL = 0x05 */
    out[1] = 0x00;    /* LENGTH = 0 (нет содержимого) */
    return 2;         /* Всего 2 октета */
}

/*
 * Функция: encode_octet_string
 * Назначение: Кодирование OCTET STRING по BER (X.690 раздел 8.7)
 * Параметры:
 *   data             - указатель на данные для кодирования
 *   len              - длина данных в октетах
 *   out              - выходной буфер
 *   force_constructed - 1 = принудительно конструктивное кодирование, 0 = автоматический выбор
 * Возвращает: количество записанных октетов
 */
static int encode_octet_string(const uint8_t* data, int len, uint8_t* out, int force_constructed) {
    int len_bytes;      /* Количество октетов для записи длины */
    int total_len;      /* Общая длина закодированных данных */
    int remaining;      /* Оставшиеся данные для кодирования */
    const uint8_t* src; /* Указатель на исходные данные */
    int chunk;          /* Размер текущего сегмента */
    
    /* Если не принудительно конструктивное и размер <= 1000, используем примитивное кодирование */
    if (!force_constructed && len <= 1000) {
        out[0] = 0x04;                              /* TAG OCTET STRING = 0x04 */
        len_bytes = encode_length(len, out + 1);    /* Кодируем длину */
        memcpy(out + 1 + len_bytes, data, len);     /* Копируем данные */
        return 1 + len_bytes + len;                 /* Возвращаем общую длину */
    } else {
        /* Конструктивное кодирование (для больших данных, сегментация по 1000 байт) */
        out[0] = 0x24;                              /* Constructed OCTET STRING (0x20 | 0x04) */
        out[1] = 0x80;                              /* Indefinite length = 0x80 */
        total_len = 2;                              /* Начинаем с 2 октетов (Tag + Length) */
        remaining = len;                            /* Осталось закодировать */
        src = data;                                 /* Указатель на начало данных */
        
        /* Кодируем сегментами по 1000 байт */
        while (remaining > 0) {
            chunk = (remaining > 1000) ? 1000 : remaining;  /* Размер текущего сегмента */
            out[total_len] = 0x04;                          /* Primitive OCTET STRING tag */
            len_bytes = encode_length(chunk, out + total_len + 1);  /* Длина сегмента */
            total_len += 1 + len_bytes;                     /* Увеличиваем счётчик */
            memcpy(out + total_len, src, chunk);            /* Копируем данные сегмента */
            total_len += chunk;                             /* Увеличиваем счётчик */
            src += chunk;                                   /* Сдвигаем указатель */
            remaining -= chunk;                             /* Уменьшаем остаток */
        }
        
        /* End-Of-Content (EOC): два нулевых октета */
        out[total_len] = 0x00;          /* EOC маркер */
        out[total_len + 1] = 0x00;      /* EOC маркер */
        return total_len + 2;           /* Возвращаем общую длину */
    }
}

/*
 * Функция: encode_bit_string
 * Назначение: Кодирование BIT STRING по BER (X.690 раздел 8.6)
 * Параметры:
 *   data    - указатель на битовые данные (упакованные в байты)
 *   bit_len - длина в битах (не в байтах!)
 *   out     - выходной буфер
 * Возвращает: количество записанных октетов
 */
static int encode_bit_string(const uint8_t* data, int bit_len, uint8_t* out) {
    int byte_len = (bit_len + 7) / 8;    /* Количество байт, необходимых для хранения bit_len бит */
    int unused_bits = (byte_len * 8) - bit_len;  /* Количество неиспользуемых бит в последнем байте */
    int len_bytes;                       /* Количество октетов для записи длины */
    
    out[0] = 0x03;                       /* TAG BIT STRING = 0x03 */
    len_bytes = encode_length(byte_len + 1, out + 1);  /* Длина = byte_len + 1 (плюс байт unused_bits) */
    out[1 + len_bytes] = (uint8_t)unused_bits;        /* Записываем количество неиспользуемых бит */
    memcpy(out + 2 + len_bytes, data, byte_len);      /* Копируем данные */
    return 1 + len_bytes + 1 + byte_len;              /* Общая длина */
}

/*
 * Функция: encode_string
 * Назначение: Кодирование строковых типов (PrintableString, UTF8String, IA5String)
 * Параметры:
 *   tag - TAG типа (0x13 = PrintableString, 0x0C = UTF8String, 0x16 = IA5String)
 *   str - строка для кодирования
 *   out - выходной буфер
 * Возвращает: количество записанных октетов
 */
static int encode_string(uint8_t tag, const char* str, uint8_t* out) {
    int len = (int)strlen(str);   /* Длина строки в байтах (для UTF8 может отличаться от символов) */
    int len_bytes;                /* Количество октетов для записи длины */
    
    out[0] = tag;                 /* Записываем TAG */
    len_bytes = encode_length(len, out + 1);  /* Кодируем длину */
    memcpy(out + 1 + len_bytes, str, len);   /* Копируем строку */
    return 1 + len_bytes + len;              /* Общая длина */
}

/*
 * Функция: encode_oid
 * Назначение: Кодирование OBJECT IDENTIFIER по BER (X.690 раздел 8.19)
 * Параметры:
 *   oid   - массив чисел OID (каждое число - 32 бита)
 *   count - количество чисел в OID
 *   out   - выходной буфер (только содержимое, без TAG и LENGTH!)
 * Возвращает: количество записанных октетов
 */
static int encode_oid(const uint32_t* oid, int count, uint8_t* out) {
    uint8_t buf[5];      /* Буфер для временного хранения закодированного subidentifier */
    int buf_len;         /* Длина закодированного subidentifier */
    int pos = 0;         /* Текущая позиция в выходном буфере */
    uint32_t val;        /* Текущее значение subidentifier */
    int i, j;            /* Счётчики */
    
    /* OID должен содержать хотя бы 2 компонента (первый и второй) */
    if (count < 2) return -1;
    
    /* Первый subidentifier = 40 * первый_компонент + второй_компонент */
    val = oid[0] * 40 + oid[1];
    
    /* Кодируем каждый subidentifier, начиная с первого */
    for (i = 0; i < count - 1; i++) {
        if (i > 0) val = oid[i + 1];  /* Для остальных subidentifier берём следующий компонент */
        
        /* Кодируем val в Base-128 с продолжением (least significant group first) */
        buf_len = 0;
        do {
            buf[buf_len++] = (uint8_t)(val & 0x7F);  /* Извлекаем младшие 7 бит */
            val >>= 7;                               /* Сдвигаем вправо на 7 бит */
        } while (val);                               /* Повторяем, пока есть данные */
        
        /* Записываем в обратном порядке, устанавливая бит продолжения */
        for (j = buf_len - 1; j >= 0; j--) {
            out[pos++] = (j == 0) ? buf[j] : (buf[j] | 0x80);  /* Старший байт без бита продолжения */
        }
    }
    
    return pos;  /* Возвращаем количество записанных октетов (без TAG и LENGTH) */
}

/*
 * Функция: encode_sequence
 * Назначение: Кодирование SEQUENCE по BER (X.690 раздел 8.9)
 * Параметры:
 *   components - массив закодированных компонентов последовательности
 *   comp_len   - длина массива components в октетах
 *   out        - выходной буфер
 * Возвращает: количество записанных октетов
 */
static int encode_sequence(uint8_t* components, int comp_len, uint8_t* out) {
    int len_bytes;                     /* Количество октетов для записи длины */
    
    out[0] = 0x30;                     /* TAG SEQUENCE = 0x30 (Universal, Constructed) */
    len_bytes = encode_length(comp_len, out + 1);  /* Кодируем длину содержимого */
    memcpy(out + 1 + len_bytes, components, comp_len);  /* Копируем компоненты */
    return 1 + len_bytes + comp_len;   /* Общая длина */
}

/*
 * Функция: encode_set
 * Назначение: Кодирование SET по BER (X.690 раздел 8.11)
 * Параметры:
 *   components - массив закодированных компонентов набора
 *   comp_len   - длина массива components в октетах
 *   out        - выходной буфер
 * Возвращает: количество записанных октетов
 */
static int encode_set(uint8_t* components, int comp_len, uint8_t* out) {
    int len_bytes;                     /* Количество октетов для записи длины */
    
    out[0] = 0x31;                     /* TAG SET = 0x31 (Universal, Constructed) */
    len_bytes = encode_length(comp_len, out + 1);  /* Кодируем длину содержимого */
    memcpy(out + 1 + len_bytes, components, comp_len);  /* Копируем компоненты */
    return 1 + len_bytes + comp_len;   /* Общая длина */
}

/* ============================================================================
 * ОСНОВНЫЕ ФУНКЦИИ КОМПОНЕНТА (COM-интерфейсы)
 * ============================================================================ */

/*
 * Функция: CEcoASNOneBER1_QueryInterface
 * Назначение: COM-интерфейс для получения указателей на другие интерфейсы
 * Параметры:
 *   me   - указатель на текущий объект
 *   riid - GUID запрашиваемого интерфейса
 *   ppv  - указатель на указатель для возврата интерфейса
 * Возвращает: 0 при успехе, -1 при ошибке
 */
static int16_t ECOCALLMETHOD CEcoASNOneBER1_QueryInterface(struct IEcoASNOneBER1* me, const UGUID* riid, void** ppv) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;  /* Приводим к нашему типу */
    
    /* Проверка валидности указателей */
    if (me == 0 || ppv == 0) return -1;
    
    /* Проверяем, какой интерфейс запрашивают */
    if (IsEqualUGUID(riid, &IID_IEcoASNOneBER1) || IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoASNOneBER1;     /* Возвращаем VTBL нашего интерфейса */
        ((IEcoASNOneBER1*)(*ppv))->pVTbl->AddRef((IEcoASNOneBER1*)pCMe);  /* Увеличиваем счётчик */
        return 0;                                 /* Успех */
    }
    
    *ppv = 0;          /* Запрашиваемый интерфейс не поддерживается */
    return -1;         /* Ошибка */
}

/*
 * Функция: CEcoASNOneBER1_AddRef
 * Назначение: COM-интерфейс для увеличения счётчика ссылок
 * Параметры:
 *   me - указатель на текущий объект
 * Возвращает: новое значение счётчика ссылок
 */
static uint32_t ECOCALLMETHOD CEcoASNOneBER1_AddRef(struct IEcoASNOneBER1* me) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;  /* Приводим к нашему типу */
    if (me == 0) return -1;                      /* Проверка указателя */
    return ++pCMe->m_cRef;                       /* Увеличиваем и возвращаем счётчик */
}

/*
 * Функция: CEcoASNOneBER1_Release
 * Назначение: COM-интерфейс для уменьшения счётчика ссылок
 * Параметры:
 *   me - указатель на текущий объект
 * Возвращает: новое значение счётчика ссылок (0 если объект удалён)
 */
static uint32_t ECOCALLMETHOD CEcoASNOneBER1_Release(struct IEcoASNOneBER1* me) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;  /* Приводим к нашему типу */
    if (me == 0) return -1;                      /* Проверка указателя */
    
    if (--pCMe->m_cRef == 0) {                   /* Уменьшаем счётчик, проверяем на ноль */
        deleteCEcoASNOneBER1((IEcoASNOneBER1*)pCMe);  /* Удаляем объект */
        return 0;                                     /* Возвращаем 0 */
    }
    return pCMe->m_cRef;                       /* Возвращаем новый счётчик */
}

/*
 * Функция: CEcoASNOneBER1_Encode
 * Назначение: Главная функция кодирования ASN.1 значения в BER
 * Параметры:
 *   me     - указатель на компонент
 *   pv     - указатель на ASN.1 значение (IEcoUnknown*)
 *   buffer - указатель на указатель буфера для результата
 *   length - указатель на длину буфера (на входе) или результирующую длину (на выходе)
 * Возвращает: 0 при успехе, код ошибки при неудаче
 */
static int16_t ECOCALLMETHOD CEcoASNOneBER1_Encode(IEcoASNOneBER1Ptr_t me, voidptr_t pv, byte_t** buffer, uint32_t* length) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;        /* Приводим к нашему типу */
    IEcoUnknown* pIUnk = (IEcoUnknown*)pv;              /* Приводим входной указатель к IEcoUnknown */
    IEcoASNOne1Value* pIValue = 0;                      /* Интерфейс значения (для простых типов) */
    IEcoASNOne1ValueSet* pIValueSet = 0;                /* Интерфейс набора (для SEQUENCE/SET) */
    IEcoASNOne1Type* pIType = 0;                        /* Интерфейс типа (содержит TAG) */
    voidptr_t pIItem = 0;                               /* Временный указатель на элемент набора */
    uint8_t taggedType;                                 /* Тип метки (IMPLICIT/EXPLICIT/EMPTY) */
    uint8_t typeTag;                                    /* TAG типа */
    uint32_t cCount;                                    /* Количество элементов в наборе */
    uint32_t i;                                         /* Счётчик */
    uint32_t TotalLength;                               /* Общая длина закодированных данных */
    uint32_t TempLength;                                /* Временная длина для рекурсивных вызовов */
    int32_t cbSize;                                     /* Размер данных значения */
    uint8_t* pValueData;                                /* Указатель на данные значения */
    uint8_t* pBuffer;                                   /* Указатель на выходной буфер */
    uint8_t* pOffset;                                   /* Текущее смещение в буфере */
    int result;                                         /* Результат операций */
    int encoded_len;                                    /* Длина закодированных данных */
    uint8_t temp_buffer[65536];                         /* Временный буфер для кодирования */
    int len_bytes;                                      /* Количество октетов длины */
    uint8_t header[16];                                 /* Буфер для заголовка TLV */
    int header_len;                                     /* Длина заголовка */
    
    /* Проверка входных параметров */
    if (me == 0 || pv == 0) return ERR_ECO_POINTER;
    
    /* Получаем интерфейс типа значения (содержит TAG информацию) */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1Type, (voidptr_t*)&pIType);
    if (result != 0 || pIType == 0) return -1;
    
    /* Извлекаем информацию о метке и типе */
    taggedType = pIType->pVTbl->get_TaggedType(pIType) & 0x03;  /* Тип метки (0-3) */
    typeTag = pIType->pVTbl->get_Type(pIType);                  /* TAG типа */
    
    /* Пытаемся получить интерфейс значения (для простых типов) */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1Value, (voidptr_t*)&pIValue);
    
    if (pIValue != 0) {
        /* ===== ПРОСТОЕ ЗНАЧЕНИЕ (INTEGER, BOOLEAN, STRING и т.д.) ===== */
        
        /* Сначала узнаём размер данных */
        result = pIValue->pVTbl->get_Value(pIValue, 0, &cbSize);
        if (result != 0 || cbSize <= 0) return -1;
        
        /* Выделяем временный буфер для данных */
        pValueData = (uint8_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, cbSize);
        if (!pValueData) return -1;
        
        /* Получаем данные значения */
        result = pIValue->pVTbl->get_Value(pIValue, pValueData, &cbSize);
        if (result != 0) {
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pValueData);
            return -1;
        }
        
        /* Кодируем в зависимости от типа TAG */
        switch (typeTag) {
            case 0x01:  /* BOOLEAN */
                encoded_len = encode_boolean(pValueData[0], temp_buffer);
                break;
            case 0x02:  /* INTEGER */
                encoded_len = encode_integer(*(uint32_t*)pValueData, temp_buffer);
                break;
            case 0x03:  /* BIT STRING */
                encoded_len = encode_bit_string(pValueData, cbSize, temp_buffer);
                break;
            case 0x04:  /* OCTET STRING */
                encoded_len = encode_octet_string(pValueData, cbSize, temp_buffer, 0);
                break;
            case 0x05:  /* NULL */
                encoded_len = encode_null(temp_buffer);
                break;
            case 0x06:  /* OBJECT IDENTIFIER */
                /* Кодируем OID без TAG и LENGTH */
                encoded_len = encode_oid((uint32_t*)pValueData, cbSize / 4, temp_buffer + 2);
                if (encoded_len > 0) {
                    /* Добавляем TAG и LENGTH */
                    temp_buffer[0] = 0x06;
                    len_bytes = encode_length(encoded_len, temp_buffer + 1);
                    encoded_len = 1 + len_bytes + encoded_len;
                } else {
                    encoded_len = -1;
                }
                break;
            case 0x0C:  /* UTF8String */
            case 0x13:  /* PrintableString */
            case 0x16:  /* IA5String */
                encoded_len = encode_string(typeTag, (char*)pValueData, temp_buffer);
                break;
            default:    /* Неизвестный тип - кодируем "как есть" */
                temp_buffer[0] = typeTag;
                len_bytes = encode_length(cbSize, temp_buffer + 1);
                memcpy(temp_buffer + 1 + len_bytes, pValueData, cbSize);
                encoded_len = 1 + len_bytes + cbSize;
                break;
        }
        
        /* Освобождаем временный буфер */
        pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pValueData);
        if (encoded_len < 0) return -1;
        
        /* Если нужно записать в буфер */
        if (buffer != 0) {
            if (*length == 0) {
                /* Выделяем новую память */
                pBuffer = (uint8_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, encoded_len);
            } else if (*buffer != 0) {
                /* Используем предоставленный буфер */
                pBuffer = *buffer;
            } else {
                return -1;
            }
            memcpy(pBuffer, temp_buffer, encoded_len);  /* Копируем результат */
            *buffer = pBuffer;                         /* Возвращаем указатель */
        }
        if (length != 0) *length = encoded_len;        /* Возвращаем длину */
        
    } else {
        /* ===== СОСТАВНОЕ ЗНАЧЕНИЕ (SEQUENCE, SET, CHOICE, SEQUENCE OF, SET OF) ===== */
        
        /* Получаем интерфейс набора значений */
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1ValueSet, (voidptr_t*)&pIValueSet);
        if (pIValueSet == 0) return -1;
        
        /* Получаем количество элементов в наборе */
        result = pIValueSet->pVTbl->Count(pIValueSet, (int32_t*)&cCount);
        
        /* Рекурсивно кодируем все элементы и вычисляем общую длину */
        TotalLength = 0;
        for (i = 0; i < cCount; i++) {
            result = pIValueSet->pVTbl->Item(pIValueSet, i, &pIItem);
            if (result == 0) {
                result = CEcoASNOneBER1_Encode(me, pIItem, 0, &TempLength);
                TotalLength += TempLength;
            }
        }
        
        /* Формируем заголовок (TAG + LENGTH) */
        header_len = 0;
        if (taggedType == ECO_ASN1_TAG_IMPLICIT) {
            /* Неявная метка - используем внешний TAG */
            header[header_len++] = pIType->pVTbl->get_Tag(pIType);
        } else {
            /* Явная метка или без метки - устанавливаем constructed бит */
            header[header_len++] = typeTag | 0x20;  /* 0x20 = constructed bit */
        }
        header_len += encode_length(TotalLength, header + header_len);  /* Добавляем длину */
        
        TotalLength += header_len;  /* Общая длина с заголовком */
        
        /* Если нужно записать в буфер */
        if (buffer != 0) {
            if (*length == 0) {
                pBuffer = (uint8_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, TotalLength);
            } else if (*buffer != 0) {
                pBuffer = *buffer;
            } else {
                return -1;
            }
            
            /* Копируем заголовок */
            memcpy(pBuffer, header, header_len);
            pOffset = pBuffer + header_len;
            
            /* Рекурсивно кодируем элементы в буфер */
            for (i = 0; i < cCount; i++) {
                result = pIValueSet->pVTbl->Item(pIValueSet, i, &pIItem);
                if (result == 0) {
                    result = CEcoASNOneBER1_Encode(me, pIItem, &pOffset, &TempLength);
                    pOffset += TempLength;
                }
            }
            
            *buffer = pBuffer;
        }
        if (length != 0) *length = TotalLength;
    }
    
    return 0;  /* Успех */
}

/*
 * Функция: CEcoASNOneBER1_Decode
 * Назначение: Главная функция декодирования BER в ASN.1 значение
 * Параметры:
 *   me     - указатель на компонент
 *   buffer - указатель на буфер с BER-данными
 *   length - указатель на длину буфера (на входе) или количество декодированных байт (на выходе)
 *   ppv    - указатель на указатель для результата (IEcoASNOne1Value* или IEcoASNOne1ValueSet*)
 * Возвращает: 0 при успехе, код ошибки при неудаче
 */
static int16_t ECOCALLMETHOD CEcoASNOneBER1_Decode(IEcoASNOneBER1Ptr_t me, byte_t* buffer, uint32_t* length, voidptr_t* ppv) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;        /* Приводим к нашему типу */
    IEcoASNOne1Value* pIValue = 0;                     /* Интерфейс значения (для простых типов) */
    IEcoASNOne1ValueSet* pIValueSet = 0;               /* Интерфейс набора (для SEQUENCE/SET) */
    uint8_t* p = buffer;                               /* Текущий указатель в буфере */
    uint32_t remaining = *length;                      /* Оставшаяся длина буфера */
    uint8_t tag_class, tag_pc;                         /* Класс и P/C флаг тега */
    uint32_t tag_number;                               /* Номер тега */
    uint32_t value_length;                             /* Длина значения */
    int is_indefinite;                                 /* Флаг неопределённой длины */
    uint32_t consumed;                                 /* Количество потреблённых байт */
    int32_t idx;                                       /* Индекс для добавления в ValueSet */
    int16_t result;                                    /* Результат операций */
    uint32_t oid_buf[32];                              /* Буфер для декодированного OID */
    int oid_count;                                     /* Количество компонентов OID */
    uint32_t val;                                      /* Временное значение */
    uint32_t first;                                    /* Первый компонент OID */
    voidptr_t pChild;                                  /* Указатель на дочерний объект */
    uint32_t child_len;                                /* Длина дочернего объекта */
    
    /* Проверка входных параметров */
    if (me == 0 || buffer == 0 || length == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }
    
    /* Декодируем TAG */
    decode_tag(&p, &tag_class, &tag_pc, &tag_number);
    remaining -= (p - buffer);                         /* Уменьшаем оставшуюся длину */
    
    /* Декодируем LENGTH */
    decode_length(&p, &value_length, &is_indefinite);
    remaining -= (p - buffer);
    
    /* Если это CONSTRUCTED тип (tag_pc == 1) или универсальный SEQUENCE/SET */
    if (tag_pc == 1) {
        /* ===== СОСТАВНОЕ ЗНАЧЕНИЕ (SEQUENCE, SET, CHOICE, SEQUENCE OF, SET OF) ===== */
        
        /* Создаём новый ValueSet для хранения компонентов */
        result = pCMe->m_pIASNOne->pVTbl->new_ValueSet(pCMe->m_pIASNOne, (uint8_t)tag_number, 0, (uint8_t)tag_number, &pIValueSet);
        if (result != 0 || pIValueSet == 0) return -1;
        
        consumed = 0;
        idx = 0;
        
        if (is_indefinite) {
            /* Indefinite length — читаем до EOC (00 00) */
            while (remaining >= 2) {
                /* Проверяем EOC маркер */
                if (p[0] == 0x00 && p[1] == 0x00) {
                    p += 2;          /* Пропускаем EOC */
                    break;           /* Выходим из цикла */
                }
                pChild = 0;
                child_len = remaining;
                /* Рекурсивно декодируем дочерний элемент */
                CEcoASNOneBER1_Decode(me, p, &child_len, &pChild);
                if (pChild) {
                    pIValueSet->pVTbl->Add(pIValueSet, pChild, &idx);  /* Добавляем в набор */
                }
                p += child_len;
                consumed += child_len;
                remaining -= child_len;
            }
        } else {
            /* Definite length — читаем ровно value_length байт */
            while (consumed < value_length && remaining > 0) {
                pChild = 0;
                child_len = remaining;
                CEcoASNOneBER1_Decode(me, p, &child_len, &pChild);
                if (pChild) {
                    pIValueSet->pVTbl->Add(pIValueSet, pChild, &idx);  /* Добавляем в набор */
                }
                p += child_len;
                consumed += child_len;
                remaining -= child_len;
            }
        }
        
        *ppv = pIValueSet;                     /* Возвращаем набор */
        *length = (uint32_t)(p - buffer);      /* Возвращаем количество декодированных байт */
        
    } else {
        /* ===== ПРИМИТИВНОЕ ЗНАЧЕНИЕ ===== */
        
        /* Создаём новое Value для хранения примитивного значения */
        result = pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, (uint8_t)tag_number, 0, (uint8_t)tag_number, &pIValue);
        if (result != 0 || pIValue == 0) return -1;
        
        /* Для OBJECT IDENTIFIER нужна специальная обработка (декодирование чисел) */
        if (tag_number == 0x06 && value_length > 0) {
            oid_count = 0;
            
            /* Декодируем первый subidentifier (40 * X + Y) */
            val = 0;
            while (value_length > 0 && (*p & 0x80)) {
                val = (val << 7) | (*p & 0x7F);
                p++;
                value_length--;
            }
            if (value_length > 0) {
                val = (val << 7) | (*p & 0x7F);
                p++;
                value_length--;
            }
            first = val;
            oid_buf[0] = first / 40;      /* Первый компонент OID */
            oid_buf[1] = first % 40;      /* Второй компонент OID */
            oid_count = 2;
            
            /* Декодируем остальные subidentifier */
            while (value_length > 0) {
                val = 0;
                while (value_length > 0 && (*p & 0x80)) {
                    val = (val << 7) | (*p & 0x7F);
                    p++;
                    value_length--;
                }
                if (value_length > 0) {
                    val = (val << 7) | (*p & 0x7F);
                    p++;
                    value_length--;
                }
                oid_buf[oid_count++] = val;
            }
            
            /* Сохраняем декодированный OID как массив 32-битных чисел */
            pIValue->pVTbl->set_Value(pIValue, (uint8_t*)oid_buf, oid_count * 4);
        } else {
            /* Для всех остальных типов — просто копируем данные */
            pIValue->pVTbl->set_Value(pIValue, p, value_length);
            p += value_length;
        }
        
        *ppv = pIValue;                      /* Возвращаем значение */
        *length = (uint32_t)(p - buffer);    /* Возвращаем количество декодированных байт */
    }
    
    return 0;  /* Успех */
}

/* ============================================================================
 * ФУНКЦИИ УПРАВЛЕНИЯ ЭКЗЕМПЛЯРОМ
 * ============================================================================ */

/*
 * Функция: initCEcoASNOneBER1
 * Назначение: Инициализация экземпляра компонента
 * Параметры:
 *   me         - указатель на компонент
 *   pIUnkSystem - указатель на системный интерфейс Eco
 * Возвращает: 0 при успехе, -1 при ошибке
 */
int16_t initCEcoASNOneBER1(struct IEcoASNOneBER1* me, struct IEcoUnknown *pIUnkSystem) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;  /* Приводим к нашему типу */
    if (me == 0) return -1;                      /* Проверка указателя */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;   /* Сохраняем системный интерфейс */
    pCMe->m_Name = 0;                            /* Обнуляем имя */
    return 0;                                    /* Успех */
}

/* Виртуальная таблица функций (VTBL) для интерфейса IEcoASNOneBER1 */
IEcoASNOneBER1VTbl g_x0CE271866EA74C0495282B0A4C427BBFVTbl = {
    CEcoASNOneBER1_QueryInterface,   /* Указатель на QueryInterface */
    CEcoASNOneBER1_AddRef,           /* Указатель на AddRef */
    CEcoASNOneBER1_Release,          /* Указатель на Release */
    CEcoASNOneBER1_Encode,           /* Указатель на Encode */
    CEcoASNOneBER1_Decode            /* Указатель на Decode */
};

/*
 * Функция: createCEcoASNOneBER1
 * Назначение: Создание экземпляра компонента
 * Параметры:
 *   pIUnkSystem    - указатель на системный интерфейс
 *   pIUnkOuter     - указатель на внешний Unknown (для агрегации)
 *   ppIEcoASNOneBER1 - указатель на указатель для возврата созданного компонента
 * Возвращает: 0 при успехе, код ошибки при неудаче
 */
int16_t createCEcoASNOneBER1(IEcoUnknown* pIUnkSystem, IEcoUnknown* pIUnkOuter, IEcoASNOneBER1** ppIEcoASNOneBER1) {
    int16_t result = -1;                       /* Результат операции */
    IEcoSystem1* pISys = 0;                    /* Системный интерфейс */
    IEcoInterfaceBus1* pIBus = 0;              /* Интерфейс шины */
    IEcoMemoryAllocator1* pIMem = 0;           /* Интерфейс управления памятью */
    CEcoASNOneBER1* pCMe = 0;                 /* Указатель на наш объект */

    /* Проверка входных параметров */
    if (ppIEcoASNOneBER1 == 0 || pIUnkSystem == 0) return result;

    /* Получаем системный интерфейс */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void**)&pISys);
    if (result != 0 || pISys == 0) return result;

    /* Получаем интерфейс шины */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    if (result != 0 || pIBus == 0) { 
        pISys->pVTbl->Release(pISys); 
        return result; 
    }

    /* Получаем менеджер памяти через шину */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);

    /* Выделяем память для экземпляра компонента */
    pCMe = (CEcoASNOneBER1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOneBER1));
    if (pCMe == 0) {
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return -1;
    }

    /* Инициализируем поля структуры */
    pCMe->m_pISys = pISys;                                         /* Системный интерфейс */
    pCMe->m_pIMem = pIMem;                                         /* Менеджер памяти */
    pCMe->m_cRef = 1;                                              /* Начальный счётчик ссылок = 1 */
    pCMe->m_pVTblIEcoASNOneBER1 = &g_x0CE271866EA74C0495282B0A4C427BBFVTbl;  /* VTBL */
    pCMe->m_Name = 0;                                              /* Имя (пока пусто) */

    /* Получаем интерфейс ASN.1 (нужен для создания значений и наборов) */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOne1, 0, &IID_IEcoASNOne1, (void**)&pCMe->m_pIASNOne);
    if (result != 0 || pCMe->m_pIASNOne == 0) {
        /* Ошибка — освобождаем все ресурсы */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        pIMem->pVTbl->Free(pIMem, pCMe);
        return -1;
    }

    /* Возвращаем указатель на интерфейс IEcoASNOneBER1 */
    *ppIEcoASNOneBER1 = (IEcoASNOneBER1*)pCMe;
    
    /* Освобождаем ненужные интерфейсы */
    pIBus->pVTbl->Release(pIBus);
    return 0;  /* Успех */
}

/*
 * Функция: deleteCEcoASNOneBER1
 * Назначение: Освобождение экземпляра компонента
 * Параметры:
 *   pIEcoASNOneBER1 - указатель на удаляемый компонент
 */
void deleteCEcoASNOneBER1(IEcoASNOneBER1* pIEcoASNOneBER1) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)pIEcoASNOneBER1;  /* Приводим к нашему типу */
    IEcoMemoryAllocator1* pIMem = 0;                          /* Менеджер памяти */
    
    if (pIEcoASNOneBER1 != 0) {
        pIMem = pCMe->m_pIMem;                               /* Сохраняем менеджер памяти */
        
        /* Освобождаем имя, если было выделено */
        if (pCMe->m_Name != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        
        /* Освобождаем системный интерфейс */
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        
        /* Освобождаем интерфейс ASN.1 */
        if (pCMe->m_pIASNOne != 0) {
            pCMe->m_pIASNOne->pVTbl->Release(pCMe->m_pIASNOne);
        }
        
        /* Освобождаем память самого объекта */
        pIMem->pVTbl->Free(pIMem, pCMe);
        
        /* Освобождаем менеджер памяти */
        pIMem->pVTbl->Release(pIMem);
    }
}
=======
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoASNOne1.h"
#include "IdEcoASNOne1.h"
#include "ErrEcoASNOne1.h"
#include "CEcoASNOneBER1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOneBER1
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOneBER1_QueryInterface(/* in */ struct IEcoASNOneBER1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOneBER1) ) {
        *ppv = &pCMe->m_pVTblIEcoASNOneBER1;
        pCMe->m_pVTblIEcoASNOneBER1->AddRef((IEcoASNOneBER1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoASNOneBER1;
        pCMe->m_pVTblIEcoASNOneBER1->AddRef((IEcoASNOneBER1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoASNOneBER1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOneBER1_AddRef(/* in */ struct IEcoASNOneBER1* me) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoASNOneBER1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOneBER1_Release(/* in */ struct IEcoASNOneBER1* me) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOneBER1((IEcoASNOneBER1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Encode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOneBER1_Encode(/* in */ IEcoASNOneBER1Ptr_t me, /* in */ voidptr_t pv, /* out */ byte_t** buffer, /* out */ uint32_t* length) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;
    int16_t result = 0;
    IEcoUnknown* pIUnk = (IEcoUnknown*)pv;
    IEcoASNOne1Value* pIValue = 0;
    voidptr_t pIItem = 0;
    IEcoASNOne1Type* pIType = 0;
    IEcoASNOne1ValueSet* pIValueSet = 0;
    uint8_t tagNumber = 0;
    uint8_t tagPC = 0;
    uint8_t tagClass = 0;
    uint8_t taggedType = 0;
    uint8_t typeNumber = 0;
    uint8_t typePC = 0;
    uint8_t typeClass = 0;
    byte_t* pBuffer = 0;
    byte_t* pOffset = 0;
    int32_t cbSize= 0;
    uint32_t cbLength = 0;
    int32_t cIndex= 0;
    uint32_t cCount= 0;

    byte_t* pTempBuffer = 0;
    uint32_t TempLength = 0;
    uint32_t TotalLength = 0;

    /* Проверка указателей */
    if (me == 0 || pv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Запрашивает интерфейс на тип значения */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1Type, (voidptr_t*)&pIType);
    if (result != 0 || pIType == 0) {
        return result;
    }

    /* Переобразуем тип и метку в поля */
    tagNumber = (pIType->pVTbl->get_Tag(pIType) & 0x1F);
    tagPC = (pIType->pVTbl->get_Tag(pIType) & 0x40);
    tagClass = (pIType->pVTbl->get_Tag(pIType) & 0xC0);
    taggedType = (pIType->pVTbl->get_TaggedType(pIType) & 0x03);
    typeNumber = (pIType->pVTbl->get_Type(pIType) & 0x1F);
    typePC = (pIType->pVTbl->get_Type(pIType) & 0x40);
    typeClass = (pIType->pVTbl->get_Type(pIType) & 0xC0);


    /* Запрашивает интерфейс на значения */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1Value, (voidptr_t*)&pIValue);
    /* Если удачно, то выполняем кодирование значения */
    if ( pIValue != 0) {
        /* Вычисляем необходимый размер буфера */
        result = pIValue->pVTbl->get_Value(pIValue, pBuffer, &cbSize);
        /* Добавляем байты под тип и длину */
        cbLength = cbSize+2;
        /* Если тип с меткой и явный, то добавляем дополнительные байты под тип и длину */
        if ((taggedType != ECO_ASN1_TAG_IMPLICIT) && (taggedType != ECO_ASN1_TAG_EMPTY)) {
            if (pIType->pVTbl->get_Type(pIType) != ECO_ASN1_EMPTY) {
                cbLength += 2;
            }
        }
        /* Если указатель на указатель буфера не равен нулю, то выполняем кодирование */
        if (buffer != 0) {
            /* Если длина буфера равна нулю, то выделяем необходимый размер памяти */
            if (*length == 0) {
                pBuffer = (byte_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, cbLength);
            }
            /* Иначе если указатель на буфер не равен нулю, то выполняем кодирование в выделенный буфер */
            else if (*buffer != 0) {
                pBuffer = *buffer;
            }
            /* Иначе возвращаем ошибку */
            else {
                return -1;
            }
            pOffset = pBuffer;
            /* Если есть метка и она не явная */
            if (taggedType == ECO_ASN1_TAG_IMPLICIT) {
                pOffset[0] = pIType->pVTbl->get_Tag(pIType);
                pOffset[1] = (uint8_t)cbSize;
            }
            else if (taggedType != ECO_ASN1_TAG_EMPTY) {
                pOffset[0] = pIType->pVTbl->get_Tag(pIType);
                pOffset[1] = (uint8_t)(cbSize + 2);
                if (pIType->pVTbl->get_Type(pIType) != ECO_ASN1_EMPTY) {
                    pOffset += 2;
                    pOffset[0] = pIType->pVTbl->get_Type(pIType);
                    pOffset[1] = (uint8_t)cbSize;
                }
            }
            else {
                pOffset[0] = pIType->pVTbl->get_Type(pIType);
                pOffset[1] = (uint8_t)cbSize;
            }
            pOffset += 2;
            result = pIValue->pVTbl->get_Value(pIValue, pOffset, &cbSize);
            /* Возвращаем указатель на буфер */
            *buffer = pBuffer;
        }
        /* Если указатель на длину не равен нулю, то возвращаем длину буфера */
        if (length != 0) {
            *length = cbLength;
        }
    }
    else  {
        /* Если не удачно, то запрашивает интерфейс на набор значений */
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1ValueSet, (voidptr_t*)&pIValueSet);
        /* Если удачно, то выполняем кодирование значения, иначе возвращаем ошибку */
        if ( pIValueSet == 0) {
            return ERR_ECO_POINTER;
        }
        /* Запрашиваем количество ASN.1 компонентов в наборе */
        result = pIValueSet->pVTbl->Count(pIValueSet, &cCount);
        /* Вычисляем необходимый размер буфера */
        for (cIndex = 0; cIndex < cCount; cIndex++) {
            /* Запрашиваем ASN.1 компонент по индексу в наборе */
            result = pIValueSet->pVTbl->Item(pIValueSet, cIndex, &pIItem);
            /* Выполняем кодирование без указателя на буфер, для вычисления необходимого размера памяти */
            result = CEcoASNOneBER1_Encode(me, pIItem, 0, &TempLength);
            /* Суммируем размеры всех компонентов последовательности*/
            TotalLength += TempLength;
        }
        /* Добавляем байты под тип и длину */
        cbLength = TotalLength+2;
        /* Если тип с меткой и явный, то добавляем дополнительные байты под тип и длину */
        if ((taggedType != ECO_ASN1_TAG_IMPLICIT) && (taggedType != ECO_ASN1_TAG_EMPTY)) {
            if (pIType->pVTbl->get_Type(pIType) != ECO_ASN1_EMPTY) {
                cbLength += 2;
            }
        }
        /* Если указатель на указатель буфера не равен нулю, то выполняем кодирование */
        if (buffer != 0) {
            /* Если длина буфера равна нулю, то выделяем необходимый размер памяти */
            if (*length == 0) {
                pBuffer = (byte_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, cbLength);
            }
            /* Иначе если указатель на буфер не равен нулю, то выполняем кодирование в выделенный буфер */
            else if (*buffer != 0) {
                pBuffer = *buffer;
            }
            /* Иначе возвращаем ошибку */
            else {
                return -1;
            }
            pOffset = pBuffer;

            /* Если есть метка и она не явная */
            if (taggedType == ECO_ASN1_TAG_IMPLICIT) {
                pOffset[0] = pIType->pVTbl->get_Tag(pIType);
                pOffset[1] = (uint8_t)TotalLength;
            }
            else if (taggedType != ECO_ASN1_TAG_EMPTY) {
                pOffset[0] = pIType->pVTbl->get_Tag(pIType);
                pOffset[1] = (uint8_t)TotalLength;
                if (pIType->pVTbl->get_Type(pIType) != ECO_ASN1_EMPTY) {
                    pOffset[1] = (uint8_t)(TotalLength + 2);
                    pOffset += 2;
                    pOffset[0] = pIType->pVTbl->get_Type(pIType);
                    pOffset[1] = (uint8_t)TotalLength;
                }
            }
            else {
                pOffset[0] = pIType->pVTbl->get_Type(pIType);
                pOffset[1] = (uint8_t)TotalLength;
            }
            pOffset += 2;
            /* Вычисляем кодирование всех ASN.1 компонентов набора */
            for (cIndex = 0; cIndex < cCount; cIndex++) {
                /* Запрашиваем ASN.1 компонент по индексу в наборе */
                result = pIValueSet->pVTbl->Item(pIValueSet, cIndex, &pIItem);
                /* Выполняем кодирование */
                result = CEcoASNOneBER1_Encode(me, pIItem, &pOffset, &TempLength);
                /* Смещаем указатель */
                pOffset += TempLength;
            }
            /* Возвращаем указатель на буфер */
            *buffer = pBuffer;
        }
        /* Если указатель на длину не равен нулю, то возвращаем длину буфера */
        if (length != 0) {
            *length = cbLength;
        }
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Decode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOneBER1_Decode(/* in */ IEcoASNOneBER1Ptr_t me, /* in */ byte_t* buffer, /* in | out */ uint32_t* length, /* out */ voidptr_t* ppv) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;
    int16_t result = 0;
    uint8_t Tag = 0;
    uint8_t tagNumber = 0;
    uint8_t tagPC = 0;
    uint8_t tagClass = 0;
    uint8_t taggedType = ECO_ASN1_TAG_EMPTY;
    uint8_t Type = 0;
    uint8_t typeNumber = 0;
    uint8_t typePC = 0;
    uint8_t typeClass = 0;
    IEcoUnknown* pIUnk = 0;

    IEcoASNOne1Value* pIValue = 0;
    IEcoASNOne1ValueSet* pIValueSet = 0;
    IEcoASNOne1Value* pIRootValue = 0;
    IEcoASNOne1ValueSet* pIRootValueSet = 0;

    //IEcoASNOne1INTEGER* pIINTEGER = 0;
    //uint8_t tagClass = 0;
    //uint8_t tagNumber = 0;
    uint32_t iTotalLength = *length;
    byte_t* pOffset = buffer;
    uint32_t cbCount = 0;
    uint32_t cbTempCount = 0;
    int32_t cbSize = 0;
    int32_t cbTempSize = 0;
    int32_t iIndex = 0;

    /* Проверка указателей */
    if (me == 0 || buffer == 0) {
        return ERR_ECO_POINTER;
    }

    while (cbCount < iTotalLength) {
        /* Проверим  не является ли тип меткой */
        typeNumber = (pOffset[0] & 0x1F);
        typePC = (pOffset[0] & 0x20);
        typeClass = (pOffset[0] & 0xC0);
        if ( (typePC != ECO_ASN1_PC_CONSTRUCTED && typeClass != ECO_ASN1_CLASS_UNIVERSAL) &&
             (typePC == ECO_ASN1_PC_CONSTRUCTED && typeClass == ECO_ASN1_CLASS_UNIVERSAL) ) {
            Tag = pOffset[0];
            tagNumber = typeNumber;
            tagPC = typePC;
            tagClass = typeClass;
            taggedType = ECO_ASN1_TAG_DEFAULT;
            typeNumber = (pOffset[1] & 0x1F);
            typePC = (pOffset[1] & 0x40);
            typeClass = (pOffset[1] & 0xC0);
            Type = pOffset[1];
            pOffset++;
            cbCount++;
        }
        else {
            Type = pOffset[0];
        }
        /* Оределим является ли тип одиночным значением или набором значений */

        /* Определим размер значения */
        pOffset++;
        cbCount++;
        cbSize = pOffset[0];
        pOffset++;
        cbCount++;
        /* Выполнять декодирование в созданную структуру объектов или создать новую */
        if (*ppv == 0) {

            if (typePC == ECO_ASN1_PC_CONSTRUCTED) {
                pCMe->m_pIASNOne->pVTbl->new_ValueSet(pCMe->m_pIASNOne, Tag, taggedType, Type, &pIValueSet);
                cbTempSize = cbSize;
                while (cbTempCount < cbSize) {
                    /* Указатель должен быть нулевым для вновь создаваемых объектов */
                    pIUnk = 0;
                    /* Вычисляем остаток длины */
                    cbTempSize = cbSize - cbTempCount;
                    CEcoASNOneBER1_Decode(me, pOffset, &cbTempSize, &pIUnk);
                    pIValueSet->pVTbl->Add(pIValueSet, pIUnk, &iIndex);
                    /* Перемещаем указатель на реально декодированную длину */
                    pOffset += cbTempSize;
                    /* Уведичиваем длину декодированных данных на реально декодированную длину */
                    cbTempCount += cbTempSize;
                }
                cbCount += cbSize;
                *ppv = pIValueSet;
                *length = cbCount;
            }
            else {
                pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, Tag, taggedType, Type, &pIValue);
                pIValue->pVTbl->set_Value(pIValue, pOffset, cbSize);
                cbCount += cbSize;
                *ppv = pIValue;
                *length = cbCount;
                break;
            }
        }

    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t initCEcoASNOneBER1(/*in*/ struct IEcoASNOneBER1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Инициализация данных */

    return 0;
}

/* Create Virtual Table */
IEcoASNOneBER1VTbl g_x0CE271866EA74C0495282B0A4C427BBFVTbl = {
    CEcoASNOneBER1_QueryInterface,
    CEcoASNOneBER1_AddRef,
    CEcoASNOneBER1_Release,
    CEcoASNOneBER1_Encode,
    CEcoASNOneBER1_Decode
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t createCEcoASNOneBER1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoASNOneBER1** ppIEcoASNOneBER1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOneBER1* pCMe = 0;

    /* Проверка указателей */
    if (ppIEcoASNOneBER1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoASNOneBER1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOneBER1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoASNOneBER1 */
    pCMe->m_pVTblIEcoASNOneBER1 = &g_x0CE271866EA74C0495282B0A4C427BBFVTbl;

    /* Получение интерфейса по работе с нотацией ASN.1 */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOne1, 0, &IID_IEcoASNOne1, (void**) &pCMe->m_pIASNOne);
    /* Проверка */
    if (result != 0 || pCMe->m_pIASNOne == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return -1; //ERR_ASNONE1EXAMPLE_REQ_COMP_ASN1;
    }
    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoASNOneBER1 = (IEcoASNOneBER1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void deleteCEcoASNOneBER1(/* in */ IEcoASNOneBER1* pIEcoASNOneBER1) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)pIEcoASNOneBER1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoASNOneBER1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
>>>>>>> a07e5e241146cb6af3ab0c263f13621f982cd839
