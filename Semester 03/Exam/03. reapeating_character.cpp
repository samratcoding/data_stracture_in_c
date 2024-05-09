#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;

struct MyQueue {
    char queue[MAX_SIZE];
    int front;
    int rear;

    MyQueue() {
        front = 0;
        rear = -1;
    }
};

void enqueue(MyQueue& q, char element) {
    if (q.rear >= MAX_SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    q.queue[++q.rear] = element;
}

void dequeue(MyQueue& q) {
    if (q.front > q.rear) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    ++q.front;
}

char front(const MyQueue& q) {
    if (q.front > q.rear) {
        cout << "Queue is empty.\n";
        return '\0';
    }
    return q.queue[q.front];
}

bool isEmpty(const MyQueue& q) {
    return q.front > q.rear;
}

void firstRepeatingCharacter(char stream[], int n) {
    unordered_set<char> seen; // To store characters encountered so far
    MyQueue q; // To maintain the order of characters

    for (int i = 0; i < n; ++i) {
        if (seen.find(stream[i]) != seen.end()) {
            // Character is repeating, print -1
            cout << "-1 ";
        } else {
            // Character is encountered for the first time
            seen.insert(stream[i]);
            enqueue(q, stream[i]);
            cout << stream[i] << " ";
        }
    }
}

int main() {
    char stream[] = {'b', 'b', 'c', 'd'};
    int n = sizeof(stream) / sizeof(stream[0]);
    firstRepeatingCharacter(stream, n);
    return 0;
}
