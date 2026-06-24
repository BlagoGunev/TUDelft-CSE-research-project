#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
#define pb push_back
#define fi first
#define si second
#define ar array
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;  
template<typename T> bool chmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

void debug_out() {cerr<<endl;}
template <typename Head, typename... Tail>
void debug_out(Head _H, Tail... _T) {cerr<<" "<<to_string(_H);debug_out(_T...);}
#define debug(...) cerr<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
const int MAXN = 200010;

int n, rt, cnt = 0;
int pa[MAXN], dep[MAXN];
vector<int> g[MAXN];
vector<int> dt, ans[MAXN];

void work(int x, int p) {
    for (auto i: g[x]) {
        if (i == p) continue;
        dep[i] = dep[x] + 1;
        work(i, x);
    }
}

void dfs(int x, int p) {
    for (auto i: g[x]) {
        if (i == p) continue;
        if (dep[dt.back()] >= dep[i]) {
            ++cnt;
        }
        ans[cnt].pb(i);
        dt.pb(i);
        dfs(i, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        cnt = 1;
        dt.clear();
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            ans[i].clear();
            pa[i] = 0, dep[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> pa[i];
            if (pa[i] == i) {
                rt = i;
                continue;
            }
            g[i].pb(pa[i]); g[pa[i]].pb(i);
        }
        work(rt, rt);
        dt.pb(rt); ans[1].pb(rt);
        dfs(rt, rt);
        cout << cnt << '\n';
        for (int i = 1; i <= cnt; ++i) {
            cout << (int)ans[i].size() << '\n';
            for (auto j: ans[i]) cout << j << ' ';
            cout << '\n';
        }
    }
    return 0;
}