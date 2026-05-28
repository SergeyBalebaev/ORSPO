#include <stdio.h>

int unsetbit(const int value, const int position) {
	return value & ~(1 << position);
}

int main()
{
	int val = 127;
	printf("%b\n", val);
	val = unsetbit(val, 4);
	printf("%b\n", val);
	return 0;
	return 0;
}
