#include <stdio.h>
#include <string.h>

void find_in_file(int* y, int* x, char* filename) {
	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		*y = -1;
		*x = -1;
		perror("Error occured while opening file");
		return;
	}
}

int main(int argc, char* argv) {
	return 0;
} 
