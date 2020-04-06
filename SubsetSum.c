#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int sumsTo(uint x[], uint n, uint k, uint v) {

    if (v == 0 && k == 0) return 1;
    if (v != 0 && k == 0) return 0;
    if (n == 0) return 0;

    int result1 = 0;
    if (v >= x[0]) result1 = sumsTo(x + 1, n - 1, k - 1, v - x[0]);
    int result2 = sumsTo(x + 1, n - 1, k , v);

    return result1 + result2 > 0;
}

int main() {
    uint a[5] = {1, 8, 6, 4, 3};

    printf("\nshould be false\n");
    if (sumsTo(a, 5, 3, 9)) {
        printf("\na[], n = 5, k = 3, v - 9 = True\n");
    } else {
        printf("\na[], n = 5, k = 3, v - 9 = False\n");
    }

    printf("\nshould be true\n");
    if (sumsTo(a, 5, 2, 9)) {
        printf("\na[], n = 5, k = 2, v - 9 = True\n");
    } else {
        printf("\na[], n = 5, k = 2, v - 9 = False\n");
    }

    uint b[5] = {1, 9, 4, 7, 8};

    printf("\nshould be true\n");
    if (sumsTo(b, 5, 3, 12)) {
        printf("\nb[], n = 5, k = 3, v - 12 = True\n");
    } else {
        printf("\nb[], n = 5, k = 3, v - 12 = False\n");
    }

    printf("\nshould be true\n");
    if (sumsTo(b, 5, 3, 13)) {
        printf("\na[], n = 5, k = 3, v - 13 = True\n");
    } else {
        printf("\na[], n = 5, k = 3, v - 13 = False\n");
    }

    printf("\nshould be true\n");
    if (sumsTo(b, 5, 2, 13)) {
        printf("\na[], n = 5, k = 2, v - 13 = True\n");
    } else {
        printf("\na[], n = 5, k = 2, v - 13 = False\n");
    }

    printf("\nshould be false\n");
    if (sumsTo(b, 5, 2, 14)) {
        printf("\na[], n = 5, k = 2, v - 14 = True\n");
    } else {
        printf("\na[], n = 5, k = 2, v - 14 = False\n");
    }


    return 0;
}
