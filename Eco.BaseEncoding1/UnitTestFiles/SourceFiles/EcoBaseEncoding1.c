/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoBaseEncoding1
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
#include "IdEcoBaseEncoding1.h"
#include "BaseFunc.h"

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
    int8_t* input = "foobar";
    int8_t* input_64 = "Zm9vYmFy";
    int8_t* input_32 = "MZXW6YTBOI======";
    int8_t* input_16 = "666F6F626172";
    int8_t* output = NULL;
    int8_t inlen = 0, outlen = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoBaseEncoding1* pIEcoBaseEncoding1 = 0;

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
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoBaseEncoding1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_31BC4FAD67EF41DB95687999343447F8);
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
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoBaseEncoding1, 0, &IID_IEcoBaseEncoding1, (void**) &pIEcoBaseEncoding1);
    if (result != 0 || pIEcoBaseEncoding1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    
    //output = pIEcoBaseEncoding1->pVTbl->fnBase16EncMemAllocate(pIEcoBaseEncoding1, input, &inlen, &outlen);

    //pIEcoBaseEncoding1->pVTbl->fnBase16Enc(pIEcoBaseEncoding1, input, inlen, output, outlen);

    output = pIEcoBaseEncoding1->pVTbl->fnBase64EncSh(pIEcoBaseEncoding1, input);

    output = pIEcoBaseEncoding1->pVTbl->fnBase32EncSh(pIEcoBaseEncoding1, input);

    output = pIEcoBaseEncoding1->pVTbl->fnBase16EncSh(pIEcoBaseEncoding1, input);

    output = pIEcoBaseEncoding1->pVTbl->fnBase64DecSh(pIEcoBaseEncoding1, input_64);

    output = pIEcoBaseEncoding1->pVTbl->fnBase32DecSh(pIEcoBaseEncoding1, input_32);

    output = pIEcoBaseEncoding1->pVTbl->fnBase16DecSh(pIEcoBaseEncoding1, input_16);

    printf("%s", output);

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
    if (pIEcoBaseEncoding1 != 0) {
        pIEcoBaseEncoding1->pVTbl->Release(pIEcoBaseEncoding1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

