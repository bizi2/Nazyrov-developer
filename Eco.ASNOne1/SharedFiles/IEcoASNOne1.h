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

};

interface IEcoASNOneENUMERATED {
    struct IEcoASNOneENUMERATEDVTbl* pVTbl;
} IEcoASNOneENUMERATED;

/* IEcoASNOneSEQUENCEOF */

typedef struct IEcoASNOneSEQUENCEOF* IEcoASNOneSEQUENCEOFPtr_t;

typedef struct IEcoASNOneSEQUENCEOFVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneSEQUENCEOFPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneSEQUENCEOFPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneSEQUENCEOFPtr_t me);

    /* IEcoASNOneSEQUENCEOF */

};

interface IEcoASNOneSEQUENCEOF {
    struct IEcoASNOneSEQUENCEOFVTbl* pVTbl;
} IEcoASNOneSEQUENCEOF;

/* IEcoASNOneSEQUENCEOF */

typedef struct IEcoASNOneSEQUENCE* IEcoASNOneSEQUENCEPtr_t;

typedef struct IEcoASNOneSEQUENCEVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneSEQUENCEPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneSEQUENCEPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneSEQUENCEPtr_t me);

    /* IEcoASNOneSEQUENCE */

};

interface IEcoASNOneSEQUENCE {
    struct IEcoASNOneSEQUENCEVTbl* pVTbl;
} IEcoASNOneSEQUENCE;

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

/* IEcoASNOneSETOF */

typedef struct IEcoASNOneSETOF* IEcoASNOneSETOFPtr_t;

typedef struct IEcoASNOneSETOFVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneSETOFPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneSETOFPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneSETOFPtr_t me);

    /* IEcoASNOneSETOF */

};

interface IEcoASNOneSETOF {
    struct IEcoASNOneSETOFVTbl* pVTbl;
} IEcoASNOneSETOF;

/* IEcoASNOneCHOICE */

typedef struct IEcoASNOneCHOICE* IEcoASNOneCHOICEPtr_t;

typedef struct IEcoASNOneCHOICEVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneCHOICEPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneCHOICEPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneCHOICEPtr_t me);

    /* IEcoASNOneCHOICE */

};

interface IEcoASNOneCHOICE {
    struct IEcoASNOneCHOICEVTbl* pVTbl;
} IEcoASNOneCHOICE;

/* IEcoASNOneSELECTION */

typedef struct IEcoASNOneSELECTION* IEcoASNOneSELECTIONPtr_t;

typedef struct IEcoASNOneSELECTIONVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneSELECTIONPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneSELECTIONPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneSELECTIONPtr_t me);

    /* IEcoASNOneSELECTION */

};

interface IEcoASNOneSELECTION {
    struct IEcoASNOneSELECTIONVTbl* pVTbl;
} IEcoASNOneSELECTION;

/* IEcoASNOnePREFIXED */

typedef struct IEcoASNOnePREFIXED* IEcoASNOnePREFIXEDPtr_t;

typedef struct IEcoASNOnePREFIXEDVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOnePREFIXEDPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOnePREFIXEDPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOnePREFIXEDPtr_t me);

    /* IEcoASNOnePREFIXED */

};

interface IEcoASNOnePREFIXED {
    struct IEcoASNOnePREFIXEDVTbl* pVTbl;
} IEcoASNOnePREFIXED;

/* IEcoASNOneOID */

typedef struct IEcoASNOneOID* IEcoASNOneOIDPtr_t;

typedef struct IEcoASNOneOIDVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneOIDPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneOIDPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneOIDPtr_t me);

    /* IEcoASNOneOID */

};

interface IEcoASNOneOID {
    struct IEcoASNOneOIDVTbl* pVTbl;
} IEcoASNOneOID;

/* IEcoASNOneRelativeOID */

typedef struct IEcoASNOneRelativeOID* IEcoASNOneRelativeOIDPtr_t;

typedef struct IEcoASNOneRelativeOIDVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneRelativeOIDPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneRelativeOIDPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneRelativeOIDPtr_t me);

    /* IEcoASNOneRelativeOID */

};

/* IEcoASNOneIRI */

typedef struct IEcoASNOneIRI* IEcoASNOneIRIPtr_t;

typedef struct IEcoASNOneIRIVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneIRIPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneIRIPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneIRIPtr_t me);

    /* IEcoASNOneIRI */

};

/* IEcoASNOneRelativeIRI */

typedef struct IEcoASNOneRelativeIRI* IEcoASNOneRelativeIRIPtr_t;

typedef struct IEcoASNOneRelativeIRIVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneRelativeIRIPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneRelativeIRIPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneRelativeIRIPtr_t me);

    /* IEcoASNOneRelativeIRI */

};


interface IEcoASNOneRelativeIRI {
    struct IEcoASNOneRelativeIRIVTbl* pVTbl;
} IEcoASNOneRelativeIRI;

/* IEcoASNOneEmbeddedPDV */

typedef struct IEcoASNOneEmbeddedPDV* IEcoASNOneEmbeddedPDVPtr_t;

typedef struct IEcoASNOneEmbeddedPDVVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneEmbeddedPDVPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneEmbeddedPDVPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneEmbeddedPDVPtr_t me);

    /* IEcoASNOneEmbeddedPDV */

};


interface IEcoASNOneEmbeddedPDV {
    struct IEcoASNOneEmbeddedPDVVTbl* pVTbl;
} IEcoASNOneEmbeddedPDV;

/* IEcoASNOneEXTERNAL */

typedef struct IEcoASNOneEXTERNAL* IEcoASNOneEXTERNALPtr_t;

typedef struct IEcoASNOneEXTERNALVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneEXTERNALPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneEXTERNALPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneEXTERNALPtr_t me);

    /* IEcoASNOneEXTERNAL */

};


interface IEcoASNOneEXTERNAL {
    struct IEcoASNOneEXTERNALVTbl* pVTbl;
} IEcoASNOneEXTERNAL;

/* IEcoASNOneTIME */

typedef struct IEcoASNOneTIME* IEcoASNOneTIMEPtr_t;

typedef struct IEcoASNOneTIMEVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneTIMEPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneTIMEPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneTIMEPtr_t me);

    /* IEcoASNOneTIME */

};


interface IEcoASNOneTIME {
    struct IEcoASNOneTIMEVTbl* pVTbl;
} IEcoASNOneTIME;

/* IEcoASNOneCharacterSTRING */

typedef struct IEcoASNOneCharacterSTRING* IEcoASNOneCharacterSTRINGPtr_t;

typedef struct IEcoASNOneCharacterSTRINGVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneCharacterSTRINGPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneCharacterSTRINGPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneCharacterSTRINGPtr_t me);

    /* IEcoASNOneCharacterSTRING */

};


interface IEcoASNOneCharacterSTRING {
    struct IEcoASNOneCharacterSTRINGVTbl* pVTbl;
} IEcoASNOneCharacterSTRING;

/* IEcoASNOneRestrictedCharacterSTRING */

typedef struct IEcoASNOneRestrictedCharacterSTRING* IEcoASNOneRestrictedCharacterSTRINGPtr_t;

typedef struct IEcoASNOneRestrictedCharacterSTRINGVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneRestrictedCharacterSTRINGPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneRestrictedCharacterSTRINGPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneRestrictedCharacterSTRINGPtr_t me);

    /* IEcoASNOneRestrictedCharacterSTRING */

};


interface IEcoASNOneRestrictedCharacterSTRING {
    struct IEcoASNOneRestrictedCharacterSTRINGVTbl* pVTbl;
} IEcoASNOneRestrictedCharacterSTRING;

/* IEcoASNOneUnrestrictedCharacterSTRING */

typedef struct IEcoASNOneUnrestrictedCharacterSTRING* IEcoASNOneUnrestrictedCharacterSTRINGPtr_t;

typedef struct IEcoASNOneUnrestrictedCharacterSTRINGVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneUnrestrictedCharacterSTRINGPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneUnrestrictedCharacterSTRINGPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneUnrestrictedCharacterSTRINGPtr_t me);

    /* IEcoASNOneUnrestrictedCharacterSTRING */

};


interface IEcoASNOneUnrestrictedCharacterSTRING {
    struct IEcoASNOneUnrestrictedCharacterSTRINGVTbl* pVTbl;
} IEcoASNOneUnrestrictedCharacterSTRING;

/* IEcoASNOneObjectDescriptor */

typedef struct IEcoASNOneObjectDescriptor* IEcoASNOneObjectDescriptorPtr_t;

typedef struct IEcoASNOneObjectDescriptorVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneObjectDescriptorPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneObjectDescriptorPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneObjectDescriptorPtr_t me);

    /* IEcoASNOneObjectDescriptor */

};


interface IEcoASNOneObjectDescriptor {
    struct IEcoASNOneObjectDescriptorVTbl* pVTbl;
} IEcoASNOneObjectDescriptor;

/* IEcoASNOneCONSTRAINED */

typedef struct IEcoASNOneCONSTRAINED* IEcoASNOneCONSTRAINEDPtr_t;

typedef struct IEcoASNOneCONSTRAINEDVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneCONSTRAINEDPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneCONSTRAINEDPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneCONSTRAINEDPtr_t me);

    /* IEcoASNOneCONSTRAINED */

};


interface IEcoASNOneCONSTRAINED {
    struct IEcoASNOneCONSTRAINEDVTbl* pVTbl;
} IEcoASNOneCONSTRAINED;

/* IEcoASNOneBITSTRING */

typedef struct IEcoASNOneBITSTRING* IEcoASNOneBITSTRINGPtr_t;

typedef struct IEcoASNOneBITSTRINGVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoASNOneBITSTRINGPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoASNOneBITSTRINGPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoASNOneBITSTRINGPtr_t me);

    /* IEcoASNOneBITSTRING */

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
