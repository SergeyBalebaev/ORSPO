	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
		FILE* fp = fopen("data.txt", "a+b");
		char* string = "Hello world";
		int len = strlen(string);
		
		
		
		for(int i = 0; i < len; i++) {
			putc(string[i], fp);
		}
		
		fclose(fp);
		
		fp = fopen("data.txt", "rb");
		char c;
		if(!fp) {
			fclose(fp);
			return 1;
		}
		while((c = getc(fp)) != EOF) {
			printf("%c", c);
		}
		fclose(fp);
	}
