#include "matrix.h"
#include <stdio.h>

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    Matrix matr;
    fillRand(&matr, w, h);
    display(matr);
    double m = maxValue(matr);
    clear(&matr);
    return 0;
}
