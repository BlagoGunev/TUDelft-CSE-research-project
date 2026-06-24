// Problem: D. Petya, Petya, Petr, and Palindromes
// Contest: Codeforces - Codeforces Round 861 (Div. 2)
// URL: https://codeforces.com/contest/1808/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define lowbit(x) (x & (-x))
#define SQU(x) ((x) * (x))
#define ls id << 1
#define rs id << 1 | 1
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
ll qpow(ll x,ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void add(int &x,int y) {
    x += y;
    if(x >= mod) x -= mod;
}
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int a[maxn];
vector <int> cnt[2][maxn];
int sum[2][maxn];
void solve() {
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int now = 0,las = 1;
	
	auto check = [&] (int l,int r) {
		if(r - l > m) return true;
		int d = r - l + 1;
		int rem = (m - d) / 2;
		if(r + rem > n) return true;
		if(l - rem < 1) return true;
		return false;
	};
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		swap(now,las);
		int lmid = max(m / 2 + 1,i - m / 2),rmid = min(i - 1,n - m / 2);
		int can = max(rmid - lmid + 1,0);
		if(i >= m / 2 + 2 && can > 0) {
			ans += can;
			int l = max(1,lmid * 2 - i),r = rmid * 2 - i;
			//cout << l << ' ' << r << ' ' << i << '\n';
			if(r >= l) {
				r = upper_bound(cnt[now][a[i]].begin(),cnt[now][a[i]].end(),r) - cnt[now][a[i]].begin();
				l = lower_bound(cnt[now][a[i]].begin(),cnt[now][a[i]].end(),l) - cnt[now][a[i]].begin();
				//cout << l << ' ' << r << '\n';
				ans -= (r - l);
			}
		}
		cnt[now][a[i]].push_back(i);
	}
	cout << ans << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
/*
*/