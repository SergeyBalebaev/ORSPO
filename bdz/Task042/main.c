#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
  int n = 0;
  scanf("%d", &n);
  assert(n >= 0);
  int** arr = malloc(sizeof(int*) * n);
  int** prefix = malloc(sizeof(int*) * n);
  int num = 0;
  for(int i = 0; i < n; i++) {
    arr[i] = malloc(sizeof(int));
    prefix[i] = malloc(sizeof(int));
    scanf("%d", &num);
    *arr[i] = num;
    if(i == 0) {
        *prefix[i] = *arr[i];
        continue;
    } 
    *prefix[i] = *prefix[i-1] + *arr[i];
  }
  
  printf("Основной массив: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", *arr[i]);
    free(arr[i]);
  }
  printf("\n");
  printf("Префиксные суммы: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", *prefix[i]);
    free(prefix[i]);
  }
  printf("\n");
  free(arr);
  free(prefix);
  return 0;
}
