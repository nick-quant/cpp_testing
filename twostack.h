
class Underflow;
class Overflow;

template<typename T, int max> class TwoStack
{
private:
	T _array[max];
	int _top_id_left;
	int _top_id_right;

public:
	TwoStack(): _top_id_left(-1), _top_id_right(max) {}
	
	void push_left(const T& val) {
		if (_top_id_left != _top_id_right - 1)
			_array[++_top_id_left] = val;
		else throw Overflow();
	}
	
	void push_right(const T& val) {
		if (_top_id_left != _top_id_right - 1)
			_array[--_top_id_right] = val;
		else throw Overflow();
	}
	
	void pop_left() {
		if (_top_id_left > -1)
			--_top_id_left;
		else throw Underflow();
	}
	
	void pop_right() {
		if (_top_id_right < max)
			++_top_id_right;
		else throw Underflow();
	}
	
	const T& top_left() const {
		return _array[_top_id_left];
	}
	
	const T& top_right() const {
		return _array[_top_id_right];
	}
	
	int size_left() const {
		return _top_id_left + 1;
	}
	
	int size_right() const {
		return max - _top_id_right;
	}
};

