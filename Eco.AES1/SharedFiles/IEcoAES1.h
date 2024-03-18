/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoAES1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_AES_1_H__
#define __I_ECO_AES_1_H__

#include "IEcoBase1.h"

typedef uint8_t state_t[4][4];

/* AES Key size (algorithm) */
#define ECO_KEY_SIZE_AES_128    0x0080                  /* Cipher key with length of 128 bits */
#define ECO_KEY_SIZE_AES_192    0x00C0                  /* Cipher key with length of 192 bits */
#define ECO_KEY_SIZE_AES_256    0x0100                  /* Cipher key with length of 256 bits */

/* AES modes */
#define ECO_MODE_AES_DEFAULT    0x00
#define ECO_MODE_AES_ECB        ECO_MODE_AES_DEFAULT    /* Electronic Codebook (ECB) mode */
#define ECO_MODE_AES_CBC        0x01                    /* Cipher Block Chaining (CBC) mode */
#define ECO_MODE_AES_CTR        0x02                    /* Counter (CTR) mode */
#define ECO_MODE_AES_CTS        0x03                    /* Cipher Text Stealing (CTS) mode */
#define ECO_MODE_AES_OFB        0x04                    /* Output Feedback (OFB) mode */
#define ECO_MODE_AES_CFB        0x05                    /* Cipher Feedback (CFB) mode */


/* IEcoAES1 IID = {84F33CD4-6FEC-4788-B062-F86A7D65BC4B} */
#ifndef __IID_IEcoAES1
static const UGUID IID_IEcoAES1 = {0x01, 0x10, {0x84, 0xF3, 0x3C, 0xD4, 0x6F, 0xEC, 0x47, 0x88, 0xB0, 0x62, 0xF8, 0x6A, 0x7D, 0x65, 0xBC, 0x4B}};
#endif /* __IID_IEcoAES1 */

typedef struct IEcoAES1* IEcoAES1Ptr_t;

typedef struct IEcoAES1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoAES1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoAES1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoAES1Ptr_t me);

    /* IEcoAES1 */
    uint32_t (ECOCALLMETHOD *get_KeySize)(/* in */ IEcoAES1Ptr_t me);
    void (ECOCALLMETHOD *set_KeySize)(/* in */ IEcoAES1Ptr_t me, /* in */ uint32_t keySize);
    uint32_t (ECOCALLMETHOD *get_BlockSize)(/* in */ IEcoAES1Ptr_t me);
    void (ECOCALLMETHOD *set_BlockSize)(/* in */ IEcoAES1Ptr_t me, /* in */ uint32_t blockSize);
    uint8_t (ECOCALLMETHOD *get_Mode)(/* in */ IEcoAES1Ptr_t me);
    void (ECOCALLMETHOD *set_Mode)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t mode);
    uint8_t (ECOCALLMETHOD *get_Padding)(/* in */ IEcoAES1Ptr_t me);
    void (ECOCALLMETHOD *set_Padding)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t paddingMode);
    uint8_t* (ECOCALLMETHOD *get_Key)(/* in */ IEcoAES1Ptr_t me);
    void (ECOCALLMETHOD *set_Key)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* key);
    uint8_t* (ECOCALLMETHOD *get_IV)(/* in */ IEcoAES1Ptr_t me);
    void (ECOCALLMETHOD *set_IV)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* iv);

    int16_t (ECOCALLMETHOD *Encrypt)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* input, /* out */ uint8_t** output);
    int16_t (ECOCALLMETHOD *Decrypt)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* input, /* out */ uint8_t** output);
    int16_t (ECOCALLMETHOD *GenerateKey)(/* in */ IEcoAES1Ptr_t me, /* out */ uint8_t** key, /* out */ uint8_t* keySize);
    int16_t (ECOCALLMETHOD *GenerateIV)(/* in */ IEcoAES1Ptr_t me, /* out */ uint8_t** iv, /* out */ uint8_t* ivSize);
    int16_t (ECOCALLMETHOD *KeyExpansion)(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* key, /* in */ uint8_t keySize, /* out */ uint8_t** roundKeys, /* out */ uint8_t* roundKeysSize);

} IEcoAES1VTbl, *IEcoAES1VTblPtr_t;

interface IEcoAES1 {
    struct IEcoAES1VTbl *pVTbl;
} IEcoAES1;


#endif /* __I_ECO_AES_1_H__ */
