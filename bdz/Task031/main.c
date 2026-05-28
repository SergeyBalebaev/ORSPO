#include <stdio.h>
#include <math.h>

double my_function(int x)
{
  return (pow(x, 2) + 5*x + 6)/(pow(x, 2) + x + 1);
}

int main(void)
{
  int x;
  scanf("%d", &x);
  printf("%.6f\n", my_function(x));
  return 0;
}

