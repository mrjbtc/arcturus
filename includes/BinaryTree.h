#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>

namespace NS_BinaryTree {

	struct Node {
		int val;
		Node* left;
		Node* right;
		Node(int val) {
			this->val = val;
			left = right = nullptr;
		}
	};

	using namespace std;
	class BinaryTree {

	private:
		Node* root;
		Node* insert(Node* root, int val);

	public:
		Node* getRoot() {
			return this->root;
		}
		BinaryTree(Node* root){
			this->root = root;
		}
		void buildTree(const vector<int>& data);
		bool search(Node* root, int val);

		// traverse
		void preOrderTraverse(Node* root);
		void inOrderTraverse(Node* root);
		void postOrderTraverse(Node* root);
		void levelTraverse(Node* root);
	};

	void test();
}


#endif