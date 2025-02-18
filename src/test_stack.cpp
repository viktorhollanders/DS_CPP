#include <iostream>
#include "stack.h"

int main() {
  Stack myStack;

  myStack.push(10);
  myStack.push(20);

  std::cout << "Top element: " << myStack.top() << std::endl;

  return 0;
}