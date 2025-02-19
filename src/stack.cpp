#ifndef _STACK_CPP
#define _STACK_CPP

#include <cassert>
#include <iostream>
#include "stack.h"

Stack::Stack() {};

void Stack::push(int value) {
  array_stack.push_back(value);
}

void Stack::pop() {
  return array_stack.pop_back();
}

int Stack::top() {
  if (isEmpty()) return 0;
  int size = array_stack.get_size();
  return array_stack[size - 1];
}

bool Stack::isEmpty() {
  return array_stack.get_size() == 0;
}

int Stack::size() {
  return array_stack.get_size();
}


#endif