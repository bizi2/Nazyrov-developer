/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSSH1AP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSSH1AP
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

#ifndef __I_ECOSSH1AP_HPP__
#define __I_ECOSSH1AP_HPP__

#include "IEcoBase1.hpp"

/* IEcoSSH1AP IID = {85CA4410-DBD3-4788-979B-78D0D7DD18CC} */
#ifndef __IID_IEcoSSH1AP
static const UGUID IID_IEcoSSH1AP = {0x01, 0x10, {0x85, 0xCA, 0x44, 0x10, 0xDB, 0xD3, 0x47, 0x88, 0x97, 0x9B, 0x78, 0xD0, 0xD7, 0xDD, 0x18, 0xCC}};
#endif /* __IID_IEcoSSH1AP */

interface IEcoSSH1AP : public IEcoUnknown {
public:
    /* IEcoSSH1AP */
    virtual int16_t ECOCALLMETHOD MyFunction(/* in */ char_t* Name, /* out */ char_t** CopyName) = 0;

};



#endif /* __I_ECOSSH1AP_HPP__ */
