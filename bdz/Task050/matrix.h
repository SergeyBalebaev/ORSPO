#ifndef MATRIX_H

typedef struct {
    int width;
    int height;
    double** matrix;
} Matrix;

void fillRand(Matrix* mat, int w, int h);
void display(Matrix mat);
void clear(Matrix* mat);
double maxValue(Matrix mat);

#endif
