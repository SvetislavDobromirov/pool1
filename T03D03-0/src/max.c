#include <stdio.h>

int max(int a, int b);

int main() {
    int a = 0, b = 0;
    char c;
    int _return = scanf("%d %d%c", &a, &b, &c);
    //  Enter must be "int int\n"
    //  _return must equal 3
    if (c != '\n' || _return != 3) {
        printf("n/a");
    } else {  // everything is correct
       printf("%d", max(a, b));
    }
    return 0;
}

int max(int a, int b) {
    int _max = 0;
    if (a > b)
        _max = a;
    else
        _max = b;
    return _max;
}
