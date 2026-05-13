/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CEcoASNOnePER1_F509D9E8
 * </summary>
 *
 * <description>
 *   This header describes the implementation of the CEcoASNOnePER1_F509D9E8 component
 * </description>
 *
 * <author>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </author>
 *
 */

#ifndef __C_ECOASNONEPER1_H__
#define __C_ECOASNONEPER1_H__

#include "IEcoASNOnePER1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include <string.h>

typedef enum {
    PER_ALIGNED = 0,
    PER_UNALIGNED = 1
} PER_Variant;

typedef struct {
    uint8_t* data;          // массив байт
    int bit_len;            // сколько бит записано
    int capacity;           // сколько байт выделено
    PER_Variant variant;
    IEcoMemoryAllocator1* mem; // откуда брать память (аллокатор)
} BitBuf;

/* Прототипы функций битового буфера */
static void bitbuf_init(BitBuf* buf, PER_Variant var, IEcoMemoryAllocator1* mem);
static void bitbuf_ensure(BitBuf* buf, size_t need_bit);
static void bitbuf_append(BitBuf* buf, uint64_t value, int bit);
static void bitbuf_align(BitBuf* buf);
static uint8_t* bitbuf_finalize(BitBuf* buf, uint32_t* out_len);

typedef struct {
    char* givenName;
    char* initial;
    char* familyName;
} Name;

typedef struct Child {
    Name name;
    char* dateOfBirth;
    struct Child* next;
} Child;

typedef struct {
    Name name;
    char* title;
    char* DateOfHire;
    int32_t number;
    Name nameOfSpouse;
    Child* children;
    uint32_t childCount;
} PersonnelRecord;

/* НЕ ПЕРЕОПРЕДЕЛЯЕМ IEcoASNOnePER1VTbl - он уже есть в IEcoASNOnePER1.h */
/* Просто добавляем методы в существующую структуру через отдельный интерфейс или расширение */

/* Расширенный интерфейс с PER-методами */
typedef struct IEcoASNOnePER1VTblExt {
    /* Базовые методы (должны совпадать с IEcoASNOnePER1VTbl) */
    int16_t(ECOCALLMETHOD* QueryInterface)(IEcoASNOnePER1Ptr_t me, const UGUID* riid, void** ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(IEcoASNOnePER1Ptr_t me);
    uint32_t(ECOCALLMETHOD* Release)(IEcoASNOnePER1Ptr_t me);
    int16_t(ECOCALLMETHOD* MyFunction)(IEcoASNOnePER1Ptr_t me, char_t* Name, char_t** copyName);

    /* PER-методы */
    int16_t(ECOCALLMETHOD* EncodePersonnelRecord)(IEcoASNOnePER1Ptr_t me, PersonnelRecord* rec, uint8_t** outData, uint32_t* outLen);
    int16_t(ECOCALLMETHOD* DecodePersonnelRecord)(IEcoASNOnePER1Ptr_t me, uint8_t* data, uint32_t len, PersonnelRecord** rec);
    void    (ECOCALLMETHOD* FreePersonnelRecord)(IEcoASNOnePER1Ptr_t me, PersonnelRecord* rec);
} IEcoASNOnePER1VTblExt;

typedef struct CEcoASNOnePER1_F509D9E8* CEcoASNOnePER1_F509D9E8Ptr_t;

typedef struct CEcoASNOnePER1_F509D9E8 {
    /* Указываем на расширенную таблицу */
    IEcoASNOnePER1VTblExt* m_pVTblIEcoASNOnePER1;

    /* Instance initialization */
    int16_t(ECOCALLMETHOD* Init)(/*in*/ CEcoASNOnePER1_F509D9E8Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem);
    /* Instance creation */
    int16_t(ECOCALLMETHOD* Create)(/*in*/ CEcoASNOnePER1_F509D9E8Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter);
    /* Deletion */
    void (ECOCALLMETHOD* Delete)(/*in*/ CEcoASNOnePER1_F509D9E8Ptr_t pCMe);

    /* Reference counter */
    uint32_t m_cRef;

    /* Interface for memory operations */
    IEcoMemoryAllocator1* m_pIMem;

    /* System interface */
    IEcoSystem1* m_pISys;

    /* Instance data */
    char_t* m_Name;
} CEcoASNOnePER1_F509D9E8;

#endif /* __C_ECOASNONEPER1_H__ */