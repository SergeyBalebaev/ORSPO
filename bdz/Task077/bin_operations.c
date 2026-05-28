#include <stdio.h>

int switchbit(const int value, const int position) {
	return value ^ (1 << position);
}

int main()
{
	int x = 345;
	printf("%b\n", x);
	x = switchbit(x, 4);
	printf("%b\n", x);
	return 0;
}
