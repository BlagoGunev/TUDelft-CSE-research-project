#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
int T, N;
pair<int, int> A[200001];
vector<int> V[200001];
void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i].first;
	for (int i = 1; i <= N; i++)
		cin >> A[i].second;
	sort(A + 1, A + N + 1);
	map<pair<int, int>, int> mp;
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= A[i].first && A[i].first * j <= 2 * N; j++) {
			if (V[j].empty())
				continue;
			int x = A[i].first * j - A[i].second;
			ans += upper_bound(all(V[j]), x) - lower_bound(all(V[j]), x);
		}
		V[A[i].first].push_back(A[i].second);
	}
	for (int i = 1; i <= N; i++)
		V[i].clear();
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
		solve();
	return 0;
}