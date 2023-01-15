#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = malloc(256 * sizeof(char));
    fgets(str, 256, stdin);
    int flag = 1;

    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 2]) {
            flag = 0;
            break;
        }
    }
    printf("%s", (flag == 1) ? "YES" : "NO");
    free(str);
    return 0;
}
// на вход подается строка. является ли строка палиндромом?








    // char* poscr = strchr(str,'\n');
    // if (poscr != NULL) *poscr = '\0';
    // printf("-%s-",str);