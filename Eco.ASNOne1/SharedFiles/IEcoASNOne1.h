/*
 * <кодировка символов>
 *   Unicode (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoASNOne1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoASNOne1
 * </описание>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов ASN1,
 *   согластно спецификации разработанной Международным Союзом Электросвязиz
 * </описание>
 *
 * <ссылка>
 *   Спецификация: ITU-T X.680
 *                 08/2015
 *                 Abstract Syntax Notation One (ASN.1): Specification of basic notation
 *                 T-REC-X.680-201508-I.pdf
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__
#define __I_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__

#include "IEcoBase1.h"
#include "IEcoEnumConnections.h"
#include "IEcoList1.h"

typedef enum {
    ECO_ASN1_CLASS_UNIVERSAL,
    ECO_ASN1_CLASS_APPLICATION,
    ECO_ASN1_CLASS_CONTEXT_SPECIFIC,
    ECO_ASN1_CLASS_PRIVATE
} ECO_ASN1_IDENTIFIER_OCTET_CLASS;


typedef enum {
    ECO_ASN1_PC_PRIMITIVE,
    ECO_ASN1_PC_CONSTRUCTED
} ECO_ASN1_IDENTIFIER_OCTET_PC;

typedef union ECO_ASN1_IDENTIFIER_OCTET {
    struct {
        uint8_t TagNumber   : 5;    /* Tag number */
        uint8_t PC          : 1;    /* P/C enc. rules */
        uint8_t Class       : 2;    /* Class */
    } bits;
    uint8_t byte;
} ECO_ASN1_IDENTIFIER_OCTET;


/* IEcoASNOneDataValue IID = {4A6CB985-554D-4717-BE59-772716FBB52F} */
#ifndef __IID_IEcoASNOneDataValue
static const UGUID IID_IEcoASNOneDataValue = {0x01, 0x10, {0x4A, 0x6C, 0xB9, 0x85, 0x55, 0x4D, 0x47, 0x17, 0xBE, 0x59, 0x77, 0x27, 0x16, 0xFB, 0xB5, 0x2F}};
#endif /* __IID_IEcoASNOneDataValue */

typedef struct IEcoASNOneDataValue* IEcoASNOneDataValuePtr_t;

typedef struct IEcoASNOneDataValueVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOneDataValuePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOneDataValuePtr_t me);

    /* IEcoASNOneDataValue */
    int16_t (ECOCALLMETHOD *set_IdentifierOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ ECO_ASN1_IDENTIFIER_OCTET* id, /* in */ byte_t* highTagNumber, /* in */ int16_t octets);
    int16_t (ECOCALLMETHOD *get_IdentifierOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ ECO_ASN1_IDENTIFIER_OCTET** id, /* out */ byte_t** highTagNumber, /* out */ int16_t* octets);
    int16_t (ECOCALLMETHOD *set_LengthOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ byte_t* length, /* in */ int16_t octets);
    int16_t (ECOCALLMETHOD *get_LengthOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ byte_t** length, /* out */ int16_t* octets);
    int16_t (ECOCALLMETHOD *set_ContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ byte_t* contents, /* in */ int16_t octets);
    int16_t (ECOCALLMETHOD *get_ContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ byte_t** contents, /* out */ int16_t* octets);
    int16_t (ECOCALLMETHOD *set_EndOfContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ uint16_t zeroOctets);
    int16_t (ECOCALLMETHOD *get_EndOfContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ uint16_t* zeroOctets);

} IEcoASNOneDataValueVTbl, *IEcoASNOneDataValueVTblPtr_t;

interface IEcoASNOneDataValue {
    struct IEcoASNOneDataValueVTbl *pVTbl;
} IEcoASNOneDataValue;


/* IEcoASNOneDataValue IID = {4A6CB985-554D-4717-BE59-772716FBB52F} */
#ifndef __IID_IEcoASNOneDataValue
static const UGUID IID_IEcoASNOneDataValue = {0x01, 0x10, {0x4A, 0x6C, 0xB9, 0x85, 0x55, 0x4D, 0x47, 0x17, 0xBE, 0x59, 0x77, 0x27, 0x16, 0xFB, 0xB5, 0x2F}};
#endif /* __IID_IEcoASNOneDataValue */

typedef struct IEcoASNOneDataValue* IEcoASNOneDataValuePtr_t;

typedef struct IEcoASNOneDataValueVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOneDataValuePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOneDataValuePtr_t me);

    /* IEcoASNOneDataValue */
    int16_t (ECOCALLMETHOD *set_IdentifierOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ ECO_ASN1_IDENTIFIER_OCTET* id, /* in */ byte_t* highTagNumber, /* in */ int16_t octets);
    int16_t (ECOCALLMETHOD *get_IdentifierOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ ECO_ASN1_IDENTIFIER_OCTET** id, /* out */ byte_t** highTagNumber, /* out */ int16_t* octets);
    int16_t (ECOCALLMETHOD *set_LengthOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ byte_t* length, /* in */ int16_t octets);
    int16_t (ECOCALLMETHOD *get_LengthOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ byte_t** length, /* out */ int16_t* octets);
    int16_t (ECOCALLMETHOD *set_ContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ byte_t* contents, /* in */ int16_t octets);
    int16_t (ECOCALLMETHOD *get_ContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ byte_t** contents, /* out */ int16_t* octets);
    int16_t (ECOCALLMETHOD *set_EndOfContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* in */ uint16_t zeroOctets);
    int16_t (ECOCALLMETHOD *get_EndOfContentsOctets)(/* in */ IEcoASNOneDataValuePtr_t me, /* out */ uint16_t* zeroOctets);

} IEcoASNOneDataValueVTbl, *IEcoASNOneDataValueVTblPtr_t;

interface IEcoASNOneDataValue {
    struct IEcoASNOneDataValueVTbl *pVTbl;
} IEcoASNOneDataValue;

/* IEcoASNOneINTEGER */

typedef struct IEcoASNOneINTEGER* IEcoASNOneINTEGERPtr_t;

typedef struct IEcoASNOneINTEGERVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneINTEGERPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneINTEGERPtr_t me);
    uint32_t (ECOCALLMETHOD* Release)(/* in */ IEcoASNOneINTEGERPtr_t me);

    /* IEcoASNOneINTEGER */
    int16_t(ECOCALLMETHOD* setValue)(/* in */ IEcoASNOneINTEGERPtr_t me, /* in */ voidptr_t IntegerValue, /* in */ int32_t* SizeValue);
    int16_t(ECOCALLMETHOD* getValue)(/* in */ IEcoASNOneINTEGERPtr_t me, /* out */ voidptr_t IntegerValue, /* out */ int32_t* SizeValue);
    uint32_t(ECOCALLMETHOD* NamedNumberList)(/* in */ IEcoASNOneINTEGERPtr_t me);
};

interface IEcoASNOneINTEGER {
    struct IEcoASNOneINTEGERVTbl* pVTbl;
} IEcoASNOneINTEGER;

/* IEcoASNOneBOOLEAN */

typedef struct IEcoASNOneBOOLEAN* IEcoASNOneBOOLEANPtr_t;

typedef struct IEcoASNOneBOOLEANVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneBOOLEANPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneBOOLEANPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneBOOLEANPtr_t me);

    /* IEcoASNOneBOOLEAN */
    bool_t(ECOCALLMETHOD* setValue)(/* in */ IEcoASNOneBOOLEANPtr_t me, /* in */ bool_t Value);
    bool_t(ECOCALLMETHOD* getValue)(/* in */ IEcoASNOneBOOLEANPtr_t me, /* out */ bool_t Value);
};

interface IEcoASNOneBOOLEAN {
    struct IEcoASNOneBOOLEANVTbl* pVTbl;
} IEcoASNOneBOOLEAN;

/* IEcoASNOneREAL */

typedef struct IEcoASNOneREAL* IEcoASNOneREALPtr_t;

typedef struct IEcoASNOneREALVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneREALPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneREALPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneREALPtr_t me);

    /* IEcoASNOneREAL */
    int16_t(ECOCALLMETHOD* setValue)(/* in */ IEcoASNOneREALPtr_t me, /* in */ voidptr_t RealValue, /* in */ int32_t* SizeValue);
    int16_t(ECOCALLMETHOD* getValue)(/* in */ IEcoASNOneREALPtr_t me, /* out */ voidptr_t RealValue, /* out */ int32_t* SizeValue);
};

interface IEcoASNOneREAL {
    struct IEcoASNOneREALVTbl* pVTbl;
} IEcoASNOneREAL;

/* IEcoASNOneENUMERATED */

typedef struct IEcoASNOneENUMERATED* IEcoASNOneENUMERATEDPtr_t;

typedef struct IEcoASNOneENUMERATEDVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneENUMERATEDPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneENUMERATEDPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneENUMERATEDPtr_t me);

    /* IEcoASNOneENUMERATED */
    int16_t(ECOCALLMETHOD* Next)(/* in */ IEcoASNOneENUMERATEDPtr_t me, /* in */ uint32_t cConnections, /* out */ struct EcoConnectionData* rgcd, /* out */ uint32_t* pcFetched);
    int16_t(ECOCALLMETHOD* Skip)(/* in */ IEcoASNOneENUMERATEDPtr_t me, /* in */ uint32_t cConnections);
    int16_t(ECOCALLMETHOD* Reset)(/* in */ IEcoASNOneENUMERATEDPtr_t me);
    int16_t(ECOCALLMETHOD* Clone)(/* in */ IEcoASNOneENUMERATEDPtr_t me, /* out */ IEcoASNOneENUMERATEDPtr_t* ppEnum);
};

interface IEcoASNOneENUMERATED {
    struct IEcoASNOneENUMERATEDVTbl* pVTbl;
} IEcoASNOneENUMERATED;

/* IEcoASNOneSET */

typedef struct IEcoASNOneSET* IEcoASNOneSETPtr_t;

typedef struct IEcoASNOneSETVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneSETPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneSETPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneSETPtr_t me);

    /* IEcoASNOneSET */
    int16_t(ECOCALLMETHOD* setValue)(/* in */ IEcoASNOneSETPtr_t me, voidptr_t value);
    voidptr_t(ECOCALLMETHOD* getValue)(/* in */ IEcoASNOneSETPtr_t me, voidptr_t value);
};

interface IEcoASNOneSET {
    struct IEcoASNOneSETVTbl* pVTbl;
} IEcoASNOneSET;

/* IEcoASNOneBITSTRING */

typedef struct IEcoASNOneBITSTRING* IEcoASNOneBITSTRINGPtr_t;

typedef struct IEcoASNOneBITSTRINGVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneBITSTRINGPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneBITSTRINGPtr_t me);

    /* IEcoASNOneBITSTRING */
    int16_t(ECOCALLMETHOD* set_LengthBitstring)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* in */ byte_t* length, /* in */ int16_t bitstring);
    int16_t(ECOCALLMETHOD* get_LengthBitstring)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* out */ byte_t** length, /* out */ int16_t* bitstring);
    int16_t(ECOCALLMETHOD* set_ContentsBitstring)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* in */ byte_t* contents, /* in */ int16_t bitstring);
    int16_t(ECOCALLMETHOD* get_ContentsBitstring)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* out */ byte_t** contents, /* out */ int16_t* bitstring);
    int16_t(ECOCALLMETHOD* set_EndOfContentsBitstring)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* in */ uint16_t zeroBitstring);
    int16_t(ECOCALLMETHOD* get_EndOfContentsBitstring)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* out */ uint16_t* zeroBitstring);
};


interface IEcoASNOneBITSTRING {
    struct IEcoASNOneBITSTRINGVTbl* pVTbl;
} IEcoASNOneBITSTRING;

/* IEcoASNOneNULL */

typedef struct IEcoASNOneNULL* IEcoASNOneNULLPtr_t;

typedef struct IEcoASNOneNULLVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneNULLPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneNULLPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneNULLPtr_t me);

};


interface IEcoASNOneNULL {
    struct IEcoASNOneNULLVTbl* pVTbl;
} IEcoASNOneNULL;

/* IEcoASNOne1 IID = {AED4F084-9F58-430D-9620-1E0D43831516} */
#ifndef __IID_IEcoASNOne1
static const UGUID IID_IEcoASNOne1 = {0x01, 0x10, {0xAE, 0xD4, 0xF0, 0x84, 0x9F, 0x58, 0x43, 0x0D, 0x96, 0x20, 0x1E, 0x0D, 0x43, 0x83, 0x15, 0x16}};
#endif /* __IID_IEcoASNOne1 */

typedef struct IEcoASNOne1* IEcoASNOne1Ptr_t;

typedef struct IEcoASNOne1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1Ptr_t me);

    /* IEcoASNOne1 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoASNOne1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoASNOne1VTbl, *IEcoASNOne1VTblPtr_t;

interface IEcoASNOne1 {
    struct IEcoASNOne1VTbl *pVTbl;
} IEcoASNOne1;


#endif /* __I_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__ */
