#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define x0 abc

#define y0 ABC

#define x1 abcd

#define y1 ABCD

#define xn abcde

#define yn ABCDE



#define lb lower_bound

#define ub upper_bound



#define in insert

#define er erase



#define fi first

#define se second

#define mp make_pair



#define pb push_back

#define pob pop_back



#define uns unsigned



#define ld long double

#define ll long long



#define cont continue

#define re return



#define endl '\n'



#define fbo find_by_order

#define ook order_of_key



#define MAXLL 9000000000000000000LL

#define MAXINT 2000000000



#define MINLL -9000000000000000000LL

#define MININT -2000000000



#define OUT cout << "-------" << endl;



#define bpc __builtin_popcount

#define bpcll __builtin_popcountll



#define tm qwerty



using namespace std;



using namespace __gnu_pbds;



mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());



typedef tree < pair <ll, ll>, null_type, less < pair <ll, ll> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;







ld pi = acos(-1.), E = exp(1.);



ll N = 10000, M = 998244353, D = 5000, T, Q;



struct segment

{

    ll l, r, c, idx;

};



segment a[250001];



ll ans[250001], t[1200001], n, i, j, lst;



bool fl;



    bool comp(segment a, segment b)

    {

        if (a.r < b.r)

        re 1;



        re 0;

    }



    bool comp1(segment a, segment b)

    {

        if (a.l < b.l)

        re 1;



        re 0;

    }



    void update(ll tl, ll tr, ll v, ll idx, ll val)

    {

        if (tl > idx || tr < idx)

        re;



        if (tl == tr) {

            t[v] = max(t[v], val);



            re;

        }



        ll mid = (tl + tr) / 2;



        update(tl, mid, v * 2, idx, val);

        update(mid + 1, tr, v * 2 + 1, idx, val);



        t[v] = max(t[v * 2], t[v * 2 + 1]);

    }



    ll get(ll tl, ll tr, ll v, ll l, ll r)

    {

        if (l > r || tl > r || tr < l)

        re 0;



        if (l <= tl && tr <= r)

        re t[v];



        ll mid = (tl + tr) / 2;



        re max(get(tl, mid, v * 2, l, r), get(mid + 1, tr, v * 2 + 1, l, r));

    }



    void solve()

    {

        cin >> n;



        for (i = 1; i <= n; i++) {

            cin >> a[i].l >> a[i].r >> a[i].c;



            a[i].idx = i;

        }



        for (i = 1; i <= n; i++) ans[i] = MAXLL;



        sort(a + 1, a + n + 1, comp);



        a[n + 1].r = a[n].r - 1;



        lst = 1;



        for (i = 1; i <= n; i++)

            if (a[i].r != a[i + 1].r) {

                fl = false;



                for (j = lst; j <= i - 1; j++)

                    if (a[j].c != a[j + 1].c) fl = true;



                if (fl) {

                    for (j = lst; j <= i; j++) ans[a[j].idx] = 0;

                }



                lst = i + 1;

            }



        lst = 0;



        for (i = 2; i <= n; i++) {

            if (a[i].c != a[i - 1].c)

            lst = i - 1;



            if (lst != 0)

            ans[a[i].idx] = min(ans[a[i].idx], max(a[i].l - a[lst].r, 0LL));

        }



        sort(a + 1, a + n + 1, comp1);



        a[n + 1].l = a[n].l - 1;



        lst = 1;



        for (i = 1; i <= n; i++)

            if (a[i].l != a[i + 1].l) {

                fl = false;



                for (j = lst; j <= i - 1; j++)

                    if (a[j].c != a[j + 1].c) fl = true;



                if (fl) {

                    for (j = lst; j <= i; j++) ans[a[j].idx] = 0;

                }



                lst = i + 1;

            }



        lst = n + 1;



        for (i = n - 1; i >= 1; i--) {

            if (a[i].c != a[i + 1].c)

            lst = i + 1;



            if (lst != n + 1)

            ans[a[i].idx] = min(ans[a[i].idx], max(a[lst].l - a[i].r, 0LL));

        }



        for (i = 1; i <= n * 4; i++) t[i] = 0;



        for (i = 1; i <= n; i++) {

            if (max(get(1, n, 1, 1, a[i].c - 1), get(1, n, 1, a[i].c + 1, n)) >= a[i].r)

            ans[a[i].idx] = 0;



            update(1, n, 1, a[i].c, a[i].r);

        }



        for (i = 1; i <= n; i++) cout << ans[i] << " ";



        cout << endl;

    }



int main()

{

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    ios::sync_with_stdio(0);

    cin.tie(0);



    cin >> T;



    while (T--) solve();



    re 0;

}