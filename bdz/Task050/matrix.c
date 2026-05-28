#include "matrix.h"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <float.h>

void fillRand(Matrix* mat, int w, int h) {
    srand(time(NULL));
    mat->width = w; mat->height = h;
    mat->matrix = malloc(mat->height * sizeof(double*));

    for(int i = 0; i < mat->height; i++) {
        mat->matrix[i] = malloc(sizeof(double) * mat->width);
        for(int j = 0; j < mat->width; j++) {
            mat->matrix[i][j] = (double)rand()/RAND_MAX;
        }
    }
}

void display(Matrix mat) {
    for(int i = 0; i < mat.height; i++) {
        for(int j = 0; j < mat.width; j++) {
            printf("%f ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

double maxValue(Matrix mat) {
    double max = DBL_MIN;
    for(int i = 0; i < mat.height; i++) {
        for(int j = 0; j < mat.width; j++) {
            if (max < mat.matrix[i][j]) max = mat.matrix[i][j];
        }
    }
    return max;
}

void clear(Matrix* mat) {
    for(int i = 0; i < mat->height; i++) {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
}
