#include "RSAFunc.h"

uint8_t* fnI20SP(uint32_t input, uint32_t outputLength)
{
    uint8_t* res = malloc(outputLength + 1);
    uint8_t counter = outputLength - 1;
    memset(res, 0, outputLength + 1);

    if (input >= pow(256, outputLength)) {
        return res;
    }

    while (counter) {
        *res++ = (uint8_t)(input % 256);
        counter--;
    }

    *res = '\0';

    return res;
}
