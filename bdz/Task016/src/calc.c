#include "calc.h"
#include <stdio.h>
#include <limits.h>

int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) { 
        sum += arr[i];
    }
    return sum;
}

int divide(int a, int b) {
    if (b == 0) {
	return INT_MAX;
    }
    return a / b;
}


