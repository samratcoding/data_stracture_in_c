#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

struct MyStack {
    char stack[MAX_SIZE];
    int top;

    MyStack() {
        top = -1;
    }
};

void push(MyStack& stack, char element) {
    if (stack.top >= MAX_SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack.stack[++stack.top] = element;
}

char pop(MyStack& stack) {
    if (stack.top < 0) {
        cout << "Stack Underflow\n";
        return '\0';
    }
    return stack.stack[stack.top--];
}

bool isEmpty(const MyStack& stack) {
    return stack.top == -1;
}

string reverseString(const string& input_str) {
    MyStack char_stack;
    for (char ch : input_str) {
        push(char_stack, ch);
    }

    string reversed_str;
    while (!isEmpty(char_stack)) {
        reversed_str += pop(char_stack);
    }

    return reversed_str;
}

int main() {
    string input_str = "khulna sam";
    string reversed_str = reverseString(input_str);
    cout << reversed_str << endl;  // Output: "mas anluhk"

    return 0;
}
