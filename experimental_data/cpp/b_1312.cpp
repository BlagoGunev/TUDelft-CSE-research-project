#include <iostream>

#include <fstream>

#include <stack>

#include <set>

#include <map>

#include <stack>

#include <vector>

#include <queue>

#include <string>

#include <algorithm>

#include <numeric>

#include <cmath>

#include <array>

#include <bitset>

#include <queue>

#include <cstring>

#include <iomanip>

#define int long long

#define all(v) begin(v), end(v)

#define ve vector

#define vi vector<int>

#define vd vector<double>

#define pb push_back

#define pii pair<int,int>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

using ull = unsigned long long;



const double pi = atan(1) * 4;



void fast() {

	ios::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	cout << fixed; cout.precision(10);

}



void solve() {

	int n;

	cin >> n;

	vi v(n);

	for (auto& i : v)

		cin >> i;

	sort(all(v));

	reverse(all(v));

	for (int i : v)

		cout << i << " ";

	cout << "\n";

}



signed main() {

#ifdef LOCAL

	freopen("local.in", "r", stdin);

	freopen("local.out", "w", stdout);

#endif

	fast();

	int T = 1;

	cin >> T;

	while (T--)

		solve();

	return 0;

}