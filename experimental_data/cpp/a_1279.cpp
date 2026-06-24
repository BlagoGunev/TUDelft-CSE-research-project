//https://codeforces.com/group/JC4gmpF4LH/contest/259206/problem/K
#include<iostream>
#include<cmath>
#include<list>
#include<climits>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<numeric>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define doub long double
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define pdd pair<double , double>
#define pll pair<long long int,long long int>
#define vpl vector<pll >
#define vll vector<ll >
#define vi vector<int >
#define mi map<int, int>
#define mull map<ull, ull>
#define stp setprecision(20)
#define N 100005
#define rep(i,a,b,c)            for(ll i=(a);i<=(b);i+=(c))
#define repb(i,a,b,c)           for(ll i=(a);i>=(b);i-=(c))
#define MOD                     1000000007
#define ld                      long double
#define inf                     1e18
#define mp                      make_pair
#define vpll                    vector<pair<ll,ll>>
#define vvpll                   vector<vector<pair<ll,ll>>>
#define vvll                    vector<vector<ll>>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define test                    ll T;cin>>T;while(T--)
#define isvowel(a)              (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define show(w,size)            for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define print(a)                cout<<a<<"\n";
#define pqll                    priority_queue<ll>
#define mset(dp,no)             memset(dp,no,sizeof(dp))
#define umll                    unordered_map<ll,ll>
#define mll                     map<ll,ll>
#define input(a,n)              ll I;rep(I,0,n-1,1) cin>>a[I];
#define countbit                __builtin_popcount // Number of set bits .
#define fbo(k)                  find_by_order // K-th element in a set (counting from zero) .
#define ook(k)                  order_of_key //  Number of items strictly smaller than k .
#define lb                      lower_bound
#define up                      upper_bound
#define in                      insert
//#define db(x) cout <<#x<<": "<<x<<'\n';
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
ll gcd(ll a,ll b){if(a<b)return gcd(b,a);else if(b==0)return a;else return gcd(b,a%b);}
ll isPrime(ll n){ll p=(ll)sqrt(n);rep(i,2,p,1) if(n%i==0) return 0;return 1;}// reuturn 1 if prime
ll pow(ll b,ll e){if(e==0)return 1;else if(e%2==0){ll a=pow(b,e/2);return a*a;}else {ll a=pow(b,e/2);return b*a*a;}}
ll powm(ll x,ll y,ll m=MOD){x=x%m;ll res=1;while(y){if(y&1)res=res*x;res%=m;y=y>>1;x=x*x;x%=m;}return res;}
ll ceil(long double a){ll b=a;if(a==b){return b;}else{return b+1;}}
ll floor(long double a){ll b=a;return b;}
ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
ll modInverse(ll a, ll m) { return powm(a, m-2, m);}
bool issq(ll n){ ll p=sqrt(n);return p*p==n;}
vll prime;// if i==prime[i] then prime otherwise smallest prime factor of that number
void sieve(ll n)
{
    prime.resize(n+1,1);
    prime[0] = 0, prime[1] = 0;
    for (ll i = 2; i*i <= n; i++)
        if (prime[i])
            for (ll j = i * i; j <= n; j += i)
                prime[j] = 0;
}
ll extended_GCD(ll a ,ll b ,ll &x ,ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
    ll mulInv(ll a , ll mod=26){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll find(ll num[], ll rem[], ll k,ll prod)
{
    // Compute product of all numbers
    ll result = 0;
    // Apply above formula
    for (ll i = 0; i < k; i++)
    {
        ll pp = prod / num[i];
        result += rem[i] * mulInv(pp, num[i]) * pp;
    }
    return result % prod;
}
ll nCr(ll n,ll k)
{
  ll res = 1;
 
      // Since C(n, k) = C(n, n-k)
      if ( k > n - k )
          k = n - k;
 
      // Calculate value of
      // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
      for (ll i = 0; i < k; ++i)
      {
          res *= (n - i);
          res /= (i + 1);
      }
 
      return res;
}
class DSU
{
 public:vll parent,size;
public: DSU(ll n)
{
 
        parent.resize(n+1);size.resize(n+1);
        for(ll i=1;i<=n;i++)
            {
            parent[i]=i;
            size[i]=1;
          }
    }
public:ll find_set(ll x)
    {
      if(parent[x]==x)
      {
        return x;
      }
      return parent[x]=find_set(parent[x]);
    }
public:void union_set(ll x,ll y)
    {
        x=find_set(x);y=find_set(y);
        if(x!=y)
        {
          parent[y]=x;
        }
}
};
bool cmp(pair<ll,ll>&p1,pair<ll,ll>&p2)
{
  if(p1.fi==p2.fi)
  {
    return p1.se>p2.se;
  }
  return p1.fi>p2.fi;
}
bool isPalindrome(string s)
{
  ll i,j;
  for(i=0,j=s.length()-1;i<=j;i++,j--)
  {
    if(s[i]!=s[j])
    {
      return 0;
    }
  }
return 1;
}
ll ToInt(char ch)
{
  return ch-'0';
}
char ToChar(ll a)
{
  return a+'0';
}
bool isSubSeq(string str1, string str2, ll m, ll n)
{
    // Base Cases
    if (m == 0) return true;
    if (n == 0) return false;
    // If last characters of two strings are matching
    if (str1[m-1] == str2[n-1])
        return isSubSeq(str1, str2, m-1, n-1);
    // If last characters are not matching
    return isSubSeq(str1, str2, m, n-1);
}
void printVectorPair(vpll v)
{
  for(ll i=0;i<v.size();i++)
  {
    cout<<v[i].fi<<" "<<v[i].se<<"\n";
  }
}
void modBigNumber(string num, ll m)
{
    // Store the modulus of big number
    vector<int> vec;
    ll mod = 0;
    // Do step by step division
    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        mod = mod * 10 + digit;
        int quo = mod / m;
        if((vec.size()!=0)||(quo!=0))        //to remove initiale zeros
        vec.push_back(quo);
        mod = mod % m;
    }
   // cout << "\nRemainder : " << mod << "\n";
   // cout << "Quotient : ";rep(i,0,vec.size()-1,1)cout<<vec[i];cout<<"\n";
    return;
}
struct SegmentTree
{
  ll n;
  vll v;
  SegmentTree(ll size)
  {
    n=4*size+1;
    v.resize(n,0);
  }
  void build(ll ar[],ll ipos,ll fpos,ll pos=1)
  {
    if(ipos>fpos)
    return ;
    if(ipos==fpos)
    v[pos]=ar[ipos];
    else
    {
    ll mid=(ipos+fpos)/2;
    build(ar,ipos,mid,pos*2);
    build(ar,mid+1,fpos,pos*2+1);
    v[pos]=v[pos*2]+v[pos*2+1];
    }
  }
  void update(ll index,ll val,ll ipos,ll fpos,ll pos=1)
  {
    if(ipos>fpos)
    return ;
    if(ipos==fpos)
    v[pos]+=val;
    else
    {
      v[pos]+=val;
      ll mid=(ipos+fpos)/2;
      if(mid>=index)
      update(index,val,ipos,mid,pos*2);
      else
      update(index,val,mid+1,fpos,pos*2+1);
    }
  }
  ll get_sum(ll l,ll r,ll ipos,ll fpos,ll pos=1)
  {
    if(ipos>fpos)
    return 0;
    if(l>r)
    return 0;
    ll mid=(ipos+fpos)/2;
    if((l==ipos)&&(r==fpos))
    return v[pos];
    else return get_sum(l,min(mid,r),ipos,mid,pos*2)+get_sum(max(mid+1,l),r,mid+1,fpos,pos*2+1);
  }
};
struct BIT
{
vector<ll>bitree;ll n;
BIT(ll n)
{
this->n=n;
bitree.resize(n+1,0);
}
void update(ll idx,ll val)
{
  idx++;
  while(idx<=n)
  {
    bitree[idx]+=val;
    idx+=idx&(-idx);
  }
}
ll Sum(ll idx)
{
  ll sum=0;
  idx++;
  while(idx>0)
  {
    sum+=bitree[idx];
    idx-=idx&(-idx);
  }
  return sum;
}
};
ll sumofdigits(ll a)
{
  ll val=0;
  while(a>0)
  {
    val+=a%10;
    a/=10;
  }
  return val;
}
ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

string rotate(string s, ll k){
  string temp;
  for(ll i=k; ; i++){
    if((i>0 and i%s.length()!=k) or i==k) temp.pb(s[i%s.length()]);
    else if(i%s.length()==k) break;
  }
  return temp;
}

int main(){
  fastio;
  test{
    int arr[3];cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr, arr+3); 
    if(arr[2]<=arr[0]+arr[1]+1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}