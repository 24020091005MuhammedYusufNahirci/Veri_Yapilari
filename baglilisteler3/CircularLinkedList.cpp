#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedLiS::LinkedLiS() {
    head=nullptr;
    tail=nullptr;
}

LinkedLiS::~LinkedLiS() {

}

void LinkedLiS::push_front(int value) {
    Node* newNode = new Node(value);
    if (head==nullptr) {
        head=newNode;
        tail=newNode;
        head->next=tail;
        tail->prev=head;
        return;
    }
    newNode->next=head;
    newNode->prev=tail;
    tail->next=newNode;
    head->prev=newNode;
    tail=newNode;
}

void LinkedLiS::push_back(int value) {
    Node* newNode = new Node(value);
    if (head==nullptr) {
        head=newNode;
        tail=newNode;
        head->next=tail;
        tail->prev=head;
        return;
    }
    newNode->next=head;
    newNode->prev=tail;
    tail->next=newNode;
    head->prev=newNode;
    tail=newNode;
}

void LinkedLiS::insert_after(int aftervalue, int newvalue) {
    if (!head) {
        std::cout << "Liste bos\n";
        return;
    }

    Node* temp = head;
    bool found = false;

    do {
        if (temp->data == aftervalue) {
            found = true;
            Node* newNode = new Node(newvalue);

            // Yeni düğümü araya ekle
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;

            // Eğer temp tail ise tail güncelle
            if (temp == tail) tail = newNode;

            break;
        }

        temp = temp->next;
    } while (temp != head);

    if (!found) {
        std::cout << "Deger bulunamadi\n";
    }
}


void LinkedLiS::pop_front() {
    if (head==nullptr) {
        return;
    }
    if (head==tail) {
        delete head;
        head=tail=nullptr;
        return;
    }
    Node* temp=head;
    head=head->next;
    tail->next=head;
    head->prev=tail;
    delete temp;
}

void LinkedLiS::delete_Node(int value) {
    if (!head) return;

    Node* temp = head;
    Node* prev = tail;
    bool found = false;

    // Tek elemanlı liste kontrolü
    if (head == tail) {
        if (head->data == value) {
            delete head;
            head = tail = nullptr;
        } else {
            std::cout << "Deger bulunamadi\n";
        }
        return;
    }

    // Listeyi dolaş
    while (true) {
        if (temp->data == value) {
            found = true;

            prev->next = temp->next;
            temp->next->prev = prev;

            if (temp == head) head = temp->next;
            if (temp == tail) tail = prev;

            delete temp;
            break;
        }

        // Listeyi tamamen dolaştık mı kontrol et
        if (temp == tail) break;

        prev = temp;
        temp = temp->next;
    }

    if (!found)
        std::cout << "Deger bulunamadi\n";
}




void LinkedLiS::print_list() {
    if (!head) {
        std::cout << "Liste bos\n";
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}


void LinkedLiS::Search(int value) {
    if (head==nullptr) {
        cout<<"liste bos"<<endl;
        return;
    }
    Node* temp=head;
    if (temp->data==value) {
        cout<<"deger bulundu"<<endl;
        return;
    }
    temp=temp->next;
    while (temp!=head) {
        if (temp->data==value) {
            cout<<"deger bulundu"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"deger bulunamadi"<<endl;
}

