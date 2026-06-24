#include<bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(x) vector<int>().swap(x);
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define random mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); mt19937 rnd(time(0));
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
//#define no {cout << "NO" << endl; return;}
//#define yes {cout << "YES" << endl;}
const ll N=3e5+9;
const ll INF=1e18;
const ll MN=-2e9;
const ll MXX=2e9;
const ll SQ=644;
const ll mod=1e9+7;
//const ll MOD=998244353;
const ll PP=1e6+3;
const ll P2=1299827;
const ld PI=3.141592653589793;
const ld eps=1e-11;
//const ld eps = 1e-6;
int mul(int x,int y,int mod=mod){return (long long) x*y%mod;}
int add(int x,int y,int mod=mod){x+=y; return x<mod?x:x-mod;}
int sub(int x,int y,int mod=mod){x-=y;return x<0?x+mod:x;}
int power(int x,ll y,int mod=mod){if(!y)return 1;int ret=power(x,y/2,mod);
ret = mul(ret,ret,mod);if(y&1) ret = mul(ret,x,mod);return ret;}
pair<ll,ll> a[N];
int n,k;
void solve(){
    cin>>n>>k;
    multiset<ll>smn,so;
    for(int i=0;i<n;i++)cin>>a[i].S;
    for(int i=0;i<n;i++)cin>>a[i].F;
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        so.insert(a[i].S);
    }
    ll sum=0;
    while(smn.size()<k){
        ll x=*so.begin();
        smn.insert(x);
        so.erase(so.find(x));
        sum+=x;
    }
    ll ans=0,cdif=0;
    for(int i=0;i<n-k;i++){
        if(so.find(a[i].S)!=so.end())so.erase(so.find(a[i].S));
        else {
            sum-=a[i].S;
            smn.erase(smn.find(a[i].S));
            ll x=*so.begin();
            smn.insert(x);
            so.erase(so.find(x));
            sum+=x;
        }
        cdif+=max(0ll,a[i].F-a[i].S);
        ans=max(ans,cdif-sum);
    }
    cout<<ans<<"\n";

}
int main()
{
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) {
            solve();
    }
}
/*

*/