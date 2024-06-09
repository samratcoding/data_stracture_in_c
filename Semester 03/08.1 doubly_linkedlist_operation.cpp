#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

// Function to traverse the list forwards
void forward_traverse(Node *firstptr) {
    Node *traverse = firstptr;
    while(traverse != nullptr) {
        cout << traverse->data << " -> ";
        traverse = traverse->next;
    }
    cout << "nullptr" << endl;
}

// Function to traverse the list backwards
void reverse_traverse(Node *lastptr) {
    Node *traverse = lastptr;
    while(traverse != nullptr) {
        cout << traverse->data << " -> ";
        traverse = traverse->prev;
    }
    cout << "nullptr" << endl;
}

// Function to insert a node at the last position
Node* insert_node(Node *firstptr, int item) {
    Node *newptr = new Node;
    newptr->data = item;
    newptr->next = nullptr;
    newptr->prev = nullptr;

    if(firstptr == nullptr) {
        firstptr = newptr;
    } else {
        Node *lastptr = firstptr;
        while(lastptr->next != nullptr) {
            lastptr = lastptr->next;
        }
        lastptr->next = newptr;
        newptr->prev = lastptr;
    }
    return firstptr;
}

// Function to insert a node at the first position
Node *insert_first(Node *firstptr, int item){
    Node *newptr = new Node;
    newptr->data = item;
    newptr->next = firstptr;
    newptr->prev = nullptr;
    if (firstptr != nullptr) {
        firstptr->prev = newptr;
    }
    return newptr;
}

// Function to insert a node at a specific position
Node* insert_middel(Node *firstptr, int item, int position){
    if (position == 1) {
        return insert_first(firstptr, item);
    }

    Node *newptr = new Node;
    newptr->data = item;
    newptr->next = nullptr;
    newptr->prev = nullptr;

    Node *current = firstptr;
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newptr;
        return firstptr;
    }

    newptr->next = current->next;
    newptr->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newptr;
    }
    current->next = newptr;

    return firstptr;
}

int main() {
    int n, item, lastitem, firstitem, middleitem, middleposition;
    Node *firstptr = nullptr;

    cout << "Enter number of items: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter item " << i + 1 << ": ";
        cin >> item;
        firstptr = insert_node(firstptr, item);
    }

    cout << "Forward traverse:" << endl;
    forward_traverse(firstptr);
    cout << "First traverse Done!\n";

    cout << "Enter data for the last position: ";
    cin >> lastitem;
    firstptr = insert_node(firstptr, lastitem);

    cout << "Forward traverse after insertion:" << endl;
    forward_traverse(firstptr);
    cout << "Second traverse Done!\n";

    cout << "Enter data for the first position: ";
    cin >> firstitem;
    firstptr = insert_first(firstptr, firstitem);

    cout << "Forward traverse after first position insertion:" << endl;
    forward_traverse(firstptr);
    cout << "Third traverse Done!\n";

    // Traverse backwards to find the last node
    Node *lastptr = firstptr;
    while(lastptr != nullptr && lastptr->next != nullptr) {
        lastptr = lastptr->next;
    }

    cout << "Reverse traverse:" << endl;
    reverse_traverse(lastptr);

    cout << "Enter data for the middle position: ";
    cin >> middleitem;
    cout << "Enter position: ";
    cin >> middleposition;
    firstptr = insert_middel(firstptr, middleitem, middleposition);

    cout << "Forward traverse after middle insertion:" << endl;
    forward_traverse(firstptr);
    cout << "Fourth traverse Done!\n";

    return 0;
}
