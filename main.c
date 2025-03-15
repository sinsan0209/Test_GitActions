#include <stdio.h>
#include <stdlib.h>
#include "fizzbuzz.h"

int main(void) {
    int i;
    char result[256];
    for (i = 1; i < 20; i++) {
        if (fizzbuzz(i, result) == -1) {
            exit(EXIT_FAILURE);
        }
        printf("%s\n", result);
    }
    return 0;
}

int error(char *mes) {
    fprintf(stderr, "ERROR:%s\n", mes);
    return -1;
}
