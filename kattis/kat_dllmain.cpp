#include <cassert>
#include <iostream>
#include "dll.h"

using std::cout;
using std::cin;
using std::ws;

Dll lists[1000];
Node* cursors[1000];

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < 1000; i++) {
        cursors[i] = lists[i].back();
    }

    for (int i = 0; i < q; i++) {
        int instance;
        cin >> instance;
        instance--;
        cin >> ws;
        char op;
        cin >> op;

        if (op == 'a') {
            int other;
            cin >> other;
            other--;
            lists[instance] = lists[other];
            cursors[instance] = lists[instance].back();
        }
        else if (op == 'f') {
            cursors[instance] = lists[instance].front();
        }
        else if (op == 'b') {
            cursors[instance] = lists[instance].back();
        }
        else if (op == 'i') {
            int value;
            cin >> value;
            cursors[instance] = lists[instance].insert(cursors[instance], value);
        }
        else if (op == 'e') {
            cursors[instance] = lists[instance].erase(cursors[instance]);
        }
        else if (op == '>') {
            cursors[instance] = lists[instance].get_next(cursors[instance]);
        }
        else if (op == '<') {
            cursors[instance] = lists[instance].get_prev(cursors[instance]);
        }
        else if (op == 'g') {
            cout << cursors[instance]->data << '\n';
        }
        else if (op == 's') {
            int value;
            cin >> value;
            cursors[instance]->data = value;
        }
        else if (op == 'z') {
            cout << lists[instance].get_size() << '\n';
        }
        else {
            assert(false);
        }
    }
}