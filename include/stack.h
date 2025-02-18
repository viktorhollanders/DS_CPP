#ifndef _STACK_H
#define _STACK_H
#include "dll.h"


class Stack {

  Dll stack;

  public:
      void push(int value);
      int pop();
      int top();
      bool isEmpty();
  };

#endif