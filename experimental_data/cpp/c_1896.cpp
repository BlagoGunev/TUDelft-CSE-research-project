#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef long long int ll;
typedef long double ld;
 
#define fast ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define pi  3.141592653589793238462643383279502884L
#define size(x) x.size()
#define endl "\n"
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define yes cout << "YES" << endl;
#define no cout<<"NO"<<endl;
#define f first
#define s second
ll lcm(ll a , ll b) {return (a * b) / __gcd(a , b);}
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
const ll N=1e5+4;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MOD = 1000000007;
const ll MAX = 1000001;
const ll P=9973;



void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>>a(n);
    vector<ll>b(n);
    for(int i=0;i<n;i++)
    {
        ll k;
        cin>>k;
        a[i]={k,i};
    }
    set<ll>st;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        st.insert(b[i]);
    }
    sort(allr(a));
    sort(all(b));
    vector<ll>ans(n);
    ll j=1;
    for(int i=0;i<x;i++)
    {
        ans[i]=b[x-j];
        j++;
    }
    j=1;
    for(int i=x;i<n;i++)
    {
        ans[i]=b[n-j];
        j++;
    }
    ll nb=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].f>ans[i]) nb++;
    }
    if(nb!=x)
    {
        no;
        return;
    }
    yes;
    vector<ll>aa(n);
    for(int i=0;i<n;i++) 
    {
        aa[a[i].s]=ans[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<aa[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    fast;
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}