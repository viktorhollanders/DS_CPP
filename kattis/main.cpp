#include <iostream>
#include "array.h"

int main(){
  Array arr1;
  Array arr2;

  arr1.push_back(33);

  std::cout << arr1[0] << std::endl;

  arr1.resize(5);

  arr1.print();

  arr2.insert(0, -14);
  arr2.print();

  std::cout <<"copy arr1 to arr2" << std::endl;
  arr2 = arr1;

  std::cout << "print arr2" << std::endl;
  arr2.print();

  arr2 = arr2;

  std::cout << "print arr2" << std::endl;
  arr2.print();

  arr1.push_back(1);
  arr1.push_back(3);
  arr1.push_back(4);

  arr1.insert(1, 2);

  arr1.print();

  arr1.erase(2);
  std::cout << "print after erase" << std::endl;
  arr1.print();


  std::cout << "print element access arr1[5] should return 1" << std::endl;
  std::cout << arr1[5] << std::endl;

  arr1.resize(3);
  arr1.print();

  return 0;
}