#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <complex>
#include <math.h>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <list>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "strings"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgashqt
#define free afdshjioeyqtw
#define next qpowityqwopqw

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INF64 = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll MD = 1551513443;
const ll T = 25923;
const int N = 100010;
const int M = 1010;

int n, m, a[N], jj[N], sum[N * 4], pp[N * 4], cl[N * 4];
pii t[N * 4];
vector < int > p;

void rec(int x) {
    if (x > 0)
        p.pb(x);
    if (x > 10000)
        return;
    rec(x * 10 + 4);
    rec(x * 10 + 7);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        while (p[jj[tl]] < a[tl])
            jj[tl]++;
        t[v] = mp(p[jj[tl]] - a[tl], tl);
        if (t[v].x == 0) {
            sum[v] = 1;
            jj[tl]++;
            t[v] = mp(p[jj[tl]] - a[tl], tl);
        }
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

inline void push(int v, int tl, int tr) {
    if (tl != tr) {
        pp[v * 2] += pp[v];
        pp[v * 2 + 1] += pp[v];
        cl[v * 2] |= cl[v];
        cl[v * 2 + 1] |= cl[v];
    }
    if (tl == tr)
        a[tl] += pp[v];
    t[v].x -= pp[v];
    if (cl[v])
        sum[v] = 0;
    pp[v] = 0;
    cl[v] = 0;
}


void update(int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r) {
        pp[v] += val;
        cl[v] = 1;
        push(v, tl, tr);
    }
    else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), val);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

void dfs(int v, int tl, int tr) {
    push(v, tl, tr);
    if (t[v].x > 0)
        return;
    if (tl == tr) {
        while (p[jj[tl]] < a[tl])
            jj[tl]++;
        t[v] = mp(p[jj[tl]] - a[tl], tl);
        if (t[v].x == 0) {
            sum[v] = 1;
            jj[tl]++;
            t[v] = mp(p[jj[tl]] - a[tl], tl);
        }
    } else {
        int tm = (tl + tr) / 2;
        dfs(v * 2, tl, tm);
        dfs(v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return sum[v];
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) +
           get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    //FREOPEN;
    ios::sync_with_stdio(0);
    rec(0);
    sort(all(p));
    cin >> n >> m;
    forn(i, n)
        cin >> a[i];
    build(1, 0, n - 1);
    forn(i, m) {
        string s;
        cin >> s;
        if (s == "add") {
            int l, r, d;
            cin >> l >> r >> d;
            l--; r--;
            update(1, 0, n - 1, l, r, d);
            dfs(1, 0, n - 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }
    return 0;
}




/*



*/