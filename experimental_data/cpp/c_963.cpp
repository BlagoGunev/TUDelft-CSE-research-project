#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

const int maxn = 200005;
int n, m;
vector<ll> qw, qh;
vector<ll> c[maxn];
ll w[maxn], h[maxn], cc[maxn];

bool check(){
	for(int i = 1; i < n; ++i)
		for(int j = 1; j < m; ++j){
			ll p = c[i][j], q = c[i - 1][j];
			ll t = c[i][j - 1], k = c[i - 1][j - 1];
			ll gpq = __gcd(p, q); p /= gpq, q /= gpq;
			ll gtk = __gcd(t, k); t /= gtk, k /= gtk;
			if(t != p || q != k) return 0;
		}
	return 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%I64d%I64d%I64d", w + i, h + i, cc + i);
		qw.pb(w[i]);
		qh.pb(h[i]);
	}
	sort(all(qw));
	sort(all(qh));
	qw.erase(unique(all(qw)), qw.end());
	qh.erase(unique(all(qh)), qh.end());	

	if(qw.size() * qh.size() != n){
		puts("0");
		return 0;
	}
	
	for(int i = 0; i < qw.size(); ++i)
		c[i].resize(qh.size());
	
	for(int i = 1; i <= n; ++i){
		int tw = lower_bound(all(qw), w[i]) - qw.begin();
		int tr = lower_bound(all(qh), h[i]) - qh.begin();
		c[tw][tr] = cc[i];
	}

	
	n = qw.size();
	m = qh.size();
	if(!check()){
		puts("0");
		return 0;
	}

	ll d = 0;
	for(int i = 0; i < m; ++i)
		d = __gcd(d, c[0][i]);

	ll e = 1;
	for(int i = 1; i < n; ++i){
		ll p = c[i][0], q = c[0][0], g = __gcd(p, q);
		p /= g, q /= g;

		q /= __gcd(e, q);
		if(1. * q * e > d + 1){
			puts("0");
			return 0;
		}

		e *= q;
	}

	if(d % e != 0){
		puts("0");
		return 0;
	}

	d /= e;

	int lim = sqrt(d + 0.1);
	int res = 0;
	for(int i = 1; i <= lim; ++i)
		if(d % i == 0){
			++res;
			if(d / i != i) ++res;
		}

	printf("%d\n", res);
	
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}