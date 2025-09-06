#ifndef REVERSE_NODE_K_GROUP_H
#define REVERSE_NODE_K_GROUP_H

namespace NS_REVERSE_NODE_K_GROUP {
	struct Node {
	    int val;
	    Node *next;
	    Node() : val(0), next(nullptr) {}
	    Node(int x) : val(x), next(nullptr) {}
	    Node(int x, Node *next) : val(x), next(next) {}
	 };

	class ReverseNodesInKGroup {
	public:
	 	Node* reverseKGroup(Node* head, int k);
	 	static void printList(Node* head);
	private:
		int getTotalNodes(Node* head);
		Node* getKthNode(Node* head, int k);
	 	Node* reverse(Node* head, Node* until, bool toReverese);
	};

	void test();
}

#endif