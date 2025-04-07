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


/* class */
#define ECO_ASN1_CLASS_UNIVERSAL            0x00
#define ECO_ASN1_CLASS_APPLICATION          0x40
#define ECO_ASN1_CLASS_CONTEXT_SPECIFIC     0x80
#define ECO_ASN1_CLASS_PRIVATE              0xC0

/* P/C */
#define ECO_ASN1_PC_PRIMITIVE               0x00
#define ECO_ASN1_PC_CONSTRUCTED             0x20

#define ECO_ASN1_EMPTY                      0

/* Universal class tag assignments */
#define ECO_ASN1_UNIVERSAL_0            0 /* Reserved for use by the encoding rules */
#define ECO_ASN1_RESERVED_0             ECO_ASN1_UNIVERSAL_0
#define ECO_ASN1_UNIVERSAL_1            1 /* Boolean type */
#define ECO_ASN1_BOOLEAN_TYPE           ECO_ASN1_UNIVERSAL_1
#define ECO_ASN1_UNIVERSAL_2            2 /* Integer type */
#define ECO_ASN1_INTEGER_TYPE           ECO_ASN1_UNIVERSAL_2
#define ECO_ASN1_UNIVERSAL_3            3 /* Bitstring type */
#define ECO_ASN1_BIT_STRING_TYPE        ECO_ASN1_UNIVERSAL_3
#define ECO_ASN1_UNIVERSAL_4            4 /* Octetstring type */
#define ECO_ASN1_OCTET_STRING_TYPE      ECO_ASN1_UNIVERSAL_4
#define ECO_ASN1_UNIVERSAL_5            5 /* Null type */
#define ECO_ASN1_NULL_TYPE              ECO_ASN1_UNIVERSAL_5
#define ECO_ASN1_UNIVERSAL_6            6 /* Object identifier type */
#define ECO_ASN1_OBJECT_IDENTIFIER_TYPE ECO_ASN1_UNIVERSAL_6
#define ECO_ASN1_UNIVERSAL_7            7 /* Object descriptor type */
#define ECO_ASN1_OBJECT_DESCRIPTOR_TYPE ECO_ASN1_UNIVERSAL_7
#define ECO_ASN1_UNIVERSAL_8            8 /* External type and Instance-of type */
#define ECO_ASN1_EXTERNAL_TYPE          ECO_ASN1_UNIVERSAL_8
#define ECO_ASN1_INSTANCE_OF_TYPE       ECO_ASN1_UNIVERSAL_8
#define ECO_ASN1_UNIVERSAL_9            9 /* Real type */
#define ECO_ASN1_REAL_TYPE              ECO_ASN1_UNIVERSAL_9
#define ECO_ASN1_UNIVERSAL_10           10 /* Enumerated type */
#define ECO_ASN1_ENUMERATED_TYPE        ECO_ASN1_UNIVERSAL_10
#define ECO_ASN1_UNIVERSAL_11           11 /* Embedded-pdv type */
#define ECO_ASN1_EMBEDDED_PDV_TYPE      ECO_ASN1_UNIVERSAL_11
#define ECO_ASN1_UNIVERSAL_12           12 /* UTF8String type */
#define ECO_ASN1_UTF8_STRING_TYPE       ECO_ASN1_UNIVERSAL_12
#define ECO_ASN1_UNIVERSAL_13           13 /* Relative object identifier type */
#define ECO_ASN1_RELATIVE_OBJECT_IDENTIFIER_TYPE   ECO_ASN1_UNIVERSAL_13
#define ECO_ASN1_UNIVERSAL_14           14 /* The time type */
#define ECO_ASN1_TIME_TYPE              ECO_ASN1_UNIVERSAL_14
#define ECO_ASN1_UNIVERSAL_15           15 /* Reserved for future editions of this Recommendation | International Standard */
#define ECO_ASN1_RESERVED_15            ECO_ASN1_UNIVERSAL_15
#define ECO_ASN1_UNIVERSAL_16           16 /* Sequece and Sequece-of types */
#define ECO_ASN1_SEQUENCE_TYPE          ECO_ASN1_UNIVERSAL_16
#define ECO_ASN1_SEQUENCE_OF_TYPE       ECO_ASN1_UNIVERSAL_16
#define ECO_ASN1_UNIVERSAL_17           17 /* Set and Set-of types */
#define ECO_ASN1_SET_TYPE               ECO_ASN1_UNIVERSAL_17
#define ECO_ASN1_SET_OF_TYPE            ECO_ASN1_UNIVERSAL_17
#define ECO_ASN1_UNIVERSAL_18           18 /* NumericString type */
#define ECO_ASN1_NUMERIC_STRING_TYPE    ECO_ASN1_UNIVERSAL_18
#define ECO_ASN1_UNIVERSAL_19           19 /* PrintableString type */
#define ECO_ASN1_PRINTABLE_STRING_TYPE  ECO_ASN1_UNIVERSAL_19
#define ECO_ASN1_UNIVERSAL_20           20 /* TeletexString type */
#define ECO_ASN1_TELETEX_STRING_TYPE    ECO_ASN1_UNIVERSAL_20
#define ECO_ASN1_UNIVERSAL_21           21 /* VideotexString type */
#define ECO_ASN1_VIDEOTEXT_STRING_TYPE  ECO_ASN1_UNIVERSAL_21
#define ECO_ASN1_UNIVERSAL_22           22 /* IA5String type */
#define ECO_ASN1_IA5STRING_TYPE         ECO_ASN1_UNIVERSAL_22
#define ECO_ASN1_UNIVERSAL_23           23 /* UTCTime type */
#define ECO_ASN1_UTCTIME_TYPE           ECO_ASN1_UNIVERSAL_23
#define ECO_ASN1_UNIVERSAL_24           24 /* GeneralizedTime type */
#define ECO_ASN1_GENERALIZED_TIME_TYPE  ECO_ASN1_UNIVERSAL_24
#define ECO_ASN1_UNIVERSAL_25           25 /* GraphicString type */
#define ECO_ASN1_GRAPHIC_STRING_TYPE    ECO_ASN1_UNIVERSAL_25
#define ECO_ASN1_UNIVERSAL_26           26 /* VisibleString (ISO646String) type */
#define ECO_ASN1_VISIBLE_STRING_TYPE    ECO_ASN1_UNIVERSAL_26
#define ECO_ASN1_ISO646STRING_TYPE      ECO_ASN1_UNIVERSAL_26
#define ECO_ASN1_UNIVERSAL_27           27 /* GeneralString type */
#define ECO_ASN1_GENERAL_STRING_TYPE    ECO_ASN1_UNIVERSAL_27
#define ECO_ASN1_UNIVERSAL_28           28 /* UniversalString type */
#define ECO_ASN1_UNIVERASL_STRING_TYPE  ECO_ASN1_UNIVERSAL_28
#define ECO_ASN1_UNIVERSAL_29           29 /* Unrestricted CharacterString Type (CHARACTER STRING) */
#define ECO_ASN1_CHARACTER_STRING_TYPE  ECO_ASN1_UNIVERSAL_29
#define ECO_ASN1_UNIVERSAL_30           30 /* BMPString type */
#define ECO_ASN1_BMPSTRING_TYPE         ECO_ASN1_UNIVERSAL_30


//#define ECO_ASN1_UNIVERSAL_31-34    0 /* DATE, TIME-OF-DAY, DATE-TIME and DURATION respectively */
//#define ECO_ASN1_UNIVERSAL_35    0 /* OID internationalized resource identifier type */
//#define ECO_ASN1_UNIVERSAL_36    0 /* Relative OID internationalized resource identifier type */
//#define ECO_ASN1_UNIVERSAL_37-...    0 /* Reserved for addenda to this Recommendation | International Standard */

#define ECO_ASN1_TAG_EMPTY          0x00 
#define ECO_ASN1_TAG_EXPLICIT       0x01
#define ECO_ASN1_TAG_DEFAULT        ECO_ASN1_TAG_EXPLICIT
#define ECO_ASN1_TAG_IMPLICIT       0x02
#define ECO_ASN1_TAG_AUTOMATIC      0x03

/* IEcoASNOne1Type IID = {62229AB7-563D-4257-A751-EB3278BEB369} */
#ifndef __IID_IEcoASNOne1Type
static const UGUID IID_IEcoASNOne1Type = {0x01, 0x10, {0x62, 0x22, 0x9A, 0xB7, 0x56, 0x3D, 0x42, 0x57, 0xA7, 0x51, 0xEB, 0x32, 0x78, 0xBE, 0xB3, 0x69}};
#endif /* __IID_IEcoASNOne1Type */

typedef struct IEcoASNOne1Type* IEcoASNOne1TypePtr_t;

typedef struct IEcoASNOne1TypeVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1TypePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1TypePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1TypePtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1TypePtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1TypePtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1TypePtr_t me);

} IEcoASNOne1TypeVTbl, *IEcoASNOne1TypeVTblPtr_t;

interface IEcoASNOne1Type {
    struct IEcoASNOne1TypeVTbl* pVTbl;
} IEcoASNOne1Type;

/* IEcoASNOne1Value IID = {188D761E-316F-4348-8274-BE142A9EA308} */
#ifndef __IID_IEcoASNOne1Value
static const UGUID IID_IEcoASNOne1Value = {0x01, 0x10, {0x18, 0x8D, 0x76, 0x1E, 0x31, 0x6F, 0x43, 0x48, 0x82, 0x74, 0xBE, 0x14, 0x2A, 0x9E, 0xA3, 0x08}};
#endif /* __IID_IEcoASNOne1Value */

typedef struct IEcoASNOne1Value* IEcoASNOne1ValuePtr_t;

typedef struct IEcoASNOne1ValueVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ValuePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ValuePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ValuePtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ValuePtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ValuePtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ValuePtr_t me);

    /* IEcoASNOne1Value */
    int16_t (ECOCALLMETHOD *set_Value)(/* in */ IEcoASNOne1ValuePtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    int16_t (ECOCALLMETHOD *get_Value)(/* in */ IEcoASNOne1ValuePtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);

} IEcoASNOne1ValueVTbl, *IEcoASNOne1ValueVTblPtr_t;

interface IEcoASNOne1Value {
    struct IEcoASNOne1ValueVTbl* pVTbl;
} IEcoASNOne1Value;

/* IEcoASNOne1ValueSet IID = {8312A933-5DE7-4B47-A9C0-14B2FE4B83C7} */
#ifndef __IID_IEcoASNOne1ValueSet
static const UGUID IID_IEcoASNOne1ValueSet = {0x01, 0x10, {0x83, 0x12, 0xA9, 0x33, 0x5D, 0xE7, 0x4B, 0x47, 0xA9, 0xC0, 0x14, 0xB2, 0xFE, 0x4B, 0x83, 0xC7}};
#endif /* __IID_IEcoASNOne1ValueSet */

typedef struct IEcoASNOne1ValueSet* IEcoASNOne1ValueSetPtr_t;

typedef struct IEcoASNOne1ValueSetVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1ValueSetPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1ValueSetPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t (ECOCALLMETHOD *get_Tag)(/* in */ IEcoASNOne1ValueSetPtr_t me);
    uint8_t (ECOCALLMETHOD *get_TaggedType)(/* in */ IEcoASNOne1ValueSetPtr_t me);
    uint8_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoASNOne1ValueSetPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t (ECOCALLMETHOD *Count)(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ int32_t* Count);
    int16_t (ECOCALLMETHOD *Item)(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t (ECOCALLMETHOD *Add)(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

} IEcoASNOne1ValueSetVTbl, *IEcoASNOne1ValueSetVTblPtr_t;

interface IEcoASNOne1ValueSet {
    struct IEcoASNOne1ValueSetVTbl* pVTbl;
} IEcoASNOne1ValueSet;

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
    int16_t (ECOCALLMETHOD *new_Value)(/* in */ IEcoASNOne1Ptr_t me, /* in */ uint8_t Tag, /* in */ uint8_t TaggetType, /* in */ uint8_t Type, /* out */ IEcoASNOne1Value** ppIValue);
    int16_t (ECOCALLMETHOD *new_ValueSet)(/* in */ IEcoASNOne1Ptr_t me, /* in */ uint8_t Tag, /* in */ uint8_t TaggetType, /* in */ uint8_t Type, /* out */ IEcoASNOne1ValueSet** ppIValueSet);

} IEcoASNOne1VTbl, *IEcoASNOne1VTblPtr_t;

interface IEcoASNOne1 {
    struct IEcoASNOne1VTbl *pVTbl;
} IEcoASNOne1;


/* IEcoASNOne1EncodingRules IID = {347BFCFB-CFE3-418F-8EE5-DADF17B39B28} */
#ifndef __IID_IEcoASNOne1EncodingRules
static const UGUID IID_IEcoASNOne1EncodingRules = {0x01, 0x10, {0x34, 0x7B, 0xFC, 0xFB, 0xCF, 0xE3, 0x41, 0x8F, 0x8E, 0xE5, 0xDA, 0xDF, 0x17, 0xB3, 0x9B, 0x28}};
#endif /* __IID_IEcoASNOne1EncodingRules */

typedef struct IEcoASNOne1EncodingRules* IEcoASNOne1EncodingRulesPtr_t;

typedef struct IEcoASNOne1EncodingRulesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOne1EncodingRulesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOne1EncodingRulesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOne1EncodingRulesPtr_t me);

    /* IEcoASNOne1EncodingRules */
    int16_t (ECOCALLMETHOD *Encode)(/* in */ IEcoASNOne1EncodingRulesPtr_t me, /* in */ voidptr_t pv, /* out */ byte_t* buffer, /* out */ uint32_t* length);
    int16_t (ECOCALLMETHOD *Decode)(/* in */ IEcoASNOne1EncodingRulesPtr_t me, /* in */ byte_t* buffer, /* in */ uint32_t length, /* out */ voidptr_t* ppv);

} IEcoASNOne1EncodingRulesVTbl, *IEcoASNOne1EncodingRulesVTblPtr_t;

interface IEcoASNOne1EncodingRules {
    struct IEcoASNOne1EncodingRulesVTbl *pVTbl;
} IEcoASNOne1EncodingRules;


#endif /* __I_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__ */
