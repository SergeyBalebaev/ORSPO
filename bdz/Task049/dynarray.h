#ifndef DYNARRAY_H
typedef struct {
    double* array;
    int size;
} Dynamic1D;

void fillRand(Dynamic1D* arr, int siz);
void display(Dynamic1D arr);
double maxValue(Dynamic1D arr);
void clear(Dynamic1D* arr);
#endif
