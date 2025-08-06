#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"

using namespace std;

namespace NS_BinaryTree {


	void BinaryTree::buildTree(const vector<int>& data) {

		for (int val: data) {
			 this->root = this->insert(this->root, val);
		}
	}

	Node* BinaryTree::insert(Node* root, int val) {
		if (root == nullptr) {
			return new Node(val);
		}
		if (val < root->val) {
			root->left = this->insert(root->left, val);
		} else {
			root->right = this->insert(root->right, val);
		}
		return root;
	}

	bool BinaryTree::search(Node* root, int val) {

		if (root == nullptr) {
			return false;
		}

		if (root->val == val) {
			return true;
		}

		if (val < root->val ) {
			return this->search(root->left, val);
		}

		return this->search(root->right, val);
	}

	void BinaryTree::preOrderTraverse(Node* root) {
		if (root == nullptr) {
			return;
		}
		
		cout << root->val << " ";
		this->preOrderTraverse(root->left);
		this->preOrderTraverse(root->right);
		cout << endl;
	}

	void BinaryTree::inOrderTraverse(Node* root) {
		if (root == nullptr) {
			return;
		}
		
		this->inOrderTraverse(root->left);
		cout << root->val << " ";
		this->inOrderTraverse(root->right);
		cout << endl;

	}

	void BinaryTree::postOrderTraverse(Node* root) {
		if (root == nullptr) {
			return;
		}
		
		this->postOrderTraverse(root->left);
		this->postOrderTraverse(root->right);
		cout << root->val << " ";
	}

	void BinaryTree::levelTraverse(Node* root) {
		if (root == nullptr) {
			return;
		}
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			size_t levelSize = q.size();
			for (size_t i = 0; i < levelSize; i++ ) {
				Node* current = q.front();
				cout << current->val << " ";
				q.pop();

				if (current->left != nullptr) {
					q.push(current->left);
				}

				if (current->right != nullptr) {
					q.push(current->right);
				}
			}
			cout << endl;
		}
	}


	void test() {
		Node* root = new Node(10);
		root->left = new Node(11);
		root->right = new Node(12);
		root->left->left = new Node(15);
		root->left->right = new Node(16);
		root->right->left = new Node(20);
		root->right->right = new Node(25);
		int search = 4;
		
		unique_ptr<BinaryTree> bt = make_unique<BinaryTree>(root);
		cout << "Pre order Traversal " <<endl;
		bt->preOrderTraverse(root);

		cout << "Inorder Traversal " <<endl;
		bt->inOrderTraverse(root);
		
		cout << "Post order Traversal " <<endl;
		bt->postOrderTraverse(root);

		cout << endl << "Level Traversal " <<endl;
		bt->levelTraverse(root);

		cout << "#### searching for " << search << " ........ : " << (bt->search(root, search) ? " found " : " not found ") << endl;
	}
}