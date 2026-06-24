#include <bits/stdc++.h>

using namespace std;



template<class T>

class fenwick {

public:

	fenwick() : fenwick(0) {}



	fenwick(int _n) : n(_n), data(_n) {}



	void add(int p, T x) {

		assert(0 <= p && p < n);

		while(p < n) {

			data[p] += x;

			p |= (p + 1);

		}

	}



	T get(int p) {

		assert(0 <= p && p < n);

		T res{};

		while(p >= 0) {

			res += data[p];

			p = (p & (p + 1)) - 1;

		}

		return res;

	}



	T sum(int l, int r) {

		return get(r) - (l ? get(l - 1) : T{});

	}



private:

	int n;

	vector<T> data;

};



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	int tt;

	cin >> tt;

	while(tt--) {

		int n;

		cin >> n;

		vector<int> a(n);

		for(int i = 0; i < n; ++i) {

			cin >> a[i];

		}

		int ones = accumulate(a.begin(), a.end(), 0LL) / n;

		fenwick<int> fenw(n);

		vector<int> ans(n);

		for(int i = n - 1; i >= 0; --i) {

			a[i] -= fenw.get(i);

			if(a[i] == i + 1) {

				ans[i] = 1;

				ones -= 1;

				fenw.add(i - ones, 1);

				continue;

			}

			if(ones > 0) {

				fenw.add(i + 1 - ones, 1);

			}

		}

		for(int i = 0; i < n; ++i) {

			cout << ans[i] << " \n"[i == n - 1];

		}

	}

	return 0;

}