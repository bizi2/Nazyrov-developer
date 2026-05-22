/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoIPCCMailbox1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoIPCCMailbox1
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

#ifndef __I_ECO_IPCC_MAILBOX_1_H__
#define __I_ECO_IPCC_MAILBOX_1_H__

#include "IEcoBase1.h"

/* Определение списка каналов ящика прошивки */
#define MB_CHANNEL_ARM_POWER_MANAGEMENT 0x00
#define MB_CHANNEL_ARM_FRAMEBUFFER      0x01
#define MB_CHANNEL_ARM_VIRTUAL_UART     0x02
#define MB_CHANNEL_ARM_VCHIQ            0x03
#define MB_CHANNEL_ARM_LEDS             0x04
#define MB_CHANNEL_ARM_BUTTONS          0x05
#define MB_CHANNEL_ARM_TOUCH_SCREEN     0x06
#define MB_CHANNEL_ARM_COUNTER          0x07
#define MB_CHANNEL_ARM_PROPERTY_ARM     0x08
#define MB_CHANNEL_ARM_PROPERTY_VC      0x09

typedef union ECO_MB_LINEAR_ADDRESS_t {
    struct {
        uint32_t LowPart;
        uint32_t HighPart;
    } Base;
    uint64_t Linear;
} ECO_MB_LINEAR_ADDRESS_t;

/* IEcoIPCCMailbox1 IID = {669CE664-EF34-4967-A524-55CD22D78C56} */
#ifndef __IID_IEcoIPCCMailbox1
static const UGUID IID_IEcoIPCCMailbox1 = {0x01, 0x10, {0x66, 0x9C, 0xE6, 0x64, 0xEF, 0x34, 0x49, 0x67, 0xA5, 0x24, 0x55, 0xCD, 0x22, 0xD7, 0x8C, 0x56}};
#endif /* __IID_IEcoIPCCMailbox1 */

typedef struct IEcoIPCCMailbox1* IEcoIPCCMailbox1Ptr_t;

typedef struct IEcoIPCCMailbox1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoIPCCMailbox1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoIPCCMailbox1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoIPCCMailbox1Ptr_t me);

    /* IEcoIPCCMailbox1 */
    ECO_MB_LINEAR_ADDRESS_t (ECOCALLMETHOD *get_MappedAddress)(/* in */ IEcoIPCCMailbox1Ptr_t me);
    void (ECOCALLMETHOD *set_MappedAddress)(/* in */ IEcoIPCCMailbox1Ptr_t me, /* in */ ECO_MB_LINEAR_ADDRESS_t address);
    uint32_t (ECOCALLMETHOD *Read)(/* in */ IEcoIPCCMailbox1Ptr_t me, /* in */ uint8_t channel);
    void (ECOCALLMETHOD *Write)(/* in */ IEcoIPCCMailbox1Ptr_t me, /* in */ uint8_t channel, /* in */ uint32_t data);
    int16_t (ECOCALLMETHOD *ProcessingByArgs)(/* in */ IEcoIPCCMailbox1Ptr_t me, /* in */ uint8_t channel, /* out */ uint32_t* buffer, /* in */ uint32_t size, ...);

} IEcoIPCCMailbox1VTbl, *IEcoIPCCMailbox1VTblPtr;

interface IEcoIPCCMailbox1 {
    struct IEcoIPCCMailbox1VTbl *pVTbl;
} IEcoIPCCMailbox1;

#endif /* __I_ECO_IPCC_MAILBOX_1_H__ */

