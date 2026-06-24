/*/ Author: Aniruddh Lawande /*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;


/*/---------------------------Defines----------------------/*/
 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))

typedef pair<ll,ll> pii;

ll lcm(ll a,ll b){
    return (a*b)/(__gcd(a,b));
}

ll gcd(ll a,ll b) {
    return __gcd(a,b);
}

/*/-----------------------extras---------------/*/
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

bool sort2(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
}
/*/-----------------------Modular Arithmetic---------------/*/
 
const long long INF = 1e18; 
const int mod=998244353;
const int mod2=998244353;
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(int x,int y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
inline int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
inline int inv(int x){
    return power(x,mod-2);
}

const ll FACTORIAL_SIZE = 1.1e6+1;
ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
void gen_factorial(ll n) {
	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
	for (ll i = 2; i <= n; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	ifact[n] = inv(fact[n]);
	for (ll i = n - 1; i >= 2; i--) {
		ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
	}
}


ll nck(ll n, ll k) {
	ll den = (ifact[k] * ifact[n - k]) % mod;
	return (den * fact[n]) % mod;
}

/*/-----------------------------Code begins----------------------------------/*/
const int N=2e5+5;


void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];
    bool vis[n+1],ok[n+1];
    memf(vis);
    memf(ok);
    for(ll i=1;i<=n;i++)
    {
        if(a[i]<=n && !vis[a[i]]) vis[a[i]]=true,ok[i]=true;
    }
    for(ll i=1;i<=n;i++)
    {
        if(ok[i]) continue;
        while(a[i]>n)
        {
            a[i]/=2;
            if(a[i]<1) break;
        }
        while(vis[a[i]] && a[i]>=1) a[i]/=2; 
        if(a[i]>=1 && !vis[a[i]])
        {
            vis[a[i]]=true;
        }
        else 
        {   
            cout<<"NO"<<endl;
            return;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll tc=1;
    cin>>tc;
    ll i=1;
	while(tc--)
	{
        //cout<<"CASE #"<<i<<": ";
		solve();
        i++;
	}
	return 0;
}