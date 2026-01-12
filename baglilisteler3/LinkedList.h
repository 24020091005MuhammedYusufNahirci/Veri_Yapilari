#ifndef BAGLILISTELER3_LINKEDLIST_H
#define BAGLILISTELER3_LINKEDLIST_H
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data=value;
        next=nullptr;
        prev=nullptr;
    }
};

class LinkedLiS {

private:

    Node* head;
    Node* tail;

public:
    LinkedLiS();
    ~LinkedLiS();

    void push_front(int value);
    void push_back(int value);
    void insert_after(int aftervalue, int newvalue);
    void pop_front();
    void delete_Node(int value);
    void print_list();
    void Search(int value);

};
#endif //BAGLILISTELER3_LINKEDLIST_H