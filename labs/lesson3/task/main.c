#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;   // исправлено

    while (left < right) {
        if (str[left] != str[right]) { // исправлено
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main()
{
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    if (is_palindrome(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
