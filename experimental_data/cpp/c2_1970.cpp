#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define all(p) p.begin(),p.end()
using ll =long long;

template<class T>
struct Reroot{
    using F1 = function<T(T, T)>;
    using F2 = function<T(T, T)>;
    struct edge{ll to, i , r;};
    ll n;
    vector<vector<edge>> es;
    vector<int> vis;
    vector<vector<T>> outs;
    vector<T> ans, re;
    T e;
    F1 op;
    F2 f, g;
    Reroot(ll n,T e, F1 op, F2 f, F2 g): n(n),es(n),vis(n, 0), outs(n),ans(n),re(n),e(e),op(op),f(f),g(g){}
    void add_edge(ll u,ll v,ll i,ll j){
        es[u].push_back({v,i,j});
        es[v].push_back({u,j,i});
    }
    vector<T> calc(ll v = 0){
        dfs(v);
        re[v]=e;
        bfs(v);
        return ans;
    }
    T dfs(ll v){
        vis[v]++;
        T val = e;
        for(auto &p:es[v]){
            if(vis[p.to]>0){
                if(p.to == es[v].back().to) continue;
                swap(p,es[v].back());
            }
            T ch = f(dfs(p.to),p.i);
            outs[v].push_back(ch);
            val=op(val,ch);
        }
        return g(val,v);
    }

    void bfs(ll v){
        ll siz=outs[v].size();
        vector<T> lui(siz+1,e);
        rep(i,0,siz) lui[i+1]=op(lui[i],outs[v][i]);
        T tmp = re[v];
        for(ll i=siz;i--;){
            edge e = es[v][i];
            re[e.to]=f(g(op(lui[i],tmp),v),e.r);
            bfs(e.to);
            tmp=op(outs[v][i],tmp);
        }
        ans[v]=g(op(lui[siz],re[v]),v);
    }
};

void solve(){
    int N,t;
    cin>>N>>t;
    Reroot<bool> R(N,true,[](bool a,bool b){return a&b;},[](bool a,int v){return a;},[](bool a,int v){return !a;});
    rep(i,0,N-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        R.add_edge(a,b,0,0);
    }
    auto ans=R.calc();
    rep(i,0,t){
        int a;
        cin>>a;
        cout<<(ans[a-1]?"Ron\n":"Hermione\n");
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}