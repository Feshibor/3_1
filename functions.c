#include "functions.h"

void decimal_to_base(uint32_t n, uint8_t base, char *result) {
    char buffer[64];
    int pos = 0;

    if (n == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    uint32_t mask = (1U << base) - 1; 

    while (n) {
        uint32_t digit = n & mask; 
        if (digit < 10) {
            buffer[pos++] = '0' + digit;
        } else {
            buffer[pos++] = 'A' + (digit - 10);
        }
        n = n >> base;
    }

    for (int i = 0; i < pos; i++) {
        result[i] = buffer[pos - 1 - i];
    }
    result[pos] = '\0';
}
