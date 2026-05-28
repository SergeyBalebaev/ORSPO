	#include <stdio.h>

	int main(void)
	{
		FILE* fp = fopen("data.txt", "a");
		char sym[5];
		
		fprintf(fp, "%s", "Hello world!");
		fputs("Bye World", fp);
		fclose(fp);

		fp = fopen("data.txt", "r");
		while ((fgets(sym, sizeof(sym), fp)) != NULL)
		{
		    printf("%s\n", sym);
		}
		fclose(fp);

	return 0;
	}
