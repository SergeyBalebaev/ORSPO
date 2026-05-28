#include "customstr.h"
#include <stdio.h>

int main()
{
	char string1[90] = "Change   da world";
	char *string2 = " my final message";
	char *ptr = strcat_new(string1, string2);
	char *ptr2 = strcat_new(ptr, "   Goodbye");
	printf("%s\n", ptr2);
	char *token = strtok(ptr2, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return 0;
}