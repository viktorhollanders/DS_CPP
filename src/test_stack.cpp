#include <iostream>
#include "stack.h"
#include <cassert>


int main() {


  Stack myStack;

  myStack.push(1);
  assert(myStack.top() == 1);
  std::cout << "Test 1 Passed: push(1), top() == 1" << std::endl;

  myStack.push(2);
  assert(myStack.top() == 2);
  std::cout << "Test 2 Passed: push(2), top() == 2" << std::endl;

  assert(myStack.size() == 2);
  std::cout << "Test 3 Passed: size() == 2 after two pushes" << std::endl;

  myStack.pop();
  assert(myStack.size() == 1);
  std::cout << "Test 4 Passed: pop(), size() == 1" << std::endl;


  std::cout << "Test sujit 1 passed" << std::endl;

  Stack myStack1;
  Stack myStack2;

  myStack1.push(-9);
  myStack1.push(6);
  myStack1.push(42);
  myStack2.push(-5);

  assert(myStack1.size() == 3);
  std::cout << "Test 5 Passed: myStack1.size() = 3" << std::endl;

  assert(myStack2.size() == 1);
  std::cout << "Test 5 Passed: myStack2.size() = 1" << std::endl;


  return 0;
}