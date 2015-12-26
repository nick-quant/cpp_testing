#include <iostream>

using namespace std;

template<typename T> class Btree {
public:
	class Node;
private:
	Node* _root;
	enum DIR { DOWN_LEFT, DOWN_RIGHT, UP_LEFT, UP_RIGHT };

public:
	Btree(): _root(0) {}
	
	void InOrderTreeWalk(const Node* node) const {
		if (!node)
			return;
		InOrderTreeWalk(node->left);
		cout << node->val;
		InOrderTreeWalk(node->right);
	}
	
	void TreeWalkWhileInOrder() const {
		// We print an element if we moved up right, or if we moved down and there is no way left
		DIR dir;
		Node* node = &_root;
		if (node->left) {
			dir = DOWN_LEFT;
			node = node->left;
		}
		else if (node->right) {
			dir = DOWN_RIGHT;
			cout << node->val << endl;
			node = node->right;
		}
		else {
			cout << node.val << endl;
			return;
		}
		while (node != 0) {
			if (dir == DOWN_LEFT) {
				if (node->left) {
					node = node->left;
				}
				else if (node->right) {
					dir = DOWN_RIGHT;
					cout << node->val << endl;
					node = node->right;
				}
				else {
					dir = UP_RIGHT;
					node = node->parent;
				}
			}
			if (dir == DOWN_RIGHT) {
				if (node->left) {
					dir = DOWN_LEFT;
					node = node->left;
				}
				else if (node->right) {
					cout << node->val << endl;
					node = node->right;
				}
				else {
					dir = UP_LEFT;
					node = node->parent;
				}
			}
			else if (dir == UP_RIGHT) {
				cout << node->val << endl;
				if (node->right) {
					dir = DOWN_RIGHT;
					node = node->right;
				}
				else {
					node = node->parent;
					if (node->parent->left == node)
						dir = UP_RIGHT;
					else
						dir = UP_LEFT;
				}
			}
			else { // (dir == UP_LEFT)
				node = node_parent;
				if (node->parent->left == node)
					dir = UP_RIGHT;
				else
					dir = UP_LEFT;
			}
		}
	}
	
	const Node* Search(int val) const {
		Node* node = &_root;
		while (node) {
			if (node->val == val)
				return node;
			if (val <= node->val)
				node = node->left;
			else
				node = node->right;
		}
		return 0;
	}
	
	const Node* Successor(const Node* node) const {	
		if (node->right) {
			node = node->right;
			while (node->left)
				node = node->left;
			return node;
		}
		else {
			while (node->parent->left != node) {
				node = node->parent;
				if (!node)
					return;
			}
			return node;
		}
	}
	
	const Node* Predecessor(const Node* node) const {
		if (node->left) {
			node = node->left;
			while (node->right)
				node = node->right;
			return node;
		}
		else {
			while (node->parent->right != node) {
				node = node->parent;
				if (!node)
					return;
			}
			return node;
		}
	}
	
	void Insert(int key) {
		if (!_root)
			_root = new Node(key);
		}
		else {
			Node* current = _root;
			Node* parent = 0;
			while (current) {
				parent = current;
				if (key <= parent.key)
					current = current->left;
				else
					current = current->right;
			}
			// We should add our new Node to the parent node. But we forgot whether our key is
			// more or less than parent key
			if (key <= parent->key)
				parent->left = new Node(key);
			else
				parent->right = new Node(key);
		}
	}
	
	void Delete(Node* node) {
		// If it has only one child then just put the child on its position
		// Delete in the end
		if (node->left && !node->right) {
			if (node->parent->right == node) {
				node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			else {
				node->parent->left = node->left;
				node->left->parent = node->parent;
			}
		}
		else if (!node->left && node->right) {
			if (node->parent->right == node) {
				node->parent->right = node->right;
				node->right->parent = node->parent;
			}
			else {
				node->parent->left = node->right;
				node->left->parent = node->parent;
			}
		}
		else if (node->left && node->right) {
			// Let's find the successor
			Node* l = node->right;
			while (l->left)
				l = l->left;
			// l is the last node with the left child
			Node* r = l->right; // may be null
			Node* lp = l->parent;
			if (node->parent->right == node)
				node->parent->right = l;
			if (node->parent->left == node)
				node->parent->left = l;
			l->parent = node->parent;			
			l->right = node->right;
			node->right->parent = l;
			lp->left = r;
			r->parent = lp;
		}
		delete Node;
	}
		
		
	void TreeInsert(Node* node, int key) {
		if (key <= node->key && node->left == 0)
			node->left = new Node(key);
		else if (key > node->key && node->right == 0)
			node->right = new Node(key);
		else if (key <= node->key && node->left)
			TreeInsert(node->left, key);
		else
			TreeInsert(node->right, key);
	}
			
		
		
		
		
		
		
		
		
		
		
				
		
