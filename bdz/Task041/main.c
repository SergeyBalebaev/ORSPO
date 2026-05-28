#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
  int n;
  scanf("%d", &n);
  if(n == 0) {
    printf("0 0");
    return 0;
  }
  if(n == 1) {
    scanf("%d", &n);
    printf("Min: %d\n", n);
    printf("Max: %d\n", n);
    return 0;
  }
  int* min = malloc(sizeof(int)); *min = INT_MAX; 
  int* max = malloc(sizeof(int)); *max = INT_MIN;
  int** arr = malloc(sizeof(int*) * n);
  int num = 0;
  for(int i = 0; i < n; i++) {
    arr[i] = malloc(sizeof(int));
    scanf("%d", &num);
    *arr[i] = num;
    if(*min > num) *min = num;
    if(*max < num) *max = num;
  }
  printf("Min: %d\n", *min);
  printf("Max: %d\n", *max);

  for(int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
  free(min); free(max);
  return 0;
}
