#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};


void traverse(Node *firstptr){
    Node *traverse = firstptr;
    while(traverse!= nullptr){
        cout << traverse->data << " -> ";
        traverse = traverse->next;
    }
    
}


Node *insert_node(Node *firstptr, int item){
     Node *newptr= new Node;
     newptr->data = item;
     newptr->next = nullptr;
     if(firstptr==nullptr){
         firstptr=newptr;
     }
     else{
         Node *lastptr = firstptr;
         while(lastptr->next!=nullptr){
             lastptr=lastptr->next;
         }
         lastptr->next = newptr;
     }
     return firstptr;
}

Node *insert_first(Node *firstptr, int item){
     Node *newptr= new Node;
     newptr->data = item;
     newptr->next = firstptr;
     return newptr;
}



int main()
{
    int n, item, lastitem, firstitem;
    Node *firstptr=nullptr;
    
    cout << "Enter Nmber : ";
    cin>>n;
    for(int i=0;i<n;i++){
        
        cout<< "Enter item " << i+1 <<": ";
        cin>>item;
        
        firstptr = insert_node(firstptr, item);
        
    }
    
    traverse(firstptr);
    cout << "Firs traverse Done!\n";
    

    cout<<"Enter a data for last position : ";
    cin>>lastitem;
    firstptr = insert_node(firstptr,lastitem);
    
    traverse(firstptr);
    cout << "Second traverse Done!\n";
    
    cout<<"Enter a data for first position : ";
    cin>>firstitem;
    firstptr = insert_first(firstptr,firstitem);
    
    traverse(firstptr);
    cout << "Third traverse Done!\n";

    return 0;
}
