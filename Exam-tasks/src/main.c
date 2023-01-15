#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
#ifdef Task_4

typedef struct data {
    char name[20];
    int grade;
} Student;

#endif

//////////////////////////////////////////////////////////////////////
#ifdef Task_7

#define Radian 57.29

#endif

//////////////////////////////////////////////////////////////////////
#ifdef Task_8

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int C(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

#endif

//////////////////////////////////////////////////////////////////////
#ifdef Task_9

typedef struct data {
    char name[20];
    char last_name[20];
    int height;
} Human;

#endif

int main() {
    //////////////////////////////////////////////////////////////////////
    #ifdef Task_1
    /*
        В stdin поступает 3 числа, каждое из которых
        может принимать 1 или 0. Необходимо вывести в stdout 1,
        если значение следующего выражения x and (z or y) истинно,
        в противном случае вывести 0. В конце строки не должно
        быть символа переноса строки. В случае ошибки вывести n/a.
    */
    int x, y, z;
    if (scanf("%d %d %d", &x, &y, &z) == 3) {
        printf("%d", x && (z || y));
    } else {
        printf("n/a");
    }
    //////////////////////////////////////////////////////////////////////
    #elif Task_2
    /*
        На вход подаётся целое положительное число n. Заполнить
        квадратную матрицу числами от 1 до n^2 по часовой стрелке.
        В случае ошибки вывести n/a.
    */
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
    } else {
        // calloc для заполнения матрицы нулями
        int **matrix = calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++)
            matrix[i] = calloc(n, sizeof(int));
        // // current position              // ГЕНИАЛЬНЫЙ
        // int current_circle = 0;          // МАТЬ ЕГО
        // // fill direction                // СПОСОБ
        // // current number                // ПРОСТО
        // int number = 0;                  // ЖЕСТЬ
        // while (number < n * n) {
        //     for (int i = current_circle; i < n - current_circle; i++)
        //         matrix[current_circle][i] = ++number;
        //     for (int i = current_circle + 1; i < n - current_circle; i++)
        //         matrix[i][n - current_circle - 1] = ++number;
        //     for (int i = n - current_circle - 2; i >= current_circle; i--)
        //         matrix[n - current_circle - 1][i] = ++number;
        //     for (int i = n - current_circle - 2; i > current_circle; i--)
        //         matrix[i][current_circle] = ++number;
        //     current_circle++;
        // }
        int count = 0, i = 0, j = 0, direction = 0;
        while (count < n * n) {
            int check = 0;
            switch (direction) {
                case 0:
                    if (j >= n)
                        check = 1;
                    else if (matrix[i][j] != 0)
                        check = 1;
                    if (check == 1) {
                        j--;
                        i++;
                        direction++;
                    } else {
                        matrix[i][j] = ++count;
                        j++;
                    }
                    break;
                case 1:
                    if (i >= n)
                        check = 1;
                    else if (matrix[i][j] != 0)
                        check = 1;
                    if (check == 1) {
                        i--;
                        j--;
                        direction++;
                    } else {
                        matrix[i][j] = ++count;
                        i++;
                    }
                    break;
                case 2:
                    if (j < 0)
                        check = 1;
                    else if (matrix[i][j] != 0)
                        check = 1;
                    if (check == 1) {
                        j++;
                        i--;
                        direction++;
                    } else {
                        matrix[i][j] = ++count;
                        j--;
                    }
                    break;
                case 3:
                    if (i < 0)
                        check = 1;
                    else if (matrix[i][j] != 0)
                        check = 1;
                    if (check == 1) {
                        i++;
                        j++;
                        direction = 0;
                    } else {
                        matrix[i][j] = ++count;
                        i--;
                    }
                    break;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                printf("%d", matrix[k][l]);
                if (l != n - 1)
                    printf(" ");
            }
            if (k != n - 1)
                printf("\n");
        }
        if (matrix != NULL) {
            for (int k = 0; k < n; k++)
                free(matrix[k]);
            free(matrix);
        }
    }
    //////////////////////////////////////////////////////////////////////
    #elif Task_3
    /*
        На вход подаётся 2 положительных числа - размеры
        матрицы. Повернуть матрицу на 90 градусов вправо.
        Входные данные проверить на валидность.
    */
    int n, m, check = 1, **matrix = NULL;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0)
        check = 0;
    if (check == 1) {
        matrix = calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++)
            matrix[i] = calloc(m, sizeof(int));
        for (int i = 0; i < n; i++)  // ввод матрицы
            for (int j = 0; j < m; j++) {
                if (scanf("%d", &matrix[i][j]) != 1) {
                    check = 0;
                    i = n;  // чтобы выйти из цикла досрочно
                    break;
                }
            }
    }
    if (check == 1) {
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                printf("%d", matrix[i][j]);
                if (i != 0)
                    printf(" ");
            }
            if (j != m - 1)
                printf("\n");
        }
    } else {
        printf("n/a");
    }
    if (matrix != NULL) {
        for (int i = 0; i < n; i++)
            free(matrix[i]);
        free(matrix);
    }
    //////////////////////////////////////////////////////////////////////
    #elif Task_4
    /*
        Создать структуру студента с именем и баллом.
        Ввести N студентов, каждое имя и баллы с новой
        строки. Имя не длиннее 20 символов. Проверить
        входные данные на валидность. Вывести студентов
        через запятую тех, у кого наибольший балл.
    */
    // typedef struct data {
        // char name[20];
        // int grade;
    // } Student;
    int n, check = 1;
    Student *data = NULL;
    if (scanf("%d", &n) != 1 || n <= 0) {
        check = 0;
    } else {
        data = malloc(n * sizeof(Student));
    }
    if (check == 1) {
        for (int i = 0; i < n; i++) {
            if (scanf("%20s\n%d", data[i].name, &data[i].grade) != 2 || data[i].grade < 0) {
                check = 0;
                break;
            }
        }
    }
    if (check != 1) {
        printf("n/a");
    } else {
        int max_grade = data[0].grade;
        for (int i = 1; i < n; i++) {
            if (data[i].grade > max_grade)
                max_grade = data[i].grade;
        }
        // вывод искомыъ студентов
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (data[i].grade == max_grade) {
                if (count++ != 0)
                    printf(", ");
                printf("%s", data[i].name);
            }
        }
    }
    if (data != NULL)
        free(data);
    //////////////////////////////////////////////////////////////////////
    #elif Task_5
    /*
        Посчитать скалярное произведение векторов
    */
    int n, *a = NULL, *b = NULL, check = 1;
    int sum = 0;
    if (scanf("%d", &n) != 1 || n <= 0) {
        check = 0;
    } else {
        a = malloc(n * sizeof(int));
        b = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &a[i]) != 1) {
                check = 0;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &b[i]) != 1) {
                check = 0;
                break;
            }
        }
        if (check != 0) {
            for (int i = 0; i < n; i++)
                sum += a[i] * b[i];
        }
    }
    if (check != 1)
        printf("n/a");
    else
        printf("%d", sum);
    if (a != NULL)
        free(a);
    if (b != NULL)
        free(b);
    //////////////////////////////////////////////////////////////////////
    #elif Task_6
    /*
        Принимаем строку на любое количество
        символов. Сделать каждое слово с большой буквы.
    */
    char *str = NULL, c;
    scanf("%c", &c);
    int n = 1;
    while (c != '\0' && c != '\n') {
        char *p = str;
        str = realloc(p, n++ * sizeof(char));
        str[n - 1] = '\0';
        str[n - 2] = c;
        scanf("%c", &c);
    }
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] += 'A' - 'a';
        }
        while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
            i++;
        i++;
    }
    printf("%s", str);
    if (str != NULL)
        free(str);
    //////////////////////////////////////////////////////////////////////
    #elif Task_7
    /*
        Перевести радианы в градусы.
    */
    double x;
    if (scanf("%lf", &x) == 1) {
        printf("%.0lf", x * Radian);
    } else {
        printf("n/a");
    }
    //////////////////////////////////////////////////////////////////////
    #elif Task_8
    /*
        Биноминальные коэффициенты
    */
    int n;
    if (scanf("%d", &n) == 1 && n >= 0) {
        for (int i = 0; i <= n; i++) {
            printf("%d", C(n, i));
            if (i != n)
                printf(" ");
        }
    } else {
        printf("n/a");
    }
    //////////////////////////////////////////////////////////////////////
    #elif Task_9
    /*
        Структура: имя, фамилия, рост.
        Вывести людей выше определённого
        значения.
    */
    int n, m, check = 0;
    Human *data = NULL;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m < 0) {
        check = 1;
    } else {
        data = malloc(n * sizeof(Human));
        for (int i = 0; i < n; i++) {
            if (scanf("%s\n%s\n%d", data[i].name, data[i].last_name, &data[i].height) != 3) {
                check = 1;
                break;
            }
        }
    }
    if (check == 1) {
        printf("n/a");
    } else {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (data[i].height > m) {
                if (count++ != 0) {
                    printf(", ");
                }
                printf("%s %s", data[i].name, data[i].last_name);
            }
        }
    }
    if (data != NULL)
        free(data);
    #endif
    return 0;
}
