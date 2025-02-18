#ifndef _STACK_CPP
#define _STACK_CPP

#include <cassert>
#include <iostream>
#include "stack.h"


bool Stack::isEmpty() {
  return stack.empty();
}

int Stack::pop() {
  return stack.erase(stack._trailer->_prev)->data;
}

void Stack::push(int value) {
  stack.insert(stack._trailer, value);
}

int Stack::top() {
  if (stack.empty()) return 0;

  return stack.back()->data;
}

#endif