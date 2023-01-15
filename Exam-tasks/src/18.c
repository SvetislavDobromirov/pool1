#include <stdio.h>
#include <stdlib.h>
int input(int* x, int* y, int* z);

int main() {
    int x, y, z;
    int flag;
    flag = input(&x, &y, &z);
    if (flag != 3) {
        printf("n/a");
    } else {
        ((z > x && z < y) || (z < x && z > y)) ? printf("1") : printf("0");
    }

    return 0;
}


// вводятся 3 числа: a, b, c. определить, находится ли С строго между A и B.
// вывести 1, если да, 0, если нет.
// if-else использовать только для проверки корректного ввода

int input(int* x, int* y, int* z) {
    int check = scanf("%d %d %d", x, y, z);
    return check;
}
