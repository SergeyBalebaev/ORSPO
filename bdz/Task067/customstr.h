#ifndef CUSTOMSTR_H
#include <stddef.h>

int atoi(const char *str);
size_t strlen(const char *str);
int strcmp(const char *str1, const char *str2);
char *strcat(char *str1, const char *str2);
char *strcat_new(char *str1, const char *str2);
char *my_strstr(char *str, char *sub);
char *strtok(char *string, char *del);

#endif
