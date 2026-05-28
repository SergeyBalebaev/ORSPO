#include <stdio.h>

int checkbit(const int value, const int position) {
	return (value >> position) & 1;
}

int main()
{
	int x = 150;
	printf("%b\n", x);
	printf("%b", checkbit(x, 4));
	return 0;
}
