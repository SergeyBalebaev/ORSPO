#include <stdio.h>

double average(int n, int numbers[])
{
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += numbers[i]; 
  }
  return (double)(sum/n);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int numbers[100];
  for (int i = 0; i < n; i++)
    scanf("%d", &numbers[i]);
  printf("%.6f\n", average(n, numbers));
  return 0;
}
