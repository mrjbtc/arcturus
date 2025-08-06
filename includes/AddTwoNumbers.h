#ifndef ADD_TWO_NUMBERS_H
#define ADD_TWO_NUMBERS_H

namespace NS_ADD_TWO_NUMBERS {

    struct Node {
        int val;
        Node *next;
        Node() : val(0), next(nullptr) {}
        Node(int x) : val(x), next(nullptr) {}
        Node(int x, Node *next) : val(x), next(next) {}
    };

    void printListNodes(Node* ln);
    Node* test(Node* l1, Node* l2);

    class AddTwoNumbers {
    public:
        Node* addTwoNumbers(Node* l1, Node* l2);
    };

    void test();
}

#endif