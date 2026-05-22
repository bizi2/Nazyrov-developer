/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoDiffieHellman1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoDiffieHellman1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_DIFFIE_HELLMAN_1_H__
#define __C_ECO_DIFFIE_HELLMAN_1_H__

#include "IEcoDiffieHellman1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoDiffieHellman1_BFB8A295 {

    /* Таблица функций интерфейса IEcoDiffieHellman1 */
    IEcoDiffieHellman1VTbl* m_pVTblIEcoDiffieHellman1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoDiffieHellman1_BFB8A295, *CEcoDiffieHellman1_BFB8A295Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoDiffieHellman1_BFB8A295(/*in*/ IEcoDiffieHellman1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoDiffieHellman1_BFB8A295(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoDiffieHellman1Ptr_t* ppIEcoDiffieHellman1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoDiffieHellman1_BFB8A295(/* in */ IEcoDiffieHellman1Ptr_t pIEcoDiffieHellman1);

#endif /* __C_ECO_DIFFIE_HELLMAN_1_H__ */
