#include "dynarray.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include <float.h>

void fillRand(Dynamic1D* arr, int siz) {
    srand(time(NULL));
    arr->size = siz;
    arr->array = malloc(sizeof(double) * siz);
    for(int i = 0; i < arr->size; i++) {
        arr->array[i] = (double)(rand()) / RAND_MAX;
    }
}


void display(Dynamic1D arr) {
    for(int i = 0; i < arr.size; i++) {
    printf("%f ", arr.array[i]);
}
}


double maxValue(Dynamic1D arr) {
    double max = DBL_MIN;
    for(int i = 0; i < arr.size; i++) {
    if(max < arr.array[i]) max = arr.array[i];
}
    return max;
}

void clear(Dynamic1D* arr) {
    free(arr->array);
}

