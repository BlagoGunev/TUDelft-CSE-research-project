#include <bits/stdc++.h>

#define fi first

#define se second

#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)

#define mk make_pair

#define pii pair<int, int>

#define pll pair<ll, ll>

#define pb push_back

#define IT iterator

#define V vector

#define TP template <class o>

#define TPP template <typename t1, typename t2>

#define SZ(a) ((int)a.size())

#define all(a) a.begin(), a.end()

#define rep(i, a, b) for (int i = a, i##ed_ = b; i <= i##ed_; i++)

#define REP(i, a, b) for (int i = b, i##st_ = a; i >= i##st_; i--)

#define FOR(i, n) rep(i, 1, n)

#define debug(x) cerr << #x << ' ' << '=' << ' ' << x << endl

using namespace std;

typedef unsigned ui;

typedef long long ll;

typedef long double ld;



char buf[1 << 20],*p1=buf,*p2=buf;

TP void qr(o& x) {

    char c = gc;

    x = 0;

    int f = 1;

    while (!isdigit(c)) {

        if (c == '-')

            f = -1;

        c = gc;

    }

    while (isdigit(c))

        x = x * 10 + c - '0', c = gc;

    x *= f;

}

template <class o, class... O> void qr(o& x, O&... y) { qr(x), qr(y...); }

TP void qw(o x) {

    if (x < 0)

        putchar('-'), x = -x;

    if (x / 10)

        qw(x / 10);

    putchar(x % 10 + '0');

}

TP void pr1(o x) { qw(x), putchar(' '); }

template <class o, class... O> void pr1(o x, O... y) { pr1(x), pr1(y...); }

TP void pr2(o x) { qw(x), putchar(10); }

template <class o, class... O> void pr2(o x, O... y) { pr2(x), pr2(y...); }

TP bool cmax(o& x, o y) { return (x < y ? x = y, 1 : 0); }

TP bool cmin(o& x, o y) { return (x > y ? x = y, 1 : 0); }



const int mod = 998244353;

TPP void ad(t1& x, t2 y) { (x += y) >= mod && (x -= mod); }

TPP void dl(t1& x, t2 y) { (x -= y) < 0 && (x += mod); }



const int N = 2e5 + 10, inf = 2e9;

const ll INF = 1e15;

int n, m, a[N], b[N], pa, pb, da[N], db[N];



bool check(int v) {

    int j = m;

    FOR(i, n) {

        while(j && a[i] + b[j] > v) j--;

        da[i] = j;

    }

    j = n;

    ll s = 0, i1, i2;

    FOR(i, m) {

        while(j && b[i] + a[j] > v) j--;

        db[i] = j; s += j;

    }

    i1 = i2 = s;

    j = m;

    REP(i, 1, n) {

        s += m - (da[i] + j);

        cmax(i1, s);

        cmax(i2, s - (i <= pa && j < pb));

        while(j && n >= (i - 1 + db[j])) {

            s += n - (i - 1 + db[j--]);

            cmax(i1, s);

            cmax(i2, s - (i <= pa && j < pb));

        }

    }

    return i1 == i2;

}



void solve() {

    qr(n, m);

    FOR(i, n) qr(a[i]);

    FOR(i, m) qr(b[i]);

    pa = a[1]; pb = b[1];

    sort(a + 1, a + n + 1);

    sort(b + 1, b + m + 1);

    int l = a[1] + b[1], r = pa + pb;

    pa = lower_bound(a + 1, a + n + 1, pa) - a;

    pb = lower_bound(b + 1, b + m + 1, pb) - b;

    while(l < r) {

        int mid = (l + r) / 2;

        if(check(mid)) r = mid;

        else l = mid + 1;

    } pr2(l);

}



int main() {

#ifndef ONLINE_JUDGE

    clock_t start_time = clock();

#endif

    int T = 1;

    // qr(T);

    while (T--)

        solve();

#ifndef ONLINE_JUDGE

    cerr << 1.0 * (clock() - start_time) / CLOCKS_PER_SEC << ' ' << 's' << endl;

#endif

    return 0;

}