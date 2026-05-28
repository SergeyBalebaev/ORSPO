#include <stdio.h>

int setbit(const int value, const int position) {
	return value | (1 << position);
}

int checkbit(const int value, const int position) {
	return (value >> position) & 1;
}

int switchbit(const int value, const int position) {
	return value ^ (1 << position);
}

int unsetbit(const int value, const int position) {
	return value & ~(1 << position);
}

struct byte_s {
	unsigned a0 : 1;
	unsigned a1 : 1;
	unsigned a2 : 1;
	unsigned a3 : 1;
	unsigned a4 : 1;
	unsigned a5 : 1;
	unsigned a6 : 1;
	unsigned a7 : 1;
};


union code
{
	unsigned char letter;
	struct byte_s bitfield;
}byte;


void bin(long unsigned int k, long unsigned int size)
{
	long unsigned int bits = size * 8;
	for(long int i = bits - 1; i >= 0; i--) {
		printf("%d", checkbit(k, i));
	}
	printf("\n");
}

int main()
{
	union code a, b;
    a.letter = 0b00000000;
    b.letter = 0b11111111;
    a.letter = setbit(a.letter, 5);
    bin(a.letter, sizeof(a.letter)); // печатает на экран число в двоичном виде
    
    union floatf {
    	float f;
    	unsigned int u;
    } float_trick;
    float_trick.f = 7.62;
    
    bin(float_trick.u, sizeof(float_trick.u));
    
	return 0;
}
