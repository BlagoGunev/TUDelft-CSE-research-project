#include <bits/stdc++.h>     
#define ll  long long
#define ld long double
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvvll vector<vector<vector<ll>>>
#define pll pair<long long,long long>
#define vpll vector<pair<long long, long long>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define vs vector<string>
#define ump unordered_map<ll,ll>
#define umpc unordered_map<char,ll>
#define ompc map<char,ll>
#define omp map<ll,ll>
#define ustc unordered_set<char>
#define ostc set<char>
#define ust unordered_set<ll>
#define ost set<ll>
#define pb push_back
#define f first
#define s second
#define ff fflush(stdout)
#define test() ll tc; cin>>tc; while(tc--)
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::currue, typename T_container::currue_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void ldg_out() { cerr << endl; }
template<typename Head, typename... Tail> void ldg_out(Head H, Tail... T) { cerr << ' ' << H; ldg_out(T...); }
#ifdef LOCAL
#define ldg(...) cerr << "(" << #VA_ARGS << "):", ldg_out(VA_ARGS)
#else
#define ldg(...)
#endif
mt19937 rng((ll) chrono::steady_clock::now().time_since_epoch().count());
ll get_rng() 
{
    uniform_int_distribution<ll> uid(0,1e18);
    return uid(rng);
}
//........................constants..............................//
const ll N=2e5+10;
const ll mod=1e9+7;
const ll INF=1e9;
const long double EPS=1e-9;
#define PI 3.1415926535897932384626433832795
//......................print functions..........................//
void print(vll&a) {
    ll n = a.size();
    for (ll i = 0; i < n; i++) cout << a[i] <<" ";
    cout << endl;
}
void print(vll&a, ll n) {
    for (ll i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
void print(vll&a,ll l,ll r) {
    for (ll i=l;i<=r; i++) cout << a[i] << " ";
    cout << endl;
}
void print(vpll&a)
{
    ll n=a.size();
    for(ll i=0;i<n;i++)
     cout<<a[i].f<<" "<<a[i].second<<endl; 
}
void print(vpll&a,ll n)
{
    for(ll i=0;i<n;i++)
     cout<<a[i].f<<" "<<a[i].second<<endl;
}
void print(vpll&a,ll l,ll r)
{
    for(ll i=l;i<=r;i++)
     cout<<a[i].f<<" "<<a[i].second<<endl; 
}
//.........................helper functions......................//
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
ll modd(ll a){return(a%mod+mod)%mod;}
vector<bool> is_prime;
   void sieve(ll n)
   {
     is_prime.resize(n+1, true);
     is_prime[0] = is_prime[1]=false;
     for(ll i = 2; i <= n; i++) {
      if (is_prime[i] && (long long)i*i <= n) {for (ll j = i * i; j <= n; j += i) is_prime[j] = false;}
     }
   }
ll binpow(ll x, ll y)
{
    ll ans=1;
    for(;y;y>>=1,x=x*x)
    {
        if(y & 1)
        {
            ans=ans*x;
        }
    }
    return ans;
}

ll multmod(ll a,ll b) {
    ll result=0;
    while (b) {
        if (b & 1)
            result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}
ll addmod(ll a,ll b)
{
    a=a%mod;
    b=b%mod;
    return (((a+b)%mod)+mod)%mod;
}
ll submod(ll a,ll b)
{
    a=a%mod;
    b=b%mod;
    return (((a-b)%mod)+mod)%mod;
}
ll mult(ll a,ll b) {
    ll result=0;
    while (b) {
        if (b & 1)
            result = (result + a);
        a = (a + a);
        b >>= 1;
    }
    return result;
}
ll add(ll a,ll b)
{
    return a+b;
}
ll sub(ll a,ll b)
{
    return a-b;
}
ll binpowmod(ll x, ll y)
{
    ll ans=1;
    for(;y;y>>=1,x=multmod(x,x))
    {
        if(y&1)
        {
            ans=multmod(ans,x);
        }
    }
    return ans;
}
//.......................code starts from here...................//
ll ans,m,zero;
omp mp;
ll inv(ll i)
{
	return i<=1?i:m-(m/i)*inv(m%i)%m;
}
void f(ll x)
{
	for(ll i=2;i*i<=x;i++)
    { 
		if(i*i>x) break;
		if(x%i) continue;
		if(i!=2)
        {
			if((mp[i]+1)%m==0) zero--;
			else ans=ans*inv(mp[i]+1)%m;
		}
		while(x%i==0) 
        {
			x/=i;
			mp[i]++;
			mp[i]%=m;
		}
		if(i!=2) 
        {
			if((mp[i]+1)%m==0) zero++;
			else ans=ans*(mp[i]+1)%m;
		}
	}
	if(x!=1 and x!=2)
    {
		if((mp[x]+1)%m==0) zero--;
		else ans=ans*inv(mp[x]+1)%m;
		mp[x]++;
		mp[x]%=m;
		if((mp[x]+1)%m==0) zero++;
		else ans=ans*(mp[x]+1)%m;
	}
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//14028432
    // test()
    // {
    // }
	ll x,q; cin>>x>>q>>m;
	ans=1;
	f(x);
	while(q--)
    {
		ll n; cin>>n;
		f(n);
		if(zero) cout<<0<<endl;
        else cout<<ans<<endl;
	}
    return 0;            
}