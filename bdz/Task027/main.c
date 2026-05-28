#include <stdio.h>
#include <assert.h>

const char *get_time_of_day(int n)
{
  assert(0 <= n && n <= 86400);
  int hours = n / 3600;
  int minutes = (n % 3600) / 60;
  printf("%d : %d\n", hours, minutes);

  if(0<= hours && hours <= 5) return "Ночь";
  else if(6<= hours && hours <= 11) return "Утро";
  else if(12<= hours && hours <= 17) return "День";
  else return "Вечер";

}

int main(void)
{
  int n;
  scanf("%d", &n);
  const char *tod = get_time_of_day(n);
  printf("%s\n", tod);
  return 0;
}
