#ifndef _ARRAY_CPP
#define _ARRAY_CPP

#include <cassert>
#include <iostream>
#include "array.h"

Array::Array() {
  _capacity = 4;
  _size = 0;
  _limit = 0;
  data = new int[_capacity];
}

Array::Array(int size) : _capacity(size),  _size(size) {
  data = new int[_capacity];
  for (int i = 0; i < _capacity; i++) {
      data[i] = 0;
  }
}

Array::Array(int size, int value) : _capacity(size), _size(size) {
  data = new int[_capacity];
  for (int i = 0; i < _size; ++i) {
      data[i] = value;
  }
}

/* copy constructor */
Array::Array(const Array& other) {
  _size = other._size;
  _capacity = other._capacity;
  data = new int[_capacity];

  for (int i = 0; i < _size; i++) {
    data[i] = other.data[i];
  }
}

/* deconstructor */
Array::~Array(){
  delete[] data;
}

/* [] operator*/
int& Array::operator[](int index){
  assert(index >= 0 && index < _size);
  return data[index];
}

/* = operator*/
 Array &Array::operator=(const Array& other) {
  if (&other == this) return *this;

  // free old memmory
  delete[] data;

  // copy the propperties
  _size = other._size;
  _capacity = other._capacity;

  // allocate the new memmory
  data = new int[_capacity];

  // copy over the data
  for (int i = 0; i < _size; i++) {
    data[i] = other.data[i];
  }

  return *this;
}

/* Adds an item to the back of the array */
void Array::push_back(int item) {
  if (_size >= _capacity) {
    Array::reserve(_capacity * 2);
  }
  data[_size] = item;
  _size++;
}

/* Removes an item to the back of the array */
void Array::pop_back() {
  if (_size <= 0) return;
  _limit = 4;
  _size--;

  if (_size < _capacity / 4) {
    int new_capacity = _size < _limit ? 4 : _capacity / 2;
    reserve(new_capacity);
  }
}

/* Insert an item at a given index in the array */
void Array::insert(int index, int item) {
  if (index < 0 || index > _size) return;

  if (_size + 1 >= _capacity) {
    reserve(_capacity * 2);
  }

  for (int i = _size; i >= index; i--) {
    data[i + 1] = data[i];
  }

  data[index] = item;
  _size++;
}

/* Removes an item at a given index from the array */
void Array::erase(int index) {
  if (_size < 0 || index < 0 || index >= _size) return;
  for (int i = index; i < _size - 1; i++)
  {
    data[i] = data[i + 1];
  }
  _size--;
}

/* changes how many items an array can hold */
void Array::resize(int new_size) {
  if (new_size < 0 || new_size == _size) return;

  if (new_size < _size) {
    _size = new_size;
  } else if (new_size > _size) {
    if (new_size >= _capacity) reserve(new_size *2);
    for (int i = _size; i < new_size; i++) {
      data[i] = 0;
    }
    _size = new_size;
  }

}

/* Reserves space for an array of a given size */
void Array::reserve(int new_capacity) {
  if (new_capacity < 0) return;
  if (new_capacity <= _capacity) return;

  int *temp_arr = new int[new_capacity];

  for (int i = 0; i < _size; i++){
      temp_arr[i] = data[i];
  }

  delete[] data;
  data = temp_arr;
  _capacity = new_capacity;
}

/* Gets the size of an array which is how many items are currently in the array */
int Array::get_size() {
  return _size;
}

/* Gets the capasity of the array which is how many item the array can hold in total */
int Array::get_capacity() {
  return _capacity;
}

/* A print function */
void Array::print(){
  int size  = this->get_size();
  std::cout << size << std::endl;

  for (int i = 0; i < size; i++) {
    std::cout << this->data[i] << " ";
  }
  std::cout << std::endl;
}

#endif