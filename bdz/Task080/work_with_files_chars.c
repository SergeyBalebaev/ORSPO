	#include <stdio.h>

	int main(void)
	{
		FILE* fp = fopen("data.txt", "a");
		char* string = "Hello world";
		int strlen = sizeof(string) / sizeof(string[0]);
		
		
		
		for(int i = 0; i < strlen; i++) {
			putc(string[i], fp);
		}
		
		fclose(fp);
		
		fp = fopen("data.txt", "w");
		char c;
		if(!fp) {
			fclose(fp);
			return 1;
		}
		while(c != EOF) {
			c = getc(fp);
			printf("%c", c);
		}
		fclose(fp);
	}
