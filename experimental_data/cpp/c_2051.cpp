#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <iterator>
#include <numeric>
#include <complex>
#include <utility>
#include <random>
#include <cassert>
#include <fstream>
using namespace std;
mt19937 rnd(time(nullptr));

/* -------------------- Typedefs -------------------- */

typedef int itn;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef float fl;
typedef long double ld;

/* -------------------- Usings -------------------- */

using vi = vector<int>;
using vll = vector<ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

/* -------------------- Defines -------------------- */

#define ff first
#define ss second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mpr make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define all(x) (x).begin(), (x).end()
#define USACO freopen("feast.in", "r", stdin); freopen("feast.out", "w", stdout);

/* -------------------- Constants -------------------- */

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int dy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = int(1e9 + 5);
const ll MAXL = ll(1e18) + 5ll;
const ll MOD = ll(1000000007);
const ll MOD2 = ll(998244353);

/* -------------------- Functions -------------------- */

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void precision(int x) {
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(x);
}

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return(max(a, b));
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll range_sum(ll a, ll b) {
    if (a > b) return 0ll;
    ll dif = a - 1, cnt = b - a + 1;
    ll ans = ((b - a + 1) * (b - a + 2)) / 2;
    ans += ((b - a + 1) * dif);
    return ans;
}

string dec_to_bin(ll a) {
    string s = "";
    for (ll i = a; i > 0; ) {
        ll k = i % 2;
        i /= 2;
        char c = k + 48;
        s += c;
    }
    if (a == 0) {
        s = "0";
    }
    reverse(all(s));
    return s;
}

ll bin_to_dec(string s) {
    ll num = 0;
    for (int i = 0; i < s.size(); i++) {
        num *= 2ll;
        num += (s[i] - '0');
    }
    return num;
}

ll factorial_by_mod(ll n, ll mod) {
    ll ans = 1;
    ll num;
    for (ll i = 1; i <= n; ++i) {
        num = i % mod;
        ans *= num;
        ans %= mod;
    }
    return ans;
}

bool isPrime(ll a) {
    if (a == 1) return false;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

ll binpow(ll a, ll b) {
    if (!a) return 0;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll binpow_by_mod(ll a, ll b, ll mod) {
    if (!a) return 0;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ans;
}

/* -------------------- Solution -------------------- */

void slv() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(m + 1), b(k + 1);
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
        st.erase(b[i]);
    }
    if ((int)st.size() > 1) {
        for (int i = 0; i < m; ++i) {
            cout << 0;
        }
        cout << '\n';
        return;
    }
    if ((int)st.size() == 0) {
        for (int i = 0; i < m; ++i) {
            cout << 1;
        }
        cout << '\n';
        return;
    }
    int num = *st.begin();
    for (int i = 1; i <= m; ++i) {
        if (a[i] == num) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << '\n';
}

void cs() {
    int tstc = 1;
    cin >> tstc;
    while (tstc--) {
        slv();
    }
}

void precalc() {
    return;
}

int main() {
    fastio();
    precalc();
    //precision(0);
    cs();
    return 0;
}