#include <stdio.h>

void fizzbuzz(int n)
{
  for(int i = 1; i < n; i++) {
    printf("%d\r", i);
    if(i % 3 == 0) printf("Fizz");
    if(i % 5 == 0) printf("Buzz");
    printf("\n");
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  fizzbuzz(n);
  return 0;
}
