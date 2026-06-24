#include <bits/stdc++.h>

using namespace std;



#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define forw(i,a,b) for(ll i=a;i<=b;i++)

#define forb(i,a,b) for(ll i=a;i>=b;i--)

#define pu push

#define pb push_back

#define fi first

#define se second

#define all(a) a.begin(),a.end()

#define minimize(a,b) a=min(a,b)

#define maximize(a,b) a=max(a,b)

#define getbit(a,i) (a&(1<<i))

typedef long long int ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

typedef pair<pair<int,int>,int > piii;

const int maxN=3000+5;

const ll oo=1e18;

const ll block=300;

const ll mod=998244353;

const int tx[4]={1,0,-1,0};

const int ty[4]={0,1,0,-1};

string s,t;

ll n,m,dp[maxN][maxN];

void add(ll &a, ll b)

{

    a+=b;

    a%=mod;

    return;

}

void solve()

{

    cin>>s>>t;

    n=s.length(); m=t.length();

    s=' '+s; t=' '+t;

    forw(i,1,n)

    if (i>m || s[1]==t[i])

        dp[i][i]=1;

    forw(len,2,n)

    forw(l,1,n-len+1)

    {

        int r=l+len-1;

        if (l>m || s[len]==t[l])

            add(dp[l][r],dp[l+1][r]);

        if (r>m || s[len]==t[r])

            add(dp[l][r],dp[l][r-1]);

    }

    ll ans=0;

    forw(i,m,n)

        add(ans,dp[1][i]);

    cout<<(ans*2)%mod;

    return;

}

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    //freopen("bruh.INP","r",stdin);

    //freopen("bruh.out","w",stdout);

    int t=1; //cin>>t;

    while(t--) solve();

    return 0;

}