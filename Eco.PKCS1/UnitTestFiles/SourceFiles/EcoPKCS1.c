/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoPKCS1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoPKCS1.h"

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoPKCS1* pIEcoPKCS1 = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoPKCS1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_F48EB9164869423796702F3AA50FB39D);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Выделение блока памяти */
    name = (char_t *)pIMem->pVTbl->Alloc(pIMem, 10);

    /* Заполнение блока памяти */
    pIMem->pVTbl->Fill(pIMem, name, 'a', 9);


    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoPKCS1, 0, &IID_IEcoPKCS1, (void**) &pIEcoPKCS1);
    if (result != 0 || pIEcoPKCS1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }


    result = pIEcoPKCS1->pVTbl->MyFunction(pIEcoPKCS1, name, &copyName);

    IEcoASNOneINTEGER* pointerInteger = NULL;


    IEcoPKCS1RSAPublicKey* pointerPublicKey;
    pointerInteger = pointerPublicKey->pVTbl->modulus;
    pointerInteger->set(10);

    pointerInteger = pointerPublicKey->pVTbl->publicExponent;
    pointerInteger->set(30);

    IEcoPKCS1* pointerPKCS1;
    IEcoASNOneEncoder* pointerEncoder;
    pointerPKCS1->pVTbl->QueryInterface(pointerPKCS1, IIDAsnOneEncoder, &pointerEncoder);
    pointerEncoder->Encode(&buffer, len);
    printf(hexdump, buffer);

    IEcoPKCS1* pointer2PKCS1;
    pointer2PKCS1 = pointerEncoder->Decode(buffer, len);
    pointerInteger = pointerPublicKey->pVTbl->modulus;
    int value = pointerInteger->get;
    pointerInteger = pointerPublicKey->pVTbl->publicExponent;
    int value2 = pointerInteger->get;

    IEcoPKCS7* pointerPKCS7;
    pointerPKCS7->QueryInterface(pointerPKCS7, IIDEcoPKCS1, &pointerPKCS1)

    /* Освлбождение блока памяти */
    pIMem->pVTbl->Free(pIMem, name);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoPKCS1 != 0) {
        pIEcoPKCS1->pVTbl->Release(pIEcoPKCS1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

