#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define mem(x,num) memset(x,num,sizeof x)
#define reg(x) for(int i=last[x];i;i=e[i].next)
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
#define pi acos(-1)
#define mp make_pair
#define pb push_back
#define pa pair<int,int>
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))
using namespace std;
inline ll read(){
 ll f=1,x=0;char ch=getchar();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
 return x*f;
}
inline ll getgcd(ll x,ll y){return !x?y:getgcd(y%x,x);}
inline ll getlcm(ll x,ll y){return x/getgcd(x,y)*y;}
inline ll qpow(int x,int y,int p){
 ll re=1;
 while(y){
     if(y&1)re=(re*x)%p;
  y>>=1,x=(x*x)%p;
 }
 return re;
}
//**********head by yjjr**********
ll n,q,x;
int main()
{
 n=read(),q=read();
 while(q--){
  x=read();
  while(!(x&1))x=(x>>1)+n;
  printf("%I64d\n",(x+1)>>1);
 }
 return 0;
}