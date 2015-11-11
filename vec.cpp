#include <iostream>
#include <vector>

int main()
{
	std::cout << "Start\n";
	std::vector<int> vec(1000, 0);
	
	int exit = 0;	
	while (!exit)
	{
		vec.push_back(3);
		std::cout << vec.size() << "\t" << vec.capacity() << "\n";
		std::cin >> exit;	
	}
	return 0;
}
