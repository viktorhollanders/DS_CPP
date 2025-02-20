#include <cassert>
#include <iostream>
#include "deque.h"

using std::cout;
using std::cin;
using std::ws;

Deque deque[1000];

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int instance;
        cin >> instance;
        instance--; // Change to 0-based index

        // Consume whitespace before reading character
        cin >> ws;
        char op;
        cin >> op; // Read operation character

        if (op == 'a') {
            int other;
            cin >> other;
            other--; // Change to 0-based index
            // Assignment
            deque[instance] = deque[other];
        }
        else if (op == '+') {
          int value;
            char le;
            cin >> le;
            if (le == 'f') {

              cin >> value;
              // Push front
              deque[instance].push_front(value);
            } else if (le == 'b'){
              cin >> value;
              // Push back
              deque[instance].push_back(value);
            }
        }
        else if (op == '-') {
          char le;
            cin >> le;
            if (le == 'f') {
              // Pop front
              deque[instance].pop_front();
            } else if (le == 'b') {
              // Pop back
              deque[instance].pop_back();
            }
        }
        else if (op == 'f') {
            // gets the first element
            cout << deque[instance].front()->data << '\n';
        }
        else if (op == 'b') {
            // gets the last element
            cout << deque[instance].back()->data << '\n';
        }
        else if (op == 's') {
          cout << deque[instance].size() << '\n';
      }
        else {
            assert(false);
        }
    }
}
