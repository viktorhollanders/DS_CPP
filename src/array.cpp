#include <cassert>
#include "../include/array.h"

int &Array::operator[](int index){
  if (index > _size) assert("index out of bounds");
  return data[index];
}

Array::Array(const Array &other) {
  _size = other._size;
  _capacity = other._capacity;
  data = new int[_capacity];

  for (int i = 0; i < _size; i++) {
    data[i] = other.data[i];
  }
}

/* Adds an item to the back of the array */
void Array::push_back(int num) {
  if (_size == _capacity) {
    Array::reserve(_size * 2);
  }
  data[_size] = num;
  _size++;
}

/* Removes an item to the back of the array */
void Array::pop_back() {
  assert(_size > 0 && "array is empty");

  if (_size > 0) {
    _size--;
    if (_size < _capacity - (_capacity / 4)) {
      int new_capacity = _capacity <= 4 ? 4 : _capacity / 2;
      reserve(new_capacity);
    }
  }
}

/* Insert an item in the array */
int Array::insert(int index, int item) {
  if (index > _capacity) return 1;
  data[index] = item;
  return 0;
}

/* Removes an item at a given index from the array */
void Array::erase(int index) {
  data[index] = NULL;
}

/* Reserves space for an array of a given size */
void Array::reserve(int new_capacity) {
  if (new_capacity <= _capacity) return;
    int *temp_arr = new int[new_capacity];

    for (int i = 0; i <= _capacity; i++){
      temp_arr[i] = data[i];
    }

    delete data;
    data = temp_arr;
    _capacity = new_capacity;
  }

/* changes how many items an array can hold */
void Array::resize(int size) {
  if (_capacity == size) return;
  else{
    if (size < _capacity) _capacity = _size;
  }
}

/* Gets the capasity of the array which is how many item the array can hold in total */
int Array::get_capacity() {
  return _capacity;
}

/* Gets the size of an array which is how many items are currently in the array */
int Array::get_size() {
  return _size;
}
