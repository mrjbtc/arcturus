/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * 
 *   Input: l1 = [2,4,3], l2 = [5,6,4]
 *   Output: [7,0,8]
 *   Explanation: 342 + 465 = 807.
 *   
 *   Example 2:
 *   
 *   Input: l1 = [0], l2 = [0]
 *   Output: [0]
 *   
 *   Example 3:
 *   
 *   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *   Output: [8,9,9,9,0,0,0,1]
 *   
 *    
 *   
 *   Constraints:
 *   
 *       The number of nodes in each linked list is in the range [1, 100].
 *       0 <= Node.val <= 9
 *       It is guaranteed that the list represents a number that does not have leading zeros.
 *   

 */ 
#include "AddTwoNumbers.h"
#include <iostream>

using namespace std;

namespace NS_ADD_TWO_NUMBERS {

    Node* AddTwoNumbers::addTwoNumbers(Node* l1, Node* l2) {
        Node init;
        Node* current = &init;
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
            current->next = new Node(sum % 10);
            current = current->next;
        }
        cout << endl;
        delete l1;
        delete l2;
        return init.next;
    }

    void printListNodes(Node* ln) {
        while (ln) {
            cout << ln->val << " -> ";
            ln = ln->next;
        }
    }

    void test() {

        Node* l1 = new Node(2, new Node(4, new Node(3))); // [2, 4, 3]
        Node* l2 = new Node(5, new Node(6, new Node(4))); // [5, 6, 4]
        
        cout << "Linked List 1: ";
        printListNodes(l1);
        cout << endl << "Linked List 2: ";
        printListNodes(l2);


        unique_ptr<AddTwoNumbers> addTwo = make_unique<AddTwoNumbers>();
        Node* results = addTwo->addTwoNumbers(l1, l2);
        cout << "result: ";
        printListNodes(results);
    }

}