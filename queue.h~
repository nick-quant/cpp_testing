
// array on the stack

class Underflow;
class Overflow;

template<typename T, int max> class Queue
{
private:
	T _array[max];
	int _head;
	int _tail;
	int _size;

public:
	Queue(): _head(0), _tail(-1), _size(0) {}
	
	void enqueue(const T& val) {
		int tmp = _tail != max - 1 ? _tail + 1 : 0;
		if (_tail == -1 || tmp != _head) {
			_tail = tmp;
			_array[_tail] = val;
			++_size;
		}
		else throw Overflow();
	}
	
	void dequeue() {
		int tmp = _head != max - 1 ? _head + 1 : 0;
		if (_tail != -1 && _head != _tail) {
			_head = tmp;
			--_size;
		}
		else if (_head == _tail) {
			_head = 0;
			_tail = -1;
			--_size;
		}
		else throw Underflow();
	}
	
	const T& front() const {
		if (_tail >= 0)
			return _array[_head];
		else {
			// Exception
			return _array[_head];
		}
	}
	
	const T& back() const {
		if (_tail >= 0)
			return _array[_tail];
		else {
			// Exception
			return _array[_tail];
		}
	}
	
	int size() const {
		return _size;
	}
};
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

