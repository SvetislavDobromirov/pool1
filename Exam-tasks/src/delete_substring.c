#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// считывание строчки
char *str_input() {
    char *result = NULL, c;
    int n = 0;
    c = getchar();
    while (c != '\n') {
        char *tmp_str = result;
        result = realloc(tmp_str, (++n + 1) * sizeof(char));
        result[n - 1] = c;
        c = getchar();
    }
    if (result)
        result[n] = '\0';
    return result;
}

int main() {
    char *str = str_input(), *sub_str = str_input();
    // ищем последнее вхождение подстроки sub_str
    // в строку str
    char *last = NULL, *last_tmp = NULL;
    if (str) {
        last = strstr(str, sub_str), last_tmp = last;
    }
    while (last_tmp) {
        last = last_tmp;
        // сдвиг вхождения на подстроку, которую нужно удалить
        last_tmp += strlen(sub_str);
        last_tmp = strstr(last_tmp, sub_str);
    }
    if (last) {
        last += strlen(sub_str);
        // тупо меняем напрямую символы в строке на нужные
        for (size_t i = 0; i < strlen(last); i++)
            str[strlen(str) - strlen(last) - strlen(sub_str) + i] = last[i];
        // перемещаем символ конца строки
        str[strlen(str) - strlen(sub_str)] = '\0';
    }
    if (str)
        printf("%s", str);
    if (str)
        free(str);
    if (sub_str)
        free(sub_str);
    return 0;
}
