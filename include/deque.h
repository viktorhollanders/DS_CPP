#ifndef _DEQUE_H
#define _DEQUE_H
#include "dll.h"

class Deque {
  public:
    Dll dll_deque;;

    Deque();
    Deque(const Deque& other);
    ~Deque();

    // Operators
    Deque& operator=(const Deque& other);

    // Methods
    void push_front(int value);
    void push_back(int value);


    void pop_front();
    void pop_back();

    Node* front();
    Node* back();
    int size();
};

#endif