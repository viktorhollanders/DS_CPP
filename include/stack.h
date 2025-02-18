#ifndef _STACK_H
#define _STACK_H
#include "dll.h"

class Stack {


  public:
    Dll stack;
    void push(int value);
      int pop();
      int top();
      bool isEmpty();
  };

#endif