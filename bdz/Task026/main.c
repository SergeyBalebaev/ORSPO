#include <stdio.h>
#include <assert.h>

void seconds_to_time(int n)
{
  assert(n >= 0);
  printf("%d : %d : %d", n/3600, (n%3600)/60, (n%3600)%60);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  seconds_to_time(n);
  return 0;
}
