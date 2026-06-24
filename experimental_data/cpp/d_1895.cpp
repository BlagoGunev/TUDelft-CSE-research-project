#include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
//mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<ll> rnd(0,LLONG_MAX);
template<typename T>
inline T cei(T x, T y) {
	T t = (x+y-1)/y;
	return t;
}

template<typename T>
inline T power(T base, T powerRaised) {
	if (powerRaised != 0) return (base*power(base, powerRaised-1));
	else return 1;
}

template<typename T>
inline T gcd(T a, T b) {
	while(b) {
		b^=a^=b^=a%=b;
	}
	return a;
}

template<typename T>
inline T lcm(T x, T y ) {
	return x*y/gcd(x,y);
}
template<typename T>
inline T findLessPower(T base, T n) {
	if(n==1) {
		return 0;
	}
	T temp = log(n)/log(base);
	if(power(base, temp) == n) {
		return temp-1;
	} else {
		return temp;
	}
}
const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll INF=1e9+5;
const ll maxN=1e5+5;
const ll MAXLEN=1e6+5;
ll gcdl(ll a,ll b) {
	if(a==0||b==0) {
		return abs(a+b);
	}
	return gcdl(b%a,a);
}
//ll lcml(ll a,ll b) {
//	if(a>=INF||b>=INF) {
//		return INF;
//	}
//	ll ans=a*b/gcdl(a,b);
//	if(ans>=INF) {
//		return INF;
//	}
//	return ans;
//}
ll mo(ll a,ll b,ll mod) {
	if(b==0) {
		return 1ll;
	}
	ll vmod;
	vmod=mo(a,b/2,mod);
	vmod=(vmod*vmod)%mod;
	if(b%2==0) {
		return vmod;
	}
	return (vmod*a)%mod;
}
ll segtree[4*maxN];
ll lazy[4*maxN];
void push(ll v,ll l,ll r,ll mid){
	if(lazy[v]!=0){
		segtree[2*v]+=(mid-l+1)*lazy[v];
		segtree[2*v+1]+=(r-mid)*lazy[v];
		lazy[2*v]+=lazy[v];
		lazy[2*v+1]+=lazy[v];
		lazy[v]=0;
	}
}
void update(ll number,ll tl,ll tr,ll pos, ll val){
	if(tl==tr){
		segtree[number]+=val;
		return;
	}
	ll mid=(tl+tr)/2;
	if(pos<=mid){
	    update(2*number,tl,mid,pos,val);
	}
	else{
	    update(2*number+1,mid+1,tr,pos,val);
	}
	segtree[number]=segtree[2*number]+segtree[2*number+1];	
}
void build(ll number, ll a[],ll tl,ll tr){
	lazy[number]=0;
	if(tl==tr){
		segtree[number]=a[tl];
		return;
	}
	ll mid=(tl+tr)/2;
	build(2*number,a,tl,mid);
	build(2*number+1,a,mid+1,tr);
	segtree[number]=segtree[number*2]+segtree[number*2+1];
}
ll query(ll number,ll tl,ll tr,ll l ,ll r){
    if(l>r){
    	return 0;
    }
	if(l<=tl&&r>=tr){
	    return segtree[number];
	}
	ll mid=(tl+tr)/2;
	push(number,tl,tr,mid);
	return query(2*number,tl,mid,l,min(r,mid))+query(2*number+1,mid+1,tr,max(mid+1,l),r);
}
ll segtree1[4*maxN];
void build1(ll number, ll a[],ll tl,ll tr){
	if(tl==tr){
		segtree1[number]=a[tl];
		return;
	}
	ll mid=(tl+tr)/2;
	build1(2*number,a,tl,mid);
	build1(2*number+1,a,mid+1,tr);
	segtree1[number]=min(segtree1[number*2],segtree1[number*2+1]);
}
ll query1(ll number,ll tl,ll tr,ll l ,ll r){
    if(l>r){
    	return INF;
    }
	if(l<=tl&&r>=tr){
	    return segtree1[number];
	}
	ll mid=(tl+tr)/2;
	return min(query1(2*number,tl,mid,l,min(r,mid)),query1(2*number+1,mid+1,tr,max(mid+1,l),r));
}
vector<ll> solvexor(ll n, vector<ll> d){
	ll i,j,sum1,sum2;
	sum1=0;
	sum2=0;
	for(i=0;i<n-1;i++){
		sum1=sum1^d[i];
		sum2=sum2^i;
	}
	sum2=sum2^(n-1);
	if(n%2==1){
		vector<ll> ans(n);
		ans[0]=sum2^sum1;
		for(i=0;i<n-1;i++){
			ans[i+1]=ans[0]^d[i];
		}
		return ans;
	}
	if(n==2){
		vector<ll> ans(2);
		ans[0]=0;
		ans[1]=1;
		return ans;
	}
	vector<ll> newd;
	for(i=0;i<n-1;i++){
		if(d[i]%2==0){
			newd.push_back(d[i]/2);
		}
	}
	vector<ll> ans(n);
	vector<ll> nans=solvexor(n/2,newd);
	
	map<ll,ll> ml;
	for(i=0;i<(n/2)-1;i++){
		ml[newd[i]]=nans[i+1];
	}
	ml[0]=nans[0];
	ans[0]=2*nans[0];
	for(i=0;i<n-1;i++){
		ans[i+1]=2*ml[(d[i]/2)];
		if(d[i]%2==1){
			ans[i+1]=ans[i+1]+1;
		}
	}
	return ans;
}
void solve() {
	ll n,i,j;
	ll l,r,x;
	ll sum;
	cin >> n;
	ll a[n+1];
	for(i=1;i<=n-1;i++){
		cin >> a[i];
	}
	vector<ll> d;
	sum=0;
	for(i=1;i<=n-1;i++){
		sum=sum^a[i];
		d.push_back(sum);
	}
	auto ans=solvexor(n,d);
	for(auto x:ans){
		cout << x << " ";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,i,j;
	c=1;
	//cin >> c;
	while(c--) {
		solve();
	}
}