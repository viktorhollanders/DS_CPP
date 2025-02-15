#include <iostream>
#include "../include/array.h"


void printArr(Array arr){
  int size  = arr.get_size();
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
}

int main(){
  Array a1;

  a1.pop_back();

  std::cout << a1.get_capacity() << std::endl;

  // add some elements
  a1.push_back(10);
  a1.push_back(20);
  a1.push_back(30);
  a1.push_back(40);

  printArr(a1);

  a1.push_back(50);
  a1.push_back(60);
  printArr(a1);

  std::cout << a1.get_capacity() << std::endl;
  std::cout << a1.get_size() << std::endl;


  return 0;
}