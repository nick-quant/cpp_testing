
class Bad {};

template<typename T> class SingleLinkList
{
private:
	int _size;
	struct Node;
	Node* _head;
public:
	SingleLinkList(): _size(0), _head(0) {}	
	
	void push_front(const T& val) {
		_head = new Node(val, _head);
		++_size;		
	}
	
	void pop_front() {
		if (_head) {
			Node* tmp = _head->next;
			delete _head;
			_head = tmp;
			--_size;	
		}
		else throw Bad();
	}
	
	const T& front() const {
		return _head->key;
	}
	
	int size() const {
		return _size;
	}
};

template<typename T>
struct SingleLinkList<T>::Node {
	Node(const T& val, Node* next_node = 0): key(val), next(next_node) {}		
	T key;
	Node* next;
};
				
template<typename T> class SingleLinkList<T*> {
private:
	int _size;
	struct Node;
	Node* _head;
public:
	SingleLinkList(): _size(0), _head(0) {}	
	
	void push_front(T* val) {
		_head = new Node(val, _head);
		++_size;		
	}
	
	void pop_front() {
		if (_head) {
			Node* tmp = _head->next;
			delete _head;
			_head = tmp;
			--_size;	
		}
		else throw Bad();
	}
	
	const T* front() const {
		return _head->key;
	}
	
	int size() const {
		return _size;
	}
};

template<typename T>
struct SingleLinkList<T*>::Node {
	Node(T* val, Node* next_node = 0): key(val), next(next_node) {}		
	~Node() { delete key; }
	T* key;
	Node* next;
};
