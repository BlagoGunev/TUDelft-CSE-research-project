#include <bits/stdc++.h>
#define fi first
#define sc second
#define pb push_back
#define rep(i,p,k) for(int i=(p);i<(k);++i)
#define forn(i,p,k) for(int i=(p);i<=(k);++i)
#define forr(i,k,p) for(int i=(k)-1;i>=(p);--i)
#define each(a,b) for(auto&a:b)
#define all(v)  begin(v), end(v)
#define RET(smth)   {cout<<(smth)<<'\n'; return;}
#define sz(v) (int)v.size()
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using Vi = vector<int>;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) ;
#endif
const int L = 18;
const int MM = 2e5+13;
int anc[L][MM],num[L][MM],nuM[L][MM];
Vi W[MM];
int deep[MM], pre[MM], post[MM];
int lca(int a, int b) {
    if(deep[a] < deep[b]) swap(a,b);
    int k = deep[a] - deep[b];
    rep(i,0,L) if(k&(1<<i)) a = anc[i][a];
    if(a==b) return a;
    forr(i,L,0) if(anc[i][a] != anc[i][b]) {
        a = anc[i][a];
        b = anc[i][b];
    }
    return anc[0][a];
}
bool is_anc(int a, int b){
    return pre[a] <= pre[b] && post[b] <= post[a];
}
void DFS(int w, int p, int &t, int d) {
    anc[0][w] = p;
    pre[w] = t++;
    deep[w] = d;
    for(auto v : W[w]) if(v!=p) DFS(v,w,t,d+1);
    post[w] = t-1;
}
struct MAIN {
    int n;
    vector<Vi> G;
    void add_path(int a, int k, int c, bool dir) {
        rep(i,0,L) if(k&(1<<i)) {
            if(dir) G[c].push_back(num[i][a]);
            else    G[nuM[i][a]].push_back(c);
            a = anc[i][a];
        }
    }
    Vi vis,ord;
    bool topo(int w) {
        vis[w] = 1;
        for(auto v : G[w]) {
            if(vis[v] == 1) return true;
            if(!vis[v] && topo(v)) return true; 
        }
        if(w < n) ord.push_back(w);
        vis[w] = 2;
        return false;
    }
    MAIN(int _n) : n(_n), G(n) {
        int m; cin >> m;
        rep(i,0,n-1) {
            int a,b; cin >> a >> b; --a; --b;
            W[a].push_back(b);
            W[b].push_back(a);
        }
        int tim = 0;
        DFS(0,0,tim,0);
        rep(i,0,n) num[0][i] = nuM[0][i] = i;
        rep(i,1,L) rep(j,0,n) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
            num[i][j] = G.size();
            G.emplace_back();
            G.back().push_back(num[i-1][j]);
            G.back().push_back(num[i-1][anc[i-1][j]]);
            nuM[i][j] = G.size();
            G[nuM[i-1][j]].push_back(G.size());
            G[nuM[i-1][anc[i-1][j]]].push_back(G.size());
            G.emplace_back();
        }
        rep(i,0,m) {
            int t,a,b,c; cin >> t >> a >> b >> c; --a, --b, --c;
            int l = lca(a,b);
            bool dir = t == 1;
            if(c == l) {
                add_path(a,deep[a]-deep[c],c,dir);
                add_path(b,deep[b]-deep[c],c,dir);
                continue;
            }
            if(is_anc(c,b)) swap(a,b);
            add_path(a,deep[a]-deep[c],c,dir);
            add_path(anc[0][c],deep[c]-deep[l]-1,c,dir);
            add_path(b,deep[b]-deep[l],c,dir);
            if(dir) G[c].push_back(l);
            else    G[l].push_back(c);
        }
        ord.reserve(n);
        vis.resize(sz(G));
        rep(i,0,n) if(!vis[i] && topo(i)) RET(-1);
        reverse(all(ord));
        int cnt{};
        Vi R(n);
        for(auto v : ord) R[v]=++cnt;
        for(auto v : R) cout << v << ' ';
        cout << '\n';
    }
};

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    int n; cin >> n;
    MAIN{n};
    return 0;
}