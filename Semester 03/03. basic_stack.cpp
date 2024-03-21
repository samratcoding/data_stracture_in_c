#include <iostream>
using namespace std;
#define CAPACITY 3

int stack[CAPACITY];
int top = -1;

void push(int data){
  if(top < CAPACITY -1){
    top += 1;
    stack[top] = data;
    cout << data << " added successfully" << endl;
    
  }
  else{
    cout << "No Empty space available" << endl;
  }
};


void pop(){
  if(top >= 0){
    cout << stack[top] << " Has beed Deleted" << endl;
    top -= 1;
  }

};


int main() 
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    push(50);
    
    
}
