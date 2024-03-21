#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    int item, n;
    Node *fptr = nullptr, *eptr = nullptr, *nptr = nullptr;

    cout << "Enter number of Nodes:" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter value for node " << i << ":" << endl;
        cin >> item;

        nptr = new Node;
        nptr->data = item;
        nptr->next = nullptr;
        nptr->prev = nullptr;

        if (fptr == nullptr) {
            fptr = nptr;
            eptr = nptr;
        } else {
            eptr->next = nptr;
            nptr->prev = eptr;
            eptr = nptr;
        }
    }

    // Display data
    cout << "Linked List values (forward):" << endl;
    Node* current = fptr;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    // Display data in reverse
    cout << "Linked List values (backward):" << endl;
    current = eptr;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->prev;
    }
    cout << "NULL" << endl;

    // Free memory (not required in this simple example, but good practice)
    current = fptr;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
