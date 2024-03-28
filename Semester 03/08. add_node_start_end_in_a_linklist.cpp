#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* addToBeginning(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}


Node* addToEnd(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr)
        return newNode;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Taking input for creating the linked list with 6 nodes
    cout << "Enter 6 numbers to create the initial linked list: ";
    for (int i = 0; i < 6; ++i) {
        int num;
        cin >> num;
        head = addToEnd(head, num);
    }

    int newDataBegin, newDataEnd;
    cout << "Enter a number to add at the beginning: ";
    cin >> newDataBegin;
    head = addToBeginning(head, newDataBegin);

    cout << "Enter a number to add at the end: ";
    cin >> newDataEnd;
    head = addToEnd(head, newDataEnd);

    // Printing the linked list
    cout << "Linked List after adding nodes at the beginning and end: ";
    printLinkedList(head);

    return 0;
}
