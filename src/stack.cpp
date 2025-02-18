#ifndef _STACK_CPP
#define _STACK_CPP

#include <cassert>
#include <iostream>
#include "stack.h"
#include "dll.h"

Bool Stack::isEmpty() {
  return Dll::empty();
}

int Stack::pop(Node* last_val) {
  return Dll::erase(Node* last_val);
}

void Stack::push(Node* last_val, int value) {
  Dll::insert(Node* last_val, value)
}

int Stack::top() {
  if (Stack::isEmpty()) return NULL;

  return Dll::back()->data;
}

#endif