/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoEventPoll1
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
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IdEcoDateTime1.h"
#include "IdEcoLog1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoEventPoll1.h"
#include "IdEcoThreadManager1.h"

/* Глобальный указатель на интерфейс работы с журналом */
IEcoLog1* g_pILog = 0;
/* Глобальный указатель на интерфейс работы с файлом */
IEcoFile1* g_pIFile = 0;

/*
 *
 * <сводка>
 *   Функция SimpleThread
 * </сводка>
 *
 * <описание>
 *   Функция SimpleThread - поток
 * </описание>
 *
 */
uint32_t SimpleThread(/* in */ IEcoUnknown* pIUnk, /* in */ void* param) {
    IEcoThread1* pIThread = (IEcoThread1*)pIUnk;
    char_t buffer[] = "Hello Event Poll\n";
    uint32_t size = sizeof(buffer) - 1;
    int16_t index = 0;
    g_pILog->pVTbl->InfoFormat(g_pILog, "Simple Thread Id = %x - Start write to file fd = %X", pIThread->pVTbl->get_Id(pIThread), g_pIFile->pVTbl->get_Descriptor(g_pIFile));

    while (index < 1000) {
        size = sizeof(buffer) - 1;
        g_pIFile->pVTbl->Write(g_pIFile, buffer, &size);
        index++;
    }
    g_pILog->pVTbl->InfoFormat(g_pILog, "Simple Thread Id = %x - Completed", pIThread->pVTbl->get_Id(pIThread));
    return 0;
}

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
    IEcoEventPoll1* pIEventPoll = 0;
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    /* Указатели на интерфейсы для работы с потоками */
    IEcoThreadManager1* pIThreadMgr = 0;
    IEcoThread1* pICurrentThread = 0;
    IEcoThread1* pISimpleThread = 0;
    /* Указатели на интерфейсы для работы с файлами */
    IEcoFileManager1* pIFileMgr = 0;

    int32_t countReady = 0;
    int32_t indexReady = 0;
    descriptor_t fd = 0;


    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
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
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoEventPoll1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_777B4B258FDC44C9A54F78A98339851F);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с менеджером потоков */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoThreadManager1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_B7D8E10E1D3540CCB1CA96F766AF1936);
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
    /* Регистрация статического компонента для работы со строкой */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0 ) {
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
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса  для работы с журналом */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &g_pILog);
    if (result != 0 || g_pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0 || pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    g_pILog->pVTbl->AddAffiliate(g_pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    g_pILog->pVTbl->Info(g_pILog, "Start tests!!!");

    /* Получение тестируемого интерфейса */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoEventPoll1, 0, &IID_IEcoEventPoll1, (void**) &pIEventPoll);
    if (result != 0 && pIEventPoll == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса управление файлами */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFileSystemManagement1, 0, &IID_IEcoFileManager1, (void**) &pIFileMgr);
    if (result != 0 || pIFileMgr == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Создание нового файла */
    g_pIFile = pIFileMgr->pVTbl->Create(pIFileMgr, "Simple.txt");

    /* Добавление в пул событий файловый дескриптор для отслеживания */
    pIEventPoll->pVTbl->Add(pIEventPoll, g_pIFile->pVTbl->get_Descriptor(g_pIFile));

    /* Получение интерфейса для работы с потоками */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoThreadManager1, 0, &IID_IEcoThreadManager1, (void**) &pIThreadMgr);
    if (result != 0 || pIThreadMgr == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Создание нового потока */
    pISimpleThread = pIThreadMgr->pVTbl->CreateThread(pIThreadMgr, SimpleThread, 0, 0, 0);
    /* Вывод информации о потоке*/
    if (pISimpleThread != 0) {
        g_pILog->pVTbl->InfoFormat(g_pILog, "Create Simple Thread Id : %X", pISimpleThread->pVTbl->get_Id(pISimpleThread));
    }
    else {
        g_pILog->pVTbl->Error(g_pILog, "Error create Simple Thread ");
    }

    /* Ожидание завершения записи на 10 секунд */
    countReady = pIEventPoll->pVTbl->Wait(pIEventPoll, 10, 10000);
    if (countReady != -1) {
        /* Просмотр списка готовых дескрипторов */
        while (indexReady < countReady && countReady != -1) {
            pIEventPoll->pVTbl->Enum(pIEventPoll, indexReady, &fd);
            g_pILog->pVTbl->InfoFormat(g_pILog, "Write completed for descriptor : %X", fd);
            indexReady++;
        }
    }
    else {
        g_pILog->pVTbl->ErrorFormat(g_pILog, "Error : timeout...");
    }


    /* Освлбождение блока памяти */
   // pIMem->pVTbl->Free(pIMem, name);

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
    if (pIEventPoll != 0) {
        pIEventPoll->pVTbl->Release(pIEventPoll);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

