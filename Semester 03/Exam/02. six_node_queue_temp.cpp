#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }
};

void enqueue(Queue& q, int value) {
    Node* newNode = new Node(value);
    if (q.front == nullptr) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

void dequeue(Queue& q) {
    if (q.front == nullptr) {
        cout << "Queue is empty. Cannot dequeue.\n";
    } else {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
        if (q.front == nullptr) {
            q.rear = nullptr; // Reset rear if queue becomes empty after dequeue
        }
    }
}

bool isEmpty(const Queue& q) {
    return q.front == nullptr;
}

void printQueue(const Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = q.front;
    cout << "Queue: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Queue queue;

    // Adding six nodes to the queue
    for (int i = 1; i <= 6; ++i) {
        enqueue(queue, i);
    }

    // Adding two more nodes
    enqueue(queue, 7);
    enqueue(queue, 8);

    cout << "After adding two nodes: ";
    printQueue(queue);

    // Deleting one node
    dequeue(queue);
    cout << "After deleting one node: ";
    printQueue(queue);

    return 0;
}
