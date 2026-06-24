#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define pb push_back
#define conts continue
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define ff first
#define ss second
#define ceil2(x,y) (x+y-1) / y
#define MAX 100000

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" = "; print(x); cout << endl;
#else
#define debug(x)
#endif

bool iseven(ll n) {if ((n & 1) == 0) return true; return false;}

void print(ll t) {cout << t;}
void print(int t) {cout << t;}
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}
void print(ld t) {cout << t;}

template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.ff); cout << ","; print(p.ss); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]";}

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

void solve()
{
    vector<ll> lcmvec(41);
    ll currlcm = 1;

    for (ll i = 1; i <= 40; ++i) {
        currlcm = lcm(currlcm, i);
        lcmvec[i] = currlcm;
    }

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        ll ind = 0;

        for (ll i = 1; i <= 40; ++i) {
            if (lcmvec[i] > n) {
                break;
            }
            ind = i;
        }

        ll prefix = 0;
        ll ans = 0;

        for (ll i = ind; i >= 1; --i) {
            ll divisible = n / lcmvec[i];
            ll temp = (divisible - prefix) * (i + 1);
            ans = (ans % MOD) + (temp % MOD);
            ans %= MOD;
            prefix += (divisible-prefix);
        }

        cout << ans << endl;

    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Competitive Programming/input.txt", "r", stdin);
    freopen("D:/Competitive Programming/output.txt", "w", stdout);
#endif
    fastio;
    solve();
    return 0;
}