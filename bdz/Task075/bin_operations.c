#include <stdio.h>

int setbit(const int value, const int position) {
	return value | (1 << position);
}


int main()
{
	int val = 64;
	printf("%b\n", val);
	val = setbit(val, 4);
	printf("%b\n", val);
	return 0;
}
