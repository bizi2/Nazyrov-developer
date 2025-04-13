/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSSH1CP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSSH1CP
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

#ifndef __I_ECOSSH1CP_HPP__
#define __I_ECOSSH1CP_HPP__

#include "IEcoBase1.hpp"

/* IEcoSSH1CP IID = {58182FFD-6184-45A0-B72D-DF702C45F1EC} */
#ifndef __IID_IEcoSSH1CP
static const UGUID IID_IEcoSSH1CP = {0x01, 0x10, {0x58, 0x18, 0x2F, 0xFD, 0x61, 0x84, 0x45, 0xA0, 0xB7, 0x2D, 0xDF, 0x70, 0x2C, 0x45, 0xF1, 0xEC}};
#endif /* __IID_IEcoSSH1CP */

interface IEcoSSH1CP : public IEcoUnknown {
public:
    /* IEcoSSH1CP */
    virtual int16_t ECOCALLMETHOD MyFunction(/* in */ char_t* Name, /* out */ char_t** CopyName) = 0;

};



#endif /* __I_ECOSSH1CP_HPP__ */
