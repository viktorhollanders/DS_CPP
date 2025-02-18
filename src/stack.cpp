#ifndef _STACK_CPP
#define _STACK_CPP

#include <cassert>
#include <iostream>
#include "stack.h"

Stack::Stack() {};

bool Stack::isEmpty() {
  return array_stack.get_size() == 0;
}

void Stack::pop() {
  return array_stack.pop_back();
}

void Stack::push(int value) {
  array_stack.push_back(value);
}

int Stack::top() {
  if (isEmpty()) return 0;
  int size = array_stack.get_size();
  return array_stack[size - 1];
}

#endif