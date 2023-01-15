#include <stdio.h>

int sum(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int sub(int a, int b);

int main() {
    int a = 0, b = 0;
    char c;
    int _return = scanf("%d %d%c", &a, &b, &c);
    //  Enter must be "int int\n"
    //  _return must equal 3
    if (c != '\n' || _return != 3) {
        printf("n/a");
    } else {  // everything is correct
        printf("%d %d %d ", sum(a, b), sub(a, b), mul(a, b));
        if (b == 0) {
            printf("n/a");
        } else {
            printf("%d", div(a, b));
        }
    }
    return 0;
}

int sum(int a, int b) {
    return a+b;
}

int mul(int a, int b) {
    return a*b;
}

int sub(int a, int b) {
    return  a-b;
}

int div(int a, int b) {
    return a/b;
}
