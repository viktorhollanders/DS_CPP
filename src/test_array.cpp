#include <iostream>
#include "../include/array.h"


void printArr(Array arr){
  int size  = arr.get_size();
  std::cout << size << std::endl;

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(){
  Array a1;

  a1.push_back(1);
  a1.push_back(2);
  a1.push_back(3);
  a1.push_back(4);
  a1.push_back(5);

  printArr(a1);
  return 0;
}