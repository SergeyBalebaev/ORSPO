#include <stdio.h>
#include <string.h>

int main() {
    
    char* str1;
    char* str2;
    printf("1 строка: "); fgets(str1, sizeof(str1), stdin);
    printf("2 строка: "); fgets(str2, sizeof(str2), stdin);
    
    printf("%d", strcmp(str1, str2));
    return 0;
}

