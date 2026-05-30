#include "stdstring.h"
#include <stdio.h>
#include <string.h>


int main() {
	StdString s = init("Hello, World!");
	s.print(s);
	printf("%ld\n", s.size);
	printf("%ld\n", strlen(s.data));
	s.append(&s, "govno");
	printf("%ld\n", s.size);
	printf("%ld\n", strlen(s.data));
	s.pushback(&s, 'k');
	printf("%ld\n", s.size);
	printf("%ld\n", strlen(s.data));
	s.print(s);
	return 0;
}
