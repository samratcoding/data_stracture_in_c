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
