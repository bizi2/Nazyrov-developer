/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSSH1TLP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSSH1TLP
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

#ifndef __I_ECOSSH1TLP_HPP__
#define __I_ECOSSH1TLP_HPP__

#include "IEcoBase1.hpp"

/* IEcoSSH1TLP IID = {9D5A03CC-CDF4-4BF0-BE7B-A3216C695842} */
#ifndef __IID_IEcoSSH1TLP
static const UGUID IID_IEcoSSH1TLP = {0x01, 0x10, {0x9D, 0x5A, 0x03, 0xCC, 0xCD, 0xF4, 0x4B, 0xF0, 0xBE, 0x7B, 0xA3, 0x21, 0x6C, 0x69, 0x58, 0x42}};
#endif /* __IID_IEcoSSH1TLP */

interface IEcoSSH1TLP : public IEcoUnknown {
public:
    /* IEcoSSH1TLP */
    virtual int16_t ECOCALLMETHOD MyFunction(/* in */ char_t* Name, /* out */ char_t** CopyName) = 0;

};



#endif /* __I_ECOSSH1TLP_HPP__ */
