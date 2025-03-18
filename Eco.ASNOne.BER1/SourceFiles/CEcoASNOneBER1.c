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
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOneBER1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoASNOneBER1.h"

void encode_length(size_t length, uint8_t* encoded_length, size_t* encoded_len) {
    if (length < 128) {
        encoded_length[0] = (uint8_t)length;
        *encoded_len = 1;
    }
    else {
        size_t num_bytes = 0;
        size_t temp = length;
        while (temp > 0) {
            temp >>= 8;
            num_bytes++;
        }

        encoded_length[0] = 0x80 | num_bytes;
        for (size_t i = 0; i < num_bytes; i++) {
            encoded_length[num_bytes - i] = (length >> (8 * i)) & 0xFF;
        }

        *encoded_len = num_bytes + 1;
    }
}

size_t encode_oid_number(uint32_t number, uint8_t* buffer) {
    size_t len = 0;
    if (number == 0) {
        buffer[len++] = 0;
    }
    else {
        uint8_t temp[10];
        size_t temp_len = 0;

        // Разбиваем число на 7-битные части
        while (number > 0) {
            temp[temp_len++] = (number & 0x7F) | (temp_len > 0 ? 0x80 : 0);
            number >>= 7;
        }

        // Копируем байты в обратном порядке
        for (size_t i = temp_len; i > 0; i--) {
            buffer[len++] = temp[i - 1];
        }
    }
    return len;
}


uint8_t* CEcoASNOneBER1_EncodeOID(struct IEcoASNOneBER1* me, const uint8_t* buffer, size_t len) {
    uint32_t numbers[32];
    size_t num_count = 0;
    const uint8_t* ptr = oid_str;
    while (*ptr) {
        char* endptr;
        numbers[num_count++] = strtoul((const char*)ptr, &endptr, 10);
        ptr = (const uint8_t*)endptr;

        if (*ptr == '.') ptr++;
    }

    size_t total_len = 1;
    for (size_t i = 2; i < num_count; i++) {
        uint32_t num = numbers[i];
        do {
            total_len++;
            num >>= 7;
        } while (num > 0);
    }

    uint8_t* encoded = malloc(2 + total_len);
    if (!encoded) {
        return NULL;
    }

    encoded[0] = 0x06;

    encoded[1] = (uint8_t)total_len;

    encoded[2] = (numbers[0] * 40) + numbers[1];

    size_t offset = 3;
    for (size_t i = 2; i < num_count; i++) {
        offset += encode_oid_number(numbers[i], encoded + offset);
    }

    *encoded_len = offset;
    return encoded;
}


uint8_t* CEcoASNOneBER1_EncodeInteger(struct IEcoASNOneBER1* me, const int32_t value, size_t len) {
    size_t size = 0;
    int32_t temp = value;
    while (temp != 0 && temp != -1) {
        temp >>= 8;
        size++;
    }
    if (value == 0) {
        size = 1;
    }

    uint8_t* encoded = malloc(2 + size);
    if (!encoded) {
        return NULL;
    }

    encoded[0] = 0x02; // Tag
    encoded[1] = size; // Length
    for (size_t i = 0; i < size; i++) {
        encoded[2 + i] = (value >> (8 * (size - 1 - i))) & 0xFF;
    }

    *encoded_len = 2 + size;
    return encoded;
}

// OCTET STRING
uint8_t* CEcoASNOneBER1_EncodeOctetString(struct IEcoASNOneBER1* me, const uint8_t* data, size_t data_len, size_t* encoded_len) {
    uint8_t* encoded = malloc(2 + data_len);
    if (!encoded) {
        return NULL;
    }

    encoded[0] = 0x04;

    // Length
    encoded[1] = (uint8_t)data_len;

    // Value
    memcpy(encoded + 2, data, data_len);

    *encoded_len = 2 + data_len;
    return encoded;
}

uint8_t* CEcoASNOneBER1_EncodeSequence(struct IEcoASNOneBER1* me, uint8_t** elements, size_t* element_lens, size_t num_elements, size_t* encoded_len) {
    size_t total_len = 0;
    for (size_t i = 0; i < num_elements; i++) {
        total_len += element_lens[i];
    }

    uint8_t length_buffer[10];
    size_t length_len;
    encode_length(total_len, length_buffer, &length_len);

    // (Tag + Length + Value)
    uint8_t* encoded = malloc(1 + length_len + total_len);
    if (!encoded) {
        return NULL;
    }

    // Tag (SEQUENCE = 0x30)
    encoded[0] = 0x30;

    // Length
    memcpy(encoded + 1, length_buffer, length_len);

    // Value
    size_t offset = 1 + length_len;
    for (size_t i = 0; i < num_elements; i++) {
        memcpy(encoded + offset, elements[i], element_lens[i]);
        offset += element_lens[i];
    }

    *encoded_len = 1 + length_len + total_len;
    return encoded;
}

uint8_t* CEcoASNOneBER1_UTF8String(struct IEcoASNOneBER1* me, const uint8_t* str, size_t* encoded_len) {
    size_t str_len = strlen((const char*)str);
    uint8_t* encoded = malloc(2 + str_len);
    if (!encoded) {
        return NULL;
    }

    encoded[0] = 0x0C;
    encoded[1] = (uint8_t)str_len;
    memcpy(encoded + 2, str, str_len);

    *encoded_len = 2 + str_len;
    return encoded;
}

uint8_t* CEcoASNOneBER1_EncodePrintableString(struct IEcoASNOneBER1* me, const uint8_t* str, size_t* encoded_len) {
    size_t str_len = strlen((const char*)str);
    uint8_t* encoded = malloc(2 + str_len);
    if (!encoded) {
        return NULL;
    }

    encoded[0] = 0x13;
    encoded[1] = (uint8_t)str_len;
    memcpy(encoded + 2, str, str_len);

    *encoded_len = 2 + str_len;
    return encoded;
}

uint8_t* CEcoASNOneBER1_EncodeUTCTime(struct IEcoASNOneBER1* me, const uint8_t* utc_time, size_t* encoded_len) {
    size_t time_len = strlen((const char*)utc_time);
    uint8_t* encoded = malloc(2 + time_len);
    if (!encoded) {
        return NULL;
    }

    encoded[0] = 0x17;
    encoded[1] = (uint8_t)time_len;
    memcpy(encoded + 2, utc_time, time_len);

    *encoded_len = 2 + time_len;
    return encoded;
}

// --------------------------decode--------------------------

// INTEGER
int32_t CEcoASNOneBER1_DecodeInteger(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len) {
    if (encoded_len < 2 || encoded[0] != 0x02) {
        return 0;
    }

    size_t length = encoded[1];
    if (encoded_len < 2 + length) {
        return 0;
    }

    const uint8_t* ptr = encoded + 2;

    int32_t value = 0;
    if (ptr[0] & 0x80) {

        value = -1;
    }

    for (size_t i = 0; i < length; i++) {
        value = (value << 8) | ptr[i];
    }

    return value;
}

uint32_t decode_oid_number(const uint8_t** ptr) {
    uint32_t value = 0;
    uint8_t byte;
    do {
        byte = *(*ptr)++;
        value = (value << 7) | (byte & 0x7F);
    } while (byte & 0x80);
    return value;
}

// OID
uint8_t* CEcoASNOneBER1_DecodeOID(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len, size_t* decoded_len) {
    if (encoded_len < 2 || encoded[0] != 0x06) {
        return NULL;
    }

    size_t length = encoded[1];
    if (encoded_len < 2 + length) {
        return NULL;
    }

    const uint8_t* ptr = encoded + 2;

    uint32_t first = ptr[0] / 40;
    uint32_t second = ptr[0] % 40;
    ptr++;

    uint8_t* oid_str = malloc(256);
    if (!oid_str) {
        return NULL;
    }

    int offset = snprintf((char*)oid_str, 256, "%u.%u", first, second);

    while (ptr < encoded + 2 + length) {
        uint32_t number = decode_oid_number(&ptr);
        offset += snprintf((char*)oid_str + offset, 256 - offset, ".%u", number);
    }

    *decoded_len = strlen((char*)oid_str);
    return oid_str;
}

// OCTET STRING
uint8_t* CEcoASNOneBER1_DecodeOctetString(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len, size_t* decoded_len) {
    if (encoded_len < 2 || encoded[0] != 0x04) {
        return NULL;
    }

    size_t length = encoded[1];
    if (encoded_len < 2 + length) {
        return NULL;
    }

    uint8_t* decoded = malloc(length + 1);
    if (!decoded) {
        return NULL;
    }

    memcpy(decoded, encoded + 2, length);
    decoded[length] = '\0';

    *decoded_len = length;
    return decoded;
}

// SEQUENCE
uint8_t** CEcoASNOneBER1_DecodeSequence(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len, size_t* decoded_len) {
    
    return NULL;
}

// UTF8 STRING
uint8_t* CEcoASNOneBER1_DecodeUTF8String(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len, size_t* decoded_len) {
    if (encoded_len < 2 || encoded[0] != 0x04) {
        return NULL;
    }

    size_t length = encoded[1];
    if (encoded_len < 2 + length) {
        return NULL;
    }

    uint8_t* decoded = malloc(length + 1);
    if (!decoded) {
        return NULL;
    }

    memcpy(decoded, encoded + 2, length);
    decoded[length] = '\0';

    *decoded_len = length;
    return decoded;
}

// PRINTABLE STRING
uint8_t* CEcoASNOneBER1_DecodePrintableString(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len, size_t* decoded_len) {
    if (encoded_len < 2 || encoded[0] != 0x13) {
        return NULL;
    }

    size_t length = encoded[1];
    if (encoded_len < 2 + length) {
        return NULL;
    }

    uint8_t* decoded = malloc(length + 1);
    if (!decoded) {
        return NULL;
    }

    memcpy(decoded, encoded + 2, length);
    decoded[length] = '\0';

    *decoded_len = length;
    return decoded;
}

// UTC TIME
uint8_t* CEcoASNOneBER1_DecodeUTCTime(struct IEcoASNOneBER1* me, const uint8_t* encoded, size_t encoded_len, size_t* decoded_len) {
    if (encoded_len < 2 || encoded[0] != 0x17) {
        return NULL;
    }

    size_t length = encoded[1]; 
    if (encoded_len < 2 + length) {
        return NULL; 
    }

    uint8_t* decoded = malloc(length + 1); 
    if (!decoded) {
        return NULL;
    }

    memcpy(decoded, encoded + 2, length); 
    decoded[length] = '\0'; 

    *decoded_len = length;
    return decoded;
}

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
int16_t CEcoASNOneBER1_QueryInterface(/* in */ struct IEcoASNOneBER1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
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
uint32_t CEcoASNOneBER1_AddRef(/* in */ struct IEcoASNOneBER1* me) {
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
uint32_t CEcoASNOneBER1_Release(/* in */ struct IEcoASNOneBER1* me) {
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
uint8_t* CEcoASNOneBER1_Encode(/* in */ struct IEcoASNOneBER1* me) {



        return 0;
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
uint8_t* CEcoASNOneBER1_Encode(/* in */ struct IEcoASNOneBER1* me, const uint8_t* buffer, size_t len) {



    return 0;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoASNOneBER1_MyFunction(/* in */ struct IEcoASNOneBER1* me, /* in */ char_t* Name, /* out */ char_t** copyName) {
    CEcoASNOneBER1* pCMe = (CEcoASNOneBER1*)me;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || Name == 0 || copyName == 0) {
        return -1;
    }

    /* Копирование строки */
    while(Name[index] != 0) {
        index++;
    }
    pCMe->m_Name = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, index + 1);
    index = 0;
    while(Name[index] != 0) {
        pCMe->m_Name[index] = Name[index];
        index++;
    }
    *copyName = pCMe->m_Name;

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
    CEcoASNOneBER1_MyFunction,
    CEcoASNOneBER1_Encode,
    CEcoASNOneBER1_EncodeInteger,
    CEcoASNOneBER1_EncodeOID,
    CEcoASNOneBER1_EncodeOctetString,
    CEcoASNOneBER1_EncodeSequence,
    CEcoASNOneBER1_EncodeUTF8String,
    CEcoASNOneBER1_EncodePrintableString,
    CEcoASNOneBER1_EncodeEncodeUTCTime,
    CEcoASNOneBER1_Decode,
    CEcoASNOneBER1_DecodeOID,
    CEcoASNOneBER1_DecodeInteger,
    CEcoASNOneBER1_DecodeOctetString,
    CEcoASNOneBER1_DecodeSequence,
    CEcoASNOneBER1_DecodeUTF8String,
    CEcoASNOneBER1_DecodePrintableString,
    CEcoASNOneBER1_DecodeUTCTime
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
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

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
