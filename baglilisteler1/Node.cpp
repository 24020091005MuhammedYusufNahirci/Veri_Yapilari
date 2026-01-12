#include "LşnkedList.h"

LşnkedList::LşnkedList() {
    head = nullptr;
}

LşnkedList::~LşnkedList() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LşnkedList::push_front(int value) {
    Node* NewNode = new Node(value);
    NewNode->next = head;
    head = NewNode;
}

void LşnkedList::push_back(int value) {
    Node* NewNode = new Node(value);
    if (head == nullptr) {
        head = NewNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = NewNode;
}

void LşnkedList::insert_after(int aftervalue, int newvalue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != aftervalue) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << aftervalue << " bulunamadi" << std::endl;
        return;
    }
    Node* NewNode = new Node(newvalue);
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void LşnkedList::pop_front() {
    if (head == nullptr) {
        std::cout << "Liste bos" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LşnkedList::delete_Node(int value) {
    if (head == nullptr) {
        std::cout << "Liste bos" << std::endl;
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << value << " silindi" << std::endl;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    if (current->next == nullptr) {
        std::cout << value << " listede yok" << std::endl;
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    std::cout << value << " silindi" << std::endl;
}

void LşnkedList::print_list() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LşnkedList::Search(int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            std::cout << value << " deger listede var" << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << value << " deger listede yok" << std::endl;
}
