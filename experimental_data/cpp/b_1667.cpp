#include <bits/stdc++.h>

using namespace std;

using LL = long long;



const int inf = 1e9;

struct Fenwick {

	const int n;

	vector<int> a;

	Fenwick(int n) : n(n), a(n, -inf) {}

	void add(int x, int val) {

		for(int i = x + 1; i <= n; i += i & -i) 

			a[i - 1] = max(a[i - 1], val);

	}

	int sum(int x) {

		int res = -inf;

		for(int i = x; i > 0; i -= i & -i)

			res = max(res, a[i - 1]);

		return res;

	}

};



void solve() {

	int n;

	cin >> n;

	vector<LL> a(n);

	for(LL &x : a)

		cin >> x;

	vector<LL> s(n + 1);

	for(int i = 0; i < n; i++)

		s[i + 1] = s[i] + a[i];



	auto v = s;

	sort(v.begin(), v.end());

	for(int i = 0; i <= n; i++)

		s[i] = lower_bound(v.begin(), v.end(), s[i]) - v.begin();



	Fenwick fw(n + 1);

	

	vector<int> f(n + 1);

	for(int i = 1; i <= n; i++) {

		fw.add(s[i - 1], f[i - 1] - (i - 1));



		f[i] = max(i + fw.sum(s[i]), f[i - 1] + (a[i - 1] < 0 ? -1 : 0));

	}



	cout << f[n] << '\n';



}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	int t;

	cin >> t;

	while(t--) 

		solve();

	return 0;

}