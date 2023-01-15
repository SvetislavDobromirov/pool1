#include <stdio.h>
#include <stdlib.h>

int input(int* x);
int mult(int* x);

int main() {
    int x;
    int result;
    int flag;
    flag = input(&x);
    if (flag == 1) {
       result = mult(&x);
       printf("%d", result);
    }
    else {
        printf("n/a");
    }
    return 0;
}

int input(int *x) {
    int check = scanf("%d", x);
    return check;
}

int mult(int* x) {
    int y;
    if (*x < 0) {
        y = -(*x);
    } else {
        y = *x;
    }

    int mult = 1;
    int flag = 0;
    while (y != 0) {
        if ((y%10)%2 == 1) {
            mult *= y%10;
            flag = 1;
        }
        y /= 10;
    }
    if (flag == 0) {
        mult = 0;
    }

    return mult;
    
}

// вводится произвольное целое число, вывести произведение
// нечетных чисел этого числа (всегда положительное),
// ноль - если таких нет, n/a на любые ошибки