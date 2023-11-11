#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

int main() {
    int item, i, n;
    node *fptr = NULL, *eptr = NULL, *nptr = NULL;

    // ftr = First Node
    // eptr = End node pointer
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

    // Display data
    printf("Linked List values:\n");
    node* current = fptr;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
