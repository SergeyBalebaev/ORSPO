#include <stdio.h>
#include <string.h>

void find_in_file(int* y, int* x, char* filename, char* find) {
	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		*y = -1;
		*x = -1;
		perror("Error occured while opening file");
		return;
	}
	char buffer[1000];
	int line = 0;
	while(fgets(buffer, sizeof(buffer), fp) != NULL) {
		if(strstr(buffer, find) != NULL) {
			*x = strstr(buffer, find) - buffer;
			*y = line;
			fclose(fp);
			return;
		}
		line++;
	}
	*x = -1;
	*y = -1;
	fclose(fp);
	return;
	
}

int main() {
	
	int x = 0;
	int y = 0;
	find_in_file(&y, &x, "input.txt", "how");
	printf("%d %d\n", x, y);
	return 0;
} 
