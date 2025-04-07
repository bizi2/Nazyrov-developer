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
