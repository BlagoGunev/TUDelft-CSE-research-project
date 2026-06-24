// LUOGU_RID: 98702376

#include <iostream>

#include <cstring>

#include <vector>

#include <queue>

#include <map>

#include <set>

#include <string>

#include <iomanip>

#include <algorithm>

#define x first

#define y second

using namespace std;



using PII = pair<int, int>;

using i64 = long long;



void solve()

{

	int n; cin >> n;

	int cnt = n;

	vector<int> arr(n);

	vector<PII> ans; ans.reserve(n);

	for (auto& x : arr) cin >> x, cnt -= (!x);

	if (cnt & 1) return void(cout << "-1\n");

	for (int i = 0, now = 0; i < n; ++i)

	{

		if (i + 1 < n)

		{

			if (arr[i])

			{

				if (arr[i + 1] == 0) now = arr[i], ans.push_back({ i + 1, i + 1 });

				else if (arr[i] == arr[i + 1]) ans.push_back({ i + 1, i + 2 }), ++i;

				else ans.push_back({ i + 1, i + 1 }), ans.push_back({ i + 2, i + 2 }), ++i;

			}

			else if (!arr[i])

			{

				if (!arr[i + 1] || !now) ans.push_back({ i + 1, i + 1 });

				else if (now == arr[i + 1]) ans.push_back({ i + 1, i + 2 }) ,++i, now = 0;

				else ans.push_back({ i + 1, i + 1 }), ans.push_back({ i + 2, i + 2 }), now = 0, ++i;

			}

		}

		else ans.push_back({ i + 1, i + 1 });

	}

	cout << ans.size() << '\n';

	for (auto& x : ans) cout << x.x << ' ' << x.y << '\n';

}



signed main()

{



#ifndef ONLINE_JUDGE

	freopen("r.in", "r", stdin);

	//freopen("w.out", "w", stdout);

#endif

	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



	int t; cin >> t;

	while (t--) solve();



	//solve();



	return 0;

}