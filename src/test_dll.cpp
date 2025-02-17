#include <iostream>
#include "dll.h"

int main(){

  Dll list1;
  Dll list2;

  Node* cursor1 = list1._header->_next;
  Node* cursor2 = list2._header->_next;

  list1.insert(cursor1, 5);

  std::cout << "THIS IS LIST 1" << std::endl;
  Node* cur1 = list1._header->_next;
  while (cur1 != list1._trailer) {
    std::cout << cur1->data << std::endl;
    cur1 = cur1->_next;
  }
  std::cout << std::endl;

  list2.insert(cursor2, 3);
  list2 = list1;


  std::cout << "THIS IS LIST 2" << std::endl;
  Node* cur2 = list2._header->_next;
  while (cur2 != list2._trailer) {
    std::cout << cur2->data << std::endl;
    cur2 = cur2->_next;
  }




  return 0;
}