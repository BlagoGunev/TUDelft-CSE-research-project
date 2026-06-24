#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);

#define ch(a) (int(a-'a')+1)

#define chh(a) (int(a-'A')+1)

#define mm(a) memset(a,0,sizeof(a))

#define rep(i,a,b) for(int i=(a);i<=(b);++i)

#define inf  0x7FFFFFFF

#define Inf  0x3F3F3F3F

#define odd(n) ((n)&1)

#define even(n) (!((n)&1))

#define lb(x) ((x)&(-(x)))

#define endl '\n'

#define sset set<int>::iterator it=s.begin();it!=s.end();++it

typedef long long ll;

typedef unsigned long long ull;

typedef unsigned int uint;

const int Maxx=1e5+55;

const int maxn=1e6+33;

const int mod=998244353;

int t;

int n;

int  x[1111],y[1111];

void solve()

{

    cin>>n;

    rep(i,1,n) cin>>x[i]>>y[i];

    ll ans=0;

    sort(x+1,x+n+1);

    if(n&1) ans=1;

    else ans=x[n/2+1]-x[n/2]+1;

    sort(y+1,y+n+1);

    if(n&1) ans*=1ll;

    else ans*=(1ll*y[n/2+1]-1ll*y[n/2]+1);

    cout<<ans<<endl;

}

int main()

{

    //scanf("%d",&t);

    //IOS;

    IOS;cin>>t;while(t--)

        solve();

    return 0;

}