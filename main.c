#include <stdio.h>
#include <stdint.h>

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
