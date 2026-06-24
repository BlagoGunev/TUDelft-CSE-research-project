#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define ll long long
#define N 110000
#define MOD 1000000007
using namespace std;

int n,m;
int a[N],b[N];
ll inv,curInv,ans;

inline void nextInt(int &x) 
{ 
      x=0;
       char c=getchar(); 
    for(;(c<'0')||(c>'9');c=getchar()); 
    for(;(c>='0')&&(c<='9');c=getchar()) 
    x=x*10+(c-'0'); 
}

int e_gcd(ll a,ll b,ll& x,ll& y)
{
 if(!b) {x=1;y=0;return a;}
 ll x1,y1;
 int RV=e_gcd(b,a%b,x1,y1);
 x=y1;
 y=x1-a/b*y1;
 return RV;
}

void dfs(int cur)
{
 if(cur>n)return;
 if(a[cur]==0&&b[cur]==0)
 {
  curInv=(curInv*inv)%MOD;
  ll INV=(500000004*curInv)%MOD;
  ans=(ans+INV*(m-1))%MOD;
  dfs(cur+1);
  return;
 }
 if(b[cur]==0)
 {
  curInv=(curInv*inv)%MOD;
  ans=(ans+(a[cur]-1)*curInv)%MOD;
  dfs(cur+1);
  return;
 }
 if(a[cur]==0)
 {
  curInv=(curInv*inv)%MOD;
  ans=(ans+(m-b[cur])*curInv)%MOD;
  dfs(cur+1);
  return;
 }
 if(a[cur]<b[cur])return;
 if(a[cur]==b[cur])
 {
  dfs(cur+1);
  return;
 }
 if(a[cur]>b[cur])
 {
  ans=(ans+curInv)%MOD;
  return;
 }
}

int main()
{
 //freopen(".in","r",stdin);
 //freopen(".out","w",stdout);
 nextInt(n);nextInt(m);
 for(int i=1;i<=n;i++)nextInt(a[i]);
 for(int i=1;i<=n;i++)nextInt(b[i]);
 ll x;
 e_gcd(MOD,(ll)m,x,inv);
 inv=(inv+MOD)%MOD;
 //cout<<inv<<endl;
 curInv=1;
 dfs(1);
 cout<<ans<<endl;
 return 0;
}