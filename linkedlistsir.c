
// Online C compiler to run C program online
#include <stdio.h>


int main() {
 struct Node{
     int data;
     struct Node *next;
 };
 int item,i,n;
struct Node *fptr=NULL, *eptr=NULL, *nptr=NULL, *tptr=NULL;


//fptr= first Node
//eptr= Moveable  node pointer
//nptr= new node
 fptr= NULL;
 printf("Enter Num of Node\n");
 scanf("%d",&n);
 for (i=1;i<=n;i++){
     printf("Enter value for %dth node ",i);
     scanf("%d",&item);
     nptr= (struct Node *)malloc(sizeof(struct Node *));
     nptr->data=item;
     nptr->next=NULL;

     if (fptr == NULL){
         fptr=nptr;
         eptr= nptr;
     }
     else{
         eptr->next=nptr;
         eptr=nptr;
     }
 }

 //Display Data before inserting another node
 printf("Before Inserting another Node: ");
 eptr=fptr;
 for(i=1;i<=n;i++){

    printf("%d ",eptr->data);
    eptr=eptr->next;


 }
 printf("\n");


 //Inserting new node after a specific node whose value is 25

 tptr=fptr;
 while(tptr->data!=25){
    tptr=tptr->next;
 }

 nptr= (struct Node *)malloc(sizeof(struct Node *));
     nptr->data=30; // insert a nose whose value is 30
     nptr->next=tptr->next;
     tptr->next=nptr;




 //Display Data after inserting 30 after a node value 25

 printf("After Inserting another Node: ");
 eptr=fptr;
 for(i=1;eptr!=NULL;i++){

    printf("%d ",eptr->data);
    eptr=eptr->next;


 }

    return 0;
}
Singly Linked List with a node insertition.c
Displaying Singly Linked List with a node insertition.c.
