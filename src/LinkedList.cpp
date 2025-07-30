#include <iostream>
#include "LinkedList.h"

using namespace std;

void LinkedList::printList(Node* head) {
	Node *temp = head;
	while(temp) {
		cout << temp->val << " -> ";
		temp = temp->next;
	}
	cout << "nullptr" << endl;

}

void LinkedList::removeList(Node*& head) {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}