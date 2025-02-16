#include <iostream>
#include "../include/array.h"

int main(){
  Array arr(10);

  arr[-100] = 300;
  arr[8000] = 300;

  arr.print();

  return 0;
}