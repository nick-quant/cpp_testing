#include<stack>
#include<iostream>

template<typename T> class Bintree {
protected:
	struct Node;
	Node _root;
	enum TRAVERSE_DIRECTION { DOWN_LEFT, DOWN_RIGHT, UP_FROM_LEFT, UP_FROM_RIGHT };
	
public:
	Bintree(): _root(this) {}
	
	Node* SetLeftChild(Node* node, const T& val) {
		node->left = new Node(this, val, node);
		return node->left;
	}
	
	Node* SetRightChild(Node* node, const T& val) {
		node->right = new Node(this, val, node);
		return node->right;
	}
	
	Node& Root() {
		return _root;
	}
	
	const Node& Root() const {
		return _root;
	}
	
	void PrintAllRecursive(const Node& node) {
		std::cout << node.val << std::endl;
		if (node.left)
			PrintAllRecursive(*node.left);
		if (node.right)
			PrintAllRecursive(*node.right);
	}
	
	void PrintAll()
	{
		std::stack<const Node*> right_stack;
		std::cout << _root.val << std::endl;
		const Node* child;
		if (_root.left) {
			if (_root.right)
				right_stack.push(_root.right);
			child = _root.left;
		}
		else if (_root.right) // && !_root.left
			child = _root.right;
		else return;
		// If the parent has a rightmost sibling or the child exists loop further
		while (!right_stack.empty() || child) {
			// If the child exists it has a priority over right parent-siblings
			if (child) {
				std::cout << child->val << std::endl;
				if (child->left) {									
					if (child->right)
						right_stack.push(child->right);
					child = child->left;
				}
				else if (child->right)
					child = child->right;
				else 
					child = 0;							
			}
			else { //child == 0
				child = right_stack.top();
				right_stack.pop();
			}
		}
	}
	
	
	void PrintAllNoMemory() {		
		Node* prev_node = &_root;
		std::cout << prev_node->val << std::endl;
		Node* cur_node;
		TRAVERSE_DIRECTION dir = (TRAVERSE_DIRECTION)0;
		if (prev_node->left) {
			dir = DOWN_LEFT;
			cur_node = prev_node->left;
		}
		else if (prev_node->right) {
			dir = DOWN_RIGHT;
			cur_node = prev_node->right;
		}
		else return;
		
		while (cur_node) {			
			if (dir == DOWN_LEFT || dir == DOWN_RIGHT)
			//std::cout << cur_node->val << " " << dir << std::endl;
				std::cout << cur_node->val << " REAL" << std::endl;
			prev_node = cur_node;
			if (dir == DOWN_LEFT || dir == DOWN_RIGHT) {
				if (cur_node-> left) {
					dir = DOWN_LEFT;
					cur_node = cur_node->left;
				}
				else if (cur_node->right) {
					dir = DOWN_RIGHT;
					cur_node = cur_node->right;
				}
				else { // We have to move to the parent. It definitely exists
					Node* p = cur_node->parent;
					if (p->left == cur_node)
						dir = UP_FROM_LEFT;
					else
						dir = UP_FROM_RIGHT;
					cur_node = p;
				}
			}
			else {				
				if (cur_node->right && dir == UP_FROM_LEFT) {
					dir = DOWN_RIGHT;
					cur_node = cur_node->right;
				}
				else { // Wa are moving to the parent which can probably not exist
					if (cur_node == &_root)
						return;
					Node* p = cur_node->parent;
					if (p->left == cur_node)
						dir = UP_FROM_LEFT;
					else
						dir = UP_FROM_RIGHT;
					cur_node = p;
				}
			}
		}
	}
				
				
};

template<typename T> struct Bintree<T>::Node {
friend class Bintree<T>;
private:
	Bintree* _tree;
	Node* parent;
	Node* left;
	Node* right;
	
	Node(Bintree* tree, Node* parent_node = 0, Node* left_node = 0, Node* right_node = 0):
		_tree(tree), parent(parent_node), left(left_node), right(right_node) {}
	
	Node(Bintree* tree, const T& value, Node* parent_node = 0, Node* left_node = 0, Node* right_node = 0):
		_tree(tree), parent(parent_node), left(left_node), right(right_node), val(value) {}
		
public:
	T val;
};










