#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  scanf("%d", &n);

  int** arr = malloc(sizeof(int*) * n); // (int*) писать необязательно
  int num = 0;
  for(int i = 0; i < n; i++) {
    arr[i] = malloc(sizeof(int));
    scanf("%d", &num);
    *arr[i] = num;
  }  

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(*arr[i] == *arr[j]) {
        printf("Найден дубликат: %d\n", *arr[j]);
        break;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}
