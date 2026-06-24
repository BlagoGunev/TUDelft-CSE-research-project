#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
//#pragma GCC optimize("O3")
//#pragma GCC optimize("fast-math")
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
ll t,a[200005],b[200005],n,pa[200005],pb[200005],sa[200005],sb[200005];
ll cmmdc(ll x,ll y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    return __gcd(x,y);
}
map<pll,ll> dp;
void solve()
{
    dp.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    pa[0]=0;
    pb[0]=0;
    for(int i=1;i<=n;i++)
    {
        pa[i]=cmmdc(pa[i-1],a[i]);
        pb[i]=cmmdc(pb[i-1],b[i]);
    }
    sa[n+1]=0;
    sb[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        sa[i]=cmmdc(sa[i+1],a[i]);
        sb[i]=cmmdc(sb[i+1],b[i]);
    }
    ll maxim=0,ways=0;
    for(int i=1;i<=n;i++)
    {
        vector<pair<pll,ll>> vals;
        for(auto p:dp)
        {
            ll x=p.first.first;
            ll y=p.first.second;
            ll cnt=p.second;
            x=cmmdc(x,b[i]);
            y=cmmdc(y,a[i]);
            vals.push_back({{x,y},cnt});
        }
        ll x=cmmdc(b[i],pa[i-1]);
        ll y=cmmdc(a[i],pb[i-1]);
        vals.push_back({{x,y},1});
        dp.clear();
        for(auto p:vals)
        {
            ll x=p.first.first;
            ll y=p.first.second;
            ll cnt=p.second;
            dp[{x,y}]+=cnt;
            x=cmmdc(x,sa[i+1]);
            y=cmmdc(y,sb[i+1]);
            if(x+y>maxim)
            {
                maxim=x+y;
                ways=cnt;
            }
            else if(x+y==maxim)
                ways+=cnt;
        }
    }
    cout<<maxim<<' '<<ways<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}