#include <cassert>
#include <iostream>
#include "../include/array.h"

using std::cout;
using std::cin;
using std::ws;

int vecs[1000];

int main() {
    int q;
    cin >> q;
    Array my_arr;

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
        }
        else if (op == '+') {
            int value;
            cin >> value;
            // Push back
            my_arr.push_back(value);
        }
        else if (op == '-') {
            // Pop back
            my_arr.pop_back();
        }
        else if (op == 'i') {
            int index, value;
            cin >> index >> value;
            // Insert
            my_arr.insert(index, value);
        }
        else if (op == 'e') {
            int index;
            cin >> index;
            // Erase
            my_arr.erase(index);
        }
        else if (op == 'g') {
            int index;
            cin >> index;
            // Get
            my_arr[index];
        }
        else if (op == 's') {
            int index, value;
            cin >> index >> value;
            // Set
            my_arr[index] = value;
        }
        else if (op == 'r') {
            int sz;
            cin >> sz;
            // Resize
            my_arr.resize(sz);
        }
        else if (op == 'p') {
            // Print
            for (int i = 0; i < my_arr.get_size(); i++) {
              std::cout << my_arr[i] << std::endl;
            }
        }
        else {
            assert(false);
        }
    }
}
