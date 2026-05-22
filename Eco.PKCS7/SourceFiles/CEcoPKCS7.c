/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS7_6EA80DA5
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS7_6EA80DA5
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
#include "CEcoPKCS7.h"
#include "CEcoPKCS7ContentInfo.h"
#include "CEcoPKCS7DigestInfo.h"
#include "CEcoPKCS7EncryptedContentInfo.h"
#include "CEcoPKCS7EncryptedData.h"
#include "CEcoPKCS7EnvelopedData.h"
#include "CEcoPKCS7SignedAndEnvelopedData.h"
#include "CEcoPKCS7SignedData.h"
#include "CEcoPKCS7SignerInfo.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoPKCS7
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_QueryInterface(/* in */ IEcoPKCS7Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoPKCS7) ) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7;
        pCMe->m_pVTblIEcoPKCS7->AddRef((IEcoPKCS7*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7;
        pCMe->m_pVTblIEcoPKCS7->AddRef((IEcoPKCS7*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS7
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_AddRef(/* in */ IEcoPKCS7Ptr_t me) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;

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
 *   Функция Release для интерфейса IEcoPKCS7
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_Release(/* in */ IEcoPKCS7Ptr_t me) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoPKCS7_6EA80DA5((IEcoPKCS7*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
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
int16_t ECOCALLMETHOD initCEcoPKCS7_6EA80DA5(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_ContentInfo
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_ContentInfo(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7ContentInfo* ppIPKCS7ContentInfo) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7ContentInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7ContentInfo);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_DigestInfo
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_DigestInfo(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7DigestInfo* ppIPKCS7DigestInfo) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7DigestInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7DigestInfo);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_EncryptedContentInfo(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7EncryptedContentInfo* ppIPKCS7EncryptedContentInfo) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7EncryptedContentInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7EncryptedContentInfo);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_EncryptedData(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7EncryptedData* ppIPKCS7EncryptedData) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7EncryptedData((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7EncryptedData);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_PBEParameter
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_EnvelopedData(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7EnvelopedData* ppIPKCS7EnvelopedData) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7EnvelopedData((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7EnvelopedData);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_SignedAndEnvelopedData(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignedAndEnvelopedData* ppIPKCS7SignedAndEnvelopedData) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7SignedAndEnvelopedData((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7SignedAndEnvelopedData);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_SignedData(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignedData* ppIPKCS7SignedData) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7SignedData((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7SignedData);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_SignerInfo(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignerInfo* ppIPKCS7SignerInfo) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7SignerInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7SignerInfo);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_SignerInfos(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignerInfos* ppIPKCS7SignerInfos) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7SignerInfos((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7SignerInfos);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_RecipientInfo(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7RecipientInfo* ppIPKCS7RecipientInfo) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7RecipientInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7RecipientInfo);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS7_6EA80DA5_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS7_6EA80DA5_new_RecipientInfos(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7RecipientInfos* ppIPKCS7RecipientInfos) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS7RecipientInfos((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS7RecipientInfos);


    return result;
}

/* Create Virtual Table IEcoPKCS7 */
IEcoPKCS7VTbl g_x9748EA58DD7541E5B0A203702BD96EF6VTbl_6EA80DA5 = {
    CEcoPKCS7_6EA80DA5_QueryInterface,
    CEcoPKCS7_6EA80DA5_AddRef,
    CEcoPKCS7_6EA80DA5_Release,
    CEcoPKCS7_6EA80DA5_new_SignerInfo,
    CEcoPKCS7_6EA80DA5_new_SignedData,
    CEcoPKCS7_6EA80DA5_new_SignedAndEnvelopedData,
    CEcoPKCS7_6EA80DA5_new_EnvelopedData,
    CEcoPKCS7_6EA80DA5_new_EncryptedData,
    CEcoPKCS7_6EA80DA5_new_EncryptedContentInfo,
    CEcoPKCS7_6EA80DA5_new_DigestInfo,
    CEcoPKCS7_6EA80DA5_new_ContentInfo,
    CEcoPKCS7_6EA80DA5_new_SignerInfos,
    CEcoPKCS7_6EA80DA5_new_RecipientInfo,
    CEcoPKCS7_6EA80DA5_new_RecipientInfos
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
int16_t ECOCALLMETHOD createCEcoPKCS7_6EA80DA5(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS7_6EA80DA5* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoPKCS7 == 0 || pIUnkSystem == 0) {
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

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoPKCS7_6EA80DA5*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS7_6EA80DA5));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoPKCS7 */
    pCMe->m_pVTblIEcoPKCS7 = &g_x9748EA58DD7541E5B0A203702BD96EF6VTbl_6EA80DA5;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoPKCS7 = (IEcoPKCS7*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS7_6EA80DA5(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7) {
    CEcoPKCS7_6EA80DA5* pCMe = (CEcoPKCS7_6EA80DA5*)pIEcoPKCS7;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoPKCS7 != 0 ) {
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
