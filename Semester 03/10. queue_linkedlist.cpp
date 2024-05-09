#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

bool isEmpty(Queue* queue) {
    return queue->front == nullptr;
}

void enqueue(Queue* queue, int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue underflow!" << endl;
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == nullptr) {
        queue->rear = nullptr;
    }
    delete temp;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty!" << endl;
        return -1; // Return a sentinel value to indicate empty queue
    }
    return queue->front->data;
}

int main() {
    Queue* queue = new Queue;
    queue->front = nullptr;
    queue->rear = nullptr;

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Display the front element
    cout << "Front element: " << front(queue) << endl;

    // Dequeue elements
    dequeue(queue);

    // Display elements after dequeuing
    cout << "After dequeuing:" << endl;
    while (!isEmpty(queue)) {
        cout << front(queue) << endl;
        dequeue(queue);
    }

    delete queue;
    return 0;
}
