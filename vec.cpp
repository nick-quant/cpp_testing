#include <iostream>
#include <vector>

int main()
{
	double a = 0.159 + 0.141;
	float b = 0.1 + 0.2;
	float sum = 0;
	for (int i = 0; i < 24; ++i)
		sum += 2 * sum + a - b;
	std::cout << sum << std::endl;
	return 0;
}
