#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 300005, B = 1000;
int arr[N], cnt[N], prv[N], res = 0;
bool cmp(array<int, 2>&x, array<int, 2>&y) {
	if(x[0] / B == y[0] / B) {
		return (x[0] / B) & 1 ? x[1] > y[1] : x[1] < y[1];
	}
	return (x[0] / B) < (y[0] / B);
}

void add(int i) {
	int x = arr[i];
	if(cnt[x] == 0) res ++;
	cnt[x] += 1;
}

void del(int i) {
	int x = arr[i];
	cnt[x] --;
	if(cnt[x] == 0) res --;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> arr[i];
	vector<array<int, 2>> query;
	set<int>st;
	for(int i = 0; i < n; i ++) {
		int l = prv[arr[i]], r = i - 1;
		if(l <= r) {
			query.push_back({l, r});
		}
		st.insert(arr[i]);
		prv[arr[i]] = i + 1;
	}

	for(int i = 1; i <= m; i ++) {
		int l = prv[i], r = n - 1;
		if(l <= r) {
			query.push_back({l, r});
		}
	}
	ll ans = 1LL * ((int)m - 1) * n;
	sort(query.begin(), query.end(), cmp);
	int l = 0, r = -1;
	for(auto [L, R] : query) {
		while(L < l) add(--l);
		while(l < L) del(l ++);
		while(r < R) add(++ r);
		while(r > R) del(r --);
		int baad = R - L + 1 - res;
		ans -= baad;
	}
	cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);//cout.tie(NULL);
    solve();
    return 0;
}