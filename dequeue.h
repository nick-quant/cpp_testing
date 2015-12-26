class Overflow;
class Underflow;

template<typename T, int max> class Dequeue
{
private:
	T _array[max];
	int _head;
	int _tail;

public:
	Dequeue(): _head(0), _tail(-1) {}
	
	void push_back(const T& val) {
		int tmp = _tail != max - 1 ? _tail + 1 : 0;
		if (_tail == -1 || tmp != _head) {
			_array[tmp] = val;
			_tail = tmp;
		}
		else throw Overflow();
	}
	
	void pop_back() {
		int tmp = _tail != 0 ? _tail - 1: max - 1;
		if (_tail != -1 && _tail != _head)
			_tail = tmp;
		else if (_tail == _head) {
			_tail = -1;
			_head = 0;
		}
		else throw Underflow();
	}
	
	
	void push_front(const T& val) {
		int tmp = _head != 0 ? _head - 1: max - 1;
		if (tmp != _tail && _tail != -1) {
			_head = tmp;
			_array[_head] = val;
		}
		else if (_tail == -1) {
			_tail = 0;
			_array[0] = val;
		}
		else throw Overflow();
	}
	
	void pop_front() {
		int tmp = _head != max - 1? _head + 1 : 0;
		if (_head != _tail && _tail != -1)
			_head = tmp;
		else if (_head == _tail) {
			_head = 0;
			_tail = -1;
		}
		else throw Underflow();
	}
	
	const T& back() {
		return _array[_tail];
	}
	
	const T& front() {
		return _array[_head];
	}
	
};
			
