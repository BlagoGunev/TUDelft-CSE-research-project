#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define int long long

#define fi first

#define se second

#define all(m) (m).begin(), (m).end()

#define rall(m) (m).rbegin(), (m).rend()

#define vec vector

#define mp make_pair



typedef pair <int, int> pii;

typedef long long ll;

typedef long double ld;



using mtx = vec <vec <int>>;

const int maxn  = 1e6 + 42;

const int inf = 1e18;

const int logn = 23;



int a[maxn], b[maxn];

int p[maxn];

int pref[maxn], suf[maxn];



struct ft{

    vector <int> t;

    int sz = 0;

    ft(int n){

        t = vector <int> (n, 0);

        sz = n;

    }

    void inc(int pos, int d){

        for (pos; pos < sz; pos |= pos + 1){

            t[pos] += d;

        }

    }

    int get(int pos){

        int res = 0;

        for (pos; pos >= 0; pos = (pos & (pos + 1)) - 1){

            res += t[pos];

        }

        return res;

    }

};



void solve(int l, int r, int pl, int pr){

    if (l >= r) return;

    int mid = (l + r) >> 1;

    int cur = b[mid];

    pref[pl] = 0;

    for (int i = pl + 1; i < pr; ++i){

        pref[i] = pref[i - 1] + (a[i - 1] > cur);

    }

    suf[pr] = 0;

    for (int i = pr - 1; i >= pl; --i){

        suf[i] = suf[i + 1] + (a[i] < cur);

    }

    int pos = pl;

    int ans = inf;

    for (int i = pl; i < pr; ++i){

        if (pref[i] + suf[i] < ans){

            ans = pref[i] + suf[i];

            pos = i;

        }

    }

    p[mid] = pos;

    if (l + 1 < r){

        solve(l, mid, pl, pos + 1);

        solve(mid, r, pos, pr);

    }

}



int slv(){

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; ++i){

        cin >> a[i];

    }

    for (int i = 0; i < m; ++i){

        cin >> b[i];

    }

    sort(b, b + m);

    solve(0, m, 0, n + 1);

    vector <int> c;

    int j = 0;

    for (int i = 0; i < n; ++i){

        while(j < m && p[j] == i){

            c.push_back(b[j]);

            j++;

        }

        c.push_back(a[i]);

    }

    while(j < m){

        c.push_back(b[j]);

        j++;

    }

    vector <int> tm = c;

    sort(all(tm));

    for (auto &i: c){

        i = lower_bound(all(tm), i) - tm.begin();

    }

    assert(c.size() == n + m);

    n = c.size();

    ft fen(n + 42);

    ll ans = 0;

    for (int i = 0; i < n; ++i){

        ans += (ll)i - fen.get(c[i]);

        fen.inc(c[i], 1);



    }

    cout << ans << "\n";

    return 0;

}



signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ttt;

    cin >> ttt;

    while(ttt--){

        slv();

    }

	return 0;

}