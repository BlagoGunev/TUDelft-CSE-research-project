#include "bits/stdc++.h"

using namespace::std;



#ifdef LOCAL

#include "debug.h"

#else

#define debug(...) 42

#endif



int main() {

	cin.tie(nullptr)->sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {

		int n;

		cin >> n;

		vector<long long> A(n + 1);

		long long sum = 0;

		for (int i = 1; i <= n; ++i) {

			cin >> A[i];

			sum += A[i];

		}

		if (sum % n) {

			cout << -1 << '\n';

			continue;

		}

		sum /= n;

		vector<pair<int, pair<int, long long>>> ans;

		function<void(int, int, long long)> operation = [&](int I, int J, long long X) {

			long long num = X * I;

			A[I] -= num;

			A[J] += num;

			ans.push_back({I, {J, X}});

		};

		for (int i = 2; i <= n; ++i) {

			if (A[i] % i) {

				long long rem = i - A[i] % i;

				operation(1, i, rem);

			}

			operation(i, 1, A[i] / i);

		}

		for (int i = 2; i <= n; ++i) {

			operation(1, i, sum);

		}

		cout << ans.size() << '\n';

		for (auto &k : ans) {

			cout << k.first << ' ' << k.second.first << ' ' << k.second.second << '\n';

		}

	}

}