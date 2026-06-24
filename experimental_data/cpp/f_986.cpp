#include <bits/stdc++.h>
#define int long long
const int lim = 3.4e7;
const long long inf = 1e18;
signed main () {
	std::vector<int> p;
	{
		std::array<bool, lim> tag;
		for (int i = 2; i < lim; ++i) {
			if (!tag[i])
				p.push_back(i);
			for (auto j : p) {
				if (i * j > lim)
					break;
				tag[i * j] = 1;
				if (i % j == 0)
					break;
			}
		}
	}
	int m;
	std::cin >> m;
	std::vector<long long> res(m + 1);
	std::map<long long, std::vector<std::pair<long long, int> > > t;
	for (int i = 1; i <= m; ++i) {
		long long n, k;
		std::cin >> n >> k;
		t[k].emplace_back(n, i);
	}
	auto qkp = [](long long x, int y, int mod) {
		long long res = 1;
		for (; y; (x *= x) %= mod, y >>= 1)	
			if (y & 1)
				(res *= x) %= mod;
		return res;
	};
	for (auto &[k, l] : t)
		if (k != 1) {
			std::vector<int> fac;
			int now = k;
			for (auto j : p) {
				if (now / j < j)
					break;
				if (now % j == 0) {
					fac.push_back(j);
					for (; now % j == 0; now /= j);
				}
			}
			if (now != 1)
				fac.push_back(now);
			if ((int)fac.size() == 1)
				for (auto [n, id] : l)
					res[id] = (n % fac.front() == 0);
			else if ((int)fac.size() == 2)
				for (auto [n, id] : l)
					res[id] = (n % fac.front() == 0 || n % fac.back() == 0 || fac.back() * (n % fac.front() * qkp(fac.back(), fac.front() - 2, fac.front()) % fac.front()) <= n);
			else {
				std::vector<int> tag(fac.front());
				std::vector<long long> dis(fac.front(), inf);
				std::vector<std::vector<std::pair<int, long long> > > g(fac.front());
				for (int i = 0; i < fac.front(); ++i)
					for (int j = 1; j < (int)fac.size(); ++j)
						g[i].emplace_back((i + fac[j]) % fac.front(), fac[j]);
				std::priority_queue<std::pair<long long, int> > q;
				dis[0] = 0;
				q.emplace(0, 0);
				for (; !q.empty(); ) {
					int f = q.top().second;
					q.pop();
					if (!tag[f]) {
						tag[f] = 1;
						for (auto [i, w] : g[f])
							if (dis[i] > dis[f] + w) {
								dis[i] = dis[f] + w;
								q.emplace(-dis[i], i);
							}
					}
				}
				for (auto [n, id] : l)
					res[id] = (n >= dis[n % fac.front()]);
			}
		}
	for (int i = 1; i <= m; ++i)
		std::cout << (res[i] ? "YES" : "NO") << '\n';
	return 0;
}