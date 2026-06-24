#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 50;

set<int> show[N], star;
int n, m, q, v[N], w[N], id[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int ttT; cin >> ttT;
	for(; ttT--; ) {
		star.clear();
		cin >> n >> m >> q;
		for(int i = 1; i <= n; ++i) cin >> v[i], id[v[i]] = i, show[i].clear();
		for(int j = 1; j <= m; ++j) cin >> w[j], w[j] = id[w[j]], show[w[j]].insert(j);
		for(int i = 1; i <= n; ++i) show[i].insert(m + 1);
		auto check = [&](int x) { // x is the lower
			if(x < 1 || x >= n) return ;
			if(*show[x].begin() > *show[x+1].begin())
				star.insert(x);
			else if(star.count(x)) star.erase(x);
		};
		for(int i = 1; i < n; ++i) check(i);
		cout << (star.size() ? "TIDAK" : "YA") << "\n";
		for(int x, y; q--; ) {
			cin >> x >> y; y = id[y];
			show[w[x]].erase(x);
			check(w[x]-1), check(w[x]);
			show[y].insert(x);
			check(y-1), check(y);
			w[x] = y;
			cout << (star.size() ? "TIDAK" : "YA") << "\n";
		} 
	}
}