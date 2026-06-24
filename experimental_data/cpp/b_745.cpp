#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
#define all(v) v.begin(), v.end()
#define fi(i, n) for (int i = 0; i < n; i++)
#define pb push_back
const int inf = 2e9;
const ll infl = 9e18;
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vi h(n), v(m);
	char c;
	int cx = -1, cy = -1, k = 0;
	fi(i, n) {
		fi(j, m) {
			cin >> c;
			if (c == 'X') h[i]++, v[j]++;
		}
	}
	int q, w;
	fi(i, n) if (h[i] != 0) q = h[i];
	fi(i, m) if (v[i] != 0) w = v[i];
	int qq = 0;
	fi(i, n) {
		if ((h[i] != 0 && h[i] != q)
			|| (h[i] != 0 && qq == 2)) {
			cout << "NO";
			return 0;
		}
		if (h[i] != 0) qq = 1;
		else if (qq) qq = 2;
	}
	qq = 0;
	fi(i, m) {
		if ((v[i] != 0 && v[i] != w)
			|| (v[i] != 0 && qq == 2)) {
			cout << "NO";
			return 0;
		}
		if (v[i] != 0) qq = 1;
		else if (qq) qq = 2;
	}
	cout << "YES";
}