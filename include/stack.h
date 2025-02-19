#ifndef _STACK_H
#define _STACK_H
#include "array.h"

class Stack {
  public:
    Array array_stack;

    Stack();

    void push(int value);
    void pop();
    int top();
    bool isEmpty();
    int size();
};

#endif