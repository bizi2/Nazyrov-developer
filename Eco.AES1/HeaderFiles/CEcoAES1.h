/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoAES1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_AES_1_H__
#define __C_ECO_AES_1_H__

#include "IEcoAES1.h"
#include "IEcoAES1Cipher.h"
#include "IEcoAES1InvCipher.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoAES1 {

    /* Таблица функций интерфейса IEcoAES1 */
    IEcoAES1VTbl* m_pVTblIAES;

    /* Таблица функций интерфейса IEcoAES1Cipher */
    IEcoAES1CipherVTbl* m_pVTblIAESCipher;

    /* Таблица функций интерфейса IEcoAES1InvCipher */
    IEcoAES1InvCipherVTbl* m_pVTblIAESInvCipher;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    uint8_t m_iMode;
    uint8_t m_iPaddingMode;
    uint8_t* m_pKey;
    uint8_t* m_pIV;


    uint8_t m_Nb;
    uint8_t m_Nk; /* Кол-во 32-битных слов в ключе. */
    uint8_t m_Nr;


} CEcoAES1, *CEcoAES1Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoAES1(/*in*/ IEcoAES1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoAES1(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoAES1Ptr_t* ppIEcoAES1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoAES1(/* in */ IEcoAES1Ptr_t pIEcoAES1);

#endif /* __C_ECO_AES_1_H__ */
