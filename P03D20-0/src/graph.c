#include "string_analysis.h"
#include <stdio.h>

int main() {
    char *str = str_input();
    // str = str_push(str, 'r');
    printf("%s", str);
    free(str);
    return 0;
}
