#ifndef SARKIPROGRAMI_NODE_H
#define SARKIPROGRAMI_NODE_H
#include "Song.h"
//dairesel linked list bu da
struct Node {
    Song data;
    Node* next;
    Node* prev;

    Node(const Song& s) : data(s), next(nullptr), prev(nullptr) {}
};

#endif //SARKIPROGRAMI_NODE_H