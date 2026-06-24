//#pragma GCC optimize("Ofast")
////#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define in insert
#define pb push_back
#define mp make_pair
#define int long long
#define ll long long
#define fi first
#define double long double
#define se second
#define endl " \n"
#define pii pair<int,int>
#define pdd pair<double,double>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define mod2 1000000009
#define MAXN  29
#define all(v) v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int spf[MAXN];
int fac[MAXN];
int inv[MAXN];
void sieve()//sieve
{
  spf[1] = 1;
  for (int i=2; i<MAXN; i++)
      spf[i] = i;
  for (int i=4; i<MAXN; i+=2)
      spf[i] = 2;
  for (int i=3; i*i<MAXN; i+=2)
  {
      if (spf[i]==i)
      {
          for (int j=i*i; j<MAXN; j+=i)
              if (spf[j]==j)
                  spf[j]=i;
      }
  }
}//sieve ends
map<int,int> getfactor(int a)//factor prime
{
  map<int,int> m;
  while(a>1)
  {
      m[spf[a]]++;
      a/=spf[a];
  }
  return m;
}//prime factor ends
int power(int x,int y,int p)
{
  int res = 1;
  if (x == 0||y < 0)
      return 0;
   x = x%p;
  while (y > 0)
  {
      if (y & 1)
          res = (res*x)% p;
      y = y>>1;
      x = (x*x)%p;
  }
  return res;
}
int gcd(int a, int b)
{
  if (a == 0)
      return b;
  return gcd(b % a, a);
}
int inverse(int a, int p)
{
  return power(a, p-2, p);
}
void getfac(int p)
{
   fac[0]=1;
   inv[0]=inverse(fac[0],p);
   for(int i=1;i<MAXN;i++)
   {
       fac[i]=(fac[i-1]*i)%p;
       inv[i]=inverse(fac[i],p);
   }
}
int ncr(int n, int r, int p)
{
  if(r>n||r<0)
      return 0;
  return (fac[n]*inv[r] % p *
          inv[n-r] % p) % p;
}
void solve(int tt)
{
    int n;
    cin>>n;
    vector<int> v[n+1];
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        v[x].pb(i);
        v[i].pb(x);
    }
    int dp[n+1]={0};
    int sub[n+1]={0};
    function<void(int,int)> dfs=[&](int cur,int par)
    {
        int maxi=0,tot=0,now=0,id=0;
        for(auto it:v[cur])
        {
            if(it!=par)
            {
                dfs(it,cur);
                if(dp[it]>=maxi)
                    id=it;
                maxi=max(maxi,dp[it]);
                tot+=dp[it];
                now+=sub[it];
            }
        }
        sub[cur]=now+1;
        now-=sub[id];
        if(tot-maxi>=maxi)
            dp[cur]=tot&1;
        else {
            now-=(tot-maxi);
            dp[cur]=maxi-(tot-maxi);
            if(now>=dp[cur])
                dp[cur]=dp[cur]&1;
            else dp[cur]-=now;
        }
        dp[cur]++;
    };
    dfs(1,1);
    cout<<(n-dp[1])/2<<endl;
}
signed main()
{
   fast
   int test=1;
   cin>>test;
   for(int tt=1;tt<=test;tt++)
   {
       solve(tt);
   }
}