#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("fast-math")
// #pragma GCC optimize(2)
// #pragma GCC optimize("Ofast","inline","-ffast-math")
// #pragma GCC optimize "-O3"

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vvll = vector<vll>;
using ld = long double;

const ll INF = 1e16;
const ld EPS = 1e-8;

// v2 = rand() % 100 + 1;  --- v2 in the range 1 to 100

struct node {
    ll u, a, b;
};

ll bin_search(vll &a, ll x) {

    ll l = -1;
    ll r = a.size();

    while (r - l > 1) {

        ll m = (l + r) / 2;

        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }

    }

    return l + 1;

}

void dfs(ll curV, vll &marked, vll &curPathA, vll &curPathB, vll &ans, vector<vector<node>> &E) {

    if (marked[curV])
        return;

    // find ans
    if (curV != 0) {
        ll curA = curPathA[curPathA.size() - 1];

        ll k = bin_search(curPathB, curA);

        ans[curV] = k;

    }
    // 

    for (ll i = 0; i < E[curV].size(); ++i) {
        ll curU = E[curV][i].u;
        if (marked[curU])
            continue;
        
        ll v1 = E[curV][i].a;
        if (curPathA.size() != 0) 
            v1 += curPathA[curPathA.size() - 1];
        curPathA.push_back(v1);
        
        ll v2 = E[curV][i].b;
        if (curPathB.size() != 0) 
            v2 += curPathB[curPathB.size() - 1];
        curPathB.push_back(v2);

        
        dfs(curU, marked, curPathA, curPathB, ans, E);

        curPathA.pop_back();
        curPathB.pop_back();
    }

}   

void solve() {
    ll n; cin >> n;

    vector<vector<node>> E(n);

    for (ll i = 0; i < n - 1; ++i) {
        ll v, u, a, b;
        cin >> u >> a >> b;
        --u;
        v = i + 1;
        E[u].push_back({v, a, b});
    }


    vll curPathA;
    vll curPathB;
    vll marked(n, 0);
    vll ans(n, 0);
    dfs(0, marked, curPathA, curPathB, ans, E);

    for (ll i = 1; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    // cout << fixed << setprecision(10);
    
    while (t--) {
        solve();
        // cout << solve() << endl;
        // if (solve())
        //    cout << "Yes" << endl;
        // else
        //    cout << "No" << endl;
    }

    return 0;
}