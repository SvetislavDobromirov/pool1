#include "string_analysis.h"

char *str_push(char *str, const char c) {
    if (str != NULL) {
        str = realloc(str, (strlen(str) + 1) * sizeof(char));
        str[strlen(str)] = '\0';
    } else {
        str = malloc(2 * sizeof(char));
        str[1] = '\0';
    }
    str[strlen(str) - 1] = c;
    return str;
}

char *str_input() {
    char *result = NULL, c = getchar();
    while (c != '\0' && c != '\n') {
        result = str_push(result, c);
        c = getchar();
    }
    return result;
}

char *str_del_sp(char *str) {
    char *result = NULL;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            result = str_push(result, str[i]);
        }
        i++;
    }
    return result;
}

int str_to_double(char *str) {
    int result = 0, count = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] - '0' >= 0 && str[i] - '9' <= 9) {
            result += ((int) (str[i] - '0')) * pow(10, count++);
        } else {
            result = -1;
            break;
        }
        i++;
    }
    return result;
}
