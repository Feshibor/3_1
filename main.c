#include <stdio.h>
#include <stdint.h>
#include "functions.h"

int main() {
    uint32_t number;
    uint8_t base;
    char result[64];  

    printf("Введите число в десятичной системе: ");
    scanf("%u", &number);

    printf("Введите основание системы счисления (1..5): ");
    scanf("%hhu", &base);

    if (base < 1 || base > 5) {
        printf("Ошибка: основание должно быть от 1 до 5\n");
        return 1;
    }

    decimal_to_base(number, base, result);

    printf("Число %u в системе с основанием 2^%u: %s\n", number, base, result);

    return 0;
}
