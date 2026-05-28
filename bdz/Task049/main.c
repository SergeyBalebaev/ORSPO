#include "dynarray.h"
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    Dynamic1D arr1;
    fillRand(&arr1, n);
    display(arr1);
    double m = maxValue(arr1);
    printf("\n\nMAX: %f", m);
    clear(&arr1);
    return 0;
};
