#include <bits/stdc++.h>

#pragma GCC optimize(2)



template <typename T>

inline void read(T &x) {

	x = 0;

	int f = 1;

	char ch = getchar();

	while (!isdigit(ch)) {

		if (ch == '-')

			f = -1;

		ch = getchar();

	}

	while (isdigit(ch)) {

		x = x * 10 + ch - '0', ch = getchar();

	}

	x *= f;

}



template <typename T>

void write(T x) {

	if (x < 0)

		putchar('-'), x = -x;

	if (x > 9)

		write(x / 10);

	putchar(x % 10 + '0');

}



#define INF 0x3f3f3f3f

typedef long long ll;

const double PI = acos(-1);

const double eps = 1e-6;

const int mod = 1e9 + 7;

const int N = 2e3 + 5;

int t, n;

int p[4];

std::string s[4];



int main() {

//	freopen("test.in","r",stdin);

//  freopen("output.in", "w", stdout);

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	std::cin >> t;

	while (t--) {

		std::cin >> n;

		memset(p, 0, sizeof(p));

		std::string u;

		std::cin >> s[0] >> s[1] >> s[2];

		while (p[0] < 2 * n && p[1] < 2 * n && p[2] < 2 * n) {

			if (s[0][p[0]] == s[1][p[1]]) {

				u += s[0][p[0]];

				p[0]++, p[1]++;

			} else if (s[0][p[0]] == s[2][p[2]]) {

				u += s[0][p[0]];

				p[0]++, p[2]++;

			} else if (s[1][p[1]] == s[2][p[2]]) {

				u += s[1][p[1]];

				p[1]++, p[2]++;

			}

		}

		std::string u1, s1;

		if (p[0] == 2 * n) {

			while (p[1] < 2 * n) {

				u1 += s[1][p[1]++];

			}

			while (p[2] < 2 * n) {

				s1 += s[2][p[2]++];

			}

		} else if (p[1] == 2 * n) {

			while (p[0] < 2 * n) {

				u1 += s[0][p[0]++];

			}

			while (p[2] < 2 * n) {

				s1 += s[2][p[2]++];

			}

		} else if (p[2] == 2 * n) {

			while (p[0] < 2 * n) {

				u1 += s[0][p[0]++];

			}

			while (p[1] < 2 * n) {

				s1 += s[1][p[1]++];

			}

		}

		if (u1.size() + u.size() <= 3 * n)

			std::cout << u + u1 << '\n';

		else

			std::cout << u + s1 << '\n';

	}

	return 0;

}