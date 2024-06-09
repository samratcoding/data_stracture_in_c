#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete a node in a singly linked list
Node* delete_node(Node* head, int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // If the head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == key) {
        head = temp->next; // Change head
        delete temp;       // Free old head
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the linked list
    if (temp == nullptr) return head;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp; // Free memory
    return head;
}

// Function to print the linked list
void print_list(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};

    cout << "Original list:" << endl;
    print_list(head);

    head = delete_node(head, 3);

    cout << "List after deleting node with value 3:" << endl;
    print_list(head);

    return 0;
}
