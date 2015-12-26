

template<typename T> class QueueFromList {
private:
	class DoublyLinkList<T>;
	DoubleLikList<T> _lst;
	typename DoublyLinkList<T>::Node* _end;

public:
	QueueFromList(): _end(_lst.after()), _begin(_lst.after) {}
	
	void Enqueue(const T& val) {
		_end.next = new Node(val);
		_end = _end.next;
	}
	
	void Dequeue() {
		if (_lst.begin == _end)
			_end = _lst.after();
		_lst.pop_front();
	}
	
	const T& front() {
		return _lst.front();
	}
	
	const T& back() {
		return _end->val;
	}
};
