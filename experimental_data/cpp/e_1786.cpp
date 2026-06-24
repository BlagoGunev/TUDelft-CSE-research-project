#include <iostream>

#include <sstream>

#include <string>

#include <vector>

#include <algorithm>

#include <map>

#include <set>

#include <functional>

#include <cstring>

#include <unordered_map>

#include <unordered_set>

#ifdef LOCAL

#   include "debug.h"

#else

#   define debug(...)

#endif



using namespace std;



auto FastIO = []() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

	return 0;

}();



int main() {

#ifdef LOCAL

	freopen("in", "r", stdin);

	// freopen("out", "w", stdout);

#endif

	int tt;

	cin >> tt;

	while (tt--) {

		int n;

		cin >> n;

		vector<int> a(n);

		map<int, int> candicate;

		for (int i = 0; i < n; i++) {

			cin >> a[i];

		}

		vector<int> b = a;

		sort(b.begin(), b.end());

		long long total = 0;

		long long sum = 0;

		for (int i = 0; i < n; i++) {

			if (b[i] > total) {

				total++;

				sum += b[i];

			} else {

				candicate[b[i]]++;

			}

		}

		vector<long long> ans(n);

		for (int i = n - 1; i >= 0; i--) {

			ans[i] = sum - total * (total + 1) / 2;

			auto it = candicate.lower_bound(a[i]);

			if (it == candicate.end()) {

				// 没有候补人员

				total--;

				sum -= a[i];

			} else {

				// 还有候补人员

				sum += it->first - a[i];

				if (it->second <= 1) candicate.erase(it);

				else it->second--;

			}



		}

		for (int i = 0; i < n; i++) {

			cout << ans[i] << ' ';

		}

		cout << endl;

	}



		

	return 0;

}