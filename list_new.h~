
class Underflow;
class NoElem;

template<typename T> class DoubleLinkList {
public:
	struct Node;
private:
	Node* _nil;
	int _size;

public:
	
	DoubleLinkList(): _size(0) {
		_nil = new Node(this);
		_nil->next = _nil;
		_nil->prev = _nil;
	}
	
	void push_front(const T& val) {
		if (_size == 0) {
			_nil->next = new Node(val, _nil, _nil, this);
			_nil->prev = _nil->next;
		}
		else {
			_nil->next = new Node(val, _nil, _nil->next, this);
			_nil->next->next->prev = _nil->next;
		}
		++_size;
	}
	
	void push_back(const T& val) {
		if (_size == 0) {
			_nil->next = new Node(val, _nil, _nil, this);
			_nil->prev = _nil->next;
		}
		else {
			_nil->prev = new Node(val, _nil->prev, _nil, this);
			_nil->prev->prev->next = _nil->prev;
		}
		++_size;
	}
	
	void pop_front() {
		if (_size != 0) {
			Node* del = _nil->next;
			_nil->next = del->next;
			del->next->prev = _nil;
			delete del;
		}
		--_size;
	}
	
	void pop_back() {
		if (_size != 0) {
			Node* del = _nil-> prev;
			_nil->prev = del->prev;
			del->prev->next = _nil;
			delete del;
		}
		--_size;
	}
	
	T& front() {
		if (_size != 0)
			return _nil->next->val;
		else throw NoElem();
	}
	
	T& back() {
		if (_size != 0)
			return _nil->prev->val;
		else throw NoElem();
	}
	
	Node* begin() {
		if (_size != 0)
			return _nil->next;
		else throw NoElem();
	}
	
	Node* end() {
		if (_size != 0)
			return *_nil->prev;
		else throw NoElem();
	}
	
	Node* after() {
		return _nil;
	}
	
	// Inserting before node a value val
	void insert(Node& node, const T& val) {
		if (node._lst_ptr == this) {
			node.prev = new Node(val, node.prev, node);
			node.prev->prev->next = node.prev;
			++_size;
		}
		else throw AccessViolation();
	}

	void erase(Node& node) {
		if (node._lst_ptr == this && _nil != &node) {
			node.prev->next = node.next;
			node.next->prev = node.prev;
			--_size;
		}
		else throw AccessViolation();
	}
	
	const Node* find(const T& val) {
		Node* it = _nil->next;
		while (it != _nil) {
			if (it->val == val)
				return it;
			it = it->next;
		}
		return _nil;
	}
	
	const Node* find_intelligent(const T& val) {
		_nil->val = val;
		Node* it = _nil->next;
		while (it->val != val)
			it = it->next;
		if (it == _nil)
			return 0;
		else return it;
	}		
	
	int size() const {
		return _size;
	}
};
			
	
template<typename T> 
struct DoubleLinkList<T>::Node {
	friend class DoubleLinkList<T>;
private:	
	const DoubleLinkList<T>* const _lst_ptr;
	Node(const DoubleLinkList<T>* const lst_ptr): prev(0), next(0), _lst_ptr(lst_ptr) {}
	Node(const T& value, Node* prev_n, Node* next_n, const DoubleLinkList<T>* const lst_ptr):
		val(value), prev(prev_n), next(next_n), _lst_ptr(lst_ptr) {}

public:
	Node* prev;
	Node* next;
	T val;
};
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
