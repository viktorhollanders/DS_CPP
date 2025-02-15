#include <string.h>

#ifndef ARRAY_H
#define ARRAY_H

class Array {

private:
  int _capacity; // the total capasity
  int _size; // the current size of the list

public:
  int *data;

  // oerators
  int &operator[](int index);

  Array() : _capacity(4), _size(0) {
    data = new int[_capacity];
  }
  Array(int _size, int value) : _capacity(_size) {
    data = new int[_capacity];
  }

  Array(const Array& other);
  ~Array() {};

  // Methods
  void push_back(int item);
  void pop_back();
  int insert(int index, int item);
  void erase(int item);
  void resize(int size);
  void reserve(int size);
  int get_size();
  int get_capacity();
  char print();
};

#endif
