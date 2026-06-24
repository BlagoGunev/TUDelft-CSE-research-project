#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <bitset>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
#include <numeric>
#include <math.h>
#include <cassert>
#include <climits>
#include <chrono>
#include <random>
#pragma warning(disable:4996)
#define endl "\n"
#define ld long double
#define int int
#define uint unsigned long long
#define _default std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout << fixed; cout.precision(8);
typedef long long ll;
using namespace std;
using namespace std::chrono;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;

#ifdef TSAR
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << x << endl
#else
#define dbg(x)
#endif

ostream& operator<<(ostream& o, string& a) {
    for (auto& el : a) {
        o << el;
    }
    return o;
}

template<typename T, template<typename... Args> class cont>
ostream& operator<<(ostream& o, cont<T>& a) {
    for (auto& el : a) {
        o << el << " ";
    }
    o << "\n";
    return o;
}

int test;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}



void solve() {

    int a, b, c, d; cin >> a >> b >> c >> d;

    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    int cnt = 0;
    for (int i = a; i <= b; ++i) {
        if (i == c || i == d) {
            cnt++;
        }
    }

    if (cnt == 1) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return;
}


signed main() {
    _default;
    srand(time(NULL));
#ifdef TSAR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    //freopen("grant.in", "r", stdin);
    //freopen("grant.out", "w", stdout);


    int t = 1;

    cin >> t;

    for (test = 1; test <= t; ++test) {

        solve();
    }



    return 0;
}