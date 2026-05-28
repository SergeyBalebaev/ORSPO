#include <stdio.h>

void swap(int* x, int* y) {
    *x = *x ^ *y;
    *y = *x^*y;
    *x = *x^*y;
}

int main() {
    int xx = 5;
    int yy = 4;
    int* px = &xx;
    int* py = &yy;
    swap(px, py);
    printf("x = %d y = %d", xx, yy);
    return 0;
}
