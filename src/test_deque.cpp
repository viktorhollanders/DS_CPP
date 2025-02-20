#include <iostream>
#include "deque.h"

int main() {

  Deque dq;

  dq.push_back(1);

  std::cout << dq.front()->data << std::endl;

  dq.push_front(2);
  std::cout << dq.front()->data << std::endl;

  std::cout << dq.size() << std::endl;

  dq.pop_back();
  std::cout << dq.size() << std::endl;


  dq.push_back(3);
  dq.push_back(5);
  dq.push_back(3);
  std::cout << dq.back()->data << std::endl;

  dq.pop_back();
  dq.pop_back();
  dq.pop_back();
  dq.pop_back();
  dq.pop_back();



  std::cout << dq.front()->data << std::endl;
  std::cout << dq.back()->data << std::endl;
  std::cout << dq.size() << std::endl;




  std::cout << "test ran sucseffully " << std::endl;

  return 0;
}