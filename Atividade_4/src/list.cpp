#include "../include/list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

void List::inverte() {
        Node* last = nullptr;
        Node* current = this->head;
        Node* next = nullptr;

        this->tail = this->head;

        while (current != nullptr) {
            next = current->next;   
            current->next = last;   
            last = current;         
            current = next;         
        }

        this->head = last;
}
