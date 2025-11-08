#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "functions.h"

void run_tests() {
    char result[64];

    decimal_to_base(0, 1, result);
    assert(strcmp(result, "0") == 0);

    decimal_to_base(0, 2, result);
    assert(strcmp(result, "0") == 0);

    decimal_to_base(0, 5, result);
    assert(strcmp(result, "0") == 0);

    decimal_to_base(5, 2, result); 
    assert(strcmp(result, "101") == 0);

    decimal_to_base(10, 2, result); 
    assert(strcmp(result, "1010") == 0);

    decimal_to_base(10, 2, result); 
    assert(strcmp(result, "1010") == 0);

    decimal_to_base(31, 5, result); 
    assert(strcmp(result, "11111") == 0);

    decimal_to_base(32, 5, result); 
    assert(strcmp(result, "100000") == 0);

    printf("Все тесты пройдены успешно!\n");
}

int main() {
    run_tests();
    return 0;
}
