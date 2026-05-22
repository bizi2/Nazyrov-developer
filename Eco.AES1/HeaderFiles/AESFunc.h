/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   AESFunc
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию функций AES
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_AESFUNC_H__
#define __C_AESFUNC_H__
#include "stdint.h"

#define AES128 1

typedef uint8_t state_t[4][4];

/* Домножение полинома на X */
uint8_t fnXTime(uint8_t x);

/* Получение значения из SBox */
uint8_t fnGetSBoxValue(uint8_t _index);

/* Получение значения из инвертированного SBox */
uint8_t fnGetSBoxInvertValue(uint8_t _index);

/* Функция для умножения чисел в поле GF(2^8). Используется в fnMixColumns и fnMixColumnsInv */
uint8_t fnMultiply(uint8_t _x, uint8_t _y);

/* Функция шифрования */
void fnCipher(state_t* _state, uint8_t* _roundKey);

/* Инвертированная функция шифрования */
void fnCipherInv(state_t* _state, uint8_t* _roundKey);

/* Добавление RoundKey к State при помощи операции XOR */
void fnAddRoundKey(uint8_t _round, state_t* _state, uint8_t* _roundKey);

/* Циклический сдвиг трёх последних строк влево на определённые промежутки */
void fnShiftRows(state_t* _state);

/* Обратное от fnShiftRows */
void fnShiftRowsInv(state_t* _state);

/* Заменяет байты из State на байты из SBox */
void fnSubBytes(state_t* _state);

/* Обратное от fnSubBytes */
void fnSubBytesInv(state_t* _state);

/* Перемешивает данные из колонок State чтобы создать новые колонки */
void fnMixColumns(state_t* _state);

/* Обратное от fnMixColumns */
void fnMixColumnsInv(state_t* _state);

/* Создаёт roundKey-и из ключа шифрования _key */
void fnKeyExpansion(uint8_t* _roundKey, uint8_t* _key);


#endif
