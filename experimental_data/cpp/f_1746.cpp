#include <bits/stdc++.h>

//#include<ext/rope>

#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>



//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("unroll-loops")

//#pragma GCC optimize("-O3")

//#pragma GCC target("avx2")

//#pragma comment(linker, "/STACK:268435456")





#define in(x) freopen(x, "r", stdin)

#define out(x) freopen(x, "w", stdout)

#define F first

#define S second

#define pb push_back

#define sz(x) int(x.size())

#define el '\n'

#define all(x) x.begin(), x.end()



using namespace std;

using namespace __gnu_pbds;

//using  namespace __gnu_cxx;



typedef long long ll;

typedef long double ld;

typedef short int si;

typedef unsigned long long ull;

typedef tree <ll, null_type, less_equal <ll> , rb_tree_tag, tree_order_statistics_node_update> ordered_set;



const int M = 1e12;

const int N = 3e5 + 500;



ll t[N];

int n, q;

int l[N], r[N], k[N], T[N], x[N], ps[N], a[N], ans[N], b[N];

ll who[3 * N];



void upd(int v, ll x) {for (; v < N; v = (v | (v + 1))) t[v] += x;}

ll get(int v) {ll ret = 0; for (; v > 0; v = (v & (v + 1)) - 1) ret += t[v]; return ret;}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);



    mt19937 rnd(time(0));



    cin >> n >> q;

    vector <int> vals;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

        vals.pb(a[i]);

    }



    for (int i = 1; i <= q; i++) {

        cin >> T[i];

        if (T[i] == 1) {

            cin >> ps[i] >> x[i];

            vals.pb(x[i]);

        } else {

            cin >> l[i] >> r[i] >> k[i];

            ans[i] = 1;

        }

    }

    sort(all(vals));

    vals.resize(unique(all(vals)) - vals.begin());

    map <int, ll> mp;

    int it = 0;

    for (auto x : vals) {

        mp[x] = it++;

    }

    for (int i = 1; i <= n; i++) {

        a[i] = mp[a[i]];

    }

    for (int i = 1; i <= q; i++) {

        x[i] = mp[x[i]];

    }

    for (int it = 0; it < 30; it++) {

        for (int i = 0; i < N; i++) {

            t[i] = 0;

        }

        int vl = 0;

        for (auto x : vals) {

            who[vl++] = rnd() % M;

        }



        for (int i = 1; i <= n; i++) {

            upd(i, who[a[i]]);

            b[i] = a[i];

        }



        for (int i = 1; i <= q; i++) {

            if (T[i] == 1) {

                int I = ps[i];

                upd(I, -who[b[I]]);

                b[I] = x[i];

                upd(I, who[b[I]]);

            } else {

                ll sum = get(r[i]) - get(l[i] - 1);

                if (sum % k[i] != 0) {

                    ans[i] = 0;

                }

            }

        }

    }

    for (int i = 1; i <= q; i++) {

        if (T[i] == 2) {

            cout << (ans[i] ? "YES" : "NO") << el;

        }

    }

}