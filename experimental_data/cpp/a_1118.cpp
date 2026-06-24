#include <bits/stdc++.h>

int main()
{
	std::int64_t size;
	std::cin >> size;

	while (size--)
	{
		std::int64_t n, a, b;
		std::cin >> n >> a >> b;

		if (b <  2 * a)
			std::cout << (std::int64_t(n / 2) * b + (n % 2) * a);
		else
			std::cout << n * a;

		if (size > 0)
			std::cout << std::endl;
	}

	return 0;
}