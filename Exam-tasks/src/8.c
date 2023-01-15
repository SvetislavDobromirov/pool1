#include <stdio.h>
#include <stdlib.h>
int input(int* x);
int reverse(int x);

int main() {
    int x;
    int flag;
    flag = input(&x);
    if (flag == 1) {
        reverse(x);
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

int reverse(int x) {
    int y = x;
    if (y < 0) {
    y = - x;
    } else {
    y = x;
    }
    if (x < 0) {
        printf("-");
    }
    while (y != 0) {
        printf("%d", y%10);
        y /= 10;
    }
    if (x == 0) {
        printf("0");
    }
    return 0;
}


// развернуть и вывести число. любое отрицательное или нет