#ifndef _DLL_CPP
#define _DLL_CPP

#include <cassert>
#include <iostream>
#include "dll.h"

// constructors
Dll::Dll() {
  _header =  new Node();
  _trailer = new Node();

  _header->_next = _trailer;
  _trailer->_prev = _header;
  _size = 0;
};

Dll::Dll(const Dll& other) {

  Node* current  = other._header->_next;
  while (current != other._trailer) {
    insert(_trailer, current->data);
    current = current->_next;
  }
};

// deconstructor
Dll::~Dll(){
  Node* curr = _header;
  while (curr != NULL) {
    Node* next_node = curr->_next;
    delete curr;
    curr = next_node;
  }
};

// operators
Dll& Dll::operator=(const Dll& other) {
  if (&other == this) return *this;

  clear();

  Node* current = other._header->_next;

  while(current != other._trailer) {
    insert(_trailer, current->data);
    current = current->_next;
  }

  return *this;
};

// Methods

// element access
Node* Dll::front() {
  if (Dll::empty()) return _trailer;
  return _header->_next;
};

Node* Dll::back() {
  if (Dll::empty()) return _trailer;
  return _trailer->_prev;
};

// // modifiers


/* inserts a node in the Dll */
Node* Dll::insert(Node* cursor, int item) {
  if (cursor == _header) cursor = _header->_next;

  Node* new_node = new Node();
  new_node->data = item;

  new_node->_next = cursor;
  new_node->_prev = cursor->_prev;

  cursor->_prev->_next = new_node;
  cursor->_prev = new_node;

  _size++;

  return new_node;
};

/* erases the current node and returns the next node to that node */
Node* Dll::erase(Node* cursor) {
  if (cursor == _header || cursor == _trailer) return _trailer;

  Node* next_node = cursor->_next;

  cursor->_next->_prev = cursor->_prev;
  cursor->_prev->_next = cursor->_next;


  cursor->_next = NULL;
  cursor->_prev = NULL;

  delete cursor;

  _size--;

  return next_node;
};

void Dll::clear() {
  while (!empty()) {
    erase(_header->_next);
  }

  this->_header->_next = _trailer;
  this->_trailer->_prev = _header;
  _size = 0;
}

/* returns if the Dll is empty */
bool Dll::empty() {
  return _header->_next == _trailer;
};

/* returns the size of the Dll */
int Dll::get_size() {
  return _size;
};

Node* Dll::get_next(Node* cursor) {
  return cursor->_next;
}

Node* Dll::get_prev(Node* cursor) {
  return cursor->_prev;
}

/* prints the Dll */
void Dll::print(Node* node) {
  std::cout << node->data << std::endl;
}

#endif