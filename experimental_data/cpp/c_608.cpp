#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define D double
#define ll long long
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define pb push_back
#define LE(x) (int)((x).length())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define debug 0
const double EPS = 1e-10 ;
using namespace std;
inline ll rit(){
    ll f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
void init(){
}
const int Z = 100005;
int n;
PII a[Z];
void read(){
    int i;
    n=rit();
    for(i=1;i<=n;i++) a[i].X=rit(),a[i].Y=rit();
    sort(a+1,a+n+1);
}
int fnd(int L,int R,PII now){
    int mid = (L+R)/2;
    if(L==R) return L;
    if(now.X-a[mid].X>now.Y) return fnd(mid+1,R,now);
    else return fnd(L,mid,now);
}
int dp[Z];
void DP(){
    int i,now=1;
    dp[1] = 0;
    dp[0] = 0;
    for(i=2;i<=n;i++){
        now=fnd(1,n+1,a[i]);
        dp[i] = dp[now-1] + (i-now);
    }
}
void solve(){
    int ans=n,i;
    DP();
    // for(i=0;i<=n;i++) cout<<dp[i]<<' ';
    // cout<<endl;
    for(i=0;i<=n;i++){
        ans=min(ans,(n-i)+dp[i]);
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    int nn=1;
    // nn=rit();
    init();
    while(nn--){
        read();
        solve();
    }
    return 0;
}