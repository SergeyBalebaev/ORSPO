#include "customstr.h"
#include <stdlib.h>

size_t strlen(const char *str)
{
	if (str == NULL)
		return 0;
	size_t len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int atoi(const char *str)
{
	int val = 0;
	int k = 1;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			str++;
			continue;
		}
		if (*str == '-')
			k = -1;
		if ('0' <= *str && *str <= '9')
		{
			val *= 10;
			val += (*str) - 48;
		}
		str++;
	}
	return val * k;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1) - (*str2);
		str1++;
		str2++;
	}
	return (*str1) - (*str2);
}

char *strcat(char *str1, const char *str2)
{
	char *str1_original = str1;
	while (*str1 != '\0')
		str1++;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str1_original;
}

char *strcat_new(char *str1, const char *str2)
{
	char *new_str = malloc(strlen(str1) + strlen(str2) + 1);
	char *slider = new_str;
	while (*str1 != '\0')
	{
		*slider = *str1;
		slider++;
		str1++;
	}
	while (*str2 != '\0')
	{
		*slider = *str2;
		slider++;
		str2++;
	}
	*slider = '\0';
	return new_str;
}

static int equal(const char *str, const char *sub)
{
	if (strlen(sub) > strlen(str))
		return 0;
	int result = 0;
	while (*sub != '\0')
	{
		result |= (*sub) ^ (*str);
		sub++;
		str++;
	}
	return result == 0;
}

char *my_strstr(char *str, char *sub)
{
	if (str == NULL)
		return NULL;
	if (sub == NULL)
		return NULL;
	size_t lenstr = strlen(str);
	size_t lensub = strlen(sub);

	if (lenstr < lensub)
		return NULL;
	if (lensub == 0)
		return str;

	for (size_t i = 0; i <= lenstr - lensub; i++)
	{
		if (equal(str + i, sub))
		{
			return str + i;
		}
	}
	return NULL;
}

static int check_delim(char character, char *del)
{
	if (del == NULL)
		return 0;

	while (*del != '\0')
	{
		if (character == *del)
			return 1;
		del++;
	}
	return 0;
}

char *strtok(char *string, char *del)
{
	if (del == NULL)
		return NULL;

	static char *split = NULL;

	if (string != NULL)
		split = string;

	// На случай ",,,Hello, world"
	while (*split != '\0' && check_delim(*split, del))
		split++;

	char *token_start = split;

	while (*split != '\0' && check_delim(*split, del) == 0)
		split++;

	if (check_delim(*split, del) == 1)
	{
		*split = '\0';
		split++;
		return token_start;
	}
	if (*token_start == '\0')
		return NULL;
	if (*split == '\0')
	{
		return token_start;
	}
}
