/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoBaseEncoding1_343447F8
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoBaseEncoding1_343447F8
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
#include "CEcoBaseEncoding1.h"
#include "BaseFunc.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoBaseEncoding1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoBaseEncoding1_343447F8_QueryInterface(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoBaseEncoding1) ) {
        *ppv = &pCMe->m_pVTblIEcoBaseEncoding1;
        pCMe->m_pVTblIEcoBaseEncoding1->AddRef((IEcoBaseEncoding1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoBaseEncoding1;
        pCMe->m_pVTblIEcoBaseEncoding1->AddRef((IEcoBaseEncoding1*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoBaseEncoding1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoBaseEncoding1_343447F8_AddRef(/* in */ IEcoBaseEncoding1Ptr_t me) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;

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
 *   Функция Release для интерфейса IEcoBaseEncoding1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoBaseEncoding1_343447F8_Release(/* in */ IEcoBaseEncoding1Ptr_t me) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoBaseEncoding1_343447F8((IEcoBaseEncoding1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/* Encode Memory Allocate */
void* ECOCALLMETHOD fnBase64EncMemAllocate(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* out */ size_t* inlen, /* out */ size_t* outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    return fnBase64EncodeAlloc(in, inlen, outlen);
}

void* ECOCALLMETHOD fnBase32EncMemAllocate(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* out */ size_t* inlen, /* out */ size_t* outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    return fnBase32EncodeAlloc(in, inlen, outlen);
}

void* ECOCALLMETHOD fnBase16EncMemAllocate(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* out */ size_t* inlen, /* out */ size_t* outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    return fnBase16EncodeAlloc(in, inlen, outlen);
}

/* Encode */
void ECOCALLMETHOD fnBase64Enc(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
    /* out */ const int8_t* out, /* in */ const size_t outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    fnBase64Encode(in, inlen, out, outlen);
}

void ECOCALLMETHOD fnBase32Enc(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
    /* out */ const int8_t* out, /* in */ const size_t outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    fnBase32Encode(in, inlen, out, outlen);
}

void ECOCALLMETHOD fnBase16Enc(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen, 
    /* out */ const int8_t* out, /* in */ const size_t outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    fnBase16Encode(in, inlen, out, outlen);
}

/* Decode Memory Allocate */
void* ECOCALLMETHOD fnBase64DecMemAllocate(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* out */ size_t* inlen, /* out */ size_t* outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    return fnBase64DecodeAlloc(in, inlen, outlen);
}

void* ECOCALLMETHOD fnBase32DecMemAllocate(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* out */ size_t* inlen, /* out */ size_t* outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    return fnBase32DecodeAlloc(in, inlen, outlen);
}

void* ECOCALLMETHOD fnBase16DecMemAllocate(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* out */ size_t* inlen, /* out */ size_t* outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    return fnBase16DecodeAlloc(in, inlen, outlen);
}

/* Decode  */
void ECOCALLMETHOD fnBase64Dec(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
    /* out */ const int8_t* out, /* in */ const size_t outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    fnBase64Decode(in, inlen, out, outlen);
}

void ECOCALLMETHOD fnBase32Dec(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
    /* out */ const int8_t* out, /* in */ const size_t outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    fnBase32Decode(in, inlen, out, outlen);
}

void ECOCALLMETHOD fnBase16Dec(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
    /* out */ const int8_t* out, /* in */ const size_t outlen) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    fnBase16Decode(in, inlen, out, outlen);
}

/* Encode Shell */
int8_t* ECOCALLMETHOD fnBase64EncSh(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    size_t inl = 0, outl = 0;
    int8_t* out = NULL;
    out = fnBase64EncodeAlloc(in, &inl, &outl);
    fnBase64Encode(in, inl, out, outl);

    return out;
}

int8_t* ECOCALLMETHOD fnBase32EncSh(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    size_t inl = 0, outl = 0;
    int8_t* out = NULL;
    out = fnBase32EncodeAlloc(in, &inl, &outl);
    fnBase32Encode(in, inl, out, outl);

    return out;
}

int8_t* ECOCALLMETHOD fnBase16EncSh(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    size_t inl = 0, outl = 0;
    int8_t* out = NULL;
    out = fnBase16EncodeAlloc(in, &inl, &outl);
    fnBase16Encode(in, inl, out, outl);

    return out;
}

/* Decode Shell */
int8_t* ECOCALLMETHOD fnBase64DecSh(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    size_t inl = 0, outl = 0;
    int8_t* out = NULL;
    out = fnBase64DecodeAlloc(in, &inl, &outl);
    fnBase64Decode(in, inl, out, outl);

    return out;
}

int8_t* ECOCALLMETHOD fnBase32DecSh(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    size_t inl = 0, outl = 0;
    int8_t* out = NULL;
    out = fnBase32DecodeAlloc(in, &inl, &outl);
    fnBase32Decode(in, inl, out, outl);

    return out;
}

int8_t* ECOCALLMETHOD fnBase16DecSh(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
    size_t inl = 0, outl = 0;
    int8_t* out = NULL;
    out = fnBase16DecodeAlloc(in, &inl, &outl);
    fnBase16Decode(in, inl, out, outl);

    return out;
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
int16_t ECOCALLMETHOD initCEcoBaseEncoding1_343447F8(/*in*/ IEcoBaseEncoding1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)me;
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

/* Create Virtual Table IEcoBaseEncoding1 */
IEcoBaseEncoding1VTbl g_xA61019F6E1D24B12AD7316D88BBFE375VTbl_343447F8 = {
    CEcoBaseEncoding1_343447F8_QueryInterface,
    CEcoBaseEncoding1_343447F8_AddRef,
    CEcoBaseEncoding1_343447F8_Release,
    fnBase64EncMemAllocate,
    fnBase32EncMemAllocate,
    fnBase16EncMemAllocate,
    fnBase64DecMemAllocate,
    fnBase32DecMemAllocate,
    fnBase16DecMemAllocate,
    fnBase64Enc,
    fnBase32Enc,
    fnBase16Enc,
    fnBase64Dec,
    fnBase32Dec,
    fnBase16Dec,
    fnBase64EncSh,
    fnBase32EncSh,
    fnBase16EncSh,
    fnBase64DecSh,
    fnBase32DecSh,
    fnBase16DecSh
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
int16_t ECOCALLMETHOD createCEcoBaseEncoding1_343447F8(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoBaseEncoding1Ptr_t* ppIEcoBaseEncoding1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoBaseEncoding1_343447F8* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoBaseEncoding1 == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoBaseEncoding1_343447F8*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoBaseEncoding1_343447F8));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoBaseEncoding1 */
    pCMe->m_pVTblIEcoBaseEncoding1 = &g_xA61019F6E1D24B12AD7316D88BBFE375VTbl_343447F8;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoBaseEncoding1 = (IEcoBaseEncoding1*)pCMe;

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
void ECOCALLMETHOD deleteCEcoBaseEncoding1_343447F8(/* in */ IEcoBaseEncoding1Ptr_t pIEcoBaseEncoding1) {
    CEcoBaseEncoding1_343447F8* pCMe = (CEcoBaseEncoding1_343447F8*)pIEcoBaseEncoding1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoBaseEncoding1 != 0 ) {
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
