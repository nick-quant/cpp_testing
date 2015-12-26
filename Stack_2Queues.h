
class Underflow;
class Overflow;

template<typename T, int max> class Stack_2Queues
{
private:
	Queue<T, max> _q_in;
	Queue<T, max> _q_out; // We need it for popping
	bool _in_last;
	//int _size; don't need it. can get it from _q_in

public:
	class Queue<T, max>;
	
	Stack_2Queues(): _in_last(true) {}
	
	inline void push(const T& val) {
		if (!_in_last)
			_reverse();
		
		_q_in.enqueue(val);
	}
	
	inline void pop() {
		if (_in_last)
			_reverse();
		
		_q_out.dequeue();
	}
	
	inline void top() {
		if (_in_last)
			return _q_in.back();
		else
			return _q_out.front();
	}
	
	inline int size() const {
		return (_in_last ? _q_in.size() : _q_out.size());
	}
	
private:
	void _reverse() {
		Queue<int, max>* q_p = &_q_in;
		Queue<int, max>* q_p_inv = &_q_out;
		if (!_in_last) {
			q_p = &_q_out;
			q_p_inv = &_q_in;
		}
		_in_last = !_in_last;
		
		while (q_p->size() != 0)
			q_p_inv->enqueue(q_p->back());
	}
			
};
