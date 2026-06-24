#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

int main() 
{
	long long n;
	long long ret = 1;

	std::cin >> n;

	long long sum = (1 + n)*n / 2;

	ret = sum * 6 + 1;

	std::cout << ret;

	return 0;
}