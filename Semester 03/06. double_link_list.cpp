#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

int main(){
    
    int n, item;
    Node *firstptr=nullptr, *lastptr=nullptr, *newptr=nullptr;
    
    cout<< "Enter number : ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        cout<< "Enter Data" << i+1 << " : ";
        cin>>item;
        
        newptr = new Node;
        newptr->data = item;
        newptr->next = nullptr;
        newptr->prev = nullptr;
        
        if(firstptr==nullptr){
            firstptr=newptr;
            lastptr=newptr;
        }
        else{
            lastptr->next = newptr;
            newptr->prev = lastptr;
            lastptr = newptr;
        }
        
    }
    
    // Forward Traversing
    cout<<"\nforward Traversing";
    Node *forward = firstptr;
    while(forward!=nullptr){
        cout << forward->data << " -> ";
        forward = forward->next;
    }
    
    
    // Reverse Traversing
    cout<<"\nReverse Traversing";
    Node *reverse = lastptr;
    while(reverse!=nullptr){
        cout << reverse->data << " -> ";
        reverse = reverse->prev;
    }
     
        
}
    
