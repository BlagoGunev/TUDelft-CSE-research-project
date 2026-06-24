#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define len(v) (int)v.size() 
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef Raptor
#include "debug.h"
#else
#define debug(...) 1
#define imie(...) 1;
#endif
int mod = 998244353;
struct mint {
	unsigned x;
	mint() : x(0) { }
	mint(signed sig) : x(sig % mod) { if(x < 0) x += mod; }
	mint(signed long long sig) : x(sig % mod) { if(x < 0) x += mod; }
	int get() const { return (int)x; }
	mint pow(ll p) { mint res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
	mint &operator+=(mint that) { if ((x += that.x) >= mod) x -= mod; return *this; }
	mint &operator-=(mint that) { if ((x += mod - that.x) >= mod) x -= mod; return *this; }
	mint &operator*=(mint that) { x = (unsigned long long)x * that.x % mod; return *this; }
	mint &operator/=(mint that) { return (*this) *= that.pow(mod - 2); }
	mint operator+(mint that) const { return mint(*this) += that; }
	mint operator-(mint that) const { return mint(*this) -= that; }
	mint operator*(mint that) const { return mint(*this) *= that; }
	mint operator/(mint that) const { return mint(*this) /= that; }
	mint& operator++() { x = (x + 1) % mod; return *this; }
	mint& operator--() { x = (x + mod - 1) % mod; return *this; }
	bool operator<(mint that) const { return x < that.x; }
	bool operator>(mint that) const { return x > that.x; }
	bool operator==(mint that) const { return x == that.x; }
	bool operator>=(mint that) const { return x >= that.x; }
	bool operator<=(mint that) const { return x <= that.x; }
	bool operator!=(mint that) const { return x != that.x; }
	friend ostream& operator<<(ostream &os, mint a) { os << a.x; return os; }
};
const int nax = 1e6 + 100;
mint fact[nax];
mint inv[nax];
void calc(){
	fact[0] = 1;
	inv[0] = 1;
	for(int i=1;i<nax;i++){
		fact[i] = fact[i-1]*mint(i);
		inv[i] = fact[i].pow(mod-2);
	}
}
mint ncr(ll n, ll r){
	return fact[n]*inv[n-r]*inv[r];
}
void solve(){
	int n,q; cin>>n>>q;
	vector<ll> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	ll B = accumulate(all(b),0LL);
	vector<mint> sum(B+1);
	sum[0] = 1;
	for(int i=1;i<=B;i++){
		sum[i] += sum[i-1] + ncr(B,i); 
	}
	vector<ll> pre_a(n+1),pre_b(n+1);
	for(int i=1;i<=n;i++){
		pre_a[i] = pre_a[i-1] + a[i-1];
		pre_b[i] = pre_b[i-1] + b[i-1];
	}
	mint two = 2;
	mint den = two.pow(B);
	while(q--){
		int l,r; cin>>l>>r;
		ll b = pre_b[r] - pre_b[l-1]; 
		ll d = pre_a[n] - 2*(pre_a[r] - pre_a[l-1]) + 1;
		ll till = min(B,b-d);
		if(till < 0) cout<<0<<" ";
		else cout<<sum[till]/den<<" ";
	}
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	calc();
	solve();
	return 0;
}