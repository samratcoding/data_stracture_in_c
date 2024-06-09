#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int main()
{
    int n, item;
    Node *firstptr=nullptr, *lastptr=nullptr, *newptr = nullptr;  // *nptr = nullptr if dosen't declear then follow 20 line
    
    cout << "Enter Nmber : ";
    cin>>n;
    for(int i=0;i<n;i++){
        
        cout<< "Enter item " << i+1 <<": ";
        cin>>item;
        
        // Node *nptr = new Node;  it like Java Object declear
        newptr = new Node;
        newptr->data = item;
        newptr->next = nullptr;
        
        if(firstptr==nullptr){
            firstptr = newptr;
            lastptr = newptr;
        }
        else{
           lastptr->next=newptr;  
            // When lastptr -> next location is updating firstpt -> next is updating cause they both taken newptr initially
            // cause it is behavior of pointer/location, example : int *x = &a; int *y=&a; if x will update y will update
           lastptr = newptr;
        }
    }
    
    Node *current = firstptr;
    while(current!= nullptr){
        cout << current->data << " -> ";
        current = current->next;
        
    }

    return 0;
}
