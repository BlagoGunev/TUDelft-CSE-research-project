#include <iostream>

#include <string>

#include <array>



constexpr int A{ 'z' - 'a' + 1 };



int main()

{

	std::ios_base::sync_with_stdio(false);

	std::cin.tie(nullptr);



	int t; std::cin >> t;



	while (t--) {

		std::string s; std::cin >> s;

		int p; std::cin >> p;

		int t{};

		std::array<int, A> c{};

		for (auto e : s) {

			++c[e -= 'a'];

			t += e + 1;

		}

		for (auto i = c.rbegin(); t > p;)

			i += *i == 0, t -= int(c.rend() - i) * bool(*i), * i -= bool(*i);

		for (auto e : s)

			if (c[e - 'a']) {

				std::cout << e;

				--c[e - 'a'];

			}

		std::cout << std::endl;

	}

}