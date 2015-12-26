
// stack with dynamically determined constant size

template<typename T> class StackConstDyn
{
public:
	explicit StackConstDyn(int size): _cur_size(0), _max_size(size) 
	{
		_array = new T[_max_size];
	}
	~StackConstDyn()
	{
		delete[] _array;
	}
	void push(const T& v)
	{
		if (_cur_size < _max_size)
			_array[_cur_size++] = v;
		else {
			//throw overflow
			_array[_cur_size++] = v;
		}
	}
	void pop()
	{
		if (_cur_size > 0)
			--_cur_size;
		else {
			// throw underflow
			--_cur_size;
		}
	}
	T& top()
	{
		return _array[_cur_size - 1];
	}
	const T& top() const
	{
		return _array[_cur_size - 1];
	}
	int size() const
	{
		return _cur_size;
	}

private:
	T* _array;
	int _cur_size;
	int _max_size;
};
