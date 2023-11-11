#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    typedef struct Node {
    int data;
    struct Node* next;
    } node;
    

    
    int item, i, n;
    node *fptr = NULL, *eptr = NULL, *nptr = NULL;
    
    // ftr = First Node
    // eptr = Moveable node pointer
    // nptr = New node

    printf("Enter number of Nodes:\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d:\n", i);
        scanf("%d", &item);

        nptr = (node*)malloc(sizeof(node));
        nptr->data = item;
        nptr->next = NULL;

        if (fptr == NULL) {
            fptr = nptr;
            eptr = nptr;
        } else {
            eptr->next = nptr;
            eptr = nptr;
        }
    }
    
    
    // display data
    
    



    return 0;
}
