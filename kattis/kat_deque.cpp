#include <cassert>
#include <iostream>
#include <cstring>
#include "deque.h"
#include "deque.cpp"


using std::cout;
using std::cin;
using std::ws;

Deque deques[1000];

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int instance;
        cin >> instance;
        instance--;  // Convert to 0-index.
        char op[10];
        cin >> ws >> op;

        if (strcmp(op, "a") == 0) {
            int other;
            cin >> other;
            other--;
            deques[instance] = deques[other];
        }
        else if (strcmp(op, "+f") == 0) {
            int value;
            cin >> value;
            deques[instance].push_front(value);
        }
        else if (strcmp(op, "+b") == 0) {
            int value;
            cin >> value;
            deques[instance].push_back(value);
        }
        else if (strcmp(op, "-f") == 0) {
            deques[instance].pop_front();
        }
        else if (strcmp(op, "-b") == 0) {
            deques[instance].pop_back();
        }
        else if (strcmp(op, "f") == 0) {
            cout << deques[instance].front() << '\n';
        }
        else if (strcmp(op, "b") == 0) {
            cout << deques[instance].back() << '\n';
        }
        else if (strcmp(op, "s") == 0) {
            cout << deques[instance].size() << '\n';
        }
        else {
            assert(false && "Unknown operation");
        }
    }
    return 0;
}
