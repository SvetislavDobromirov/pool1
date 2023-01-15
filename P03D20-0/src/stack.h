#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

void print(Node *list);
void push(Node ** plist, Data d);
int pop(Node **plist);
int top(Node **plist);

#endif  // SRC_STACK_H_