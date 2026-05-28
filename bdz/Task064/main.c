#include <stdio.h>
#include <string.h>

char* concat(char* str1, char* str2) {
    return strcat(str1, str2);
}

void concat_to_existing(char* original, char* str) {
    strcat(original, str);
}

int custom_strlen(char* str) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char str1[1000] = "Hello";
    char* str2 = " world";
    printf("%s", concat(str1, str2));
    concat_to_existing(str1, " govno");
    printf("%s", str1);
    printf("%d", custom_strlen(str1));
}
