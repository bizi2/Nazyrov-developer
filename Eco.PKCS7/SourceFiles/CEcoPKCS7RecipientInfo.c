/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS7RecipientInfo
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS7RecipientInfo
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoPKCS7RecipientInfo.h"
#include "CEcoPKCS7AlgorithmIdentifier.h"
#include "CEcoPKCS7IssuerAndSerialNumber.h"
#include "CEcoPKCS7Version.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS7RecipientInfo
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_QueryInterface(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS7RecipientInfo)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7RecipientInfo;
        pCMe->m_pVTblIEcoPKCS7RecipientInfo->AddRef((IEcoPKCS7RecipientInfo*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7RecipientInfo;
        pCMe->m_pVTblIEcoPKCS7RecipientInfo->AddRef((IEcoPKCS7RecipientInfo*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7RecipientInfo;
        pCMe->m_pVTblIEcoPKCS7RecipientInfo->AddRef((IEcoPKCS7RecipientInfo*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7RecipientInfo;
        pCMe->m_pVTblIEcoPKCS7RecipientInfo->AddRef((IEcoPKCS7RecipientInfo*)pCMe);
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoPKCS7RecipientInfo
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_AddRef(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
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
 *   Функция Release для интерфейса IEcoPKCS7RecipientInfo
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_Release(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS7RecipientInfo((IEcoPKCS7RecipientInfo*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}


/*
 *
 * <сводка>
 *   Функция get_Tag
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static uint8_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_get_Tag(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SET->pVTbl->get_Tag(pCMe->m_SET);
}

/*
 *
 * <сводка>
 *   Функция get_TaggetType
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static uint8_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_get_TaggetType(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SET->pVTbl->get_TaggedType(pCMe->m_SET);
}

/*
 *
 * <сводка>
 *   Функция get_Type
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static uint8_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_get_Type(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SET->pVTbl->get_Type(pCMe->m_SET);
}

/*
 *
 * <сводка>
 *   Функция Count
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_Count(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ int32_t* Count) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SET->pVTbl->Count(pCMe->m_SET, Count);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Item
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_Item(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SET->pVTbl->Item(pCMe->m_SET, Index, Component);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Add
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7RecipientInfo_Add(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SET->pVTbl->Add(pCMe->m_SET, Component, Index);

    return result;
}

/*
 *
 * <сводка>
 *   Функция name
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoPKCS7Version* ECOCALLMETHOD CEcoPKCS7RecipientInfo_version(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_version;
}

/*
 *
 * <сводка>
 *   Функция dateOfBirth
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoPKCS7IssuerAndSerialNumber* ECOCALLMETHOD CEcoPKCS7RecipientInfo_issuerAndSerialNumber(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_issuerAndSerialNumber;
}

/*
 *
 * <сводка>
 *   Функция name
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoPKCS7AlgorithmIdentifier* ECOCALLMETHOD CEcoPKCS7RecipientInfo_keyEncryptionAlgorithm(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_keyEncryptionAlgorithm;
}

/*
 *
 * <сводка>
 *   Функция dateOfBirth
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS7RecipientInfo_encryptedKey(/* in */ IEcoPKCS7RecipientInfoPtr_t me) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_encryptedKey;
}


/* Create Virtual Table IEcoPKCS7RecipientInfo */
IEcoPKCS7RecipientInfoVTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9 = {
    CEcoPKCS7RecipientInfo_QueryInterface,
    CEcoPKCS7RecipientInfo_AddRef,
    CEcoPKCS7RecipientInfo_Release,
    CEcoPKCS7RecipientInfo_get_Tag,
    CEcoPKCS7RecipientInfo_get_TaggetType,
    CEcoPKCS7RecipientInfo_get_Type,
    CEcoPKCS7RecipientInfo_Count,
    CEcoPKCS7RecipientInfo_Item,
    CEcoPKCS7RecipientInfo_Add,
    CEcoPKCS7RecipientInfo_encryptedKey,
    CEcoPKCS7RecipientInfo_keyEncryptionAlgorithm,
    CEcoPKCS7RecipientInfo_issuerAndSerialNumber,
    CEcoPKCS7RecipientInfo_version
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
int16_t ECOCALLMETHOD createCEcoPKCS7RecipientInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS7RecipientInfoPtr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS7RecipientInfo* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    IEcoASNOne1ValueSet* pIValueSet = 0;

    /* Проверка указателей */
    if (ppIChildInformation == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void**)&pISys);
    /* Проверка */
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    /* Проверка */
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoPKCS7RecipientInfo*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS7RecipientInfo));
    if (pCMe == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoASNOne1ChildInformation */
    pCMe->m_pVTblIEcoPKCS7RecipientInfo = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SET = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pCMe->m_SET);
    pCMe->m_version = 0;
    createCEcoPKCS7Version((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_version);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_version, 0);

    pCMe->m_issuerAndSerialNumber = 0;
    createCEcoPKCS7IssuerAndSerialNumber((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_issuerAndSerialNumber);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_issuerAndSerialNumber, 0);

    pCMe->m_keyEncryptionAlgorithm = 0;
    createCEcoPKCS7AlgorithmIdentifier((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_keyEncryptionAlgorithm);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_keyEncryptionAlgorithm, 0);

    pCMe->m_encryptedKey = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_encryptedKey);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_encryptedKey, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS7RecipientInfo*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
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
void ECOCALLMETHOD deleteCEcoPKCS7RecipientInfo(/* in */ IEcoPKCS7RecipientInfoPtr_t pIChildInformation) {
    CEcoPKCS7RecipientInfo* pCMe = (CEcoPKCS7RecipientInfo*)pIChildInformation;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIChildInformation != 0) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

