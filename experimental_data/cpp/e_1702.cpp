#include <iostream>

#include <vector>

#include <algorithm>



void solve() {

	int n; std::cin >> n;

	std::vector<std::pair<int, int>> p;

	std::vector<int> c(n);

	for (int N{ n }; N--;) {

		int a, b; std::cin >> a >> b; --a; --b;

		if (a == b || ++c[a] == 3 || ++c[b] == 3) {

			std::cout << "NO" << std::endl;

			while (N--)

				std::cin >> a >> b;

			return;

		}

		p.push_back({ a,b });

		p.push_back({ b,a });

	}

	sort(p.begin(), p.end());

	for (int i{}; i < n; ++i)

		if (c[i]) {

			--c[i];

			auto it = std::lower_bound(p.begin(), p.end(), std::pair<int, int>{ i, 0 });

			int w = it->second;

			--c[w];

			std::vector<int> path; path.push_back(w);

			for (int prev{ i }; c[w]; ) {

				--c[w];

				auto jt = std::lower_bound(p.begin(), p.end(), std::pair<int, int>{ w, 0 });

				if (jt->second == prev)

					jt = std::lower_bound(jt + 1, p.end(), std::pair<int, int>{ w, 0 });

				prev = w;

				w = jt->second;

				--c[w];

				path.push_back(w);

			}

			if (path.size() & 1) {

				std::cout << "NO" << std::endl;

				return;

			}

		}

	std::cout << "YES" << std::endl;

}



int main()

{

	std::ios_base::sync_with_stdio(false);

	std::cin.tie(nullptr);



	int t; std::cin >> t;



	while (t--) {

		solve();

	}

}