/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOneBER1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOneBER1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_ASN_ONE_BER_1_H__
#define __C_ECO_ASN_ONE_BER_1_H__

#include "IEcoASNOneBER1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoASNOne1.h"

typedef struct CEcoASNOneBER1 {

    /* Таблица функций интерфейса IEcoASNOneBER1 */
    IEcoASNOneBER1VTbl* m_pVTblIEcoASNOneBER1;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoASNOneBER1, *CEcoASNOneBER1Ptr;

/* Инициализация экземпляра */
int16_t initCEcoASNOneBER1(/*in*/ struct IEcoASNOneBER1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t createCEcoASNOneBER1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoASNOneBER1** ppIEcoASNOneBER1);
/* Удаление */
void deleteCEcoASNOneBER1(/* in */ IEcoASNOneBER1* pIEcoASNOneBER1);

#endif /* __C_ECO_ASN_ONE_BER_1_H__ */
