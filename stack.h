
// Stack with max fixed amount
template<class T, int max> class Stack
{
public:
	explicit Stack(): _cur_size(0)
	{ }
	~Stack()
	{ }
	
	void push(const T& v)
	{
		if (_cur_size < max)
			_array[_cur_size++] = v;
		else {
			//throw overflow
		}
	}
	void pop()
	{
		if (_cur_size > 0)
			--_cur_size;
		else
		{
			// throw underflow
		}
	}
	
	const T& top() const
	{
		return _array[_cur_size - 1];
	}
	
	T& top()
	{
		return _array[_cur_size - 1];
	}
	
	int size() const
	{
		return _cur_size;
	}	
	
	bool empty()
	{
		return _cur_size == 0;
	}
	
private:
	T _array[max];	
	int _cur_size;
};
