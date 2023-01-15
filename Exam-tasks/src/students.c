#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    char* firstName;
    char* lastName;
    int grow;
}Man;

int main() {
    int n;
    int flag = 1;
    scanf("%d", &n);
    if (n > 0) {
    Man* people = malloc(n * sizeof(Man));
    
    for(int i = 0; i < n; i++) {
        people[i].firstName = malloc(256*sizeof(char));
        people[i].lastName = malloc(256*sizeof(char));

        int check = scanf("%s %s %d", people[i].firstName, people[i].lastName, &people[i].grow);
        if (check != 3) {
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        printf("n/a");
        for(int i = 0; i < n; i++) {
        free(people[i].firstName);
        free(people[i].lastName);   
    }
    free(people);
    } else {

    for(int i = 0; i < n; i++) {
        if(people[i].grow > 180) {
            if(i != 0) {
                printf(", ");
            }
            printf("%s %s", people[i].firstName, people[i].lastName);
        }
    }
    
    for(int i = 0; i < n; i++) {
        free(people[i].firstName);
        free(people[i].lastName);   
    }
    free(people);
    }
    } else {
        printf("n/a");
    }

    return 0;
}

typedef struct data {
    char name[20];
    int grade;
} Student;



/*

int main() {
    int n;
    scanf("%d", &n);

    Student* arr = malloc(n * sizeof(Student));

    for(int i = 0; i < n; i++) {
        scanf("%20s %d", arr[i].name, &arr[i].grade);
    }
    int max = arr[0].grade;
    for(int i = 1; i < n; i++) {
        if(arr[i].grade > max) {
            max = arr[i].grade;
        }
    }

    int hasout = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i].grade == max) {
            if (hasout == 1) printf(",");
            printf("%s", arr[i].name);
            hasout = 1;
        }
    }

    free(arr);
    return 0;
}

*/









// int main() {
//     char* str = malloc(256 * sizeof(char));
//     scanf("%s", str);
//     int flag = 1;

//     int n = strlen(str);
//     for(int i = 0; i < n/2; i++) {
//         if(str[i] == str[n/2-i]) {
//             flag = 0;
//         }
//     }

//     if (flag == 1) {
//         printf("1");
//     } else {
//         printf("0");
//     }

//     return 0;
// }

//    /*
//         Создать структуру студента с именем и баллом.
//         Ввести N студентов, каждое имя и баллы с новой
//         строки. Имя не длиннее 20 символов. Проверить
//         входные данные на валидность. Вывести студентов
//         через запятую тех, у кого наибольший балл.
//     */
//     int n, check = 1;
//     Student *data = NULL;
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         check = 0;
//     } else {
//         data = malloc(n * sizeof(Student));
//     }
//     if (check == 1) {
//         for (int i = 0; i < n; i++) {
//             if (scanf("%20s\n%d", data[i].name, &data[i].grade) != 2 || data[i].grade < 0) {
//                 check = 0;
//                 break;
//             }
//         }
//     }
//     if (check != 1) {
//         printf("n/a");
//     } else {
//         int max_grade = data[0].grade;
//         for (int i = 1; i < n; i++) {
//             if (data[i].grade > max_grade)
//                 max_grade = data[i].grade;
//         }
//         // вывод искомыъ студентов
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (data[i].grade == max_grade) {
//                 if (count++ != 0)
//                     printf(", ");
//                 printf("%s", data[i].name);
//             }
//         }
//     }
//     if (data != NULL)
//         free(data);
/*

*/




//{
    /* data */
//};


   /*
        Структура: имя, фамилия, рост.
        Вывести людей выше определённого
        значения.
    */
//     int n, m, check = 0;
//     Human *data = NULL;
//     if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m < 0) {
//         check = 1;
//     } else {
//         data = malloc(n * sizeof(Human));
//         for (int i = 0; i < n; i++) {
//             if (scanf("%s\n%s\n%d", data[i].name, data[i].last_name, &data[i].height) != 3) {
//                 check = 1;
//                 break;
//             }
//         }
//     }
//     if (check == 1) {
//         printf("n/a");
//     } else {
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (data[i].height > m) {
//                 if (count++ != 0) {
//                     printf(", ");
//                 }
//                 printf("%s %s", data[i].name, data[i].last_name);
//             }
//         }
//     }
//     if (data != NULL)
//         free(data);
//     #endif
//     return 0;
// }