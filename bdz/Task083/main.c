#include <stdio.h>
#include <string.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

unsigned long checksum(char* filename) {
	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		perror("Error occured while opening file");
		return -1;
	}
	char buffer[1000];
	unsigned long sum = 0;
	while(fgets(buffer, sizeof(buffer), fp) != NULL) {
		sum += hash_function(buffer);
	}

	fclose(fp);
	return sum;
	
}

int main() {
	unsigned long x = checksum("input.txt");
	printf("%lx", x);
	return 0;
}
