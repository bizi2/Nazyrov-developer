/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS7SignedAndEnvelopedData
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS7SignedAndEnvelopedData
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
#include "IEcoASNOne1.h"
#include "CEcoPKCS7SignedAndEnvelopedData.h"
#include "CEcoPKCS7Version.h"
#include "CEcoPKCS7DigestAlgorithmIdentifiers.h"
#include "CEcoPKCS7RecipientInfos.h"
#include "CEcoPKCS7EncryptedContentInfo.h"
#include "CEcoPKCS7SignerInfos.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS7SignedAndEnvelopedData
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_QueryInterface(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS7SignedAndEnvelopedData)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData;
        pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData->AddRef((IEcoPKCS7SignedAndEnvelopedData*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData;
        pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData->AddRef((IEcoPKCS7SignedAndEnvelopedData*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData;
        pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData->AddRef((IEcoPKCS7SignedAndEnvelopedData*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData;
        pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData->AddRef((IEcoPKCS7SignedAndEnvelopedData*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS7SignedAndEnvelopedData
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_AddRef(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

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
 *   Функция Release для интерфейса IEcoPKCS7SignedAndEnvelopedData
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_Release(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS7SignedAndEnvelopedData((IEcoPKCS7SignedAndEnvelopedData*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_get_Tag(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_get_TaggetType(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_get_Type(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

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
static int16_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_Count(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ int32_t* Count) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_Item(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_Add(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;
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
static IEcoPKCS7EncryptedContentInfo* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_encryptedContentInfo(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_encryptedContentInfo;
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
static IEcoPKCS7RecipientInfos* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_recipientInfos(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_recipientInfos;
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
static IEcoPKCS7AlgorithmIdentifier* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_digestAlgorithms(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_digestAlgorithms;
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
static IEcoASNOne1ValueSet* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_certificates(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_certificates;
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
static IEcoASNOne1ValueSet* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_crls(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_crls;
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
static IEcoPKCS7SignerInfos* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_signerInfos(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_signerInfos;
}

static IEcoPKCS7Version* ECOCALLMETHOD CEcoPKCS7SignedAndEnvelopedData_version(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_version;
}

/* Create Virtual Table IEcoPKCS7SignedAndEnvelopedData */
IEcoPKCS7SignedAndEnvelopedDataVTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9 = {
    CEcoPKCS7SignedAndEnvelopedData_QueryInterface,
    CEcoPKCS7SignedAndEnvelopedData_AddRef,
    CEcoPKCS7SignedAndEnvelopedData_Release,
    CEcoPKCS7SignedAndEnvelopedData_get_Tag,
    CEcoPKCS7SignedAndEnvelopedData_get_TaggetType,
    CEcoPKCS7SignedAndEnvelopedData_get_Type,
    CEcoPKCS7SignedAndEnvelopedData_Count,
    CEcoPKCS7SignedAndEnvelopedData_Item,
    CEcoPKCS7SignedAndEnvelopedData_Add,
    CEcoPKCS7SignedAndEnvelopedData_version,
    CEcoPKCS7SignedAndEnvelopedData_recipientInfos,
    CEcoPKCS7SignedAndEnvelopedData_digestAlgorithms,
    CEcoPKCS7SignedAndEnvelopedData_encryptedContentInfo,
    CEcoPKCS7SignedAndEnvelopedData_certificates,
    CEcoPKCS7SignedAndEnvelopedData_crls,
    CEcoPKCS7SignedAndEnvelopedData_signerInfos,
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
int16_t ECOCALLMETHOD createCEcoPKCS7SignedAndEnvelopedData(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS7SignedAndEnvelopedDataPtr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS7SignedAndEnvelopedData* pCMe = 0;
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
    pCMe = (CEcoPKCS7SignedAndEnvelopedData*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS7SignedAndEnvelopedData));
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
    pCMe->m_pVTblIEcoPKCS7SignedAndEnvelopedData = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SET = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pCMe->m_SET);
    pCMe->m_encryptedContentInfo = 0;
    createCEcoPKCS7EncryptedContentInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_encryptedContentInfo);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_encryptedContentInfo, 0);

    pCMe->m_version = 0;
    createCEcoPKCS7Version((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_version);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_version, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_recipientInfos = 0;
    createCEcoPKCS7RecipientInfos((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_recipientInfos);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_recipientInfos, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_digestAlgorithms = 0;
    createCEcoPKCS7DigestAlgorithmIdentifiers((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_digestAlgorithms);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_digestAlgorithms, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_encryptedContentInfo = 0;
    createCEcoPKCS7EncryptedContentInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_encryptedContentInfo);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_encryptedContentInfo, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_certificates = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_certificates, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_crls = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_crls, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    pCMe->m_signerInfos = 0;
    createCEcoPKCS7SignerInfos((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_signerInfos);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_signerInfos, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS7SignedAndEnvelopedData*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS7SignedAndEnvelopedData(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t pIChildInformation) {
    CEcoPKCS7SignedAndEnvelopedData* pCMe = (CEcoPKCS7SignedAndEnvelopedData*)pIChildInformation;
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

