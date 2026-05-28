#include "age.h"

void countPrice(int age) {
    if(age < 0) puts("Неверный ввод");
    if(age >= 0 && age <= 6) puts("0");
    if(age > 6 && age < 18) puts("50");
    if(age >= 18) puts("100");
}
