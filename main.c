#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isFloat(char* str) {
	while(*str != '\0') {
		if(*str == '.') return true;
		str++;
	}
	return false;
}


int main(int argc, char* argv) {
	for(int i = 1; i < argc; i++) {
		if(isFloat(&argv[i])) {
			printf("%b\n", atof(&argv[i]));
		}
		else{
			printf("%b\n", atoi(&argv[i]));
		}
	}
	return 0;
}
