/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVBIOS1Video
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVBIOS1Video
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

#ifndef __I_ECO_VBIOS_1_VIDEO_H__
#define __I_ECO_VBIOS_1_VIDEO_H__

#include "IEcoBase1.h"


#define CHARACTER_ATTRIBUTE_FORE_COLOR_BLACK                0x00
#define CHARACTER_ATTRIBUTE_FORE_COLOR_BLUE                 0x01
#define CHARACTER_ATTRIBUTE_FORE_COLOR_GREEN                0x02
#define CHARACTER_ATTRIBUTE_FORE_COLOR_CYAN                 0x03
#define CHARACTER_ATTRIBUTE_FORE_COLOR_RED                  0x04
#define CHARACTER_ATTRIBUTE_FORE_COLOR_MAGENTA              0x05
#define CHARACTER_ATTRIBUTE_FORE_COLOR_BROWN                0x06
#define CHARACTER_ATTRIBUTE_FORE_COLOR_LIGHT_GRAY           0x07
#define CHARACTER_ATTRIBUTE_FORE_COLOR_DARK_GRAY            0x08
#define CHARACTER_ATTRIBUTE_FORE_COLOR_LIGHT_BLUE           0x09
#define CHARACTER_ATTRIBUTE_FORE_COLOR_LIGHT_GREEN          0x0A
#define CHARACTER_ATTRIBUTE_FORE_COLOR_LIGHT_CYAN           0x0B
#define CHARACTER_ATTRIBUTE_FORE_COLOR_LIGHT_RED            0x0C
#define CHARACTER_ATTRIBUTE_FORE_COLOR_LIGHT_MAGENTA        0x0D
#define CHARACTER_ATTRIBUTE_FORE_COLOR_YELLOW               0x0E
#define CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE               0x0F
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_BLACK          0x00
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_BLUE           0x10
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_GREEN          0x20
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_CYAN           0x30
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_RED            0x40
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_MAGENTA        0x50
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_BROWN          0x60
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_LIGHT_GRAY     0x70
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_DARK_GRAY      0x80
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_LIGHT_BLUE     0x90
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_LIGHT_GREEN    0xA0
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_LIGHT_CYAN     0xB0
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_LIGHT_RED      0xC0
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_LIGHT_MAGENTA  0xD0
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_YELLOW         0xE0
#define CHARACTER_ATTRIBUTE_BACKGROUND_COLOR_WHITTE         0xF0


/* IEcoVBIOS1Video IID = {F88E9EB3-29E7-4DE9-80E2-94B406BCFA18} */
#ifndef __IID_IEcoVBIOS1Video
static const UGUID IID_IEcoVBIOS1Video = {0x01, 0x10, {0xF8, 0x8E, 0x9E, 0xB3, 0x29, 0xE7, 0x4D, 0xE9, 0x80, 0xE2, 0x94, 0xB4, 0x06, 0xBC, 0xFA, 0x18}};
#endif /* __IID_IEcoVBIOS1Video */

typedef struct IEcoVBIOS1Video* IEcoVBIOS1VideoPtr_t;

typedef struct IEcoVBIOS1VideoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVBIOS1VideoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVBIOS1VideoPtr_t me);

    /* IEcoVBIOS1Video */
    int16_t (ECOCALLMETHOD *SetMode)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t videoMode);
    int16_t (ECOCALLMETHOD *SetCursorType)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t bottomLine, /* in */ uint8_t topLine);
    int16_t (ECOCALLMETHOD *SetCursorPosition)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t pageNumber, /* in */ uint8_t column, /* in */ uint8_t row);
    int16_t (ECOCALLMETHOD *ReadCursorPosition)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t pageNumber, /* out */ uint8_t* column, /* out */ uint8_t* row, /* out */ uint8_t* bottomLine, /* out */ uint8_t* topLine);
    int16_t (ECOCALLMETHOD *ReadLightPenPosition)(/* in */ IEcoVBIOS1VideoPtr_t me, /* out */ uint8_t* value, /* out */ uint16_t* columnRaster, /* out */ uint16_t* rowRaster, /* out */ uint8_t* columnCharacter, /* out */ uint8_t* rowCharacter);
    int16_t (ECOCALLMETHOD *SelectActiveDisplayPage)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t pageNumber);
    int16_t (ECOCALLMETHOD *ScrollActivePageUp)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t numberLines, /* in */ uint8_t attribute, /* in */ uint8_t columnLeftCorner, /* in */ uint8_t rowLeftCorner, /* in */ uint8_t columnRightCorner, /* in */ uint8_t rowRightCorner);
    int16_t (ECOCALLMETHOD *ScrollActivePageDown)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t numberLines, /* in */ uint8_t attribute, /* in */ uint8_t columnLeftCorner, /* in */ uint8_t rowLeftCorner, /* in */ uint8_t columnRightCorner, /* in */ uint8_t rowRightCorner);
    int16_t (ECOCALLMETHOD *ReadCharAtCursorPos)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t pageNumber, /* out */ uint8_t* attribute, /* out */ uint8_t* character);
    int16_t (ECOCALLMETHOD *WriteCharWithAttrAtCursorPos)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t pageNumber, /*in */ uint8_t attribute, /* in */ uint8_t character, /* in */ uint16_t count);
    int16_t (ECOCALLMETHOD *WriteCharAtCursorPos)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t pageNumber, /* in */ uint8_t character, /* in */ uint16_t count);
    int16_t (ECOCALLMETHOD *SetColorPalette)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t colorValue, /* in */ uint8_t colorID);
    int16_t (ECOCALLMETHOD *WriteDot)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t colorValue, /* in */ uint8_t pageNumber, /* in */ uint16_t column, /* in */ uint16_t row);
    int16_t (ECOCALLMETHOD *ReadDot)(/* in */ IEcoVBIOS1VideoPtr_t me, /* out */ uint8_t* colorValue, /* out */ uint8_t* pageNumber, /* out */ uint16_t* column, /* out */ uint16_t* row);
    int16_t (ECOCALLMETHOD *WriteTeletype)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t character, /* in */ uint8_t foregroundColor);
    int16_t (ECOCALLMETHOD *ReadCurrentVideoState)(/* in */ IEcoVBIOS1VideoPtr_t me, /* out */ uint8_t* mode, /* out */ uint8_t* columns, /* out */ uint8_t* pageNumber);
    int16_t (ECOCALLMETHOD *SetPaletteRegisters)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t command, /* in */ uint8_t reg, /* in */ uint8_t value, /* in */ byte_t* table);
    int16_t (ECOCALLMETHOD *CharacterGenerator)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t command, /* in */ uint8_t block, /* in */ uint16_t offset, /* in | out */ uint8_t* numberBytes, /* in | out */ uint16_t* count, /* in | out */ byte_t** table);
    int16_t (ECOCALLMETHOD *AlternateSelect)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t colorValue, /* in */ uint8_t colorID);
    int16_t (ECOCALLMETHOD *WriteString)(/* in */ IEcoVBIOS1VideoPtr_t me, /* in */ uint8_t mode, /* in */ uint8_t pageNumber, /* in */ uint8_t column, /* in */ uint8_t row, /* in */ uint8_t attribute, /* in */ char_t* string, /* in */ uint16_t count);
    uint32_t (ECOCALLMETHOD *get_Width)(/* in */ IEcoVBIOS1VideoPtr_t me);
    uint32_t (ECOCALLMETHOD *get_Height)(/* in */ IEcoVBIOS1VideoPtr_t me);
    int16_t (ECOCALLMETHOD *ReturnPhysicalDisplayParam)(/* in */ IEcoVBIOS1VideoPtr_t me, /* out */ uint16_t* type, /* out */ uint16_t** table);

} IEcoVBIOS1VideoVTbl, *IEcoVBIOS1VideoVTblPtr_t;

interface IEcoVBIOS1Video {
    struct IEcoVBIOS1VideoVTbl *pVTbl;
} IEcoVBIOS1Video;


#endif /* __I_ECO_VBIOS_1_VIDEO_H__ */
