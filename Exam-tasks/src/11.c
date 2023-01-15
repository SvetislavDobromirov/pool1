#include <stdio.h>
#include <stdlib.h>

// входит массив положительных чисел заканчивающихся -1
// найти минимум и максимум поменять местами
// вывести символы первый последний второй предпоследний 1 2 3 4 5 6 7 8 9  -> 1 9 2 8 3 7 4 6 5
// убрать дубликаты

void sort(int* arr, int count);
void output(int* arr, int count);
void deliteDouble(int *arr, int count);
void outputForDouble(int* arr, int count);
void outputForChaos(int* arr, int count);

int main() {
int check = 1;

int x;
int count = 0;
int* arr = NULL;

while (x != -1) {
    int check = scanf("%d", &x);
    if (x == -1) {
        break;
    }
    if (check != 1) {
        printf("n/a");
        check = 0;
        break;;
    }
    count++;
    int* temp = arr;
    arr = realloc(temp, count * sizeof(int));
    arr[count - 1] = x;
}
if (check == 0) {

} else {
//sort(arr, count);
//deliteDouble(arr,count);

//outputForDouble(arr, count);
//output(arr, count);

outputForChaos(arr, count);
}
if (arr != NULL) {
    free(arr);
}
    return 0;
}

void sort(int* arr, int count) {
    int max = arr[0];
    int countMin = 0;
    int min = arr[0];
    int countMax = 0;
for (int i = 0; i < count; i++) {
    if (arr[i] > max) {
        max = arr[i];
        countMax = i;
    }
    if (arr[i] < min) {
        min = arr[i];
        countMin = i;
    }
}
    int temp = max;
    arr[countMax] = arr[countMin];
    arr[countMin] = temp;
}

void deliteDouble(int *arr, int count) {
    for (int i = count - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if (arr[i] == arr[j]) {
                arr[i] = -1;
            }
        }
    }
}

void output(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        if (i != count-1) {
        printf("%d ", arr[i]);
        } else {
        printf("%d", arr[i]);
        }
    }
}

void outputForDouble(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        if (arr[i] != -1) {
        printf("%d ", arr[i]);
        }
    }
}


void outputForChaos(int* arr, int count) {
for(int i = 0; i < count/2; i++) {
        if (i == count/2-1) {
            printf("%d %d", arr[i], arr[count - 1 - i]);
        } else {
            printf("%d %d ", arr[i], arr[count - 1 - i]);
        }
    }
    if (count%2 == 1) {
        printf(" %d", arr[count/2]);
    }
}
