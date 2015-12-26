
template<typename T> class StackFromList {
private:
	class DoubleLinkList<T>;
	DoubleLinkList<T> _lst;

public:
	typedef DoublLinkList<T> DLList;
	StackFromList() {}
	
	void push(const T& val) {
		_lst.push_front(val);
	}
	
	void pop() {
		_lst.pop_front();
	}
	
	const T& top() const {
		return _lst.front();
	}
	
	T& top() {
		return _lst.front();
	}
	
	void size() {
		return _lst.size();
	}
};
	
