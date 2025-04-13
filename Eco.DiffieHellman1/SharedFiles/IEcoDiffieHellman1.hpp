/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoDiffieHellman1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoDiffieHellman1
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

#ifndef __I_ECODIFFIEHELLMAN1_HPP__
#define __I_ECODIFFIEHELLMAN1_HPP__

#include "IEcoBase1.hpp"

/* IEcoDiffieHellman1 IID = {19D6FABF-B9E6-4719-8BC8-8EDA4E40632A} */
#ifndef __IID_IEcoDiffieHellman1
static const UGUID IID_IEcoDiffieHellman1 = {0x01, 0x10, {0x19, 0xD6, 0xFA, 0xBF, 0xB9, 0xE6, 0x47, 0x19, 0x8B, 0xC8, 0x8E, 0xDA, 0x4E, 0x40, 0x63, 0x2A}};
#endif /* __IID_IEcoDiffieHellman1 */

interface IEcoDiffieHellman1 : public IEcoUnknown {
public:
    /* IEcoDiffieHellman1 */
    virtual int16_t ECOCALLMETHOD MyFunction(/* in */ char_t* Name, /* out */ char_t** CopyName) = 0;

};



#endif /* __I_ECODIFFIEHELLMAN1_HPP__ */
