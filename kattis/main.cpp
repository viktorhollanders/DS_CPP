#include <cassert>
#include <iostream>
#include "stack.h"

using std::cout;
using std::cin;
using std::ws;

Stack stack[1000];

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


        if (op == '+') {
            int value;
            cin >> value;
            // Push
          stack[instance].push(value);
        }
        else if (op == '-') {
            // Pop
            stack[instance].pop();
        }
        else if (op == 't') {
          // top
          cout << stack[instance].top() << '\n';
      }
        else if (op == 's') {
          cout << stack[instance].size() << '\n';
      }
        else {
            assert(false);
        }
    }
}
