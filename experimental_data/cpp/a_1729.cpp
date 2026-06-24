#include <iostream>

#include <cstring>



int64_t a, b, c;



int64_t e1() {

  return std::abs(a - 1);

}



int64_t e2() {

  return std::abs(b - c) + std::abs(c - 1);

}



int64_t solve() {

  const int64_t x1 = e1(), x2 = e2();

  if (x1 == x2) return 3;

  return x1 < x2 ? 1 : 2;

}



int main() {

	std::ios::sync_with_stdio(false);

	std::cin.tie(nullptr); std::cout.tie(nullptr);



	int t; std::cin >> t;

	while (t--) {

    std::cin >> a >> b >> c;

    std::cout << solve() << '\n';

	}



	return 0;

}