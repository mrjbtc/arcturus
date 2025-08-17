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

		Node* node = new Node(9, new Node(2, new Node(8, new Node(7, new Node(11, new Node(21, new Node(6)))))));

		unique_ptr<LinkedList> llist = make_unique<LinkedList>(node);
		cout << " [Original] ";
		llist->print();
		cout << endl;
		
		cout << " [Reversed] ";
		llist->reverse();
		llist->print();
	}
}
