#include <stdio.h>
#include <stdlib.h>

int input(int *x);
int change(int *x);

int main() {
    int x;
    int flag;
    flag = input(&x);
    if (flag == 1) {
        change(&x);
    }
    else {
        printf("n/a");
    }
    return 0;
}

// инпут и проверка на валидность
int input(int *x) {
    int check = scanf("%d", x);
    return check;
}

// меняем местами символы
int change(int *x) {
    int y;
    if (*x < 0) {
        y = -(*x);
    }
    else {
        y = *x;
    }
    int a, b, c;
    a = y % 10;
    b = (y / 10) % 10;
    c = y / 100;

    if (*x < 0) {
        printf("-%d%d%d", a, b, c);
    }
    else {
        printf("%d%d%d", a, b, c);
    }
    return 0;
}

// вводится трехзначное число(в т.ч. отрицательное) поменять местами первый и последний символ