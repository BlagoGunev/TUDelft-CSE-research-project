#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <bitset>

#include <array>

// #include <bits/stdc++.h>

using namespace std;



using ll = long long;

using lld = long double;

using ull = unsigned long long;

using vll = vector<ll>;

using pll = pair<ll, ll>;

using vpll = vector<pll>;



#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;

#else

#define debug(x) ((void)0);

#endif



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define loop(i,k,n) for(ll i = k; i < n;i++)

#define MOD 1000000007

#define MOD1 998244353

#define nl "\n"

#define pb push_back

#define ppb pop_back

#define mp make_pair

#define ff first

#define ss second

#define PI 3.141592653589793238462

#define set_bits __builtin_popcountll

#define sz(x) ((int)(x).size())

#define all(x) (x).begin(), (x).end()

#define UNIQUE(X) X.erase(unique(all(X)),X.end())

const ll INF = 1e18;



template<class A> void read(vector<A>& v);

template<class T> void read(T& x) {

    cin >> x;

}

template<class H, class... T> void read(H& h, T&... t) {

    read(h);

    read(t...);

}



template<class A> void read(vector<A>& x) {

    for (auto& a: x)

        read(a);

}

template<class A> void read1(vector<A>& x) {

    for(ll i = 1; i <= sz(x) - 1; i++){

        read(x[i]);

    }    

}



void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(lld t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }

template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void google(int t) {cout << "Case #" << t << ": ";}



ll mul(ll a, ll b, ll m) {

        if (a < (1 << 14)) {

            return (a * b) % m;

        }

        ll c = mul(a >> 14, b, m);

        c <<= 14;

        c %= m;

        c = (c + (a % (1 << 14)) * b) % m;

        return c;

}

ll fast_power(ll p, ll e, ll m) {

        if (e == 0) {

            return 1 % m;

        }

        if (e % 2 == 0) {

            return fast_power(mul(p, p, m), e / 2, m);

        }

        else {

            return mul(fast_power(p, e - 1, m), p, m);

        }

}



// #define N 200005     // change N here

// vector<vll> adjl(N);

// vll visited(N);



// ll n, m;



// vector<ll> adj[N];

// void dfs(ll u){

//     visited[u] = 1;

//     for(ll v: adj[u]){

//         if(!visited[v]){

//             dfs(v);

//         }

//     }

// }



// vll dist;

 

// void bfs(ll s) {

//     dist.assign(n + 1, -1);  // n must be defined(i.e global)

//     queue<ll> q;

//     dist[s] = 0; q.push(s);

//     while (q.size()) {

//         ll u = q.front(); q.pop();

//         for (ll v : adj[u]) {

//             if (dist[v] == -1) {

//                 dist[v] = dist[u] + 1;

//                 q.push(v);

//             }

//         }

//     }

// }



// const ll maxn = 1000;   // set maxn accordingly

// ll C[maxn + 1][maxn + 1];

// void makenCr(){

//     C[0][0] = 1;

//     for (ll n = 1; n <= maxn; ++n) {

//         C[n][0] = C[n][n] = 1;

//         for (ll k = 1; k < n; ++k)

//             C[n][k] = C[n - 1][k - 1] + C[n - 1][k];

//             // C[n][k] %= MOD;

//     }

// }



void solve(){

    ll n; cin >> n;

    vll a(n); read(a);

    ll idx = -1, ans = -1;

    loop(i, 0, n){

        ll val1 = a[i], val2 = a[i], cnt = a[i];

        for(ll j = i + 1; j < n; j ++){

            val2 = min(a[j], val2);

            cnt += val2;

        }

        for(ll j = i - 1; j >= 0; j --){

            val1 = min(val1, a[j]);

            cnt += val1;

        }

        if(ans < cnt){

            ans = cnt;

            idx = i;

        }

    }



    ll val1 = a[idx], val2 = a[idx];

    for(ll j = idx + 1; j < n; j ++){

        a[j] = min(val2, a[j]);

        val2 = a[j];

    }

    for(ll j = idx - 1; j >= 0; j --){

        a[j] = min(a[j], val1);

        val1 = a[j];

    }

    for(auto x: a) cout << x << " ";

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    #ifndef ONLINE_JUDGE

    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);

    cout << "---------------------" << nl;

    cout << "OUTPUT:" << nl;

    freopen("error.txt", "w", stderr);

    #endif 



    int t = 1;

    

    // cin>>t;

    

    for(ll i = 1; i <= t; i ++)

    {   

        // google(i);

        solve();

        // cout << "\n"; 

    }

    return 0;

}