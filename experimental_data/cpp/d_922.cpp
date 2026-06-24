using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define fn "test"    ///FILE_NAME_HERE
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T,class U,class V>
T addmod(T x,U y,V mod)
{
    return ((x + y)%mod + mod)%mod;
}
template <class T,class U,class V>
T submod(T x,U y,V mod)
{
    return ((x - y)%mod + mod)%mod;
}
template <class T,class U,class V>
T mulmod(T x,U y,V mod)
{
    return (ll)x*y%mod;
}
///---------------------------------------------------------END_TEMPLATE-------------------------------------------------------///

namespace task{

const int N=1e5+5;
string t[N];
int ord[N],cur_s[N],cur_h[N];
int n,tot=0;
ll ans=0;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>t[i];
        for(auto &j : t[i])
            cur_s[i]+=(j=='s'),cur_h[i]+=(j=='h');
        tot+=cur_h[i];
    }
    for(int i=1;i<=n;++i)
        ord[i] = i;
    sort(ord + 1,ord + 1 + n,[](const int &i,const int &j)
         {
                ll lhs = 1LL*cur_s[i]*1LL*cur_h[j];
                ll rhs = 1LL*cur_s[j]*1LL*cur_h[i];
                return lhs > rhs;
         });
    string s="";
    for(int i=1;i<=n;++i)
        s+=t[ord[i]];
    int h_until=0;
    for(auto &i : s)
    {
        h_until += (i == 'h');
        if(i=='s')ans+=1LL*(tot - h_until);
    }
    cout<<ans;
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}