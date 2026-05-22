/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS11
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS11
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


#ifndef __I_ECOPKCS11_H__
#define __I_ECOPKCS11_H__

#define IEcoPKCS11PTR *

#include "IEcoBase1.h"

 /* an unsigned 8-bit value */
typedef unsigned char     IEcoPKCS11BYTE;

/* an unsigned 8-bit character */
typedef IEcoPKCS11BYTE           IEcoPKCS11CHAR;

/* an 8-bit UTF-8 character */
typedef IEcoPKCS11BYTE           IEcoPKCS11UTF8CHAR;

/* a BYTE-sized Boolean flag */
typedef IEcoPKCS11BYTE           IEcoPKCS11BBOOL;

/* an unsigned value, at least 32 bits long */
typedef unsigned long int IEcoPKCS11ULONG;

/* a signed value, the same size as a IEcoPKCS11ULONG */
typedef long int          IEcoPKCS11LONG;

/* at least 32 bits; each bit is a Boolean flag */
typedef IEcoPKCS11ULONG          IEcoPKCS11FLAGS;

typedef IEcoPKCS11BYTE     IEcoPKCS11PTR   IEcoPKCS11BYTE_PTR;
typedef IEcoPKCS11CHAR     IEcoPKCS11PTR   IEcoPKCS11CHAR_PTR;
typedef IEcoPKCS11UTF8CHAR IEcoPKCS11PTR   IEcoPKCS11UTF8CHAR_PTR;
typedef IEcoPKCS11ULONG    IEcoPKCS11PTR   IEcoPKCS11ULONG_PTR;
typedef void        IEcoPKCS11PTR   IEcoPKCS11VOID_PTR;

/* Pointer to a CK_VOID_PTR-- i.e., pointer to pointer to void */
typedef IEcoPKCS11PTR IEcoPKCS11PTR IEcoPKCS11PTR_PTR;

/* IEcoPKCS11 IID = {3A6A72F1-D57C-4813-896C-87DB92B252FF} */
#ifndef __IID_IEcoPKCS11
static const UGUID IID_IEcoPKCS11 = {0x01, 0x10, {0x3A, 0x6A, 0x72, 0xF1, 0xD5, 0x7C, 0x48, 0x13, 0x89, 0x6C, 0x87, 0xDB, 0x92, 0xB2, 0x52, 0xFF}};
#endif /* __IID_IEcoPKCS11 */

typedef struct IEcoPKCS11* IEcoPKCS11Ptr_t;

typedef struct IEcoPKCS11VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS11Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS11Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS11Ptr_t me);

    /* IEcoPKCS11 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS11Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS11VTbl, *IEcoPKCS11VTblPtr_t;

interface IEcoPKCS11 {
    struct IEcoPKCS11VTbl *pVTbl;
} IEcoPKCS11;

typedef struct IEcoPKCS11Version* IEcoPKCS11VersionPtr_t;

typedef struct IEcoPKCS11VersionVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11VersionPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11VersionPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11VersionPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11VersionPtr_t me);

    /* IEcoPKCS11Version */
    IEcoPKCS11BYTE* (ECOCALLMETHOD* major)(/* in */ IEcoPKCS11VersionPtr_t me);
    IEcoPKCS11BYTE* (ECOCALLMETHOD* minor)(/* in */ IEcoPKCS11VersionPtr_t me);

} IEcoPKCS11VersionVTbl, * IEcoPKCS11VersionVTblPtr_t;

interface IEcoPKCS11Version {
    struct IEcoPKCS11VersionVTbl* pVTbl;
} IEcoPKCS11Version;

typedef struct IEcoPKCS11Info* IEcoPKCS11InfoPtr_t;

typedef struct IEcoPKCS11InfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11InfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11InfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11InfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11InfoPtr_t me);

    /* IEcoPKCS11Info */
    IEcoPKCS11Version* (ECOCALLMETHOD* cryptokiVersion)(/* in */ IEcoPKCS11InfoPtr_t me);
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* manufacturerID)(/* in */ IEcoPKCS11InfoPtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11InfoPtr_t me);
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* libraryDescription)(/* in */ IEcoPKCS11InfoPtr_t me);
    IEcoPKCS11Version* (ECOCALLMETHOD* libraryVersion)(/* in */ IEcoPKCS11InfoPtr_t me);

} IEcoPKCS11InfoVTbl, * IEcoPKCS11InfoVTblPtr_t;

interface IEcoPKCS11Info {
    struct IEcoPKCS11InfoVTbl* pVTbl;
} IEcoPKCS11Info;

typedef struct IEcoPKCS11SlotInfo* IEcoPKCS11SlotInfoPtr_t;

typedef struct IEcoPKCS11SlotInfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SlotInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SlotInfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SlotInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SlotInfoPtr_t me);

    /* IEcoPKCS11SlotInfo */
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* slotDescription)(/* in */ IEcoPKCS11SlotInfoPtr_t me);
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* manufacturerID)(/* in */ IEcoPKCS11SlotInfoPtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11SlotInfoPtr_t me);
    IEcoPKCS11Version* (ECOCALLMETHOD* hardwareVersion)(/* in */ IEcoPKCS11SlotInfoPtr_t me);
    IEcoPKCS11Version* (ECOCALLMETHOD* firmwareVersion)(/* in */ IEcoPKCS11SlotInfoPtr_t me);

} IEcoPKCS11SlotInfoVTbl, * IEcoPKCS11SlotInfoVTblPtr_t;

interface IEcoPKCS11SlotInfo {
    struct IEcoPKCS11SlotInfoVTbl* pVTbl;
} IEcoPKCS11SlotInfo;

typedef struct IEcoPKCS11TokenInfo* IEcoPKCS11TokenInfoPtr_t;

typedef struct IEcoPKCS11TokenInfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11TokenInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11TokenInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11TokenInfoPtr_t me);

    /* IEcoPKCS11TokenInfo */
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* label)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* manufacturerID)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11UTF8CHAR* (ECOCALLMETHOD* model)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11CHAR* (ECOCALLMETHOD* serialNumber)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMaxSessionCount)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSessionCount)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMaxRwSessionCount)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRwSessionCount)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMaxPinLen)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMinPinLen)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulTotalPublicMemory)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulFreePublicMemory)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulTotalPrivateMemory)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulFreePrivateMemory)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11Version* (ECOCALLMETHOD* hardwareVersion)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11Version* (ECOCALLMETHOD* firmwareVersion)(/* in */ IEcoPKCS11TokenInfoPtr_t me);
    IEcoPKCS11CHAR* (ECOCALLMETHOD* utcTime)(/* in */ IEcoPKCS11TokenInfoPtr_t me);

} IEcoPKCS11TokenInfoVTbl, * IEcoPKCS11TokenInfoVTblPtr_t;

interface IEcoPKCS11TokenInfo {
    struct IEcoPKCS11TokenInfoVTbl* pVTbl;
} IEcoPKCS11TokenInfo;

typedef struct IEcoPKCS11SessionInfo* IEcoPKCS11SessionInfoPtr_t;

typedef struct IEcoPKCS11SessionInfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SessionInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SessionInfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SessionInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SessionInfoPtr_t me);

    /* IEcoPKCS11SessionInfo */
    IEcoPKCS11SLOTID* (ECOCALLMETHOD* slotID)(/* in */ IEcoPKCS11SessionInfoPtr_t me);
    IEcoPKCS11STATE* (ECOCALLMETHOD* state)(/* in */ IEcoPKCS11SessionInfoPtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11SessionInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulDeviceError)(/* in */ IEcoPKCS11SessionInfoPtr_t me);

} IEcoPKCS11SessionInfoVTbl, * IEcoPKCS11SessionInfoVTblPtr_t;

interface IEcoPKCS11SessionInfo {
    struct IEcoPKCS11SessionInfoVTbl* pVTbl;
} IEcoPKCS11SessionInfo;

typedef struct IEcoPKCS11Attribute* IEcoPKCS11AttributePtr_t;

typedef struct IEcoPKCS11AttributeVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11AttributePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11AttributePtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11AttributePtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11AttributePtr_t me);

    /* IEcoPKCS11Attribute */
    IEcoPKCS11AttributeTYPE* (ECOCALLMETHOD* type)(/* in */ IEcoPKCS11AttributePtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pValue)(/* in */ IEcoPKCS11AttributePtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulValueLen)(/* in */ IEcoPKCS11AttributePtr_t me);

} IEcoPKCS11AttributeVTbl, * IEcoPKCS11AttributeVTblPtr_t;

interface IEcoPKCS11Attribute {
    struct IEcoPKCS11AttributeVTbl* pVTbl;
} IEcoPKCS11Attribute;


typedef struct IEcoPKCS11Date* IEcoPKCS11DatePtr_t;

typedef struct IEcoPKCS11DateVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11DatePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11DatePtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11DatePtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11DatePtr_t me);

    /* IEcoPKCS11Date */
    IEcoPKCS11CHAR* (ECOCALLMETHOD* year)(/* in */ IEcoPKCS11DatePtr_t me);
    IEcoPKCS11CHAR* (ECOCALLMETHOD* month)(/* in */ IEcoPKCS11DatePtr_t me);
    IEcoPKCS11CHAR* (ECOCALLMETHOD* day)(/* in */ IEcoPKCS11DatePtr_t me);

} IEcoPKCS11DateVTbl, * IEcoPKCS11DateVTblPtr_t;

interface IEcoPKCS11Date {
    struct IEcoPKCS11DateVTbl* pVTbl;
} IEcoPKCS11Date;

typedef struct IEcoPKCS11Mechanism* IEcoPKCS11MechanismPtr_t;

typedef struct IEcoPKCS11MechanismVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11MechanismPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11MechanismPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11MechanismPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11MechanismPtr_t me);

    /* IEcoPKCS11Mechanism */
    IEcoPKCS11MechanismTYPE* (ECOCALLMETHOD* mechanism)(/* in */ IEcoPKCS11MechanismPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pParameter)(/* in */ IEcoPKCS11MechanismPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulParameterLen)(/* in */ IEcoPKCS11MechanismPtr_t me);

} IEcoPKCS11MechanismVTbl, * IEcoPKCS11MechanismVTblPtr_t;

interface IEcoPKCS11Mechanism {
    struct IEcoPKCS11MechanismVTbl* pVTbl;
} IEcoPKCS11Mechanism;

typedef struct IEcoPKCS11MechanismINFO* IEcoPKCS11MechanismINFOPtr_t;

typedef struct IEcoPKCS11MechanismINFOVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11MechanismINFOPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11MechanismINFOPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11MechanismINFOPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11MechanismINFOPtr_t me);

    /* IEcoPKCS11MechanismINFO */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMinKeySize)(/* in */ IEcoPKCS11MechanismINFOPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMaxKeySize)(/* in */ IEcoPKCS11MechanismINFOPtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11MechanismINFOPtr_t me);

} IEcoPKCS11MechanismINFOVTbl, * IEcoPKCS11MechanismINFOVTblPtr_t;

interface IEcoPKCS11MechanismINFO {
    struct IEcoPKCS11MechanismINFOVTbl* pVTbl;
} IEcoPKCS11MechanismINFO;

typedef struct IEcoPKCS11Interface* IEcoPKCS11InterfacePtr_t;

typedef struct IEcoPKCS11InterfaceVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11InterfacePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11InterfacePtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11InterfacePtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11InterfacePtr_t me);

    /* IEcoPKCS11Interface */
    IEcoPKCS11CHAR** (ECOCALLMETHOD* pInterfaceName)(/* in */ IEcoPKCS11InterfacePtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pFunctionList)(/* in */ IEcoPKCS11InterfacePtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11InterfacePtr_t me);

} IEcoPKCS11InterfaceVTbl, * IEcoPKCS11InterfaceVTblPtr_t;

interface IEcoPKCS11Interface {
    struct IEcoPKCS11InterfaceVTbl* pVTbl;
} IEcoPKCS11Interface;

typedef struct IEcoPKCS11CInitializeARGS* IEcoPKCS11CInitializeARGSPtr_t;

typedef struct IEcoPKCS11CInitializeARGSVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);

    /* IEcoPKCS11CInitializeARGS */
    IEcoPKCS11CREATEMUTEX* (ECOCALLMETHOD* CreateMutex)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);
    IEcoPKCS11DESTROYMUTEX* (ECOCALLMETHOD* DestroyMutex)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);
    IEcoPKCS11LOCKMUTEX* (ECOCALLMETHOD* LockMutex)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);
    IEcoPKCS11UNLOCKMUTEX* (ECOCALLMETHOD* UnlockMutex)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);
    IEcoPKCS11FLAGS* (ECOCALLMETHOD* flags)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pReserved)(/* in */ IEcoPKCS11CInitializeARGSPtr_t me);

} IEcoPKCS11CInitializeARGSVTbl, * IEcoPKCS11CInitializeARGSVTblPtr_t;

interface IEcoPKCS11CInitializeARGS {
    struct IEcoPKCS11CInitializeARGSVTbl* pVTbl;
} IEcoPKCS11CInitializeARGS;

typedef struct IEcoPKCS11RSAPKCSOAEPParams* IEcoPKCS11RSAPKCSOAEPParamsPtr_t;

typedef struct IEcoPKCS11RSAPKCSOAEPParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);

    /* IEcoPKCS11RSAPKCSOAEPParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* hashAlg)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);
    IEcoPKCS11RSA_PKCS_MGF_TYPE* (ECOCALLMETHOD* mgf)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);
    IEcoPKCS11RSA_PKCS_OAEP_SOURCE_TYPE* (ECOCALLMETHOD* source)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pSourceData)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSourceDataLen)(/* in */ IEcoPKCS11RSAPKCSOAEPParamsPtr_t me);

} IEcoPKCS11RSAPKCSOAEPParamsVTbl, * IEcoPKCS11RSAPKCSOAEPParamsVTblPtr_t;

interface IEcoPKCS11RSAPKCSOAEPParams {
    struct IEcoPKCS11RSAPKCSOAEPParamsVTbl* pVTbl;
} IEcoPKCS11RSAPKCSOAEPParams;

typedef struct IEcoPKCS11RSAPKCSSParams* IEcoPKCS11RSAPKCSSParamsPtr_t;

typedef struct IEcoPKCS11RSAPKCSSParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me);

    /* IEcoPKCS11RSAPKCSSParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* hashAlg)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me);
    IEcoPKCS11RSA_PKCS_MGF_TYPE* (ECOCALLMETHOD* mgf)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* sLen)(/* in */ IEcoPKCS11RSAPKCSSParamsPtr_t me);

} IEcoPKCS11RSAPKCSSParamsVTbl, * IEcoPKCS11RSAPKCSSParamsVTblPtr_t;

interface IEcoPKCS11RSAPKCSSParams {
    struct IEcoPKCS11RSAPKCSSParamsVTbl* pVTbl;
} IEcoPKCS11RSAPKCSSParams;

typedef struct IEcoPKCS11ECDH1DERIVEParams* IEcoPKCS11ECDH1DERIVEParamsPtr_t;

typedef struct IEcoPKCS11ECDH1DERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);

    /* IEcoPKCS11ECDH1DERIVEParams */
    IEcoPKCS11EC_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSharedDataLen)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSharedData)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11ECDH1DERIVEParamsPtr_t me);

} IEcoPKCS11ECDH1DERIVEParamsVTbl, * IEcoPKCS11ECDH1DERIVEParamsVTblPtr_t;

interface IEcoPKCS11ECDH1DERIVEParams {
    struct IEcoPKCS11ECDH1DERIVEParamsVTbl* pVTbl;
} IEcoPKCS11ECDH1DERIVEParams;

typedef struct IEcoPKCS11ECDH2DERIVEParams* IEcoPKCS11ECDH2DERIVEParamsPtr_t;

typedef struct IEcoPKCS11ECDH2DERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);

    /* IEcoPKCS11ECDH2DERIVEParams */
    IEcoPKCS11EC_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSharedDataLen)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSharedData)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPrivateDataLen)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hPrivateData)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen2)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData2)(/* in */ IEcoPKCS11ECDH2DERIVEParamsPtr_t me);

} IEcoPKCS11ECDH2DERIVEParamsVTbl, * IEcoPKCS11ECDH2DERIVEParamsVTblPtr_t;

interface IEcoPKCS11ECDH2DERIVEParams {
    struct IEcoPKCS11ECDH2DERIVEParamsVTbl* pVTbl;
} IEcoPKCS11ECDH2DERIVEParams;

typedef struct IEcoPKCS11ECMQVDERIVEParams* IEcoPKCS11ECMQVDERIVEParamsPtr_t;

typedef struct IEcoPKCS11ECMQVDERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);

    /* IEcoPKCS11ECMQVDERIVEParams */
    IEcoPKCS11EC_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSharedDataLen)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSharedData)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPrivateDataLen)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hPrivateData)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen2)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData2)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* publicKey)(/* in */ IEcoPKCS11ECMQVDERIVEParamsPtr_t me);

} IEcoPKCS11ECMQVDERIVEParamsVTbl, * IEcoPKCS11ECMQVDERIVEParamsVTblPtr_t;

interface IEcoPKCS11ECMQVDERIVEParams {
    struct IEcoPKCS11ECMQVDERIVEParamsVTbl* pVTbl;
} IEcoPKCS11ECMQVDERIVEParams;

typedef struct IEcoPKCS11X942DH1DERIVEParams* IEcoPKCS11X942DH1DERIVEParamsPtr_t;

typedef struct IEcoPKCS11X942DH1DERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);

    /* IEcoPKCS11X942DH1DERIVEParams */
    IEcoPKCS11X942DH_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOtherInfoLen)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOtherInfo)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11X942DH1DERIVEParamsPtr_t me);

} IEcoPKCS11X942DH1DERIVEParamsVTbl, * IEcoPKCS11X942DH1DERIVEParamsVTblPtr_t;

interface IEcoPKCS11X942DH1DERIVEParams {
    struct IEcoPKCS11X942DH1DERIVEParamsVTbl* pVTbl;
} IEcoPKCS11X942DH1DERIVEParams;

typedef struct IEcoPKCS11X942DH2DERIVEParams* IEcoPKCS11X942DH2DERIVEParamsPtr_t;

typedef struct IEcoPKCS11X942DH2DERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);

    /* IEcoPKCS11X942DH2DERIVEParams */
    IEcoPKCS11X942DH_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOtherInfoLen)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOtherInfo)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPrivateDataLen)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hPrivateData)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen2)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData2)(/* in */ IEcoPKCS11X942DH2DERIVEParamsPtr_t me);

} IEcoPKCS11X942DH2DERIVEParamsVTbl, * IEcoPKCS11X942DH2DERIVEParamsVTblPtr_t;

interface IEcoPKCS11X942DH2DERIVEParams {
    struct IEcoPKCS11X942DH2DERIVEParamsVTbl* pVTbl;
} IEcoPKCS11X942DH2DERIVEParams;

typedef struct IEcoPKCS11X942MQVDERIVEParams* IEcoPKCS11X942MQVDERIVEParamsPtr_t;

typedef struct IEcoPKCS11X942MQVDERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);

    /* IEcoPKCS11X942MQVDERIVEParams */
    IEcoPKCS11X942DH_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOtherInfoLen)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOtherInfo)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPrivateDataLen)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hPrivateData)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen2)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData2)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* publicKey)(/* in */ IEcoPKCS11X942MQVDERIVEParamsPtr_t me);

} IEcoPKCS11X942MQVDERIVEParamsVTbl, * IEcoPKCS11X942MQVDERIVEParamsVTblPtr_t;

interface IEcoPKCS11X942MQVDERIVEParams {
    struct IEcoPKCS11X942MQVDERIVEParamsVTbl* pVTbl;
} IEcoPKCS11X942MQVDERIVEParams;

typedef struct IEcoPKCS11KEADERIVEParams* IEcoPKCS11KEADERIVEParamsPtr_t;

typedef struct IEcoPKCS11KEADERIVEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);

    /* IEcoPKCS11KEADERIVEParams */
    IEcoPKCS11BBOOL* (ECOCALLMETHOD* isSender)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRandomLen)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pRandomA)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pRandomB)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11KEADERIVEParamsPtr_t me);

} IEcoPKCS11KEADERIVEParamsVTbl, * IEcoPKCS11KEADERIVEParamsVTblPtr_t;

interface IEcoPKCS11KEADERIVEParams {
    struct IEcoPKCS11KEADERIVEParamsVTbl* pVTbl;
} IEcoPKCS11KEADERIVEParams;

typedef struct IEcoPKCS11RC2CBCParams* IEcoPKCS11RC2CBCParamsPtr_t;

typedef struct IEcoPKCS11RC2CBCParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RC2CBCParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RC2CBCParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RC2CBCParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RC2CBCParamsPtr_t me);

    /* IEcoPKCS11RC2CBCParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulEffectiveBits)(/* in */ IEcoPKCS11RC2CBCParamsPtr_t me);
    IEcoPKCS11BYTE* (ECOCALLMETHOD* iv)(/* in */ IEcoPKCS11RC2CBCParamsPtr_t me);

} IEcoPKCS11RC2CBCParamsVTbl, * IEcoPKCS11RC2CBCParamsVTblPtr_t;

interface IEcoPKCS11RC2CBCParams {
    struct IEcoPKCS11RC2CBCParamsVTbl* pVTbl;
} IEcoPKCS11RC2CBCParams;

typedef struct IEcoPKCS11RC2MACGENERALParams* IEcoPKCS11RC2MACGENERALParamsPtr_t;

typedef struct IEcoPKCS11RC2MACGENERALParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RC2MACGENERALParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RC2MACGENERALParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RC2MACGENERALParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RC2MACGENERALParamsPtr_t me);

    /* IEcoPKCS11RC2MACGENERALParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulEffectiveBits)(/* in */ IEcoPKCS11RC2MACGENERALParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMacLength)(/* in */ IEcoPKCS11RC2MACGENERALParamsPtr_t me);

} IEcoPKCS11RC2MACGENERALParamsVTbl, * IEcoPKCS11RC2MACGENERALParamsVTblPtr_t;

interface IEcoPKCS11RC2MACGENERALParams {
    struct IEcoPKCS11RC2MACGENERALParamsVTbl* pVTbl;
} IEcoPKCS11RC2MACGENERALParams;

typedef struct IEcoPKCS11RC5Params* IEcoPKCS11RC5ParamsPtr_t;

typedef struct IEcoPKCS11RC5ParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RC5ParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RC5ParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RC5ParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RC5ParamsPtr_t me);

    /* IEcoPKCS11RC5Params */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulWordsize)(/* in */ IEcoPKCS11RC5ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRounds)(/* in */ IEcoPKCS11RC5ParamsPtr_t me);

} IEcoPKCS11RC5ParamsVTbl, * IEcoPKCS11RC5ParamsVTblPtr_t;

interface IEcoPKCS11RC5Params {
    struct IEcoPKCS11RC5ParamsVTbl* pVTbl;
} IEcoPKCS11RC5Params;

typedef struct IEcoPKCS11RC5CBCParams* IEcoPKCS11RC5CBCParamsPtr_t;

typedef struct IEcoPKCS11RC5CBCParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);

    /* IEcoPKCS11RC5CBCParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulWordsize)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRounds)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIv)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvLen)(/* in */ IEcoPKCS11RC5CBCParamsPtr_t me);

} IEcoPKCS11RC5CBCParamsVTbl, * IEcoPKCS11RC5CBCParamsVTblPtr_t;

interface IEcoPKCS11RC5CBCParams {
    struct IEcoPKCS11RC5CBCParamsVTbl* pVTbl;
} IEcoPKCS11RC5CBCParams;

typedef struct IEcoPKCS11RC5MACGENERALParams* IEcoPKCS11RC5MACGENERALParamsPtr_t;

typedef struct IEcoPKCS11RC5MACGENERALParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me);

    /* IEcoPKCS11RC5MACGENERALParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulWordsize)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRounds)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMacLength)(/* in */ IEcoPKCS11RC5MACGENERALParamsPtr_t me);

} IEcoPKCS11RC5MACGENERALParamsVTbl, * IEcoPKCS11RC5MACGENERALParamsVTblPtr_t;

interface IEcoPKCS11RC5MACGENERALParams {
    struct IEcoPKCS11RC5MACGENERALParamsVTbl* pVTbl;
} IEcoPKCS11RC5MACGENERALParams;

typedef struct IEcoPKCS11DESCBCENCRYPTDATAParams* IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t;

typedef struct IEcoPKCS11DESCBCENCRYPTDATAParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me);

    /* IEcoPKCS11DESCBCENCRYPTDATAParams */
    IEcoPKCS11BYTE* (ECOCALLMETHOD* iv)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pData)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* length)(/* in */ IEcoPKCS11DESCBCENCRYPTDATAParamsPtr_t me);

} IEcoPKCS11DESCBCENCRYPTDATAParamsVTbl, * IEcoPKCS11DESCBCENCRYPTDATAParamsVTblPtr_t;

interface IEcoPKCS11DESCBCENCRYPTDATAParams {
    struct IEcoPKCS11DESCBCENCRYPTDATAParamsVTbl* pVTbl;
} IEcoPKCS11DESCBCENCRYPTDATAParams;

typedef struct IEcoPKCS11AESCBCENCRYPTDATAParams* IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t;

typedef struct IEcoPKCS11AESCBCENCRYPTDATAParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me);

    /* IEcoPKCS11AESCBCENCRYPTDATAParams */
    IEcoPKCS11BYTE* (ECOCALLMETHOD* iv)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me);
    IEcoPKCS11BYTEPTR* (ECOCALLMETHOD* pData)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* length)(/* in */ IEcoPKCS11AESCBCENCRYPTDATAParamsPtr_t me);

} IEcoPKCS11AESCBCENCRYPTDATAParamsVTbl, * IEcoPKCS11AESCBCENCRYPTDATAParamsVTblPtr_t;

interface IEcoPKCS11AESCBCENCRYPTDATAParams {
    struct IEcoPKCS11AESCBCENCRYPTDATAParamsVTbl* pVTbl;
} IEcoPKCS11AESCBCENCRYPTDATAParams;

typedef struct IEcoPKCS11SKIPJACKPRIVATEWrapParams* IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t;

typedef struct IEcoPKCS11SKIPJACKPRIVATEWrapParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);

    /* IEcoPKCS11SKIPJACKPRIVATEWrapParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPasswordLen)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPassword)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPAndGLen)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulQLen)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRandomLen)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pRandomA)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPrimeP)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pBaseG)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSubprimeQ)(/* in */ IEcoPKCS11SKIPJACKPRIVATEWrapParamsPtr_t me);

} IEcoPKCS11SKIPJACKPRIVATEWrapParamsVTbl, * IEcoPKCS11SKIPJACKPRIVATEWrapParamsVTblPtr_t;

interface IEcoPKCS11SKIPJACKPRIVATEWrapParams {
    struct IEcoPKCS11SKIPJACKPRIVATEWrapParamsVTbl* pVTbl;
} IEcoPKCS11SKIPJACKPRIVATEWrapParams;

typedef struct IEcoPKCS11SKIPJACKRELAYXParams* IEcoPKCS11SKIPJACKRELAYXParamsPtr_t;

typedef struct IEcoPKCS11SKIPJACKRELAYXParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);

    /* IEcoPKCS11SKIPJACKRELAYXParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOldWrappedXLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOldWrappedX)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOldPasswordLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOldPassword)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOldPublicDataLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOldPublicData)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulOldRandomLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOldRandomA)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNewPasswordLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNewPassword)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNewPublicDataLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNewPublicData)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNewRandomLen)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNewRandomA)(/* in */ IEcoPKCS11SKIPJACKRELAYXParamsPtr_t me);

} IEcoPKCS11SKIPJACKRELAYXParamsVTbl, * IEcoPKCS11SKIPJACKRELAYXParamsVTblPtr_t;

interface IEcoPKCS11SKIPJACKRELAYXParams {
    struct IEcoPKCS11SKIPJACKRELAYXParamsVTbl* pVTbl;
} IEcoPKCS11SKIPJACKRELAYXParams;

typedef struct IEcoPKCS11PBEParams* IEcoPKCS11PBEParamsPtr_t;

typedef struct IEcoPKCS11PBEParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11PBEParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11PBEParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11PBEParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11PBEParamsPtr_t me);

    /* IEcoPKCS11PBEParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pInitVector)(/* in */ IEcoPKCS11PBEParamsPtr_t me);
    IEcoPKCS11UTF8CHAR_PTR* (ECOCALLMETHOD* pPassword)(/* in */ IEcoPKCS11PBEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPasswordLen)(/* in */ IEcoPKCS11PBEParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSalt)(/* in */ IEcoPKCS11PBEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSaltLen)(/* in */ IEcoPKCS11PBEParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIteration)(/* in */ IEcoPKCS11PBEParamsPtr_t me);

} IEcoPKCS11PBEParamsVTbl, * IEcoPKCS11PBEParamsVTblPtr_t;

interface IEcoPKCS11PBEParams {
    struct IEcoPKCS11PBEParamsVTbl* pVTbl;
} IEcoPKCS11PBEParams;

typedef struct IEcoPKCS11KEYWRAPSETOAEPParams* IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t;

typedef struct IEcoPKCS11KEYWRAPSETOAEPParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me);

    /* IEcoPKCS11KEYWRAPSETOAEPParams */
    IEcoPKCS11BYTE* (ECOCALLMETHOD* bBC)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pX)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulXLen)(/* in */ IEcoPKCS11KEYWRAPSETOAEPParamsPtr_t me);

} IEcoPKCS11KEYWRAPSETOAEPParamsVTbl, * IEcoPKCS11KEYWRAPSETOAEPParamsVTblPtr_t;

interface IEcoPKCS11KEYWRAPSETOAEPParams {
    struct IEcoPKCS11KEYWRAPSETOAEPParamsVTbl* pVTbl;
} IEcoPKCS11KEYWRAPSETOAEPParams;

typedef struct IEcoPKCS11SSL3RandomData* IEcoPKCS11SSL3RandomDataPtr_t;

typedef struct IEcoPKCS11SSL3RandomDataVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);

    /* IEcoPKCS11SSL3RandomData */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pClientRandom)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulClientRandomLen)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pServerRandom)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulServerRandomLen)(/* in */ IEcoPKCS11SSL3RandomDataPtr_t me);

} IEcoPKCS11SSL3RandomDataVTbl, * IEcoPKCS11SSL3RandomDataVTblPtr_t;

interface IEcoPKCS11SSL3RandomData {
    struct IEcoPKCS11SSL3RandomDataVTbl* pVTbl;
} IEcoPKCS11SSL3RandomData;

typedef struct IEcoPKCS11SSL3MasterKeyDeriveParams* IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t;

typedef struct IEcoPKCS11SSL3MasterKeyDeriveParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t me);

    /* IEcoPKCS11SSL3MasterKeyDeriveParams */
    IEcoPKCS11SSL3RandomData* (ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t me);
    IEcoPKCS11Version* (ECOCALLMETHOD* pVersion)(/* in */ IEcoPKCS11SSL3MasterKeyDeriveParamsPtr_t me);

} IEcoPKCS11SSL3MasterKeyDeriveParamsVTbl, * IEcoPKCS11SSL3MasterKeyDeriveParamsVTblPtr_t;

interface IEcoPKCS11SSL3MasterKeyDeriveParams {
    struct IEcoPKCS11SSL3MasterKeyDeriveParamsVTbl* pVTbl;
} IEcoPKCS11SSL3MasterKeyDeriveParams;

typedef struct IEcoPKCS11SSL3KeyMatOut* IEcoPKCS11SSL3KeyMatOutPtr_t;

typedef struct IEcoPKCS11SSL3KeyMatOut* IEcoPKCS11SSL3KeyMatOutPtr_t;

typedef struct IEcoPKCS11SSL3KeyMatOutVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);

    /* IEcoPKCS11SSL3KeyMatOut */
    IEcoPKCS11OBJECTHANDLE* (ECOCALLMETHOD* hClientMacSecret)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);
    IEcoPKCS11OBJECTHANDLE* (ECOCALLMETHOD* hServerMacSecret)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);
    IEcoPKCS11OBJECTHANDLE* (ECOCALLMETHOD* hClientKey)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);
    IEcoPKCS11OBJECTHANDLE* (ECOCALLMETHOD* hServerKey)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIVClient)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIVServer)(/* in */ IEcoPKCS11SSL3KeyMatOutPtr_t me);

} IEcoPKCS11SSL3KeyMatOutVTbl, * IEcoPKCS11SSL3KeyMatOutVTblPtr_t;

interface IEcoPKCS11SSL3KeyMatOut {
    struct IEcoPKCS11SSL3KeyMatOutVTbl* pVTbl;
} IEcoPKCS11SSL3KeyMatOut;

typedef struct IEcoPKCS11SSL3KeyMatParams* IEcoPKCS11SSL3KeyMatParamsPtr_t;

typedef struct IEcoPKCS11SSL3KeyMatParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);

    /* IEcoPKCS11SSL3KeyMatParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMacSizeInBits)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulKeySizeInBits)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIVSizeInBits)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bIsExport)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);
    IEcoPKCS11SSL3RandomData*(ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);
    IEcoPKCS11SSL3KeyMatOut* (ECOCALLMETHOD* pReturnedKeyMaterial)(/* in */ IEcoPKCS11SSL3KeyMatParamsPtr_t me);

} IEcoPKCS11SSL3KeyMatParamsVTbl, * IEcoPKCS11SSL3KeyMatParamsVTblPtr_t;

interface IEcoPKCS11SSL3KeyMatParams {
    struct IEcoPKCS11SSL3KeyMatParamsVTbl* pVTbl;
} IEcoPKCS11SSL3KeyMatParams;

typedef struct IEcoPKCS11TLSPrfParams* IEcoPKCS11TLSPrfParamsPtr_t;

typedef struct IEcoPKCS11TLSPrfParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);

    /* IEcoPKCS11TLSPrfParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSeed)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSeedLen)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pLabel)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulLabelLen)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOutput)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);
    IEcoPKCS11ULONG_PTR* (ECOCALLMETHOD* pulOutputLen)(/* in */ IEcoPKCS11TLSPrfParamsPtr_t me);

} IEcoPKCS11TLSPrfParamsVTbl, * IEcoPKCS11TLSPrfParamsVTblPtr_t;

interface IEcoPKCS11TLSPrfParams {
    struct IEcoPKCS11TLSPrfParamsVTbl* pVTbl;
} IEcoPKCS11TLSPrfParams;

typedef struct IEcoPKCS11WTLSRandomData* IEcoPKCS11WTLSRandomDataPtr_t;

typedef struct IEcoPKCS11WTLSRandomDataVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);

    /* IEcoPKCS11WTLSRandomData */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pClientRandom)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulClientRandomLen)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pServerRandom)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulServerRandomLen)(/* in */ IEcoPKCS11WTLSRandomDataPtr_t me);

} IEcoPKCS11WTLSRandomDataVTbl, * IEcoPKCS11WTLSRandomDataVTblPtr_t;

interface IEcoPKCS11WTLSRandomData {
    struct IEcoPKCS11WTLSRandomDataVTbl* pVTbl;
} IEcoPKCS11WTLSRandomData;

typedef struct IEcoPKCS11WTLSMasterKeyDeriveParams* IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t;

typedef struct IEcoPKCS11WTLSMasterKeyDeriveParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me);

    /* IEcoPKCS11WTLSMasterKeyDeriveParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* DigestMechanism)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me);
    IEcoPKCS11WTLSRandomDataPtr_t(ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pVersion)(/* in */ IEcoPKCS11WTLSMasterKeyDeriveParamsPtr_t me);

} IEcoPKCS11WTLSMasterKeyDeriveParamsVTbl, * IEcoPKCS11WTLSMasterKeyDeriveParamsVTblPtr_t;

interface IEcoPKCS11WTLSMasterKeyDeriveParams {
    struct IEcoPKCS11WTLSMasterKeyDeriveParamsVTbl* pVTbl;
} IEcoPKCS11WTLSMasterKeyDeriveParams;

typedef struct IEcoPKCS11WTLSPrfParams* IEcoPKCS11WTLSPrfParamsPtr_t;

typedef struct IEcoPKCS11WTLSPrfParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);

    /* IEcoPKCS11WTLSPrfParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* DigestMechanism)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSeed)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSeedLen)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pLabel)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulLabelLen)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOutput)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);
    IEcoPKCS11ULONG_PTR* (ECOCALLMETHOD* pulOutputLen)(/* in */ IEcoPKCS11WTLSPrfParamsPtr_t me);

} IEcoPKCS11WTLSPrfParamsVTbl, * IEcoPKCS11WTLSPrfParamsVTblPtr_t;

interface IEcoPKCS11WTLSPrfParams {
    struct IEcoPKCS11WTLSPrfParamsVTbl* pVTbl;
} IEcoPKCS11WTLSPrfParams;

typedef struct IEcoPKCS11WTLSKeyMatOut* IEcoPKCS11WTLSKeyMatOutPtr_t;

typedef struct IEcoPKCS11WTLSKeyMatOutVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me);

    /* IEcoPKCS11WTLSKeyMatOut */
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hMacSecret)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hKey)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIV)(/* in */ IEcoPKCS11WTLSKeyMatOutPtr_t me);

} IEcoPKCS11WTLSKeyMatOutVTbl, * IEcoPKCS11WTLSKeyMatOutVTblPtr_t;

interface IEcoPKCS11WTLSKeyMatOut {
    struct IEcoPKCS11WTLSKeyMatOutVTbl* pVTbl;
} IEcoPKCS11WTLSKeyMatOut;

typedef struct IEcoPKCS11WTLSKeyMatParams* IEcoPKCS11WTLSKeyMatParamsPtr_t;

typedef struct IEcoPKCS11WTLSKeyMatParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);

    /* IEcoPKCS11WTLSKeyMatParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* DigestMechanism)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMacSizeInBits)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulKeySizeInBits)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIVSizeInBits)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSequenceNumber)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bIsExport)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11WTLSRandomData*(ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);
    IEcoPKCS11WTLSKeyMatOut* (ECOCALLMETHOD* pReturnedKeyMaterial)(/* in */ IEcoPKCS11WTLSKeyMatParamsPtr_t me);

} IEcoPKCS11WTLSKeyMatParamsVTbl, * IEcoPKCS11WTLSKeyMatParamsVTblPtr_t;

interface IEcoPKCS11WTLSKeyMatParams {
    struct IEcoPKCS11WTLSKeyMatParamsVTbl* pVTbl;
} IEcoPKCS11WTLSKeyMatParams;

typedef struct IEcoPKCS11CMSSigParams* IEcoPKCS11CMSSigParamsPtr_t;

typedef struct IEcoPKCS11CMSSigParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);

    /* IEcoPKCS11CMSSigParams */
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* certificateHandle)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11Mechanism_PTR* (ECOCALLMETHOD* pSigningMechanism)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11Mechanism_PTR* (ECOCALLMETHOD* pDigestMechanism)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11UTF8CHAR_PTR* (ECOCALLMETHOD* pContentType)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pRequestedAttributes)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRequestedAttributesLen)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pRequiredAttributes)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulRequiredAttributesLen)(/* in */ IEcoPKCS11CMSSigParamsPtr_t me);

} IEcoPKCS11CMSSigParamsVTbl, * IEcoPKCS11CMSSigParamsVTblPtr_t;

interface IEcoPKCS11CMSSigParams {
    struct IEcoPKCS11CMSSigParamsVTbl* pVTbl;
} IEcoPKCS11CMSSigParams;

typedef struct IEcoPKCS11KeyDerivationStringData* IEcoPKCS11KeyDerivationStringDataPtr_t;

typedef struct IEcoPKCS11KeyDerivationStringDataVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11KeyDerivationStringDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11KeyDerivationStringDataPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11KeyDerivationStringDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11KeyDerivationStringDataPtr_t me);

    /* IEcoPKCS11KeyDerivationStringData */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pData)(/* in */ IEcoPKCS11KeyDerivationStringDataPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulLen)(/* in */ IEcoPKCS11KeyDerivationStringDataPtr_t me);

} IEcoPKCS11KeyDerivationStringDataVTbl, * IEcoPKCS11KeyDerivationStringDataVTblPtr_t;

interface IEcoPKCS11KeyDerivationStringData {
    struct IEcoPKCS11KeyDerivationStringDataVTbl* pVTbl;
} IEcoPKCS11KeyDerivationStringData;

typedef struct IEcoPKCS11PKCS5PBKD2Params* IEcoPKCS11PKCS5PBKD2ParamsPtr_t;

typedef struct IEcoPKCS11PKCS5PBKD2ParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);

    /* IEcoPKCS11PKCS5PBKD2Params */
    IEcoPKCS11PKCS5PBKDF2SALTSourceType* (ECOCALLMETHOD* saltSource)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pSaltSourceData)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSaltSourceDataLen)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* iterations)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11PKCS5PBKD2PseudoRandomFunctionType* (ECOCALLMETHOD* prf)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pPrfData)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPrfDataLen)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11UTF8CHAR_PTR* (ECOCALLMETHOD* pPassword)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);
    IEcoPKCS11ULONG_PTR* (ECOCALLMETHOD* ulPasswordLen)(/* in */ IEcoPKCS11PKCS5PBKD2ParamsPtr_t me);

} IEcoPKCS11PKCS5PBKD2ParamsVTbl, * IEcoPKCS11PKCS5PBKD2ParamsVTblPtr_t;

interface IEcoPKCS11PKCS5PBKD2Params {
    struct IEcoPKCS11PKCS5PBKD2ParamsVTbl* pVTbl;
} IEcoPKCS11PKCS5PBKD2Params;

typedef struct IEcoPKCS11PKCS5PBKD2Params2* IEcoPKCS11PKCS5PBKD2Params2Ptr_t;

typedef struct IEcoPKCS11PKCS5PBKD2Params2VTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);

    /* IEcoPKCS11PKCS5PBKD2Params2 */
    IEcoPKCS11PKCS5PBKDF2SALTSourceType* (ECOCALLMETHOD* saltSource)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pSaltSourceData)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSaltSourceDataLen)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* iterations)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11PKCS5PBKD2PseudoRandomFunctionType* (ECOCALLMETHOD* prf)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pPrfData)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPrfDataLen)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11UTF8CHAR_PTR* (ECOCALLMETHOD* pPassword)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPasswordLen)(/* in */ IEcoPKCS11PKCS5PBKD2Params2Ptr_t me);

} IEcoPKCS11PKCS5PBKD2Params2VTbl, * IEcoPKCS11PKCS5PBKD2Params2VTblPtr_t;

interface IEcoPKCS11PKCS5PBKD2Params2 {
    struct IEcoPKCS11PKCS5PBKD2Params2VTbl* pVTbl;
} IEcoPKCS11PKCS5PBKD2Params2;

typedef struct IEcoPKCS11OTPParam* IEcoPKCS11OTPParamPtr_t;

typedef struct IEcoPKCS11OTPParamVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11OTPParamPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11OTPParamPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11OTPParamPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11OTPParamPtr_t me);

    /* IEcoPKCS11OTPParam */
    IEcoPKCS11OTPParamType* (ECOCALLMETHOD* type)(/* in */ IEcoPKCS11OTPParamPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pValue)(/* in */ IEcoPKCS11OTPParamPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulValueLen)(/* in */ IEcoPKCS11OTPParamPtr_t me);

} IEcoPKCS11OTPParamVTbl, * IEcoPKCS11OTPParamVTblPtr_t;

interface IEcoPKCS11OTPParam {
    struct IEcoPKCS11OTPParamVTbl* pVTbl;
} IEcoPKCS11OTPParam;

typedef struct IEcoPKCS11OTPParams* IEcoPKCS11OTPParamsPtr_t;

typedef struct IEcoPKCS11OTPParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11OTPParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11OTPParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11OTPParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11OTPParamsPtr_t me);

    /* IEcoPKCS11OTPParams */
    IEcoPKCS11OTPParam* (ECOCALLMETHOD* pParams)(/* in */ IEcoPKCS11OTPParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulCount)(/* in */ IEcoPKCS11OTPParamsPtr_t me);

} IEcoPKCS11OTPParamsVTbl, * IEcoPKCS11OTPParamsVTblPtr_t;

interface IEcoPKCS11OTPParams {
    struct IEcoPKCS11OTPParamsVTbl* pVTbl;
} IEcoPKCS11OTPParams;

typedef struct IEcoPKCS11OTPSignatureInfo* IEcoPKCS11OTPSignatureInfoPtr_t;

typedef struct IEcoPKCS11OTPSignatureInfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11OTPSignatureInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11OTPSignatureInfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11OTPSignatureInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11OTPSignatureInfoPtr_t me);

    /* IEcoPKCS11OTPSignatureInfo */
    IEcoPKCS11OTPParam* (ECOCALLMETHOD* pParams)(/* in */ IEcoPKCS11OTPSignatureInfoPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulCount)(/* in */ IEcoPKCS11OTPSignatureInfoPtr_t me);

} IEcoPKCS11OTPSignatureInfoVTbl, * IEcoPKCS11OTPSignatureInfoVTblPtr_t;

interface IEcoPKCS11OTPSignatureInfo {
    struct IEcoPKCS11OTPSignatureInfoVTbl* pVTbl;
} IEcoPKCS11OTPSignatureInfo;

typedef struct IEcoPKCS11KIPParams* IEcoPKCS11KIPParamsPtr_t;

typedef struct IEcoPKCS11KIPParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11KIPParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11KIPParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11KIPParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11KIPParamsPtr_t me);

    /* IEcoPKCS11KIPParams */
    IEcoPKCS11Mechanism* (ECOCALLMETHOD* pMechanism)(/* in */ IEcoPKCS11KIPParamsPtr_t me);
    IEcoPKCS11ObjectHandle* (ECOCALLMETHOD* hKey)(/* in */ IEcoPKCS11KIPParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSeed)(/* in */ IEcoPKCS11KIPParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSeedLen)(/* in */ IEcoPKCS11KIPParamsPtr_t me);

} IEcoPKCS11KIPParamsVTbl, * IEcoPKCS11KIPParamsVTblPtr_t;

interface IEcoPKCS11KIPParams {
    struct IEcoPKCS11KIPParamsVTbl* pVTbl;
} IEcoPKCS11KIPParams;

typedef struct IEcoPKCS11AESCTRParams* IEcoPKCS11AESCTRParamsPtr_t;

typedef struct IEcoPKCS11AESCTRParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11AESCTRParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11AESCTRParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11AESCTRParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11AESCTRParamsPtr_t me);

    /* IEcoPKCS11AESCTRParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulCounterBits)(/* in */ IEcoPKCS11AESCTRParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* cb)(/* in */ IEcoPKCS11AESCTRParamsPtr_t me);

} IEcoPKCS11AESCTRParamsVTbl, * IEcoPKCS11AESCTRParamsVTblPtr_t;

interface IEcoPKCS11AESCTRParams {
    struct IEcoPKCS11AESCTRParamsVTbl* pVTbl;
} IEcoPKCS11AESCTRParams;

typedef struct IEcoPKCS11GCMParams* IEcoPKCS11GCMParamsPtr_t;

typedef struct IEcoPKCS11GCMParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11GCMParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11GCMParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11GCMParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11GCMParamsPtr_t me);

    /* IEcoPKCS11GCMParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIv)(/* in */ IEcoPKCS11GCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvLen)(/* in */ IEcoPKCS11GCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvBits)(/* in */ IEcoPKCS11GCMParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pAAD)(/* in */ IEcoPKCS11GCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAADLen)(/* in */ IEcoPKCS11GCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulTagBits)(/* in */ IEcoPKCS11GCMParamsPtr_t me);

} IEcoPKCS11GCMParamsVTbl, * IEcoPKCS11GCMParamsVTblPtr_t;

interface IEcoPKCS11GCMParams {
    struct IEcoPKCS11GCMParamsVTbl* pVTbl;
} IEcoPKCS11GCMParams;

typedef struct IEcoPKCS11GCMMessageParams* IEcoPKCS11GCMMessageParamsPtr_t;

typedef struct IEcoPKCS11GCMMessageParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);

    /* IEcoPKCS11GCMMessageParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIv)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvLen)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvFixedBits)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);
    IEcoPKCS11GeneratorFunction* (ECOCALLMETHOD* ivGenerator)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pTag)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulTagBits)(/* in */ IEcoPKCS11GCMMessageParamsPtr_t me);

} IEcoPKCS11GCMMessageParamsVTbl, * IEcoPKCS11GCMMessageParamsVTblPtr_t;

interface IEcoPKCS11GCMMessageParams {
    struct IEcoPKCS11GCMMessageParamsVTbl* pVTbl;
} IEcoPKCS11GCMMessageParams;

typedef struct IEcoPKCS11CCMParams* IEcoPKCS11CCMParamsPtr_t;

typedef struct IEcoPKCS11CCMParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11CCMParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11CCMParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11CCMParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11CCMParamsPtr_t me);

    /* IEcoPKCS11CCMParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulDataLen)(/* in */ IEcoPKCS11CCMParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11CCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceLen)(/* in */ IEcoPKCS11CCMParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pAAD)(/* in */ IEcoPKCS11CCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAADLen)(/* in */ IEcoPKCS11CCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMACLen)(/* in */ IEcoPKCS11CCMParamsPtr_t me);

} IEcoPKCS11CCMParamsVTbl, * IEcoPKCS11CCMParamsVTblPtr_t;

interface IEcoPKCS11CCMParams {
    struct IEcoPKCS11CCMParamsVTbl* pVTbl;
} IEcoPKCS11CCMParams;

typedef struct IEcoPKCS11CCMMessageParams* IEcoPKCS11CCMMessageParamsPtr_t;

typedef struct IEcoPKCS11CCMMessageParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);

    /* IEcoPKCS11CCMMessageParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulDataLen)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceLen)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceFixedBits)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    IEcoPKCS11GeneratorFunction* (ECOCALLMETHOD* nonceGenerator)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pMAC)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMACLen)(/* in */ IEcoPKCS11CCMMessageParamsPtr_t me);

} IEcoPKCS11CCMMessageParamsVTbl, * IEcoPKCS11CCMMessageParamsVTblPtr_t;

interface IEcoPKCS11CCMMessageParams {
    struct IEcoPKCS11CCMMessageParamsVTbl* pVTbl;
} IEcoPKCS11CCMMessageParams;

typedef struct IEcoPKCS11AESGCMParams* IEcoPKCS11AESGCMParamsPtr_t;

typedef struct IEcoPKCS11AESGCMParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);

    /* IEcoPKCS11AESGCMParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIv)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvLen)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIvBits)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pAAD)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAADLen)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulTagBits)(/* in */ IEcoPKCS11AESGCMParamsPtr_t me);

} IEcoPKCS11AESGCMParamsVTbl, * IEcoPKCS11AESGCMParamsVTblPtr_t;

interface IEcoPKCS11AESGCMParams {
    struct IEcoPKCS11AESGCMParamsVTbl* pVTbl;
} IEcoPKCS11AESGCMParams;

typedef struct IEcoPKCS11AESCCMParams* IEcoPKCS11AESCCMParamsPtr_t;

typedef struct IEcoPKCS11AESCCMParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);

    /* IEcoPKCS11AESCCMParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulDataLen)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceLen)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pAAD)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAADLen)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMACLen)(/* in */ IEcoPKCS11AESCCMParamsPtr_t me);

} IEcoPKCS11AESCCMParamsVTbl, * IEcoPKCS11AESCCMParamsVTblPtr_t;

interface IEcoPKCS11AESCCMParams {
    struct IEcoPKCS11AESCCMParamsVTbl* pVTbl;
} IEcoPKCS11AESCCMParams;

typedef struct IEcoPKCS11CamelliaCTRParams* IEcoPKCS11CamelliaCTRParamsPtr_t;

typedef struct IEcoPKCS11CamelliaCTRParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11CamelliaCTRParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11CamelliaCTRParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11CamelliaCTRParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11CamelliaCTRParamsPtr_t me);

    /* IEcoPKCS11CamelliaCTRParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulCounterBits)(/* in */ IEcoPKCS11CamelliaCTRParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* cb)(/* in */ IEcoPKCS11CamelliaCTRParamsPtr_t me);

} IEcoPKCS11CamelliaCTRParamsVTbl, * IEcoPKCS11CamelliaCTRParamsVTblPtr_t;

interface IEcoPKCS11CamelliaCTRParams {
    struct IEcoPKCS11CamelliaCTRParamsVTbl* pVTbl;
} IEcoPKCS11CamelliaCTRParams;

typedef struct IEcoPKCS11AriaCBCEncryptDataParams* IEcoPKCS11AriaCBCEncryptDataParamsPtr_t;

typedef struct IEcoPKCS11AriaCBCEncryptDataParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me);

    /* IEcoPKCS11AriaCBCEncryptDataParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* iv)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pData)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* length)(/* in */ IEcoPKCS11AriaCBCEncryptDataParamsPtr_t me);

} IEcoPKCS11AriaCBCEncryptDataParamsVTbl, * IEcoPKCS11AriaCBCEncryptDataParamsVTblPtr_t;

interface IEcoPKCS11AriaCBCEncryptDataParams {
    struct IEcoPKCS11AriaCBCEncryptDataParamsVTbl* pVTbl;
} IEcoPKCS11AriaCBCEncryptDataParams;

typedef struct IEcoPKCS11DSAParameterGenParam* IEcoPKCS11DSAParameterGenParamPtr_t;

typedef struct IEcoPKCS11DSAParameterGenParamVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);

    /* IEcoPKCS11DSAParameterGenParam */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* hash)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSeed)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSeedLen)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIndex)(/* in */ IEcoPKCS11DSAParameterGenParamPtr_t me);

} IEcoPKCS11DSAParameterGenParamVTbl, * IEcoPKCS11DSAParameterGenParamVTblPtr_t;

interface IEcoPKCS11DSAParameterGenParam {
    struct IEcoPKCS11DSAParameterGenParamVTbl* pVTbl;
} IEcoPKCS11DSAParameterGenParam;

typedef struct IEcoPKCS11ECDHAESKeyWrapParams* IEcoPKCS11ECDHAESKeyWrapParamsPtr_t;

typedef struct IEcoPKCS11ECDHAESKeyWrapParamsVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);

    /* IEcoPKCS11ECDHAESKeyWrapParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAESKeyBits)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);
    IEcoPKCS11EC_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSharedDataLen)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSharedData)(/* in */ IEcoPKCS11ECDHAESKeyWrapParamsPtr_t me);

} IEcoPKCS11ECDHAESKeyWrapParamsVTbl, * IEcoPKCS11ECDHAESKeyWrapParamsVTblPtr_t;

interface IEcoPKCS11ECDHAESKeyWrapParams {
    struct IEcoPKCS11ECDHAESKeyWrapParamsVTbl* pVTbl;
} IEcoPKCS11ECDHAESKeyWrapParams;

typedef struct IEcoPKCS11RSAAESKeyWrapParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11RSAAESKeyWrapParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11RSAAESKeyWrapParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11RSAAESKeyWrapParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11RSAAESKeyWrapParamsPtr_t me);

    /* IEcoPKCS11RSAAESKeyWrapParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAESKeyBits)(/* in */ IEcoPKCS11RSAAESKeyWrapParamsPtr_t me);
    IEcoPKCS11RSA_PKCS_OAEP_PARAMS_PTR* (ECOCALLMETHOD* pOAEPParams)(/* in */ IEcoPKCS11RSAAESKeyWrapParamsPtr_t me);

} IEcoPKCS11RSAAESKeyWrapParamsVTbl, * IEcoPKCS11RSAAESKeyWrapParamsVTblPtr_t;

interface IEcoPKCS11RSAAESKeyWrapParams {
    struct IEcoPKCS11RSAAESKeyWrapParamsVTbl* pVTbl;
} IEcoPKCS11RSAAESKeyWrapParams;

typedef struct IEcoPKCS11TLS12MasterKeyDeriveParams* IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t;

typedef struct IEcoPKCS11TLS12MasterKeyDeriveParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me);

    /* IEcoPKCS11TLS12MasterKeyDeriveParams */
    IEcoPKCS11SSL3_RANDOM_DATA_PTR* (ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me);
    IEcoPKCS11Version_PTR* (ECOCALLMETHOD* pVersion)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me);
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfHashMechanism)(/* in */ IEcoPKCS11TLS12MasterKeyDeriveParamsPtr_t me);

} IEcoPKCS11TLS12MasterKeyDeriveParamsVTbl, * IEcoPKCS11TLS12MasterKeyDeriveParamsVTblPtr_t;

interface IEcoPKCS11TLS12MasterKeyDeriveParams {
    struct IEcoPKCS11TLS12MasterKeyDeriveParamsVTbl* pVTbl;
} IEcoPKCS11TLS12MasterKeyDeriveParams;

typedef struct IEcoPKCS11TLS12KeyMatParams* IEcoPKCS11TLS12KeyMatParamsPtr_t;

typedef struct IEcoPKCS11TLS12KeyMatParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);

    /* IEcoPKCS11TLS12KeyMatParams */
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMacSizeInBits)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulKeySizeInBits)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIVSizeInBits)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bIsExport)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    IEcoPKCS11SSL3_RANDOM_DATA_PTR* (ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    IEcoPKCS11SSL3_KEY_MAT_OUT_PTR* (ECOCALLMETHOD* pReturnedKeyMaterial)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfHashMechanism)(/* in */ IEcoPKCS11TLS12KeyMatParamsPtr_t me);

} IEcoPKCS11TLS12KeyMatParamsVTbl, * IEcoPKCS11TLS12KeyMatParamsVTblPtr_t;

typedef struct IEcoPKCS11TLSKDFParams* IEcoPKCS11TLSKDFParamsPtr_t;

typedef struct IEcoPKCS11TLSKDFParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);

    /* IEcoPKCS11TLSKDFParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfMechanism)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pLabel)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulLabelLength)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);
    IEcoPKCS11SSL3_RANDOM_DATA_PTR* (ECOCALLMETHOD* RandomInfo)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pContextData)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulContextDataLength)(/* in */ IEcoPKCS11TLSKDFParamsPtr_t me);

} IEcoPKCS11TLSKDFParamsVTbl, * IEcoPKCS11TLSKDFParamsVTblPtr_t;

interface IEcoPKCS11TLSKDFParams {
    struct IEcoPKCS11TLSKDFParamsVTbl* pVTbl;
} IEcoPKCS11TLSKDFParams;

typedef struct IEcoPKCS11TLSMacParams* IEcoPKCS11TLSMacParamsPtr_t;

typedef struct IEcoPKCS11TLSMacParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me);

    /* IEcoPKCS11TLSMacParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfHashMechanism)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulMacLength)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulServerOrClient)(/* in */ IEcoPKCS11TLSMacParamsPtr_t me);
} IEcoPKCS11TLSMacParamsVTbl, * IEcoPKCS11TLSMacParamsVTblPtr_t;

interface IEcoPKCS11TLSMacParams {
    struct IEcoPKCS11TLSMacParamsVTbl* pVTbl;
} IEcoPKCS11TLSMacParams;

typedef struct IEcoPKCS11GOSTR3410DeriveParams* IEcoPKCS11GOSTR3410DeriveParamsPtr_t;

typedef struct IEcoPKCS11GOSTR3410DeriveParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);

    /* IEcoPKCS11GOSTR3410DeriveParams */
    IEcoPKCS11EC_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPublicData)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulPublicDataLen)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pUKM)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulUKMLen)(/* in */ IEcoPKCS11GOSTR3410DeriveParamsPtr_t me);
} IEcoPKCS11GOSTR3410DeriveParamsVTbl, * IEcoPKCS11GOSTR3410DeriveParamsVTblPtr_t;

interface IEcoPKCS11GOSTR3410DeriveParams {
    struct IEcoPKCS11GOSTR3410DeriveParamsVTbl* pVTbl;
} IEcoPKCS11GOSTR3410DeriveParams;

typedef struct IEcoPKCS11GOSTR3410KeyWrapParams* IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t;

typedef struct IEcoPKCS11GOSTR3410KeyWrapParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);

    /* IEcoPKCS11GOSTR3410KeyWrapParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pWrapOID)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulWrapOIDLen)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pUKM)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulUKMLen)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hKey)(/* in */ IEcoPKCS11GOSTR3410KeyWrapParamsPtr_t me);
} IEcoPKCS11GOSTR3410KeyWrapParamsVTbl, * IEcoPKCS11GOSTR3410KeyWrapParamsVTblPtr_t;

interface IEcoPKCS11GOSTR3410KeyWrapParams {
    struct IEcoPKCS11GOSTR3410KeyWrapParamsVTbl* pVTbl;
} IEcoPKCS11GOSTR3410KeyWrapParams;

typedef struct IEcoPKCS11SEEDCBCEncryptDataParams* IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t;

typedef struct IEcoPKCS11SEEDCBCEncryptDataParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me);

    /* IEcoPKCS11SEEDCBCEncryptDataParams */
    IEcoPKCS11BYTE* (ECOCALLMETHOD* iv)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pData)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* length)(/* in */ IEcoPKCS11SEEDCBCEncryptDataParamsPtr_t me);
} IEcoPKCS11SEEDCBCEncryptDataParamsVTbl, * IEcoPKCS11SEEDCBCEncryptDataParamsVTblPtr_t;

interface IEcoPKCS11SEEDCBCEncryptDataParams {
    struct IEcoPKCS11SEEDCBCEncryptDataParamsVTbl* pVTbl;
} IEcoPKCS11SEEDCBCEncryptDataParams;

typedef struct IEcoPKCS11PRFDataParam* IEcoPKCS11PRFDataParamPtr_t;

typedef struct IEcoPKCS11PRFDataParamVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11PRFDataParamPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11PRFDataParamPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11PRFDataParamPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11PRFDataParamPtr_t me);

    /* IEcoPKCS11PRFDataParam */
    IEcoPKCS11PRF_DATA_TYPE* (ECOCALLMETHOD* type)(/* in */ IEcoPKCS11PRFDataParamPtr_t me);
    IEcoPKCS11VOID_PTR* (ECOCALLMETHOD* pValue)(/* in */ IEcoPKCS11PRFDataParamPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulValueLen)(/* in */ IEcoPKCS11PRFDataParamPtr_t me);
} IEcoPKCS11PRFDataParamVTbl, * IEcoPKCS11PRFDataParamVTblPtr_t;

interface IEcoPKCS11PRFDataParam {
    struct IEcoPKCS11PRFDataParamVTbl* pVTbl;
} IEcoPKCS11PRFDataParam;

typedef struct IEcoPKCS11SP800108CounterFormat* IEcoPKCS11SP800108CounterFormatPtr_t;

typedef struct IEcoPKCS11SP800108CounterFormatVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SP800108CounterFormatPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SP800108CounterFormatPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SP800108CounterFormatPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SP800108CounterFormatPtr_t me);

    /* IEcoPKCS11SP800108CounterFormat */
    IEcoPKCS11BBOOL* (ECOCALLMETHOD* bLittleEndian)(/* in */ IEcoPKCS11SP800108CounterFormatPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulWidthInBits)(/* in */ IEcoPKCS11SP800108CounterFormatPtr_t me);
} IEcoPKCS11SP800108CounterFormatVTbl, * IEcoPKCS11SP800108CounterFormatVTblPtr_t;

interface IEcoPKCS11SP800108CounterFormat {
    struct IEcoPKCS11SP800108CounterFormatVTbl* pVTbl;
} IEcoPKCS11SP800108CounterFormat;

typedef struct IEcoPKCS11SP800108DKMLengthFormat* IEcoPKCS11SP800108DKMLengthFormatPtr_t;

typedef struct IEcoPKCS11SP800108DKMLengthFormatVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me);

    /* IEcoPKCS11SP800108DKMLengthFormat */
    IEcoPKCS11SP800_108_DKM_LENGTH_METHOD* (ECOCALLMETHOD* dkmLengthMethod)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bLittleEndian)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulWidthInBits)(/* in */ IEcoPKCS11SP800108DKMLengthFormatPtr_t me);
} IEcoPKCS11SP800108DKMLengthFormatVTbl, * IEcoPKCS11SP800108DKMLengthFormatVTblPtr_t;

interface IEcoPKCS11SP800108DKMLengthFormat {
    struct IEcoPKCS11SP800108DKMLengthFormatVTbl* pVTbl;
} IEcoPKCS11SP800108DKMLengthFormat;

typedef struct IEcoPKCS11DerivedKey* IEcoPKCS11DerivedKeyPtr_t;

typedef struct IEcoPKCS11DerivedKeyVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11DerivedKeyPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11DerivedKeyPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11DerivedKeyPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11DerivedKeyPtr_t me);

    /* IEcoPKCS11DerivedKey */
    IEcoPKCS11Attribute_PTR* (ECOCALLMETHOD* pTemplate)(/* in */ IEcoPKCS11DerivedKeyPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAttributeCount)(/* in */ IEcoPKCS11DerivedKeyPtr_t me);
    IEcoPKCS11OBJECT_HANDLE_PTR* (ECOCALLMETHOD* phKey)(/* in */ IEcoPKCS11DerivedKeyPtr_t me);
} IEcoPKCS11DerivedKeyVTbl, * IEcoPKCS11DerivedKeyVTblPtr_t;

interface IEcoPKCS11DerivedKey {
    struct IEcoPKCS11DerivedKeyVTbl* pVTbl;
} IEcoPKCS11DerivedKey;

typedef struct IEcoPKCS11SP800108KDFParams* IEcoPKCS11SP800108KDFParamsPtr_t;

typedef struct IEcoPKCS11SP800108KDFParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);

    /* IEcoPKCS11SP800108KDFParams */
    IEcoPKCS11SP800_108_PRF_TYPE* (ECOCALLMETHOD* prfType)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNumberOfDataParams)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);
    IEcoPKCS11PRF_DATA_PARAM_PTR* (ECOCALLMETHOD* pDataParams)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAdditionalDerivedKeys)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);
    IEcoPKCS11DERIVED_KEY_PTR* (ECOCALLMETHOD* pAdditionalDerivedKeys)(/* in */ IEcoPKCS11SP800108KDFParamsPtr_t me);
} IEcoPKCS11SP800108KDFParamsVTbl, * IEcoPKCS11SP800108KDFParamsVTblPtr_t;

interface IEcoPKCS11SP800108KDFParams {
    struct IEcoPKCS11SP800108KDFParamsVTbl* pVTbl;
} IEcoPKCS11SP800108KDFParams;

typedef struct IEcoPKCS11SP800108FeedbackKDFParams* IEcoPKCS11SP800108FeedbackKDFParamsPtr_t;

typedef struct IEcoPKCS11SP800108FeedbackKDFParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);

    /* IEcoPKCS11SP800108FeedbackKDFParams */
    IEcoPKCS11SP800_108_PRF_TYPE* (ECOCALLMETHOD* prfType)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNumberOfDataParams)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    IEcoPKCS11PRF_DATA_PARAM_PTR* (ECOCALLMETHOD* pDataParams)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulIVLen)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIV)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAdditionalDerivedKeys)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
    IEcoPKCS11DERIVED_KEY_PTR* (ECOCALLMETHOD* pAdditionalDerivedKeys)(/* in */ IEcoPKCS11SP800108FeedbackKDFParamsPtr_t me);
} IEcoPKCS11SP800108FeedbackKDFParamsVTbl, * IEcoPKCS11SP800108FeedbackKDFParamsVTblPtr_t;

interface IEcoPKCS11SP800108FeedbackKDFParams {
    struct IEcoPKCS11SP800108FeedbackKDFParamsVTbl* pVTbl;
} IEcoPKCS11SP800108FeedbackKDFParams;

typedef struct IEcoPKCS11EDDSAParams* IEcoPKCS11EDDSAParamsPtr_t;

typedef struct IEcoPKCS11EDDSAParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me);

    /* IEcoPKCS11EDDSAParams */
    IEcoPKCS11BOOL* (ECOCALLMETHOD* phFlag)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulContextDataLen)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pContextData)(/* in */ IEcoPKCS11EDDSAParamsPtr_t me);
} IEcoPKCS11EDDSAParamsVTbl, * IEcoPKCS11EDDSAParamsVTblPtr_t;

interface IEcoPKCS11EDDSAParams {
    struct IEcoPKCS11EDDSAParamsVTbl* pVTbl;
} IEcoPKCS11EDDSAParams;

typedef struct IEcoPKCS11ChaCha20Params* IEcoPKCS11ChaCha20ParamsPtr_t;

typedef struct IEcoPKCS11ChaCha20ParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);

    /* IEcoPKCS11ChaCha20Params */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pBlockCounter)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* blockCounterBits)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceBits)(/* in */ IEcoPKCS11ChaCha20ParamsPtr_t me);
} IEcoPKCS11ChaCha20ParamsVTbl, * IEcoPKCS11ChaCha20ParamsVTblPtr_t;

interface IEcoPKCS11ChaCha20Params {
    struct IEcoPKCS11ChaCha20ParamsVTbl* pVTbl;
} IEcoPKCS11ChaCha20Params;

typedef struct IEcoPKCS11Salsa20Params* IEcoPKCS11Salsa20ParamsPtr_t;

typedef struct IEcoPKCS11Salsa20ParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me);

    /* IEcoPKCS11Salsa20Params */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pBlockCounter)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceBits)(/* in */ IEcoPKCS11Salsa20ParamsPtr_t me);
} IEcoPKCS11Salsa20ParamsVTbl, * IEcoPKCS11Salsa20ParamsVTblPtr_t;

interface IEcoPKCS11Salsa20Params {
    struct IEcoPKCS11Salsa20ParamsVTbl* pVTbl;
} IEcoPKCS11Salsa20Params;

typedef struct IEcoPKCS11Salsa20ChaCha20Poly1305Params* IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t;

typedef struct IEcoPKCS11Salsa20ChaCha20Poly1305ParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);

    /* IEcoPKCS11Salsa20ChaCha20Poly1305Params */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceLen)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pAAD)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulAADLen)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305ParamsPtr_t me);
} IEcoPKCS11Salsa20ChaCha20Poly1305ParamsVTbl, * IEcoPKCS11Salsa20ChaCha20Poly1305ParamsVTblPtr_t;

interface IEcoPKCS11Salsa20ChaCha20Poly1305Params {
    struct IEcoPKCS11Salsa20ChaCha20Poly1305ParamsVTbl* pVTbl;
} IEcoPKCS11Salsa20ChaCha20Poly1305Params;

typedef struct IEcoPKCS11Salsa20ChaCha20Poly1305MsgParams* IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t;

typedef struct IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me);

    /* IEcoPKCS11Salsa20ChaCha20Poly1305MsgParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNonce)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNonceLen)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pTag)(/* in */ IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsPtr_t me);
} IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsVTbl, * IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsVTblPtr_t;

interface IEcoPKCS11Salsa20ChaCha20Poly1305MsgParams {
    struct IEcoPKCS11Salsa20ChaCha20Poly1305MsgParamsVTbl* pVTbl;
} IEcoPKCS11Salsa20ChaCha20Poly1305MsgParams;

typedef struct IEcoPKCS11X3DHInitiateParams* IEcoPKCS11X3DHInitiateParamsPtr_t;

typedef struct IEcoPKCS11X3DHInitiateParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);

    /* IEcoPKCS11X3DHInitiateParams */
    IEcoPKCS11X3DH_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* pPeer_identity)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* pPeer_prekey)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPrekey_signature)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOnetime_key)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* pOwn_identity)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* pOwn_ephemeral)(/* in */ IEcoPKCS11X3DHInitiateParamsPtr_t me);
} IEcoPKCS11X3DHInitiateParamsVTbl, * IEcoPKCS11X3DHInitiateParamsVTblPtr_t;

interface IEcoPKCS11X3DHInitiateParams {
    struct IEcoPKCS11X3DHInitiateParamsVTbl* pVTbl;
} IEcoPKCS11X3DHInitiateParams;

typedef struct IEcoPKCS11X3DHRespondParams* IEcoPKCS11X3DHRespondParamsPtr_t;

typedef struct IEcoPKCS11X3DHRespondParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);

    /* IEcoPKCS11X3DHRespondParams */
    IEcoPKCS11X3DH_KDF_TYPE* (ECOCALLMETHOD* kdf)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pIdentity_id)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pPrekey_id)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pOnetime_id)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* pInitiator_identity)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pInitiator_ephemeral)(/* in */ IEcoPKCS11X3DHRespondParamsPtr_t me);
} IEcoPKCS11X3DHRespondParamsVTbl, * IEcoPKCS11X3DHRespondParamsVTblPtr_t;

interface IEcoPKCS11X3DHRespondParams {
    struct IEcoPKCS11X3DHRespondParamsVTbl* pVTbl;
} IEcoPKCS11X3DHRespondParams;

typedef struct IEcoPKCS11X2RatchetInitializeParams* IEcoPKCS11X2RatchetInitializeParamsPtr_t;

typedef struct IEcoPKCS11X2RatchetInitializeParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);

    /* IEcoPKCS11X2RatchetInitializeParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* sk)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* peer_public_prekey)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* peer_public_identity)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* own_public_identity)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bEncryptedHeader)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* eCurve)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* aeadMechanism)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
    IEcoPKCS11X2RATCHET_KDF_TYPE* (ECOCALLMETHOD* kdfMechanism)(/* in */ IEcoPKCS11X2RatchetInitializeParamsPtr_t me);
} IEcoPKCS11X2RatchetInitializeParamsVTbl, * IEcoPKCS11X2RatchetInitializeParamsVTblPtr_t;

interface IEcoPKCS11X2RatchetInitializeParams {
    struct IEcoPKCS11X2RatchetInitializeParamsVTbl* pVTbl;
} IEcoPKCS11X2RatchetInitializeParams;

typedef struct IEcoPKCS11X2RatchetRespondParams* IEcoPKCS11X2RatchetRespondParamsPtr_t;

typedef struct IEcoPKCS11X2RatchetRespondParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);

    /* IEcoPKCS11X2RatchetRespondParams */
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* sk)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* own_prekey)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* initiator_identity)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* own_public_identity)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bEncryptedHeader)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* eCurve)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* aeadMechanism)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
    IEcoPKCS11X2RATCHET_KDF_TYPE* (ECOCALLMETHOD* kdfMechanism)(/* in */ IEcoPKCS11X2RatchetRespondParamsPtr_t me);
} IEcoPKCS11X2RatchetRespondParamsVTbl, * IEcoPKCS11X2RatchetRespondParamsVTblPtr_t;

interface IEcoPKCS11X2RatchetRespondParams {
    struct IEcoPKCS11X2RatchetRespondParamsVTbl* pVTbl;
} IEcoPKCS11X2RatchetRespondParams;

typedef struct IEcoPKCS11XEdDSAParams* IEcoPKCS11XEdDSAParamsPtr_t;

typedef struct IEcoPKCS11XEdDSAParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11XEdDSAParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11XEdDSAParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11XEdDSAParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11XEdDSAParamsPtr_t me);

    /* IEcoPKCS11XEdDSAParams */
    IEcoPKCS11XEdDSA_HASH_TYPE* (ECOCALLMETHOD* hash)(/* in */ IEcoPKCS11XEdDSAParamsPtr_t me);
} IEcoPKCS11XEdDSAParamsVTbl, * IEcoPKCS11XEdDSAParamsVTblPtr_t;

interface IEcoPKCS11XEdDSAParams {
    struct IEcoPKCS11XEdDSAParamsVTbl* pVTbl;
} IEcoPKCS11XEdDSAParams;

typedef struct IEcoPKCS11HKDFParams* IEcoPKCS11HKDFParamsPtr_t;

typedef struct IEcoPKCS11HKDFParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11HKDFParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);

    /* IEcoPKCS11HKDFParams */
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bExtract)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bExpand)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfHashMechanism)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSaltType)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSalt)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSaltLen)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hSaltKey)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pInfo)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulInfoLen)(/* in */ IEcoPKCS11HKDFParamsPtr_t me);
} IEcoPKCS11HKDFParamsVTbl, * IEcoPKCS11HKDFParamsVTblPtr_t;

interface IEcoPKCS11HKDFParams {
    struct IEcoPKCS11HKDFParamsVTbl* pVTbl;
} IEcoPKCS11HKDFParams;

typedef struct IEcoPKCS11SpecifiedParams* IEcoPKCS11SpecifiedParamsPtr_t;

typedef struct IEcoPKCS11SpecifiedParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me);

    /* IEcoPKCS11SpecifiedParams */
    IEcoPKCS11HSS_LEVELS* (ECOCALLMETHOD* levels)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me);
    IEcoPKCS11LMS_TYPE* (ECOCALLMETHOD* lm_type)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me, int index);
    IEcoPKCS11LMOTS_TYPE* (ECOCALLMETHOD* lm_ots_type)(/* in */ IEcoPKCS11SpecifiedParamsPtr_t me, int index);
} IEcoPKCS11SpecifiedParamsVTbl, * IEcoPKCS11SpecifiedParamsVTblPtr_t;

interface IEcoPKCS11SpecifiedParams {
    struct IEcoPKCS11SpecifiedParamsVTbl* pVTbl;
} IEcoPKCS11SpecifiedParams;

typedef struct IEcoPKCS11IKE2PrfPlusDeriveParams* IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t;

typedef struct IEcoPKCS11IKE2PrfPlusDeriveParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);

    /* IEcoPKCS11IKE2PrfPlusDeriveParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfMechanism)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bHasSeedKey)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hSeedKey)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pSeedData)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulSeedDataLen)(/* in */ IEcoPKCS11IKE2PrfPlusDeriveParamsPtr_t me);
} IEcoPKCS11IKE2PrfPlusDeriveParamsVTbl, * IEcoPKCS11IKE2PrfPlusDeriveParamsVTblPtr_t;

interface IEcoPKCS11IKE2PrfPlusDeriveParams {
    struct IEcoPKCS11IKE2PrfPlusDeriveParamsVTbl* pVTbl;
} IEcoPKCS11IKE2PrfPlusDeriveParams;

typedef struct IEcoPKCS11IKEPrfDeriveParams* IEcoPKCS11IKEPrfDeriveParamsPtr_t;

typedef struct IEcoPKCS11IKEPrfDeriveParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);

    /* IEcoPKCS11IKEPrfDeriveParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfMechanism)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bDataAsKey)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bRekey)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNi)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNiLen)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pNr)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulNrLen)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hNewKey)(/* in */ IEcoPKCS11IKEPrfDeriveParamsPtr_t me);
} IEcoPKCS11IKEPrfDeriveParamsVTbl, * IEcoPKCS11IKEPrfDeriveParamsVTblPtr_t;

interface IEcoPKCS11IKEPrfDeriveParams {
    struct IEcoPKCS11IKEPrfDeriveParamsVTbl* pVTbl;
} IEcoPKCS11IKEPrfDeriveParams;

typedef struct IEcoPKCS11IKE1PrfDeriveParams* IEcoPKCS11IKE1PrfDeriveParamsPtr_t;

typedef struct IEcoPKCS11IKE1PrfDeriveParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);

    /* IEcoPKCS11IKE1PrfDeriveParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfMechanism)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bHasPrevKey)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hKeygxy)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hPrevKey)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pCKYi)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulCKYiLen)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pCKYr)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulCKYrLen)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
    IEcoPKCS11BYTE* (ECOCALLMETHOD* keyNumber)(/* in */ IEcoPKCS11IKE1PrfDeriveParamsPtr_t me);
} IEcoPKCS11IKE1PrfDeriveParamsVTbl, * IEcoPKCS11IKE1PrfDeriveParamsVTblPtr_t;

interface IEcoPKCS11IKE1PrfDeriveParams {
    struct IEcoPKCS11IKE1PrfDeriveParamsVTbl* pVTbl;
} IEcoPKCS11IKE1PrfDeriveParams;

typedef struct IEcoPKCS11IKE1ExtendedDeriveParams* IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t;

typedef struct IEcoPKCS11IKE1ExtendedDeriveParamsVTbl {
    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);

    /* IEcoPKCS11IKE1ExtendedDeriveParams */
    IEcoPKCS11Mechanism_TYPE* (ECOCALLMETHOD* prfMechanism)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);
    IEcoPKCS11BOOL* (ECOCALLMETHOD* bHasKeygxy)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);
    IEcoPKCS11OBJECT_HANDLE* (ECOCALLMETHOD* hKeygxy)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);
    IEcoPKCS11BYTE_PTR* (ECOCALLMETHOD* pExtraData)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);
    IEcoPKCS11ULONG* (ECOCALLMETHOD* ulExtraDataLen)(/* in */ IEcoPKCS11IKE1ExtendedDeriveParamsPtr_t me);
} IEcoPKCS11IKE1ExtendedDeriveParamsVTbl, * IEcoPKCS11IKE1ExtendedDeriveParamsVTblPtr_t;

interface IEcoPKCS11IKE1ExtendedDeriveParams {
    struct IEcoPKCS11IKE1ExtendedDeriveParamsVTbl* pVTbl;
} IEcoPKCS11IKE1ExtendedDeriveParams;


#endif /* __I_ECOPKCS11_H__ */
