#include <stdio.h>

int main() {
    float a = 0.1;
    float b = 0.2;
    float c = a + b;
    if (c == 0.3)
        printf("Yes!\n");
    else
        printf("No!\n");

    float x = 12345678.12345678;
    printf("Float X = %20.8f\n", x);
    printf("%b", 12345678);
    printf("\n\n24 разряда ушло под целую часть\n\n");
    printf("<1> * 1.m * 2^порядок. Под дробную часть просто не осталось места");
    double y = 12345678.12345678;
    printf("%f", y);
    return 0;
}
