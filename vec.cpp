#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


class Foo 
{
public:
	Foo(int i = 0) { _i = i; }
	void f() { cout << "Foo " << endl; }	
	void f2() { cout << "Foo2 " << endl; }
	void f3() { cout << "Foo3 " << endl; }
	
	static void f4() { cout << "Static Foo" << endl; }

private:
	int _i;
};

class FooBig: public Foo
{
public:
	void f() { cout << "Big Foo" << endl; }
};

class Bar
{
public:
	int b(int a) { cout << "Bar"; }
};

template<class T>
class DummyT
{
public:
	vector<int> ret() { cout << "s"; }
	
	//int ret();
};

template <class T>
T max(T val_1, T val_2)
{
	return val_1;
}

int max_2(int a, int b)
{
	return b;
}

int max_3(double a, double b)
{
	return 1;
}

int main()
{
	//cout << max('s', 23);	// promotion needed, doesn't work
	cout << max_2('s', 23); // promotion
	cout << max_3(1, 2.7);
	
	return 0;
	Foo* p = 0;
	p->f();

	Foo a, b;
	FooBig c;
	Bar bar;
	
	cout << &a << endl;
	cout << &b << endl;	
	cout << &Foo::f << endl;
	cout << &Foo::f2 << endl;
	cout << &Foo::f3 << endl;
	
	void (Foo::*f_1)();
	f_1 = &Foo::f3;	
	(a.*f_1)();


	// Tutorial 
	cout << "\nTutorial\n";
	typedef void (Foo::* FPTR)();
	typedef void (FooBig::* FDPTR)();
	typedef int (Bar::* BPTR)(int);
	
	FPTR fptr = &Foo::f;
	(a.*fptr)();	
	FDPTR fdptr = &FooBig::f;
	(c.*fdptr)();
	fdptr = static_cast<FPTR>(fptr);
	(c.*fdptr)(); // FooBig is also Foo. that's why it can call fptr
	(c.*fptr)(); 
	(bar.*(BPTR)fptr)(1);
	
	return 0;
	
	
	
	int cycles = 100000;
	int size = 100000;
	clock_t begin = clock();
	for (int i = 0; i < cycles; ++i)
	{
		int* arr = new int[size]; // 10 Kbs
		delete[] arr;
	}
	
	clock_t end = clock();
	double elapsed_secs_1 = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs_1 << endl;
	
	begin = clock();
	for (int i = 0; i < cycles; ++i)
	{
		int arr[size];		
	}
	end = clock();
	double elapsed_secs_2 = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs_2 << endl;
	cout << (elapsed_secs_1 / elapsed_secs_2) << endl;
	
	return 0;
}
