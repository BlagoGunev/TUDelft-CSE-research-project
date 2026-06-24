#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define IOS ios::sync_with_stdio(false),cin.tie(0) 

#define _for(i,a,b) for(int i=(a) ;i<=(b) ;i++)

#define _rep(i,a,b) for(int i=(a) ;i>=(b) ;i--)

#define mst(v,s) memset(v,s,sizeof(v))

#define pii pair<int ,int >

#define pb(v) push_back(v)

#define all(v) v.begin(),v.end()

#define int long long

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3f

#define endl "\n"

#define fi first

#define se second

#define ls p<<1

#define rs p<<1|1

#define lson p<<1,l,mid

#define rson p<<1|1,mid+1,r

#define AC return 0

#define ldb long double

const int N=3e6+5;

const int mod=1e9+7;

const double eps=1e-8;

int n;

int f[N],ni_f[N];

ll qsm(int a,int b){

    int ans = 1,temp=a;

    while( b ){

        if( b&1 ) ans=  (ans * temp)%mod;

        temp = (temp *temp )%mod;

        b>>=1;

    }

    return ans;

}

void ini(){

    int maxn = 3e6;

    f[0]=1;

    _for(i,1,maxn) f[i] =  (f[i-1] * i)%mod;

    ni_f[maxn] = qsm(f[maxn],mod-2);

    _rep(i,maxn-1,0) ni_f[i] = ni_f[i+1] * (i+1)%mod;

}

ll C(int n,int m){

    if( m==n || m==0 ) return 1;

    if( n < m ) return 0;

    return f[n] * ni_f[n-m]%mod * ni_f[m]%mod;

}

int dp[N][3];

signed main(){

#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);

#endif  

    IOS;

    ini();

    int k;

    cin>>n>>k;

    dp[0][0] = n;

    dp[0][1] = n;

    int ni_3 = qsm(3,mod-2);

    _for(x,1,3*n){

        dp[x][0] = (C(3*n,x+1) +mod - 2*dp[x-1][0]%mod +mod- dp[x-1][1])%mod * ni_3%mod;

        dp[x][1] = (dp[x][0] + dp[x-1][0])%mod;

        dp[x][2] = (dp[x][1] + dp[x-1][1])%mod;

    }

    while( k-- ){

        int x;cin>>x;

        cout<< ( C(3*n,x) + dp[x][0])%mod<<endl;

    }

    AC; 

}