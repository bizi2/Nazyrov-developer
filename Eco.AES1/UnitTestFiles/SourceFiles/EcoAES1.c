/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov . All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoList1.h"
#include "IdEcoString1.h"
#include "IdEcoLog1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IEcoLog1ConsoleAffiliate.h"
#include "IEcoLog1SimpleLayout.h"
#include "IdEcoDateTime1.h"
#include "IdEcoAES1SW.h"
#include "IdEcoAES1HW.h"
#include "IEcoAES1Cipher.h"

#define AES128 1

#if defined(AES256) && (AES256 == 1)
    #define AES_KEYEXPSIZE 240
    #define AES_KEYSIZE 32
#elif defined(AES192) && (AES192 == 1)
    #define AES_KEYEXPSIZE 208
    #define AES_KEYSIZE 24
#else
    #define AES_KEYEXPSIZE 176      // Длина расширенного ключа.
    #define AES_KEYSIZE 16          // Длина ключа шифрования.
#endif

#define AES_BLOCKLEN 16             // Длина блока в байтах. AES использует блоки по 128 бит.

bool_t testCipher(IEcoLog1* pILog, IEcoAES1* pIAES);


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
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1* pILog = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    IEcoLog1ConsoleAffiliate* pIConsoleAffiliate = 0;
    IEcoLog1Layout* pILayout = 0;
    IEcoLog1SimpleLayout* pISimpleLayout = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoAES1* pIEcoAES1 = 0;
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
    /* Регистрация статического компонента для работы с алгоритмом шифрования AES программным способом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoAES1SW, (IEcoUnknown*)GetIEcoComponentFactoryPtr_7C6C9BBB77724C6C9117540BE0872BD7);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со строкой */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoList1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_53884AFC93C448ECAA929C8D3A562281);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с датой и вреенем */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoDateTime1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5B2BA17BEA704527BC708F88568FE115);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с журналом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLog1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_97322B6765B74342BBCE38798A0B40B5);
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

    /* Получение интерфейса работы с журналом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**)&pILog);
    if (result != 0 || pILog == 0) {
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**)&pIFileAffiliate);
    if (result != 0 || pIFileAffiliate == 0) {
        goto Release;
    }

    pILayout = pIFileAffiliate->pVTbl->get_Layout(pIFileAffiliate);
    pILayout->pVTbl->QueryInterface(pILayout, &IID_IEcoLog1SimpleLayout, (void**) &pISimpleLayout);
    pISimpleLayout->pVTbl->set_Pattern(pISimpleLayout, "%m");
    pISimpleLayout->pVTbl->Release(pISimpleLayout);
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1ConsoleAffiliate, (void**) &pIConsoleAffiliate);
    if (result != 0 || pIConsoleAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIConsoleAffiliate);
    pIConsoleAffiliate->pVTbl->Release(pIConsoleAffiliate);

    pILog->pVTbl->Info(pILog, "Start tests!!!\n");

    /* Получение интерфейса алгоритма шифрования AES аппаратным способом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoAES1HW, 0, &IID_IEcoAES1, (void**) &pIEcoAES1);
    if (result != 0 || pIEcoAES1 == 0) {
        /* Получение интерфейса алгоритма шифрования AES программным способом */
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoAES1SW, 0, &IID_IEcoAES1, (void**) &pIEcoAES1);
        if (result != 0 || pIEcoAES1 == 0) {
            /* Освобождение интерфейсов в случае ошибки */
            goto Release;
        }
    }

    pIEcoAES1->pVTbl->fnAESInitCtx(pIEcoAES1, keyExpanded, key);
    pIEcoAES1->pVTbl->fnAESEncrypt(pIEcoAES1, keyExpanded, cipherInput);
    pIEcoAES1->pVTbl->fnAESDecrypt(pIEcoAES1, keyExpanded, cipherInput);
    //fnKeyExpansion(ctx, key);
    //fnCipher((state_t*)cipherInput, ctx);
    //fnCipherInv((state_t*)cipherInput, ctx);

    /* Освлбождение блока памяти */
    //pIMem->pVTbl->Free(pIMem, name);

Release:

    /* Освобождение интерфейса для работы с журналированием данных */
    if (pILog != 0) {
        pILog->pVTbl->Release(pILog);
    }

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoAES1 != 0) {
        pIEcoAES1->pVTbl->Release(pIEcoAES1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

bool_t testCipher(IEcoLog1* pILog, IEcoAES1* pIAES) {
    int16_t result = -1;
    IEcoAES1Cipher* pICipher = 0;
    /* Длина расширенного ключа. */
    uint32_t iKeyExpSize = 176;
    /* Расширенный ключ. */
    uint8_t keyExpanded[AES_KEYEXPSIZE];
    /* Ключ шифрования */
    uint8_t key[AES_KEYSIZE] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
    /* Данные для шифрования */
    uint8_t cipherInput[AES_BLOCKLEN] = { 0x32, 0x43, 0xF6, 0xA8, 0x88, 0x5A, 0x30, 0x8D, 0x31, 0x31, 0x98, 0xA2, 0xE0, 0x37, 0x07, 0x34 };

    result = pIAES->pVTbl->QueryInterface(pIAES, &IID_IEcoAES1Cipher, (voidptr_t*)&pICipher);
    if (result != 0 || pICipher == 0) {
        /* Возврат в случае ошибки */
        return 0;
    }

    pIAES->pVTbl->KeyExpansion(pIAES, key, AES_KEYSIZE, (uint8_t**)&keyExpanded, &iKeyExpSize);

    pICipher->pVTbl->AddRoundKey(pICipher, l_round, _state, _roundKey);

    // Всего Nr раундов, первые Nr - 1 из них - одинаковые.
    for (l_round = 1; l_round < 10; ++l_round) {
        pICipher->pVTbl->SubBytes(pICipher, _state);
        pICipher->pVTbl->ShiftRows(pICipher, _state);
        pICipher->pVTbl->MixColumns(pICipher, _state);
        pICipher->pVTbl->AddRoundKey(pICipher, l_round, _state, _roundKey);
    }

    // Последний раунд. Здесь fnMixColumns не используется.
    pICipher->pVTbl->SubBytes(pICipher, _state);
    pICipher->pVTbl->ShiftRows(pICipher, _state);
    pICipher->pVTbl->AddRoundKey(pICipher, 10, _state, _roundKey);

    return 1;
}
