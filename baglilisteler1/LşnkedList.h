
#define BAGLILISTELER1_LŞNKEDLIST_H
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LşnkedList {
private:
    Node* head;

public:
    LşnkedList();
    ~LşnkedList();

    void push_front(int value);
    void push_back(int value);
    void insert_after(int aftervalue, int newvalue);
    void pop_front();
    void delete_Node(int value);
    void print_list();
    void Search(int value);
};


#endif //BAGLILISTELER1_LŞNKEDLIST_H