#ifndef _STACK_H
#define _STACK_H

class Stack {
  public:
      void push(int value);
      int pop();
      int top();
      bool isEmpty();
  };

#endif