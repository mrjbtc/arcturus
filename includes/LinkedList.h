#ifndef LINKED_LIST_H
#define LINKED_LIST_H


struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};


class LinkedList {
public:
   void printList(Node* head);
   void removeList(Node*& head);
};

#endif