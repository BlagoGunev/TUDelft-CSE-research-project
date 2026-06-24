//misaka, hitori, and elaina will carry me to red



#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



#include <iostream>

#include <cmath>

#include <utility>

#include <cassert>

#include <algorithm>

#include <vector>

#include <array>

#include <cstdio>

#include <cstring>

#include <functional>

#include <numeric>

#include <set>

#include <queue>

#include <map>

#include <chrono>

#include <random>



#define sz(x) ((int)(x.size()))

#define all(x) x.begin(), x.end()

#define pb push_back

#define eb emplace_back

#define kill(x, s) {if(x){ cout << s << "\n"; return ; }}



#ifndef LOCAL

#define cerr while(0) cerr

#endif



using ll = long long;

using lb = long double;



const lb eps = 1e-9;

const ll mod = 1e9 + 7, ll_max = 1e18;

//const ll mod = (1 << (23)) * 119 +1, ll_max = 1e18;

const int MX = 2e5 +10, int_max = 0x3f3f3f3f;



struct {

  template<class T>

  operator T() {

    T x; std::cin >> x; return x;

  }

} in;



using namespace std;



#define LC(k) (2*k)

#define RC(k) (2*k +1)



int st[MX*4];

ll arr[MX];

vector<ll> srt;

int n;

void U(int p, int v, int k, int L, int R){

	if(L + 1 == R){

		assert(L == p);

		st[k] = max(st[k], v);

		return ;

	}

	int mid = (L + R)/2;

	if(p < mid) U(p, v, LC(k), L, mid);

	else U(p, v, RC(k), mid, R);

	st[k] = max(st[LC(k)], st[RC(k)]);

}



int Q(int qL, int qR, int k, int L, int R){

	if(qR <= L || R <= qL) return -int_max;

	if(qL <= L && R <= qR) return st[k];

	int mid = (L + R)/2;

	return max(Q(qL, qR, LC(k), L, mid), Q(qL, qR, RC(k), mid, R));

}



void solve(){

	n = in;

	ll sum = 0;

	srt.pb(0);

	for(int i = 1; i<=n; i++){

		arr[i] = in;

		sum += arr[i];

		srt.pb(sum);

	}

	sort(all(srt));

	srt.resize(unique(all(srt)) - srt.begin());

	int m = sz(srt);

	memset(st, 0x8f, sizeof(st));

	U(lower_bound(all(srt), 0ll) - srt.begin(), 0, 1, 0, m); //base case

	sum = 0;

	int ans = 0;

	for(int i = 1; i<=n; i++){

		sum += arr[i];

		int t = lower_bound(all(srt), sum) - srt.begin();

		int v = max(Q(0, t+1, 1, 0, m) + i, ans);

		U(t, v - i, 1, 0, m);

		cerr << i << " " << sum << " " << t << " " << v << "\n";

		ans = max(ans, v);

	}

	cout << ans << "\n";

}



signed main(){

  cin.tie(0) -> sync_with_stdio(0);



  int T = 1;

  //cin >> T;

  for(int i = 1; i<=T; i++){

		//cout << "Case #" << i << ": ";

		solve();

	}

  return 0;

}