#include <iostream>
#include "array.h"
#include <cassert>


int main(){

  Array myArr;

  myArr.push_back(1);
  myArr.push_back(2);
  myArr.push_back(3);
  myArr.push_back(3);

  assert(myArr.get_size() == 4);


  myArr.push_back(5);
  assert(myArr.get_capacity() == 8);


}