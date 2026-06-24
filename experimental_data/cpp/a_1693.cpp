//starting with the name of almighty ALLAH

//Practice is the only shortcut to improve

//Code by Fatema Akther

#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MX = 1e6 + 123;

const long long MOD = 1e9 + 7;

#define pb push_back

#define eb emplace_back

#define all(a) (a).begin(),(a).end()

#define rall(a) (a).rbegin(),(a).rend()

#define sz(x) (int)x.size()

#define fr(i,a,b) for(int i = a; i <= b; i++)

#define frr(i,a,b) for(int i = a; i >= b; i--)



void slove()

{

	int n; cin >> n;

	vector<int> v(n);

	for (auto &i : v) cin >> i;

	int sum = 0;

	bool ok = 0, okk = 0, okk1 = 0;

	fr(i, 0, n - 1) {

		sum += v[i];

		if (sum < 0) {

			ok = 1; break;

		}

		if (sum == 0) {

			fr(j, i + 1, n - 1) if (v[j] != 0) {

				okk = 1; break;

			}

			okk1 = 1;

		}

		if (okk1) break;

	}

	if (ok or okk)cout << "NO\n";

	else if (sum)cout << "NO\n";

	else cout << "YES\n";

}



signed main()

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int testcase = 1; cin >> testcase;

	while (testcase--) slove();

	return 0;

}