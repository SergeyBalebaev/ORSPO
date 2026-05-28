#include <stdio.h>

int min_of_three(int a, int b, int c)
{
  if((a <= b) && (a <= c)) return a;
  else if((b <= a) && (b <= c)) return b;
  else return c;
}

int main(void)
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", min_of_three(a, b, c));
  return 0;
}
