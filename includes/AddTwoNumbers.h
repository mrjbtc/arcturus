#ifndef ADD_TWO_NUMBERS_H
#define ADD_TWO_NUMBERS_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNodes(ListNode* ln);
ListNode* test(ListNode* l1, ListNode* l2);

class AddTwoNumbers {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif