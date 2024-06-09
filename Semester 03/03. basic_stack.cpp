#include <iostream>
using namespace std;
#define CAPACITY 3

int stack[CAPACITY];
int top = 0;

void push(int data){
  if(top < CAPACITY){
    stack[top] = data;
    cout << data << " added successfully" << endl;
    top++;
    
  }
  else{
    cout << "No Empty space available" << endl;
  }
};


void pop(){
  if(top >= 0){
    cout << stack[top] << " Has beed Deleted" << endl;
    stack[top] = 0;
    top--;
  }
  else{
    cout << "No data available to  delete";
  }

};



void printStack(){
  for(int i=0; i< CAPACITY; i++){
    cout << stack[i] << ",";
  }
  cout << endl;
}

int main() 
{   
    printStack();
    
    push(10);
    printStack();
    
    push(20);
    printStack();
    
    push(30);
    printStack();
    
    push(40);
    printStack();    
    
    pop();
    printStack();    
    
    push(50);
    printStack();   
    
    pop();
    printStack(); 
    
    pop();
    printStack(); 
    
    pop();
    printStack(); 
    
    
}
