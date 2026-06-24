#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dd;
typedef long double ldd;
#define tst int T;cin>>T;for(int t=1;t<=T;t++)
#define nl cout<<"\n";
#define rep(i,l,r) for (int i=l;i<r;i++)
#define per(i,r,l) for (int i=r;i>l;i--)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define vi vector<int>
#define vll vector<ll>
#define PI 3.14159265
#define fi first
#define se second
const ll MOD1=1e9+7;
const ll MOD2=998244353;
ll mod=MOD1;
ll po(ll x,ll y,ll _prime=mod) {if(y<0)return 0;y%=(_prime-1);ll res=1;while(y>0){if(y&1)res=(res*x)%_prime;x=(x*x)%_prime;y>>=1;}return (res%_prime);}
ll gcd(ll a, ll b){if(a<b) swap(a,b);if(b==0) return a;return gcd(a%b,b);}

struct qry{
    int a,b,e,id,xx;
};
struct DSU{
    vector<int> P,S;
    DSU(int n){
        P.resize(n+1);S.resize(n+1,1);
        for(int i=0;i<=n;i++)P[i]=i;
    }int find(int u){
        if(u==P[u])return u;
        return P[u]=find(P[u]);
    }void merge(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(S[u]<S[v]){
                P[u]=v;
                S[v]+=S[u];
            }else{
                P[v]=u;
                S[u]+=S[v];
            }
        }
    }
};
void solve(){
    int n,m;cin>>n>>m;
    vector<pii>h(n+1);rep(i,1,n+1){cin>>h[i].first;h[i].second=i;}
    vector<vi>adj(n+1);
    rep(i,0,m){
        int u,v;cin>>u>>v;adj[u].pb(v);adj[v].pb(u);
    }int q;cin>>q;
    vector<qry>c(q);
    rep(i,0,q){
        cin>>c[i].a>>c[i].b>>c[i].e;
        c[i].id=i;c[i].xx=h[c[i].a].first+c[i].e;
    }
    sort(all(c),[&](qry&l,qry&r){return l.xx<r.xx;});
    vi ans(q);
    vi mark(n+1);
    DSU t(n);
    int j=1;
    sort(1+all(h));
    rep(i,0,q){
        while(j<n+1 && h[j].first<=c[i].xx){
            int u=h[j].second;
            mark[u]=1;
            for(auto v:adj[u]){
                if(mark[v]){
                    t.merge(u,v);
                }
            }j++;
        }if(t.find(c[i].a)==t.find(c[i].b)){
            ans[c[i].id]=1;
        }
    }rep(i,0,q){
        if(ans[i])cout<<"YES";
        else cout<<"NO";
        nl;
    }
}
int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    tst
    {
        solve();nl;
    }
}
/*
*/