#include "dynarray.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillRand(Dynamic1D* arr, int siz) {
    srand(time(NULL));
    arr->size = siz;
    arr->array = malloc(sizeof(double) * arr->size);
    for(int i = 0; i < arr->size; i++) {
        arr->array[i] = rand() % 100;
    }
}

void display(Dynamic1D arr) {
    for(int i = 0; i < arr.size; i++) {
        printf("%f ", arr.array[i]);
    }
    printf("\n");
}

void clear(Dynamic1D* arr) {
    free(arr);
}

void extend(Dynamic1D* arr, int old_size, int new_size) {
    double* temp;
    temp = realloc(arr->array, new_size * sizeof(double));
    if(temp == NULL) {
        printf("Ошибка расширения массива!");
        return;
    }
    arr->size = new_size;
    arr->array = temp;
    for(int i = old_size; i < new_size; i++) {
        arr->array[i] = 0.0;
    }
}


