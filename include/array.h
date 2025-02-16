#ifndef ARRAY_H
#define ARRAY_H

#include <string.h>
class Array {

private:
  int _capacity; // the total capasity
  int _size; // the current size of the list
  int _limit;

public:
  int *data;

  Array();
  Array(int size);
  Array(int size, int value);
  Array(const Array& other);
  ~Array();

   // oerators
   int& operator[](int index);
   Array& operator=(const Array &other);

  // Methods
  void push_back(int item);
  void pop_back();
  void insert(int index, int item);
  void erase(int item);
  void resize(int size);
  void reserve(int size);
  int get_size();
  int get_capacity();
  void print();
};

#endif
