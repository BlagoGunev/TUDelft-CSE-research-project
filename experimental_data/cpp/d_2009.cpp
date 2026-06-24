#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)

template <typename T> bool chmin(T &a, const T &b) {
	if (a <= b) return false;
	a = b;
	return true;
}

template <typename T> bool chmax(T &a, const T &b) {
	if (a >= b) return false;
	a = b;
	return true;
}

template <typename T> T max(vector<T> &a){
	assert(!a.empty());
	T ret = a[0];
	for (int i=0; i<(int)a.size(); i++) chmax(ret, a[i]);
	return ret;
}

template <typename T> T min(vector<T> &a){
	assert(!a.empty());
	T ret = a[0];
	for (int i=0; i<(int)a.size(); i++) chmin(ret, a[i]);
	return ret;
}

template <typename T> T sum(vector<T> &a){
	T ret = 0;
	for (int i=0; i<(int)a.size(); i++) ret += a[i];
	return ret;
}

void solve(){
	int n; cin >> n;
	vector p(n+1, vector<int>(2));
	vector<int> cnt(2);
	rep(i,0,n){
		int x, y; cin >> x >> y;
		p[x][y] = 1;
		cnt[y] += 1;
	}
	ll ans = 0;
	rep(i,0,n+1){
		if(p[i][0] == 1 && p[i][1] == 1){
			ans += cnt[0] + cnt[1] - 2;
		}
		if (p[i][0] == 1){
			if (i-1 >= 0 && i+1 <= n){
				if (p[i-1][1] == 1 && p[i+1][1] == 1){
					ans += 1;
				}
			} 
		}
		if (p[i][1] == 1){
			if (i-1 >= 0 && i+1 <= n){
				if (p[i-1][0] == 1 && p[i+1][0] == 1){
					ans += 1;
				}
			} 
		}
		
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve(); 
}