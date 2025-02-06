#include <string.h>

#ifndef ARRAY_H
#define ARRAY_H

class Array {

private:
  int capacity;
  int size;

public:
  Array();
  Array(int capacity);
  ~Array();

  // Methods
  void size();
  void push_back(int item);
  int pop_back(int item);
  void insert(int item);
  void erase(int item);
  void resize(int capacity = 4);
  Array reserve();
};

#endif

// You must implement the constructor,
//  copy constructor,
// push_back,
// pop_back,
// insert,
// erase,

// resize,
// reserve methods
