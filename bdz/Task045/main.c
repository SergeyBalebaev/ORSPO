#include <stdio.h>

int main()
{
	int x[3] = {1,2,3}; 
	printf("%d\n",x[1]);//*(x + 1)
	printf("%d\n",*(x+1));
	printf("%d\n",1[x]);
	printf("%d\n",*(&x[1])); // x[1] - 1 элемент, &x[1] - адрес, *(x[1]) - разыменование по адресу
	return 0;
}
