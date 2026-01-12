//
// Created by yossu on 29.11.2025.
//

#ifndef BAGLILISTELER2_LINKEDLIST_H
#define BAGLILISTELER2_LINKEDLIST_H
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

    class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList();
        ~LinkedList();

        void push_front(int value);
        void push_back(int value);
        void insert_after(int aftervalue, int newvalue);
        void pop_front();
        void delete_Node(int value);
        void print_list();
        void Search(int value);

};

#endif //BAGLILISTELER2_LINKEDLIST_H