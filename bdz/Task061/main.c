#include <stdio.h>

int main() {
    
    char input[1000];
    fgets(input, sizeof(input),stdin);
    puts(input);
    return 0;
}
