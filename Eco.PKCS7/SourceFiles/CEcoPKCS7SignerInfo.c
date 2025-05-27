/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS7SignerInfo
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS7SignerInfo
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
#include "CEcoPKCS7SignerInfo.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS7SignerInfo
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfo_QueryInterface(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS7SignerInfo)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfo;
        pCMe->m_pVTblIEcoPKCS7SignerInfo->AddRef((IEcoPKCS7SignerInfo*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfo;
        pCMe->m_pVTblIEcoPKCS7SignerInfo->AddRef((IEcoPKCS7SignerInfo*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfo;
        pCMe->m_pVTblIEcoPKCS7SignerInfo->AddRef((IEcoPKCS7SignerInfo*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfo;
        pCMe->m_pVTblIEcoPKCS7SignerInfo->AddRef((IEcoPKCS7SignerInfo*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS7SignerInfo
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7SignerInfo_AddRef(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

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
 *   Функция Release для интерфейса IEcoPKCS7SignerInfo
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7SignerInfo_Release(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS7SignerInfo((IEcoPKCS7SignerInfo*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignerInfo_get_Tag(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignerInfo_get_TaggetType(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignerInfo_get_Type(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

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
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfo_Count(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ int32_t* Count) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfo_Item(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfo_Add(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;
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
 *   Функция dateOfBirth
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1ValueSet* ECOCALLMETHOD CEcoPKCS7SignerInfo_authenticatedAttributes(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_authenticatedAttributes;
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
static IEcoPKCS7IssuerAndSerialNumber* ECOCALLMETHOD CEcoPKCS7SignerInfo_issuerAndSerialNumber(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_issuerAndSerialNumber;
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
static IEcoPKCS7AlgorithmIdentifier* ECOCALLMETHOD CEcoPKCS7SignerInfo_digestAlgorithm(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_digestAlgorithm;
}

static IEcoPKCS7Version* ECOCALLMETHOD CEcoPKCS7SignerInfo_version(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

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
static IEcoPKCS7AlgorithmIdentifier* ECOCALLMETHOD CEcoPKCS7SignerInfo_digestEncryptionAlgorithm(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_digestEncryptionAlgorithm;
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
static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS7SignerInfo_encryptedDigest(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_encryptedDigest;
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
static IEcoASNOne1ValueSet* ECOCALLMETHOD CEcoPKCS7SignerInfo_unauthenticatedAttributes(/* in */ IEcoPKCS7SignerInfoPtr_t me) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_unauthenticatedAttributes;
}

/* Create Virtual Table IEcoPKCS7SignerInfo */
IEcoPKCS7SignerInfoVTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9 = {
    CEcoPKCS7SignerInfo_QueryInterface,
    CEcoPKCS7SignerInfo_AddRef,
    CEcoPKCS7SignerInfo_Release,
    CEcoPKCS7SignerInfo_get_Tag,
    CEcoPKCS7SignerInfo_get_TaggetType,
    CEcoPKCS7SignerInfo_get_Type,
    CEcoPKCS7SignerInfo_Count,
    CEcoPKCS7SignerInfo_Item,
    CEcoPKCS7SignerInfo_Add,
    CEcoPKCS7SignerInfo_version,
    CEcoPKCS7SignerInfo_digestAlgorithm,
    CEcoPKCS7SignerInfo_issuerAndSerialNumber,
    CEcoPKCS7SignerInfo_authenticatedAttributes,
    CEcoPKCS7SignerInfo_digestEncryptionAlgorithm,
    CEcoPKCS7SignerInfo_encryptedDigest,
    CEcoPKCS7SignerInfo_unauthenticatedAttributes,
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
int16_t ECOCALLMETHOD createCEcoPKCS7SignerInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS7SignerInfoPtr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS7SignerInfo* pCMe = 0;
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
    pCMe = (CEcoPKCS7SignerInfo*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS7SignerInfo));
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
    pCMe->m_pVTblIEcoPKCS7SignerInfo = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SET = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pCMe->m_SET);
    pCMe->m_version = 0;
    createCEcoPKCS7encryptedContentInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_version);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_version, 0);

    pCMe->m_digestAlgorithm = 0;
    createCEcoPKCS7DigestAlgorithmIdentifier((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_digestAlgorithm);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_digestAlgorithm, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_digestEncryptionAlgorithm = 0;
    createCEcoASNOne1ValueSet((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_digestEncryptionAlgorithm);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_digestEncryptionAlgorithm, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_encryptedDigest = 0;
    createCEcoASNOne1ValueSet((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_encryptedDigest);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_encryptedDigest, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_unauthenticatedAttributes = 0;
    createCEcoPKCS7unauthenticatedAttributes((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_unauthenticatedAttributes);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_unauthenticatedAttributes, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_issuerAndSerialNumber = 0;
    createCEcoASNOne1ValueSet((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_issuerAndSerialNumber);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_issuerAndSerialNumber, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_authenticatedAttributes = 0;
    createCEcoPKCS7authenticatedAttributes((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_authenticatedAttributes);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_authenticatedAttributes, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS7SignerInfo*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS7SignerInfo(/* in */ IEcoPKCS7SignerInfoPtr_t pIChildInformation) {
    CEcoPKCS7SignerInfo* pCMe = (CEcoPKCS7SignerInfo*)pIChildInformation;
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

