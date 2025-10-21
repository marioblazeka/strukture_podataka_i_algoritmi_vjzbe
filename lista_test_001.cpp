#include <iostream>
using namespace std;

typedef int elementtype;

struct element {
    elementtype value;   // data
    element* next;       // pointer to next node
};

int main() {
    // Create three nodes dynamically
    element *a, *b, *c;

    a = new element;
    b = new element;
    c = new element;

    // Assign values and link them
    a->value = 5;
    a->next = b;

    b->value = 6;
    b->next = c;

    c->value = 7;
    c->next = NULL;  // last node

    // Traverse the list
    element* current = a;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

    // Free memory (good practice)
    delete a;
    delete b;
    delete c;

    system("pause");
    return 0;
}

