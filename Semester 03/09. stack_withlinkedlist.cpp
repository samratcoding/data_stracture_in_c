#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node* top) {
    return top == nullptr;
}

Node* push(Node* top, int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack underflow!" << endl;
        return nullptr;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    return top;
}

int peek(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack is empty!" << endl;
        return -1; // Return a sentinel value to indicate empty stack
    }
    return top->data;
}

int main() {
    Node* top = nullptr;

    // Push elements onto the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // Display the top element
    cout << "Top element: " << peek(top) << endl;

    // Pop elements from the stack
    top = pop(top);

    // Display elements after popping
    cout << "After popping:" << endl;
    while (!isEmpty(top)) {
        cout << peek(top) << endl;
        top = pop(top);
    }

    return 0;
}
