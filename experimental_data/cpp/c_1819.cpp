#include<bits/stdc++.h>
using namespace std;
const long long inf = (long long) 1e18 + 10;
const int inf1 = (int) 1e9 + 10;
#define int long long
#define dbl long double
#define endl '\n'
#define sc second
#define fr first
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
const int maxn = 2e5+10;

int n, lv[maxn], dp[maxn], dp1[maxn];
vector<int> g[maxn], ans;

void dfs(int u, int ant) {
    if(g[u].size() == 1) {
        lv[u] = 1;
        return;
    }

    vector<int> vs;
    for(auto v : g[u]) if(v != ant) {
        dfs(v,u);
        if(lv[v] == 0) vs.pb(v);
    }

    if(vs.size() == 0) {
        dp[u] = 1;
        dp1[u] = 1;
    }
    else if(vs.size() == 1) {
        dp[u] = dp1[vs[0]];
        dp1[u] = dp[vs[0]];
    }
    else {
        dp[u] = 0;
        dp1[u] = 0;
    }
}
void rec1(int u, int ant);
void rec2(int u, int ant);
void rec1(int u, int ant) {
    if(u == 0) return;
    vector<int> vs;
    for(auto v : g[u]) if(v != ant) {
        if(lv[v] == 0) vs.pb(v);
    }

    int v2 = 0;
    if(vs.size()) v2 = vs[0];
    for(auto v : g[u]) if(v != ant) {
        if(lv[v] == 1) ans.pb(v);
    }
    rec2(v2,u);
    ans.pb(u);
}

void rec2(int u, int ant) {
    if(u == 0) return;
    ans.pb(u);
    vector<int> vs;
    for(auto v : g[u]) if(v != ant) {
        if(lv[v] == 0) vs.pb(v);
    }
    int v1 = 0;
    if(vs.size()) v1 = vs[0];
    rec1(v1,u);
    for(auto v : g[u]) if(v != ant) {
        if(lv[v] == 1) ans.pb(v);
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n-1; i++) {
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int rt = -1;
    for(int i = 1; i <= n; i++) {
        if((int) g[i].size() != 1) rt = i;
    }

    if(rt == -1) {
        cout << "Yes" << endl;
        cout << "1 2" << endl;
        return;
    }

    bool ansok = true;
    dfs(rt,-1);
    vector<int> vs;
    for(auto v : g[rt]) {
        if(lv[v] == 0) vs.pb(v);
    }
    int v1 = 0;
    int v2 = 0;
    if(vs.size() == 1) {
        if(dp[vs[0]]) v2 = vs[0];
        else if(dp1[vs[0]]) v1 = vs[0];
        else ansok = false;
    }
    else if(vs.size() == 2) {
        if(dp1[vs[0]] && dp[vs[1]]) {
            v1 = vs[0];
            v2 = vs[1];
        }
        else if(dp1[vs[1]] && dp[vs[0]]) {
            v1 = vs[1];
            v2 = vs[0];
        }
        else {
            ansok = false;
        }
    }
    else if(vs.size() > 2) {
        ansok = false;
    }
    if(ansok == false) {
        cout << "No" << endl;
        return;
    }

    ans.pb(rt);
    rec1(v1,rt);
    for(auto v : g[rt]) {
        if(lv[v]) ans.pb(v);
    }
    rec2(v2,rt);

    cout << "Yes" << endl;
    for(auto x : ans) {
        cout << x << " ";
    }cout << endl;

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }

}