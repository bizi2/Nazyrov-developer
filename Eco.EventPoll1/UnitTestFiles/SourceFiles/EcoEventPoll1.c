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
#include "IdEcoSocketP02.h"

/* Указатель на интерфейс работы с системной интерфейсной шиной */
IEcoInterfaceBus1* g_pIBus = 0;
/* Указатель на интерфейс работы с памятью */
IEcoMemoryAllocator1* g_pIMem = 0;
/* Глобальный указатель на интерфейс работы с журналом */
IEcoLog1* g_pILog = 0;
/* Глобальный указатель на интерфейс работы с файлом */
IEcoFile1* g_pIFile = 0;

/*
 *
 * <сводка>
 *   Функция ServerThread
 * </сводка>
 *
 * <описание>
 *   Функция сервера принимает клиентские подключения и обрабатывает события чтения через IEcoEventPoll1
 * </описание>
 *
 * <параметры>
 *   pIUnk - указатель на интерфейс текущего потока
 *   param - указатель на количество ожидаемых клиентских подключений
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */


uint32_t ServerThread(/* in */ IEcoUnknown* pIUnk, /* in */ void* param) {
    IEcoThread1*    pIThread = (IEcoThread1*)pIUnk;
    IEcoSocketP02*  pIServerSocket  = 0;
    IEcoINetP02*    pIINet          = 0;
    IEcoEventPoll1* pIEventPoll     = 0;
    int16_t         result          = -1;

    /* данные о сокете */
    int saccepted   = -1;
    int sserver     = -1;
    struct sockaddr_in serv_addr;

    /* вспомогательные переменные */
    char_t* buf = 0;
	int i = 0;
    int count_ready = 0;
    int processed_connections_count = 0;
    int wait_attempt = 0;
    int expected_connections_count = *(int*)param;

    /* Получение интерфейса сокетов*/
    result = g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoSocketP02, 0, &IID_IEcoSocketP02, (void**) &pIServerSocket);
    if (result != 0 || pIServerSocket == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        return -1;
    }

    /*получения интерфейса для работы с сетевыми адресами*/
    result = pIServerSocket->pVTbl->QueryInterface(pIServerSocket, &IID_IEcoINetP02, (void**) &pIINet);
    if (result != 0 || pIINet == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        return -1;
    }

    sserver = pIServerSocket->pVTbl->socket(pIServerSocket, AF_INET, SOCK_STREAM , 0);

    g_pIMem->pVTbl->Fill(g_pIMem, &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = pIINet->pVTbl->inet_addr(pIINet, "127.0.0.1");
    serv_addr.sin_port = pIINet->pVTbl->htons(pIINet, 9001); 

    /* Пнивязка адреса к сокету */
    pIServerSocket->pVTbl->bind(pIServerSocket, sserver, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    /* Установка максимального числа подключений к сокету */
    pIServerSocket->pVTbl->listen(pIServerSocket, sserver, 10);

    /* Получение тестируемого интерфейса (epoll) */
    g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoEventPoll1, 0, &IID_IEcoEventPoll1, (void**) &pIEventPoll);
    if (result != 0 && pIEventPoll == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        return -1;
    }

    /* подключение всех сокетов клиентов*/
    for(i = 0; i < expected_connections_count; i++) {
        saccepted = pIServerSocket->pVTbl->accept(pIServerSocket, sserver, (struct sockaddr*)NULL, NULL);
	    g_pILog->pVTbl->InfoFormat(g_pILog, "Simple Thread Id -> socket accepted [%X]", saccepted);

        /* дбавление сокета подключение в Epoll*/
        result = pIEventPoll->pVTbl->Add(pIEventPoll, (descriptor_t)&saccepted);
        if(result != 0) {
            g_pILog->pVTbl->InfoFormat(g_pILog, "Can't add socket fd to EPOLL = %X", saccepted);
            /* Освобождение интерфейсов в случае ошибки */
           return -1;
        }
    }

    buf = (char_t*)g_pIMem->pVTbl->Alloc(g_pIMem, 256);
    if (buf == 0) {
        return -1;
    }

    /* Ожидание завершения записи до обработки всех клиентов */
    while (processed_connections_count < expected_connections_count && wait_attempt < (expected_connections_count * 4)) {
        count_ready = pIEventPoll->pVTbl->Wait(pIEventPoll, expected_connections_count, 20000);
        if (count_ready < 0) {
            g_pILog->pVTbl->Error(g_pILog, "Error : wait failure");
            break;
        }

        if (count_ready == 0) {
            g_pILog->pVTbl->Info(g_pILog, "Wait returned no ready descriptors, continue polling");
            wait_attempt++;
            continue;
        }

        g_pILog->pVTbl->InfoFormat(g_pILog, "Waited fds %d", count_ready);
        i = 0;
        while (i < count_ready && processed_connections_count < expected_connections_count) {
            pIEventPoll->pVTbl->Enum(pIEventPoll, i, &saccepted);
            g_pILog->pVTbl->InfoFormat(g_pILog, "Write completed for descriptor : %X", saccepted);

            g_pIMem->pVTbl->Fill(g_pIMem, buf, 0, 256);
            pIServerSocket->pVTbl->recv(pIServerSocket, saccepted, buf, 256, 0);
            g_pILog->pVTbl->InfoFormat(g_pILog, "ThreadID = %X -> Receive message : %s\n", pIThread->pVTbl->get_Id(pIThread), buf);
            pIEventPoll->pVTbl->Del(pIEventPoll, (descriptor_t)&saccepted);

            processed_connections_count++;
            i++;
        }

        wait_attempt++;
    }

    if (processed_connections_count != expected_connections_count) {
        g_pILog->pVTbl->Error(g_pILog, "Processed connections count is less than expected");
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция ClientThread
 * </сводка>
 *
 * <описание>
 *   Функция клиента создает сокет, подключается к серверу и отправляет тестовое сообщение
 * </описание>
 *
 * <параметры>
 *   pIUnk - указатель на интерфейс текущего потока
 *   param - пользовательский параметр потока
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
uint32_t ClientThread(/* in */ IEcoUnknown* pIUnk, /* in */ void* param) {
    IEcoThread1*    pIThread = (IEcoThread1*)pIUnk;
    IEcoSocketP02*  pIClientSocket  = 0;
    IEcoINetP02*    pIINet          = 0;
    int16_t         result          = -1;

    /* данные о сокете */
    int sclient = -1;
    struct sockaddr_in serv_addr;
    int status = -1;
	char_t* mes = "Hello";

	pIThread->pVTbl->Sleep(pIThread, 1000);

    /* Получение тестируемого интерфейса */
    result = g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoSocketP02, 0, &IID_IEcoSocketP02, (void**) & pIClientSocket);
    if (result != 0 || pIClientSocket == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        return -1;
    }

    result = pIClientSocket->pVTbl->QueryInterface(pIClientSocket, &IID_IEcoINetP02, (void**) &pIINet);
    if (result != 0 || pIINet == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        return -1;
    }

    g_pILog->pVTbl->InfoFormat(g_pILog, "ThreadID = %X -> Create ClientSocket interface", pIThread->pVTbl->get_Id(pIThread));

    /* Создаем сокет для клиента */
    sclient = pIClientSocket->pVTbl->socket(pIClientSocket, AF_INET, SOCK_STREAM , 0);

    g_pIMem->pVTbl->Fill(g_pIMem, &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = pIINet->pVTbl->inet_addr(pIINet, "127.0.0.1");
    serv_addr.sin_port = pIINet->pVTbl->htons(pIINet, 9001); 

    /* Подключение к серверу */
	do {
		status = pIClientSocket->pVTbl->connect(pIClientSocket, sclient, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	} while(status < 0);

    if (status < 0) {
        g_pILog->pVTbl->InfoFormat(g_pILog, "ThreadID = %X -> Connection Failed", pIThread->pVTbl->get_Id(pIThread));
        return -1;
    }
    else {
        g_pILog->pVTbl->InfoFormat(g_pILog, "ThreadID = %X -> Connection success", pIThread->pVTbl->get_Id(pIThread));
        pIThread->pVTbl->Sleep(pIThread, 3000);
		pIClientSocket->pVTbl->send(pIClientSocket, sclient, mes, 5, 0);
		//pIThread->pVTbl->Sleep(pIThread, 5000);
		pIClientSocket->pVTbl->shutdown(pIClientSocket, sclient, 0);
    }

	return 0;
}

/*
 *
 * <сводка>
 *   Функция InitClientThreads
 * </сводка>
 *
 * <описание>
 *   Функция создает указанное количество клиентских потоков
 * </описание>
 *
 * <параметры>
 *   pIThreadMgr - указатель на интерфейс менеджера потоков
 *   pICurrentThread - указатель на текущий поток
 *   connections - количество клиентских потоков для создания
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t InitClientThreads(/* in */ IEcoThreadManager1* pIThreadMgr, 
                          /* in */ IEcoThread1* pICurrentThread, 
                          /* in */ int connections) {
    int i = 0;
    IEcoThread1* pISimpleThread = 0;
    
    g_pILog->pVTbl->Info(g_pILog, "init client threads!!!");
    for(i = 0; i < connections; i++) {
        pISimpleThread = pIThreadMgr->pVTbl->CreateThread(pIThreadMgr, ClientThread, 0, 0, 0);
        /* Вывод информации о потоке*/
        if (pISimpleThread != 0) {
            g_pILog->pVTbl->InfoFormat(g_pILog, "Create Client Thread Id : %X", pISimpleThread->pVTbl->get_Id(pISimpleThread));
        }
        else {
            g_pILog->pVTbl->Error(g_pILog, "Error create Simple Thread ");
            return -1;
        }
        pICurrentThread->pVTbl->Sleep(pICurrentThread, 3000);
    }
    
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
 * <параметры>
 *   pIUnk - указатель на системный интерфейс приложения
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    //IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    //IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoEventPoll1* pIEventPoll = 0;
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    /* Указатели на интерфейсы для работы с потоками */
    IEcoThreadManager1* pIThreadMgr = 0;
    IEcoThread1* pICurrentThread = 0;
    IEcoThread1* pIServerSThread = 0;
    IEcoThread1* pISimpleThread = 0;
    /* Указатели на интерфейсы для работы с файлами */
    IEcoFileManager1* pIFileMgr = 0;

    int i = 0;
    int connections = 2;
    int32_t countReady = 0;
    int32_t indexReady = 0;
    descriptor_t send_fd = 0;
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
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&g_pIBus);
    if (result != 0 || g_pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы с epoll */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoEventPoll1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_777B4B258FDC44C9A54F78A98339851F);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с сокетами */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoSocketP02, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1CE95396008F46EAB4374010C8B58383);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с менеджером потоков */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoThreadManager1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_B7D8E10E1D3540CCB1CA96F766AF1936);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с журналом */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoLog1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_97322B6765B74342BBCE38798A0B40B5);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со строкой */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со списком */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoList1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_53884AFC93C448ECAA929C8D3A562281);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с датой и вреенем */
    result = g_pIBus->pVTbl->RegisterComponent(g_pIBus, &CID_EcoDateTime1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5B2BA17BEA704527BC708F88568FE115);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &g_pIMem);

    /* Проверка */
    if (result != 0 && g_pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса  для работы с журналом */
    g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &g_pILog);
    if (result != 0 || g_pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0 || pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    g_pILog->pVTbl->AddAffiliate(g_pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    g_pILog->pVTbl->Info(g_pILog, "Start tests!!!");

    /* Получение интерфейса для работы с потоками */
    g_pIBus->pVTbl->QueryComponent(g_pIBus, &CID_EcoThreadManager1, 0, &IID_IEcoThreadManager1, (void**) &pIThreadMgr);
    if (result != 0 || pIThreadMgr == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

     /* Получение интерфейса текущего потока */
    pICurrentThread = pIThreadMgr->pVTbl->get_CurrentThread(pIThreadMgr);

    /* Создание серверного потока */
    g_pILog->pVTbl->Info(g_pILog, "Creating Server thread");
    pIServerSThread = pIThreadMgr->pVTbl->CreateThread(pIThreadMgr, ServerThread, &connections, 0, 0);
    if (pIServerSThread == 0) {
        g_pILog->pVTbl->Error(g_pILog, "Error create Server Thread");
        goto Release;
    }

	/* Создание клиентских потоков */
    if (InitClientThreads(pIThreadMgr, pICurrentThread, connections) != 0) {
        goto Release;
    }

    pICurrentThread->pVTbl->Sleep(pICurrentThread, 40000);
    
Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (g_pIBus != 0) {
        g_pIBus->pVTbl->Release(g_pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (g_pIMem != 0) {
        g_pIMem->pVTbl->Release(g_pIMem);
    }
    /* Освобождение интерфейса работы с журналированием */
    if (g_pILog != 0) {
        g_pILog->pVTbl->Release(g_pILog);
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

