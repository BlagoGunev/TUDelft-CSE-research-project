/**
It falls to me to inform you that this one is in the bag
**/

#include <bits/stdc++.h>
#include <stdexcept>
#include <chrono>
#include <random>
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;

const ll Mod=998244353   ;

template <typename T>
void Max(T& x,T y){
    x=max(x,y);
}
template <typename T>
void Min(T& x,T y){
    x=min(x,y);
}
void OK(bool yes){
    cout<<(yes?"YES\n":"NO\n");
}

const int N=300300,M=4444,NN=1000200;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[N];
string s[N];
bool cmp(string x,string y){
    return x.size()<y.size();
}

ll MinPrime[NN];
vector<ll> Prime;

void sieve(){
    MinPrime[1]=0;
    for(int i=2;i<NN;i++){
        if(MinPrime[i])continue;
        Prime.pb(i);
        for(int j=i;j<NN;j+=i){
            if(MinPrime[j])continue;
            MinPrime[j]=i;
        }
    }
}

ll poww(ll a,ll b,ll mod=Mod){
    ll res=1;if(b<0||b>=Mod)b=(b%(mod-1)+mod-1)%(mod-1);
    for(;b;b>>=1,a=1ll*a*a%mod)
      if(b&1)res=1ll*res*a%mod;
    return res;
}

ll Fact[NN],iFact[NN];
void init(){
    Fact[0]=iFact[0]=1ll;
    for(ll i=1;i<NN;i++)Fact[i]=(1ll*Fact[i-1]*i)%Mod;
    iFact[NN-1]=poww(Fact[NN-1],-1,Mod);
    for(ll i=NN-2;i>=0;i--)iFact[i]=(1ll*iFact[i+1]*(i+1))%Mod;
}
ll inv(ll x,ll y=-1){
    return poww(x,y,Mod);
}
ll Cnk(ll x,ll y){
if(y > x|x < 0||y < 0)return 0;
    return (  ((Fact[x]*iFact[y])%Mod)  *iFact[x-y])%Mod;
}
ll Pnk(ll x,ll y){
if(y > x||x < 0||y < 0)return 0;
    return ((Fact[x]*iFact[y])%Mod);
}

ll dp[M][M],Counter[NN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    int Case=1;
//    cin>>T;
    sieve();
    init();
    while(T--){
        int n;
        cin>>n;
        ll m=n+n;
        ll Ans=Fact[n];
        map<ll,ll> Cnt,C;
        for(int i=1;i<=m;i++){
            cin>>a[i];
            if(MinPrime[a[i]]==a[i]){
                Cnt[a[i]]++;
            }
            else{
                C[a[i]]++;
            }
        }
//        cout<<Ans<<'\n';
        for(auto p:C){
            Ans*=iFact[p.S];
            Ans%=Mod;
        }
        if(Cnt.size()<n){
            cout<<0<<'\n';
            continue;
        }
        vector<int> v(1);
        for(auto p:Cnt){
            v.pb(p.F);
            Counter[p.F]=p.S;
        }
        int sz=v.size()-1;
        dp[0][0]=1;
        for(int i=1;i<=sz;i++){
            dp[i][0]=(dp[i-1][0]*iFact[Counter[v[i]]])%Mod;
            for(int k=1;k<=n;k++){
                dp[i][k]=(dp[i-1][k-1]*iFact[Counter[v[i]]-1]%Mod
                          +dp[i-1][k]* iFact[Counter[v[i]]]  %Mod )%Mod;
            }
        }
//        for(int i=1;i<=sz;i++){
//            for(int k=1;k<=n;k++){
//                cout<<i<<' '<<k<<" : "<<dp[i][k]<<'\n';
//            }
//        }
//
//        cout<<sz<<' '<<' '<<Ans<<' ';
        Ans*=dp[sz][n];
        Ans%=Mod;
        cout<<Ans<<'\n';
    }


    return 0;
}

/**
*/

/**
*/