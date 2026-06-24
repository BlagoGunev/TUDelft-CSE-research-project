// fuck everything :)
// A flowers
#include <bits/stdc++.h>
#define ll long long
#define D double
#define F first
#define S second
#define sc scanf
#define pr printf
#define B break
#define R return
#define C continue
#define pb push_back
#define double long double
//#define sz size()
#define P pair <D,D>
#define pi acos(-1)
using namespace std;
ll mod=1e9+7;
ll inf=1e15;
ll n,m,k,q;
vector <ll> v[103],vv[103];
ll ff(ll x,ll y){
    ll d=y-x;
    if (d<0) d+=n;
    R d;
}
ll f(ll x){
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll d1=inf;
        if (v[i].empty()) C;
        for (auto pp:v[i]){
            d1=min(ff(i,pp),d1);
        }
    //    cout <<i<<' '<<d1<<endl;
        ll dd=d1+ff(x,i)+(v[i].size()-1)*(n);
        ans=max(dd,ans);
    }
    R ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n>>m;
    for (int i=1;i<=m;i++){
        ll a,b;
        cin >>a>>b;
        v[a].pb(b);
    }
    for (int i=1;i<=n;i++){
        cout <<f(i)<<' ';
    }
    return 0;
}