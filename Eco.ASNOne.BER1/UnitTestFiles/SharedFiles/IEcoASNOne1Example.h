/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoASNOne1Example
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoASNOne1Example
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_ASN_ONE_1_EXAMPLE_H__
#define __I_ECO_ASN_ONE_1_EXAMPLE_H__

#include "IEcoBase1.h"
#include "IEcoASNOne1.h"

/* IEcoASNOne1ExDate IID = {F7FE09EB-6A06-41AE-A7AB-43E395396BCA} */
#ifndef __IID_IEcoASNOne1ExDate
static const UGUID IID_IEcoASNOne1ExDate = {0x01, 0x10, {0xF7, 0xFE, 0x09, 0xEB, 0x6A, 0x06, 0x41, 0xAE, 0xA7, 0xAB, 0x43, 0xE3, 0x95, 0x39, 0x6B, 0xCA}};
#endif /* __IID_IEcoASNOne1ExDate */

typedef struct IEcoASNOne1ExDate* IEcoASNOne1ExDatePtr_t;

typedef struct IEcoASNOne1ExDateVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ExDatePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ExDatePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ExDatePtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ExDatePtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ExDatePtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ExDatePtr_t me);

    /* IEcoASNOne1Value */
    int16_t (ECOCALLMETHOD *set_Value)(/* in */ IEcoASNOne1ExDatePtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    int16_t (ECOCALLMETHOD *get_Value)(/* in */ IEcoASNOne1ExDatePtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);

    /* IEcoASNOne1ExDate */

} IEcoASNOne1ExDateVTbl, *IEcoASNOne1ExDateVTblPtr_t;

interface IEcoASNOne1ExDate {
    struct IEcoASNOne1ExDateVTbl *pVTbl;
} IEcoASNOne1ExDate;

/* IEcoASNOne1ExEmployeeNumber IID = {440D2626-FE33-49A0-8266-393C3E7987CC} */
#ifndef __IID_IEcoASNOne1ExEmployeeNumber
static const UGUID IID_IEcoASNOne1ExEmployeeNumber = {0x01, 0x10, {0x44, 0x0D, 0x26, 0x26, 0xFE, 0x33, 0x49, 0xA0, 0x82, 0x66, 0x39, 0x3C, 0x3E, 0x79, 0x87, 0xCC}};
#endif /* __IID_IEcoASNOne1ExEmployeeNumber */

typedef struct IEcoASNOne1ExEmployeeNumber* IEcoASNOne1ExEmployeeNumberPtr_t;

typedef struct IEcoASNOne1ExEmployeeNumberVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me);

    /* IEcoASNOne1Value */
    int16_t (ECOCALLMETHOD *set_Value)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    int16_t (ECOCALLMETHOD *get_Value)(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);

    /* IEcoASNOne1ExEmployeeNumber */

} IEcoASNOne1ExEmployeeNumberVTbl, *IEcoASNOne1ExEmployeeNumberVTblPtr_t;

interface IEcoASNOne1ExEmployeeNumber {
    struct IEcoASNOne1ExEmployeeNumberVTbl *pVTbl;
} IEcoASNOne1ExEmployeeNumber;

/* IEcoASNOne1ExName IID = {8C1B98CC-E786-48B0-BAA4-11968FBDDB9C} */
#ifndef __IID_IEcoASNOne1ExName
static const UGUID IID_IEcoASNOne1ExName = {0x01, 0x10, {0x8C, 0x1B, 0x98, 0xCC, 0xE7, 0x86, 0x48, 0xB0, 0xBA, 0xA4, 0x11, 0x96, 0x8F, 0xBD, 0xDB, 0x9C}};
#endif /* __IID_IEcoASNOne1ExName */

typedef struct IEcoASNOne1ExName* IEcoASNOne1ExNamePtr_t;

typedef struct IEcoASNOne1ExNameVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ExNamePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ExNamePtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ExNamePtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ExNamePtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ExNamePtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t (ECOCALLMETHOD *Count)(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ int32_t* Count);
    int16_t (ECOCALLMETHOD *Item)(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t (ECOCALLMETHOD *Add)(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoASNOne1ExName */
    IEcoASNOne1Value* (ECOCALLMETHOD *givenName)(/* in */ IEcoASNOne1ExNamePtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *initial)(/* in */ IEcoASNOne1ExNamePtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *familyName)(/* in */ IEcoASNOne1ExNamePtr_t me);

} IEcoASNOne1ExNameVTbl, *IEcoASNOne1ExNameVTblPtr_t;

interface IEcoASNOne1ExName {
    struct IEcoASNOne1ExNameVTbl *pVTbl;
} IEcoASNOne1ExName;

/* IEcoASNOne1ExChildInformation IID = {D739CAFE-1BE2-4191-A824-788A1439E7A1} */
#ifndef __IID_IEcoASNOne1ExChildInformation
static const UGUID IID_IEcoASNOne1ExChildInformation = {0x01, 0x10, {0xD7, 0x39, 0xCA, 0xFE, 0x1B, 0xE2, 0x41, 0x91, 0xA8, 0x24, 0x78, 0x8A, 0x14, 0x39, 0xE7, 0xA1}};
#endif /* __IID_IEcoASNOne1ExChildInformation */

typedef struct IEcoASNOne1ExChildInformation* IEcoASNOne1ExChildInformationPtr_t;

typedef struct IEcoASNOne1ExChildInformationVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ExChildInformationPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t (ECOCALLMETHOD *Count)(/* in */ IEcoASNOne1ExChildInformationPtr_t me, /* in */ int32_t* Count);
    int16_t (ECOCALLMETHOD *Item)(/* in */ IEcoASNOne1ExChildInformationPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t (ECOCALLMETHOD *Add)(/* in */ IEcoASNOne1ExChildInformationPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoASNOne1ExChildInformation */
    IEcoASNOne1ExName* (ECOCALLMETHOD *name)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);
    IEcoASNOne1ExDate* (ECOCALLMETHOD *dateOfBirth)(/* in */ IEcoASNOne1ExChildInformationPtr_t me);

} IEcoASNOne1ExChildInformationVTbl, *IEcoASNOne1ExChildInformationVTblPtr_t;

interface IEcoASNOne1ExChildInformation {
    struct IEcoASNOne1ExChildInformationVTbl *pVTbl;
} IEcoASNOne1ExChildInformation;

/* IEcoASNOne1ExPersonnelRecord IID = {774C3101-CD82-48E2-A267-524D127B9D6A} */
#ifndef __IID_IEcoASNOne1ExPersonnelRecord
static const UGUID IID_IEcoASNOne1ExPersonnelRecord = {0x01, 0x10, {0x77, 0x4C, 0x31, 0x01, 0xCD, 0x82, 0x48, 0xE2, 0xA2, 0x67, 0x52, 0x4D, 0x12, 0x7B, 0x9D, 0x6A}};
#endif /* __IID_IEcoASNOne1ExPersonnelRecord */

typedef struct IEcoASNOne1ExPersonnelRecord* IEcoASNOne1ExPersonnelRecordPtr_t;

typedef struct IEcoASNOne1ExPersonnelRecordVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t (ECOCALLMETHOD *Count)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ int32_t* Count);
    int16_t (ECOCALLMETHOD *Item)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t (ECOCALLMETHOD *Add)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoASNOne1ExPersonnelRecord */
    IEcoASNOne1ExName* (ECOCALLMETHOD *name)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *title)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    IEcoASNOne1ExEmployeeNumber* (ECOCALLMETHOD *number)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    IEcoASNOne1ExDate* (ECOCALLMETHOD *dateOfHire)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    IEcoASNOne1ExName* (ECOCALLMETHOD *nameOfSpouse)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);
    IEcoASNOne1ValueSet* (ECOCALLMETHOD *children)(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me);

} IEcoASNOne1ExPersonnelRecordVTbl, *IEcoASNOne1ExPersonnelRecordVTblPtr_t;

interface IEcoASNOne1ExPersonnelRecord {
    struct IEcoASNOne1ExPersonnelRecordVTbl *pVTbl;
} IEcoASNOne1ExPersonnelRecord;


/* IEcoASNOne1Example IID = {C4996BED-1E10-4842-BE05-5D0270A58595} */
#ifndef __IID_IEcoASNOne1Example
static const UGUID IID_IEcoASNOne1Example = {0x01, 0x10, {0xC4, 0x99, 0x6B, 0xED, 0x1E, 0x10, 0x48, 0x42, 0xBE, 0x05, 0x5D, 0x02, 0x70, 0xA5, 0x85, 0x95}};
#endif /* __IID_IEcoASNOne1Example */

typedef struct IEcoASNOne1Example* IEcoASNOne1ExamplePtr_t;

typedef struct IEcoASNOne1ExampleVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ExamplePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ExamplePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ExamplePtr_t me);

    /* IEcoASNOne1Example */
    int16_t (ECOCALLMETHOD *new_PersonnelRecord)(/* in */ IEcoASNOne1ExamplePtr_t me, /* out */ IEcoASNOne1ExPersonnelRecord** ppIPersonnelRecord);
    int16_t (ECOCALLMETHOD *new_ChildInformation)(/* in */ IEcoASNOne1ExamplePtr_t me, /* out */ IEcoASNOne1ExChildInformation** ppIChildInformation);

} IEcoASNOne1ExampleVTbl, *IEcoASNOne1ExampleVTblPtr_t;

interface IEcoASNOne1Example {
    struct IEcoASNOne1ExampleVTbl *pVTbl;
} IEcoASNOne1Example;

#endif /* __I_ECO_ASN_ONE_1_EXAMPLE_H__ */
