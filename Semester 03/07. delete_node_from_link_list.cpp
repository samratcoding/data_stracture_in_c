// Singly Linklist
void deleteNode(Node*& fptr, int value) {
    if (fptr == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current = fptr;
    Node* prev = nullptr;

    // Find the node to delete and keep track of its previous node
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    // If the node with the specified value is not found
    if (current == nullptr) {
        cout << "Node with value " << value << " not found. Cannot delete." << endl;
        return;
    }

    // If the node to delete is the first node
    if (prev == nullptr) {
        fptr = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "Node with value " << value << " deleted successfully." << endl;
}


// Double

void deleteNode(Node*& fptr, Node*& eptr, int value) {
    if (fptr == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current = fptr;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node with value " << value << " not found. Cannot delete." << endl;
        return;
    }

    if (current == fptr) {    # if frist node
        fptr = current->next;
    }
    if (current == eptr) {    # if last node
        eptr = current->prev;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Node with value " << value << " deleted successfully." << endl;
}
