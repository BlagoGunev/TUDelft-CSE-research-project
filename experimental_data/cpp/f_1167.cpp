#include <bits/stdc++.h>
using namespace std;
const int maxn = 500500;
const int mod = 1000000007;
int mul(long long a, long long b){
	return a * b % mod;
}
int f[2][maxn];
void add(int h, int p, int x){
	for(; p < maxn; p += p & - p){
		f[h][p] += x;
		if(f[h][p] >= mod) f[h][p] -= mod;
	}
}
int sum(int h, int p){
	int ans = 0;
	for(; p; p -= p & -p){
		ans += f[h][p];
		if(ans >= mod) ans -= mod;
	}
	return ans;
}
int query(int h, int l, int r){
	int res = sum(h, r) - sum(h, l - 1) + mod;
	if(res >= mod) res -= mod;
	return res;
}
int main(){
	vector<pair<int,int> > all;
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		all.push_back({x, i});
	}
	sort(all.begin(), all.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		int p = all[i].second;
		int v = all[i].first;
		ans += mul(v, mul(query(0, 1, p), n + 1 - p));
		if(ans >= mod) ans -= mod;
		ans += mul(v, mul(query(1, p, n), p));
		if(ans >= mod) ans -= mod;
		ans += mul(mul(n + 1 - p, p), v);
		if(ans >= mod) ans -= mod;
		add(0, p, p);
		add(1, p, n + 1 - p);
	}
	cout << ans << endl;
	return 0;
}