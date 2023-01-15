#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void print(Node *list) {
    for (Node *p = list; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

int top(Node **plist) {
    Node *p = *plist;
    if (p) {
        return(p->data);
    } else {
        return 0;
    }
}

int pop(Node **plist) {
    int a;
    Node * p = *plist; 
    Data res = p->data;
    *plist = p->next;
    free(p);
    return res;
}

void push(Node ** plist, Data d) {
    Node * p = malloc(sizeof(Node));
    p->data = d;
    p->next = *plist;
    *plist = p;
}

void infix_to_postfix(Node **plist, char *strng) {
    int n = strlen(strng);
    Node * p = malloc(sizeof(Node));

    for (int i = 0; i < n; i++) {
        if ((strng[i] == '(' || strng[i] == ')' || strng[i] == '+' ||
        strng[i] == '-' || strng[i] == '*' || strng[i] == '/' ||
        strng[i] == 's' || strng[i] == 'c' || strng[i] == 't' || strng[i] == '^' || strng[i] == "l") &&
        ) {

        }
        // switch(strng[i]){
        //     case '(':
        //         if ()
        //         push(&list, strng[i]);
        //     break;
        //     case ')':
        //         push(&list, strng[i]);
        //     break;
        //     case '+':
        //         push(&list, strng[i]);
        //     break;
        //     case '-':
        //         push(&list, strng[i]);
        //     break;
        //     case '*':
        //         push(&list, strng[i]);
        //     break;
        //     case '/':
        //         push(&list, strng[i]);
        //     break;
        //     case 's':
        //         push(&list, strng[i]);
        //     break;
        //     case 'c':
        //         push(&list, strng[i]);
        //     break;
        //     case 't':
        //         push(&list, strng[i]);
        //     break;
        //     case 'x':
        //         push(&list, strng[i]);
        //     break;
        //     case '^':
        //         push(&list, strng[i]);
        //     break;
        // }

    }
}

int main() {
    Data test[] = {21, 17, 3, 10};
    Data test2[] = {1, 2};
    Node * list = NULL;
    int j = 0;
    for (size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        if(test[i] > 10) {
            push(&list, test[i]);
        } else {
            test2[j] = test[i];
            j = j + 1;
        }
    }
    // for (size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
    //     push(&list, test[i]);
    //     print(list);
    // }

    // int h = top(&list);
    // printf("%d", h);
    // int f = pop(&list);
    // printf("%d", f);

    print(list);
    for (size_t i = 0; i < sizeof(test2)/sizeof(test2[i]); i++) {
        printf("%d ", test2[i]);
    }

    return 0;
}
