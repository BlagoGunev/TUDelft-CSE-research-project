#include <bits/stdc++.h>

#ifndef M_PI

#define M_PI 3.14159265358979323846264338327

#endif // M_PI

#define endl "\n"

#define S struct

#define X first

#define Y second

#define V vector

#ifndef __linux__

#define LLD "%I64d"

#else

#define LLD "%ll""d"

#endif

#define FOR(x, y, z) for (int x = (y); x < (z); ++x)

#define FORR(x, y, z) for (int x = (y); x > (z); --x)

#define GET(a, n) for (int __i = 0; __i < (n); ++__i) cin >> a[__i];

#define GETM(a, n, m) for (int __i = 0; __i < (n); ++__i) for (int __j = 0; __j < m; ++__j) cin >> a[__i][__j];

#define PRINTM(a, n, m) for (int __i = 0; __i < (n); ++__i) { for (int __j = 0; __j < m; ++__j) cout << a[__i][__j] << " ";  cout << endl; };

#define PRINT(a, n) for (int __i = 0; __i < (n); ++__i) cout << a[__i] << " ";

#define IT(a) a.begin(), a.end()

#define SQR(x) (x) * (x)

#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;

#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();

#define DEBA(a) for (auto __i: a) cout << __i << " "; cout << endl; cout.flush();

#define IFDEB(b, a) if (b) { cout << #a << " = " << (a) << endl; cout.flush(); }

using namespace std;

typedef long long LL;

typedef long double LD;

typedef unsigned long long ULL;

typedef pair <int, int> PII;

typedef pair <LL, LL> PLL;

const int MOD = 1000000007;

S Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

S FAIL { FAIL () { cout << "CHANGE!!!" << endl;}};



S Z

{

    int i;

    int lev;

    int t;

    int l;

    int r;

    int x;

};



S Z2

{

    int i;

    int lev;

    int pos;

    int ans;

};



int n, m;



void compress(vector <Z> &q)

{

    map <int, int> s;

    FOR (i, 0, m) {

        if (q[i].t == 1) {

            s[q[i].x] = 0;

        }

    }

    int cnt = 0;

    for (auto &i: s) {

        s[i.X] = cnt++;

    }

    FOR (i, 0, m) {

        if (q[i].t == 1) {

            q[i].x = s[q[i].x];

        }

    }

}



int main()

{

    cin >> n >> m;

    vector <Z> q(m);

    FOR (i, 0, m) {

        int t, lev, l, r, x;

        cin >> t;

        if (t == 1) {

            cin >> lev >> l >> r >> x;

            q[i] = {i, lev, t, l, r, x};

        } else {

            cin >> lev >> x;

            q[i] = {i, lev, t, 0, 0, x};

        }

    }

    compress(q);

    vector <Z2> q2;

    vector <bitset <7000>> ans;

    FOR (i, 0, m) {

        if (q[i].t == 2) {

            q2.push_back({i, q[i].lev, q[i].x, 0});

        }

    }

    ans.resize(q2.size());

    vector <int> pre(200000);

    int j = 1;

    FOR (i, 1, pre.size()) {

        if (!(i & (i - 1))) {

            pre[j++] = i;

        }

        if (j >= pre.size()) {

            break;

        }

        pre[j++] = i;

        if (j >= pre.size()) {

            break;

        }

    }

    sort(IT(q2), [] (const Z2 &x, const Z2 &y) {

        return x.lev > y.lev;

    });

    FOR (i, 0, m) {

        if (q[i].t == 1) {

            int k = q[i].lev;

            int posl = q[i].l;

            int posr = q[i].r;

            FOR (j, 0, int(q2.size())) {

                if (k < q2[j].lev) {

                    continue;

                }

                while (k > q2[j].lev) {

                    posl = pre[posl];

                    posr = pre[posr];

                    --k;

                }

                if (posl <= q2[j].pos && q2[j].pos <= posr) {

                    ans[j].set(q[i].x);

                }

            }

        } else {

            FOR (j, 0, q2.size()) {

                if (q[i].lev == q2[j].lev && q[i].x == q2[j].pos && q[i].i == q2[j].i) {

                    q2[j].ans = ans[j].count();

                    //DEB(ans[j].count());

                }

            }

        }

        /*FOR (j, 0, int(q2.size())) {

            FOR (l, 0, 20) {

                cout << ans[j].test(l);

            }

            cout << endl;

            //DEB(ans[j].count());

        }

        cout << endl;*/

    }

    sort(IT(q2), [] (const Z2 &x, const Z2 &y) {

        return x.i < y.i;

    });

    for (auto i: q2) {

        cout << i.ans << endl;

    }

}