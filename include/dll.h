#ifndef _DLL_H
#define _DLL_H


struct Node {
  int data;
  Node* _next;
  Node* _prev;

  Node(int val = 0): data(val), _next(NULL), _prev(NULL) {};
};

class Dll {

  private:
    int _size;

  public:
    Node* _header;
    Node* _trailer;
    Dll();
    Dll(const Dll& other);
    ~Dll();

    // operators
    Dll& operator=(const Dll& other);

    // Methods

     // modifiers

     Node* insert(Node* node, int item);
     Node* erase(Node* cursor);
     void clear();


    // element access
    Node* front();
    Node* back();

    Node* get_next(Node* node);
    Node* get_prev(Node* node);


    // capacity
    bool empty();
    int get_size();
    void print(Node* node);

};
#endif
