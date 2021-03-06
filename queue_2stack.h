//#include "queue.h"


class Underflow;
class Overflow;

template<typename T, int max> class Queue_2Stacks
{
private:
	Stack<T, max> _s_in;
	Stack<T, max> _s_out;
	bool _in_last;
	
public:
	class Stack<T, max>;
	
	Queue_2Stacks(): _in_last(true) {}
	
	void enqueue(const T& val) {
		if (!_in_last)
			_reverse();
		
		if (_s_in.size() < max)
			_s_in.push(val);
		else throw Overflow();	
			
	}
	
	void dequeue() {		
		if (_in_last)
			_reverse();
		
		if (_s_out.size() > 0)
			_s_out.pop();
			
		else throw Underflow();
	}
	
	const T& front() const {
		if (_in_last)
			_reverse();
		
		return _s_out.top();
	}
	
	const T& back() const {
		if (!_in_last)
			_reverse();
			
		return _s_in.top();
	}
	
	int size() const {
		return (_in_last ? _s_in.size() : _s_out.size());
	}

private:
	void _reverse() {
		Stack<T, max>* s_p = &_s_in;
		Stack<T, max>* s_p_inv = &_s_out;		
		if (!_in_last) {
			s_p = &_s_out;
			s_p_inv = &_s_in;
		}
		_in_last = !_in_last;
		while (s_p->size() != 0) {
			s_p_inv->push(s_p->top());
			//s_p->pop();
		}
	}
};
