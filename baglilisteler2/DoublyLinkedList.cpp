#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail=nullptr;
}

LinkedList::~LinkedList() {

}

void LinkedList::push_front(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::push_back(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode; // Liste boşsa

    } else {
        // Liste doluysa
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}


void LinkedList::insert_after(int aftervalue, int newvalue) {
    Node *temp = head;
    // aftervalue değerini arıyoruz
    while (temp != nullptr && temp->data != aftervalue) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "liste bos" << std::endl;
        return;
    }
    // Yeni düğüm oluştur
    Node *newNode = new Node(newvalue);
    newNode->next = temp->next; // Yeni düğümün next'i temp'in next'i
    newNode->prev = temp; // Yeni düğümün prev'i temp
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    if (temp == tail) {
        tail = newNode;
    }
}

void LinkedList::pop_front() {
    if (head == nullptr) {
        std::cout << "liste bos" << std::endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

void LinkedList::delete_Node(int value) {
    Node *temp = head;
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "listede yok" << std::endl;
        return;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // baş düğümü güncelle
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // son düğümü güncelle
    }
}

void LinkedList::print_list() {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LinkedList::Search(int value) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            std::cout << value << "deger listede var ";
            return;
        }
        temp = temp->next;
    }
    std::cout << value << "deger listede yok " << std::endl;
}
