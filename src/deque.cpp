#ifndef _DEQUE_CPP
#define _DEQUE_CPP

#include <cassert>
#include <iostream>
#include "deque.h"

Deque::Deque() : dll_deque() {};
Deque::Deque(const Deque& other) : dll_deque(other.dll_deque) {};
Deque::~Deque() {};

/* asignment of deque*/
Deque& Deque::operator=(const Deque& other) {
  if (this != &other) {
    this->dll_deque = other.dll_deque;
  }

  return *this;
}

/* adds element to the front */
void Deque::push_front(int item) {
  dll_deque.insert(dll_deque._header->_next, item);
};

/* adds element to the back */
void Deque::push_back(int item) {
  dll_deque.insert(dll_deque._trailer->_prev, item);
}


/* remove element from the front */
void Deque::pop_front() {
  dll_deque.erase(dll_deque._header);
}

/* remove element from the back */
void Deque::pop_back() {
  dll_deque.erase(dll_deque._trailer->_prev);
}

/* gets the first element in the Deque */
Node* Deque::front() {
  return dll_deque._header->_next;
}

/* gets the last element in the Deque */
Node* Deque::back() {
  return dll_deque._trailer->_prev;
}

/* gets the size of Deque */
int Deque::size() {
  return dll_deque.get_size();
}

#endif