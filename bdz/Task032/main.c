#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_palindrome(const char *s)
{
  int len = strlen(s);

  for(int i = 0; i < len/2; i++) {
    char f = tolower(s[i]); char l = tolower(s[len-2-i]);
    if(f != l) return false;
  }
  return true;
}

int main(void)
{
  char s[101];
  fgets(s, 101, stdin);
  
  printf("%s",s);
  if (is_palindrome(s))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
