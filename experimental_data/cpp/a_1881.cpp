#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ll long long
#define vll vector<long long>
#define all(x) x.begin(),x.end()
#define ld long double
const int N = 100008;

ll poww(ll a,ll b,ll mod){
    ll res=1;if(b<0||b>=mod)b=(b%(mod-1)+mod-1)%(mod-1);
    for(;b;b>>=1,a=1ll*a*a%mod)
      if(b&1)res=1ll*res*a%mod;
    return res;
}

void solve()
{
    int n,m;cin>>n>>m;
    string x,s;
    cin>>x>>s;
    int ans=0;
    while(x.find(s)==-1){
        x+=x;
        ans++;
        if(ans>8){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;
while(t--)solve();


    return 0;
}