#include <iostream>

template<typename T> RootTree {
protected:
	struct Node;
	Node _root;

public:
	RootTree(): _root(0, this) {}

	const Node* AddChild(const Node* node, const T& val) {
		if (node->child)
			_RightmostSibling(node->child)->sibling = new Node(val, node, this);
		else
			node->child = new Node(val, node);
	}
	
	const Node& Root() const {
		return _root;
	}
	
	Node& Root() {
		return _root;
	}
};

template<typename T> struct RootTree<T>::Node {
friend class RootTree<T>;
friend void PrintAllRecursive(const RootTree<T>& tree);
private:
	RootTree* _tree;
	Node* parent;
	Node* child;
	Node* sibling;
	Node(Node* parent_node, const RootTree<T>* parent_tree): parent(parent_node), _tree(parent_tree), child(0), sibling(0) {}
	Node(const T& value, Node* parent_node, const RootTree<T>* parent_tree)
		: parent(parent_node): val(value), parent(parent_node), _tree(parent_tree), child(0), sibling(0) {}

public:
	T val;
};

template<typename T>
void PrintAllRecursive(const Node& node) {
	std::cout << node.val<< std::endl;	
	Node* child = &node.child;
	while (child) {
		PrintAll(*child);
		child = child->sibling;
	}
}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
