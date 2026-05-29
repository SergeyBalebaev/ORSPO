#include <stdio.h>

#define print_value(a) _Generic((a),\
    int:    print_value_int,\
    float:  print_value_float,\
    double: print_value_double,\
    char:   print_value_char,\
    char*:  print_value_string,\
    void*:  print_value_ptr,\
    default: print_value_unknown\
)(a)

void print_value_int(int a) {printf("int: %d\n", a);}
void print_value_float(float a) {printf("float: %f\n", a);}
void print_value_double(double a) {printf("double: %lf\n", a);}
void print_value_char(char a) {printf("char: '%c'\n", a);}
void print_value_string(char* a) {printf("string: \"%s\"\n", a);}
void print_value_ptr(void* a) {printf("pointer: %p\n", a);}
void print_value_unknown() { printf("unsupported type\n");}

#define max(a, b) _Generic((a),\
    int:    max_int,\
    float:  max_float,\
    double: max_double,\
    long:   max_long\
)(a, b)
int max_int(int a, int b) {return (a > b) ? a : b;}
float max_float(float a, float b) {return (a > b) ? a : b;}
double max_double(double a, double b) {return (a > b) ? a : b;}
long max_long(long a, long b) {return (a > b) ? a : b;}

#define is_int(a) _Generic((a),\
    int: is_int_int,\
    char: is_int_char,\
    short: is_int_short,\
    long: is_int_long,\
    unsigned int: is_int_unsint,\
    default: is_int_not\
)(a)
int is_int_int(int a){return 1;}
int is_int_char(char a){return 1;}
int is_int_short(short a){return 1;}
int is_int_long(long a){return 1;}
int is_int_unsint(unsigned int a){return 1;}
int is_int_not(){return 0;}

//specifier!
#define fc(x) _Generic((x),\
    int:"%d",\
    long:"%ld",\
    float:"%f",\
    double:"%lf",\
    char:"%c",\
    char*:"%s",\
    void*:"%p"\
)

void main(){
    int a = 33;
    float b = 23.2;
    double c = 90.2;
    char* d = "lele";
    void* ptr = &a;

    print_value(a);
    print_value(b);
    print_value(c);
    print_value(d);
    print_value(ptr);

    printf("%f\n", max(5.1, 6.4));

    char e = 'A';
    printf("%d\n", is_int(a));
    printf("%d\n", is_int(c));
    printf("%d\n", is_int(e));

    printf(fc(a),a);
    printf(fc(b),b);
    printf(fc(c),c);
    printf(fc(d),d);
    printf(fc(e),e);
}

