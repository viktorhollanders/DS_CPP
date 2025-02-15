#include <cassert>
#include <iostream>
#include "../include/array.h"

using std::cout;
using std::cin;
using std::ws;

Array vecs[1000];

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
            vecs[instance] = vecs[other];
        }
        else if (op == '+') {
            int value;
            cin >> value;
            // Push back
          vecs[instance].push_back(value);
        }
        else if (op == '-') {
            // Pop back
            vecs[instance].pop_back();
        }
        else if (op == 'i') {
            int index, value;
            cin >> index >> value;
            // Insert
            vecs[instance].insert(index, value);
        }
        else if (op == 'e') {
            int index;
            cin >> index;
            // Erase
            vecs[instance].erase(index);
        }
        else if (op == 'g') {
            int index;
            cin >> index;
            // Get
            vecs[instance][index];
        }
        else if (op == 's') {
            int index, value;
            cin >> index >> value;
            // Set
            vecs[instance][index] = value;
        }
        else if (op == 'r') {
            int sz;
            cin >> sz;
            // Resize
            vecs[instance].resize(sz);
        }
        else if (op == 'p') {
            // Print
            vecs[instance].print();
        }
        else {
            assert(false);
        }
    }
}
