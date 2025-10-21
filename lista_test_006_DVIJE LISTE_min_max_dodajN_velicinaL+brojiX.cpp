#include <iostream>
using namespace std;

typedef int elementtype;

struct element {
    elementtype value;   // vrijednost u èvoru
    element* next;       // pokazivaè na sljedeæi element
};

typedef element* List;

// Funkcija koja raèuna velièinu liste
int velicinaL(List Li) {
    int count = 0;
    element* t = Li;
    while (t != NULL) {  // prolazimo sve dok ima elemenata
        count++;
        t = t->next;
    }
    return count;
}

// Funkcija koja ispisuje samo elemente manje od a
void ispisi_manje(elementtype a, List Li) {
    element* t = Li;
    bool nadjen = false;
    while (t != NULL) {
        if (t->value < a) {   // ako je vrijednost manja od a › ispiši
            cout << t->value << " ";
            nadjen = true;
        }
        t = t->next;
    }
    if (!nadjen) cout << "Nema elemenata manjih od " << a;
    cout << endl;
}

// Funkcija koja uveæava sve elemente za x
void uvecaj(List Li, elementtype x) {
    element* t = Li;
    while (t != NULL) {
        t->value += x;   // poveæavamo vrijednost za x
        t = t->next;
    }
}

// Funkcija koja broji koliko puta se element x pojavljuje u listi
int broji(List Li, elementtype x) {
    int count = 0;
    element* t = Li;
    while (t != NULL) {
        if (t->value == x)   // ako je trenutni èvor jednak traženom
            count++;         // poveæaj brojaè
        t = t->next;
    }
    return count;
}

// Print dvije liste paralelno
void printL(List Li1, List Li2) {
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
            cout << "-\t\t";
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
    // Prva lista
    List L1 = NULL;
    element* a1 = new element;
    element* a2 = new element;
    element* a3 = new element;
    a1->value = 5; a1->next = a2;
    a2->value = 7; a2->next = a3;
    a3->value = 1; a3->next = NULL;
    L1 = a1;

    // Druga lista
    List L2 = NULL;
    element* b1 = new element;
    element* b2 = new element;
    b1->value = 10; b1->next = b2;
    b2->value = 20; b2->next = NULL;
    L2 = b1;

    // Ispis obe liste
    printL(L1, L2);

    // Testiraj velicinaL
    cout << "Velicina liste 1: " << velicinaL(L1) << endl;
    cout << "Velicina liste 2: " << velicinaL(L2) << endl;

    // Testiraj ispisi_manje
    cout << "Elementi liste 1 manji od 6: ";
    ispisi_manje(6, L1);

    // Testiraj uvecaj
    cout << "Lista 1 nakon uvecanja za 3:" << endl;
    uvecaj(L1, 3);
    printL(L1, L2);

    // Testiraj broji
    cout << "Broj pojavljivanja broja 8 u listi 1: " << broji(L1, 8) << endl;
    cout << "Broj pojavljivanja broja 20 u listi 2: " << broji(L2, 20) << endl;

    // Oslobodi memoriju
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

