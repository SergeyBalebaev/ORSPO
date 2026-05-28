#include "dynarray.h"

int main() {
    Dynamic1D arr1;
    fillRand(&arr1, 6);
    display(arr1);
    extend(&arr1, 6, 16);
    display(arr1);
    //clear(&arr1);
    return 0;
}
