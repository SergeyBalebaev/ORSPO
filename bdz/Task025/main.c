#include <stdio.h>
#include <assert.h>

int divide(int numerator, int denominator)
{
  assert(denominator != 0);
  return numerator/denominator;
}

int main(void)
{
  int a, b;
  printf("Enter numerator and denominator: ");
  scanf("%d %d", &a, &b);
  if (b == 0) {
    printf("Деление на 0! Аварийное завершение!");
    return 1;
  }
  int result = divide(a, b);
  printf("Result: %d\n", result);

  return 0;
}
