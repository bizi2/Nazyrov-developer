/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS8
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS8
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS8_H__
#define __C_ECOPKCS8_H__

#include "IEcoPKCS8.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS8EncryptedPrivateKey {

    /* Таблица функций интерфейса IEcoPKCS8 */
    IEcoPKCS8VTbl* m_pVTblIEcoPKCS8;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoPKCS8AlgorithmIdentifier* m_encryptionAlgorithm;
	IEcoPKCS8EncryptedData* m_encryptedData;

} CEcoPKCS8EncryptedPrivateKey, *CEcoPKCS8EncryptedPrivateKeyPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS8EncryptedPrivateKey(/*in*/ IEcoPKCS8Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS8EncryptedPrivateKey(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS8Ptr_t* ppIEcoPKCS8);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS8EncryptedPrivateKey(/* in */ IEcoPKCS8Ptr_t pIEcoPKCS8);

#endif /* __C_ECOPKCS8_H__ */
