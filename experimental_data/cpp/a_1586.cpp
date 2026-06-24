//#include <bits/stdc++.h>
//#define fast ios::sync_with_stdio(0), cin.tie(nullptr)
//#define all(v) v.begin(), v.end()
//#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
//#define fi first
//#define se second
//#define cat(a, b) a##b
//
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//const ll S = 3000 + 10, MOD = 1e9 + 9;

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool isp(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

pii arr[105];
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].first, arr[i].se = i + 1;
	sort(arr, arr + n, [](pii a, pii b) {return a.fi % 2 < b.fi % 2; });
	int sum = 0, i;
	for (i = 0; i < n; i++)
		sum += arr[i].fi;
	if (!isp(sum)) {
		cout << n << '\n';
		for (i = 0; i < n; i++)
			cout << i + 1 << ' ';
		cout << '\n';
	}
	else {
		cout << n - 1 << '\n';
		for (int i = 0; i < n - 1; i++) {
			cout << arr[i].se << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fast;
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	while (t--)
		solve();
}