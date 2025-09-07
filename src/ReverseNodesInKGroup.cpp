#include "ReverseNodesInKGroup.h"
#include <iostream>
/**
 * 
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. 
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 * 
 * 
 * 
 *  Solution:
 *      [1] Count the total nodes in the linked list divided by the K to identify how many times we do a reverse.
 * 		[2] Get the boundary node, which is the stopping point for every K reverse.
 * 		[3] REVERSE:       If the qoutient of total nodes / K is greater than zero then return a new head or root of the linkedlist reversed. 
 		   	DON'T REVERSE: Otherwise, return the original root/head.
 * 		[4] Recursively repeat the process, (total nodes / K) times.
 */ 

using namespace std;

namespace NS_REVERSE_NODE_K_GROUP {

	int ReverseNodesInKGroup::getTotalNodes(Node* head) {
		if (!head) return 0;

		int ctr = 0;
		while(head) {
			head = head->next;
			ctr++;
		}
		return ctr;
	}

	Node* ReverseNodesInKGroup::getKthNode(Node* head, int k) {
    	Node* until = head;
    	int ctr = 0;
        while(ctr < k) {
        	if(!until) return until;

        	until = until->next;
        	ctr++;
        }
        return until;
    }
 
	Node* ReverseNodesInKGroup::reverse(Node* head, Node* until, bool toReverese){

    	if (!head || !toReverese) {
    		return head;
    	}

    	Node *prev = nullptr;
    	Node *next = nullptr;

    	while (head != until) {
	    	next = head->next;
			head->next = prev;

			prev = head;
			head = next;

        }

        return prev;
    }


	Node* ReverseNodesInKGroup::reverseKGroup(Node* head, int k) {

       	if (!head || k == 1) return head;

		int totalGroups = this->getTotalNodes(head)/k;
		bool toReverese = (totalGroups > 0);

       	Node* until = this->getKthNode(head, k);
		Node* reverse = this->reverse(head, until, toReverese);
		if (toReverese) {
			head->next = this->reverseKGroup(until, k);
		}

       	return reverse;

    }

	void ReverseNodesInKGroup::printList(Node* head) {
		
		while(head) {
			cout << head->val << " ";
			if (head->next != nullptr) {
				cout << " -> ";
			}
			head = head->next;
		}
		cout << endl;
	}

	void test() {
		Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
		cout << " Original " << endl;
		unique_ptr<ReverseNodesInKGroup> rkg = make_unique<ReverseNodesInKGroup>();
		ReverseNodesInKGroup::printList(node);
		cout << endl;

		Node* results = rkg->reverseKGroup(node, 3);

		cout << " Reversed Nodes in K group" << endl;
		ReverseNodesInKGroup::printList(results);
	}

}



