//
// Created by kilog on 9/26/2026.
//
#include <stdio.h>
#include  <stdbool.h>

#include "Checker.h"

bool is_divisible(const int argOne, const int argTwo) {
    return argTwo % argOne == 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Incorrect number of arguments\n Expected: 3\n Actual: %i\n", argc);
    }
    const int argOne = (int) argv[1];
    const int argTwo = (int) argv[2];
    if (argOne == 0) {
        printf("Checker process []: Returning %i.", 0);
        return 1;
    }
    const bool divisible = is_divisible(argOne, argTwo);
    if (divisible) {
        printf("Checker process []: %d *IS* divisible by %d", argTwo, argOne);
    }
    else {
        printf("Checker process []: %d *IS NOT* divisible by %d", argTwo, argOne);
    }

    printf("Checker process []: Returning %i", 0);
    return 0;


}


