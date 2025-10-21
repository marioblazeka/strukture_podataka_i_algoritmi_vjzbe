#include <iostream>
using namespace std;

typedef int elementtype;

struct element {
    elementtype value;
    element* next;
};

typedef element* List1;
typedef element* List2;

// Print two lists side by side
void printL(List1 Li1, List2 Li2) {
    element* t1 = Li1;
    element* t2 = Li2;

    if (t1 == NULL && t2 == NULL) {
        cout << "Obe liste su prazne!" << endl;
        return;
    }

    cout << "Lista1\t\tLista2" << endl;
    cout << "--------------------------" << endl;

    while (t1 != NULL || t2 != NULL) {
        if (t1 != NULL) {
            cout << t1->value << "\t\t";
            t1 = t1->next;
        } else {
            cout << "-\t\t";  // placeholder if one list is shorter
        }

        if (t2 != NULL) {
            cout << t2->value;
            t2 = t2->next;
        } else {
            cout << "-";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // First list
    List1 L1 = NULL;
    element* a1 = new element;
    element* a2 = new element;
    element* a3 = new element;
    a1->value = 5; a1->next = a2;
    a2->value = 7; a2->next = a3;
    a3->value = 1; a3->next = NULL;
    L1 = a1;

    // Second list
    List2 L2 = NULL;
    element* b1 = new element;
    element* b2 = new element;
    b1->value = 10; b1->next = b2;
    b2->value = 20; b2->next = NULL;
    L2 = b1;

    // Print both
    printL(L1, L2);

    // Free memory
    while (L1 != NULL) {
        element* temp = L1;
        L1 = L1->next;
        delete temp;
    }
    while (L2 != NULL) {
        element* temp = L2;
        L2 = L2->next;
        delete temp;
    }

    return 0;
}

