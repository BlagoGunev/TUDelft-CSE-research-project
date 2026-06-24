/// Job role : Abdelraziq at Abdelraziq fan club.
/// Job description : I am responsible for making some Abdelraziq things.
/// Do you want to join Abdelraziq fan club?..... sorry you are not qualified enough.
#include<bits/stdc++.h>
using namespace std ;

const int N = 1e2+5 ,mod = 1e9+7 ;

int t ,n ,k ,u ,v;
vector<int> adj[N] ;
int dis[N] ;
int dfs(int p,int gp){
    dis[p] = 1 ;
    for(int ch:adj[p]){
        if(ch==gp) continue ;
        dis[p] = max(dis[p], 1 + dfs(ch,p));
    }
    return dis[p];
}
int get(int p,int gp,int rem){
    if(!rem) return 1;
    int ret = 0 ;
    for(int ch:adj[p]) if(ch!=gp) ret += get(ch,p,rem-1) ;
    return ret ;
}
long long fac[N]={1} ,inv[N]={1} ;
long long fast_power(long long b,long long p){
    long long res=1;
    while(p){
        if(p%2) res=(res*b)%mod;
        b=(b*b)%mod;
        p/=2;
    }
    return res;
}
void prep(){
    for(int i=1;i<N;++i){
        fac[i]=(fac[i-1]*i)%mod;
        inv[i]=fast_power(fac[i],mod-2);
    }
}
long long choose(int n,int r){
    if(r>n) return 0;
    return ((fac[n]*inv[r])%mod*inv[n-r])%mod;
}
vector<int> vec;
long long mem[N][N] ;
int vis[N][N] ,vid ;
long long solve(int i,int rem){
    if(rem==0) return 1;
    if(i==vec.size()) return 0;
    auto&ret = mem[i][rem] ;
    if(vis[i][rem]==vid) return ret ;
    vis[i][rem] = vid ;
    ret = solve(i+1,rem) ;
    ret = (ret + solve(i+1,rem-1)*vec[i]%mod)%mod ;
    return ret ;
}
int main(){
    prep();
    cin >> t ;
    while(t--){
        cin >> n >> k ;
        for(int i=1;i<=n;++i) adj[i].clear() ;
        for(int i=1;i<n;++i){
            cin >> u >> v ;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(k==1){
            cout << n << endl ;
            continue ;
        }
        if(k==2){
            cout << 1ll*n*(n-1)/2%mod << endl ;
            continue ;
        }
        int ans = 0 ;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) dis[j] = 0 ;
            dfs(i,i);
            //cout << i << endl ;
            for(int d=1;d<=n;++d){
                vec.clear() ;
                for(char ch:adj[i]) if(dis[ch]>=d) vec.push_back(get(ch,i,d-1));
                //ans = (ans+choose(cur,k))%mod ;
                if(vec.size()>=k){
                    ++vid ;
                    ans = (ans+solve(0,k))%mod  ;
                    /*cout << "--\n";
                    cout << i << " " << d << " " << solve(0,k) << endl ;
                    for(auto go:vec) cout << go << " " ;
                    cout << endl << endl ;*/
                }
            }
        }
        cout << ans << endl ;
    }
    return 0;
}