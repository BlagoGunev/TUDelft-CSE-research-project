#include "bits/stdc++.h"
#define int long long
using namespace std;
const long long INF = 1ll << 60;
const int N = 3e5 + 5;
vector<int> p[N];
int n, ans, C[N], S[N], a[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 2; i < N; i++) if (p[i].empty()) {
		for (int j = i; j < N; j += i)
			p[j].push_back(i);
	}	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	int SKol = 0;
	for (int i = 0; i < n; i++) {
		int jam = 0, tedad = 0;
		for (int j = 1; j < (1 << p[a[i]].size()); j++) {
			int P = 1, o = -1;
			for (int c = 0; c < p[a[i]].size(); c++) {
				if (j >> c & 1)
					P *= p[a[i]][c], o *= -1;
			}
			jam += S[P] * o;
			tedad += C[P] * o;
		}
		tedad = i - tedad;
		ans += tedad * i - (SKol - jam) - tedad;

		for (int j = 0; j < (1 << p[a[i]].size()); j++) {
			int P = 1;
			for (int c = 0; c < p[a[i]].size(); c++)
				if (j >> c & 1)
					P *= p[a[i]][c];
			S[P] += i;
			C[P]++;
		}
		SKol += i;
	}

	cout << ans << '\n';

	return 0;
}
//kash bazam