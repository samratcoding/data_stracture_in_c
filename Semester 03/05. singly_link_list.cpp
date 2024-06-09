#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int item, n;
    Node *fptr = nullptr, *eptr = nullptr, *nptr = nullptr;  // *nptr = nullptr if dosen't declear then follow 20 line

    cout << "Enter number of Nodes:" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter value for node " << i << ":" << endl;
        cin >> item;

        // Node *nptr = new Node;   it like Java Object declear
        nptr = new Node;
        nptr->data = item;
        nptr->next = nullptr;

        if (fptr == nullptr) {
            fptr = nptr;
            eptr = nptr;
        } else {
            eptr->next = nptr;
            eptr = nptr;
        }
    }

    // Display data
    cout << "Linked List values:" << endl;
    Node* current = fptr;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
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
