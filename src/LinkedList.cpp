#include <iostream>
#include "LinkedList.h"

using namespace std;

namespace NS_LinkedList {

	void LinkedList::print() {
		Node* current = this->node;
		while(current) {
			cout << current->val;
			if (current->next) {
				cout << " -> ";
			}
			current = current->next;
		}
		cout << endl;
	}

	void LinkedList::remove() {
		Node*& current = this->node;
		while (current) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	/*
		Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

		** reversing the linked list **

		prev -> current -> next

		[1] current 1
				point the current to previous
				1 -> nullptr

				switch previous to current and current to next
			previous 1
			current 2

		[2] current 2
				point the current to previous
				2 -> 1 -> nullptr

				switch previous to current and current to next
			previous 2
			current 3
		
		[3] current 3
				point the current to previous
				3 -> 2 -> 1 -> nullptr

				switch previous to current and current to next
			previous 3
			current 4
		
		[4] current 4
				point the current to previous
				4 -> 3 -> 2 -> 1 -> nullptr

				switch previous to current and current to next
			previous 4
			current 5

		[5] current 5
				point the current to previous

				5 -> 4 -> 3 -> 2 -> 1 -> nullptr

				switch previous to current and current to next
			previous 5
			current nullptr

		** loop ends since the current is nullptr **
	*/
	void LinkedList::reverse() {
		Node *&current = this->node;
		Node *prev = nullptr;
		Node *next;

		while(current) {
			next = current->next;
			current->next = prev;

			prev = current;
			current = next;
		}
		this->node = prev;
	}

	void test() {

		Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

		unique_ptr<LinkedList> llist = make_unique<LinkedList>(node);
		cout << " [Original] ";
		llist->print();
		cout << endl;
		
		cout << " [Reversed] ";
		llist->reverse();
		llist->print();
	}
}
