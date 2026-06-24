// Problem: E. The Human Equation

// Contest: Codeforces - Codeforces Round #843 (Div. 2)

// URL: https://codeforces.com/problemset/problem/1775/E

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

#define endl '\n'

#define Carol MyWife^=^

#define pb push_back

#define pp pop_back

#define debug1(x) cout << #x << " = " << (x) << '\n'

#define debug2(x) cout << #x << " = " << (x) << ' '

//#define x first

//#define y second

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 1e6+5, M = 1e6+5;

const int MOD = 998244353, INF = 0x3f3f3f3f;

LL n, a[N], q[N];

void solve() {

	cin >> n;

	for(int i = 1; i <= n; i ++)

		cin >> a[i];

	for(int i = 1; i <= n; i ++)

		q[i] = q[i - 1] + a[i];

	LL mx = 0, mn = 0;

	for(int i = 1; i <= n; i ++) {

		mx = max(mx, q[i]), mn = min(mn, q[i]);

	}

	cout << mx - mn << endl;

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr), cout.tie(nullptr);

	int t = 1;

	cin >> t;

	while(t --) solve();

	

	return 0;

}