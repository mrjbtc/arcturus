/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */ 
#include "AddTwoNumbers.h"
#include <iostream>

using namespace std;

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy.next;
}

void printListNodes(ListNode* ln) {
    while (ln) {
        cout << ln->val << " -> ";
        ln = ln->next;
    }
    cout << "nullptr" << endl;
}

ListNode* test(ListNode* l1, ListNode* l2) {
    
    cout << "l1: ";
    printListNodes(l1);
    cout << "l2: ";
    printListNodes(l2);

    cout << "result: ";

    unique_ptr<AddTwoNumbers> addTwo = make_unique<AddTwoNumbers>();
    return addTwo->addTwoNumbers(l1, l2);
}