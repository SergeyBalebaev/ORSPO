	#include <stdio.h>

	#define PRINT_VALUE(x) _Generic((x), \
		int: print_int, \
		float: print_float, \
		double: print_double, \
		char: print_char, \
		char*: print_str, \
		void*: print_ptr, \
		default: print_unsuppoted \
	) (x)

	#define IS_INTEGER(x) _Generic((x), \
		int: is_int_int, \
		short: is_short_int, \
		long: is_long_int, \
		char: is_char_int, \
		unsigned int: is_uint_int, \
		unsigned short: is_ushort_int, \
		unsigned long: is_ulong_int, \
		unsigned char: is_uchar_int, \
		default: isnt_int \
	) (x)

	#define SPEC(x) _Generic((x), \
		int: "%d\n", \
		float: "%f\n", \
		double: "%df\n", \
		char: "%c\n", \
		char*: "%s\n", \
		void*: "%p\n" \
	)

	void print_int(int x) {printf("int %d\n", x);}
	void print_float(float x) {printf("float %f\n", x);}
	void print_double(double x) {printf("double %lf\n", x);}
	void print_char(char x) {printf("char %c\n", x);}
	void print_str(char* x) {printf("string %s\n", x);}
	void print_ptr(void* x) {printf("pointer %p\n", x);}
	void print_unsuppoted() {printf("unsupported data type\n");}

	int is_int_int(int x) {return 1;}
	int is_short_int(short x) {return 1;}
	int is_long_int(long x) {return 1;}
	int is_char_int(char x) {return 1;}
	int is_uint_int(unsigned int x) {return 1;}
	int is_ushort_int(unsigned short x) {return 1;}
	int is_ulong_int(unsigned long x) {return 1;}
	int is_uchar_int(unsigned char x) {return 1;};
	int isnt_int() {return 0;}

	int main() {
		int i = 2;
		float f = 2.71;
		double d = 3.14159;
		char c = 'H';
		char* s = "hello, world";
		void* x = &i;
		
		char** govno = &s;
		
		PRINT_VALUE(i);
		PRINT_VALUE(f);
		PRINT_VALUE(d);
		PRINT_VALUE(c);
		PRINT_VALUE(s);
		PRINT_VALUE(x);
		PRINT_VALUE(govno);
		PRINT_VALUE(IS_INTEGER(i));
		PRINT_VALUE(IS_INTEGER(c));
		unsigned long l = 1231231231231;
		PRINT_VALUE(IS_INTEGER(l));
		PRINT_VALUE(IS_INTEGER(s));
		
		
		printf(SPEC(i), i);
		printf(SPEC(c), c);
		return 0;
	}
