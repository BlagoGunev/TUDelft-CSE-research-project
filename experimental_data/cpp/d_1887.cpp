#include <bits/stdc++.h>
using namespace std;
#define int long long 
#ifdef LOCAL
void debug_out() {cerr<<endl;}
template <typename Head, typename... Tail>
void debug_out(Head _H, Tail... _T) {cerr<<" "<<to_string(_H);debug_out(_T...);}
#define debug(...) cerr<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
const int MAXN = 300005;
const int inf=1000000500ll;
const long long oo =1000000000000000500ll;
const int MOD = (int)1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> pi; 
int n;
int A[MAXN];
int Xl[MAXN], Xr[MAXN], Xy[MAXN];
struct SparseTable {
    vector<vector<int> > ST;
    int N, K;
    SparseTable(int _N, int a[]): N(_N) {
        K = MSB(N);
        ST.resize(K);
        ST[0] = vector<int>(a, a+N);
        for (int k = 1; k < K; ++k) 
            for (int i = 0; i+(1<<k) <= N; ++i) 
                ST[k].push_back( min(ST[k-1][i], ST[k-1][i+(1<<(k-1))]) ); //min
    }
    
    /* returns most significant bit of an integer */
    inline int MSB(unsigned int x) { return 32-__builtin_clz(x); }
    
    /* Min of range (x, x + 2^k-1) and (y-2^k+1, y) */
    int query(int x, int y) {
        int k = MSB(y-x+1) - 1;
        return min(ST[k][x], ST[k][y-(1<<k)+1]);
    }
    
};
vector<array<int,3>> V[MAXN];
vector<pi> Qu[MAXN];
int q;
int ans[MAXN];
struct node {
    int s,e,m,val,lazy;
    node *l, *r;
    node(int _s, int _e){
        s=_s;e=_e;m=(s+e)/2;
        val=lazy=0;
        if(s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
        }
    }
    int value(){
        if(lazy==0)return val;
        if(s==e){
            val+=lazy;
            lazy=0;
            return val;
        }
        val+=lazy;
        l->lazy+=lazy;
        r->lazy+=lazy;
        lazy=0;
        return val;
    }
    void update(int x, int y, int nval){
        value();
        if(s==x&&e==y){
            lazy+=nval;
            return;
        }
        if(x>m)r->update(x,y,nval);
        else if(y<=m)l->update(x,y,nval);
        else l->update(x,m,nval),r->update(m+1,y,nval);
        val=l->value()+r->value();
    }
    int query(int x){
        value();
        if(s==e)return val;
        if(x>m)return r->query(x);
        else return l->query(x);
    }
}*seg;
int32_t main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    seg=new node(0,n);

    for(int i=1;i<=n;i++)cin>>A[i];
    stack<int> stk;
    for(int i=1;i<=n;i++){ // find A[j] s.t A[j]>A[i]
        while(stk.size() && A[stk.top()]<A[i])stk.pop();
        if(stk.size())Xl[i]=stk.top();
        stk.push(i);
    }

    while(stk.size())stk.pop();
    for(int i=n;i>=1;i--){

        while(stk.size() && A[stk.top()]<A[i])stk.pop();
        if(stk.size())Xr[i]=stk.top();
        else Xr[i]=n+1;
        stk.push(i);
    }

    SparseTable ST(n+1,A);
    for(int i=1;i<=n;i++){
        if(Xr[i] == n+1)continue;
        int lo=Xr[i],hi=n+1;
        while(lo<hi-1){
            int mid=(lo+hi)/2;
            if(ST.query(Xr[i],mid)>A[i])lo=mid;
            else hi=mid;
        }
        Xy[i]=lo;
    }
    for(int i=1;i<=n;i++){
        if(Xr[i]!=n+1){
            V[Xl[i]+1].push_back({Xr[i],Xy[i],1});
            V[i+1].push_back({Xr[i],Xy[i],-1});
        }
        
    }
    vector<array<int,3>> qu;
    cin>>q;
    for(int t=1;t<=q;t++){
        int l,r; cin >> l >> r;
        Qu[l].push_back({r,t});
        qu.push_back({l,r,t});
    }
    for(int i=1;i<=n;i++){
        for(auto x:V[i]){
            seg->update(x[0],x[1],x[2]);
        }
        for(auto x:Qu[i]){
            ans[x.second]=!!seg->query(x.first);
        }
    }
    for(int t=1;t<=q;t++){
        if(ans[t])cout<<"Yes\n";
        else cout<<"No\n";
    }
}