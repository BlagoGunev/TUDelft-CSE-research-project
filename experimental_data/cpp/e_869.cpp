#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#define sed 100001
using namespace std;
typedef unsigned long long ll;
int n,m,q;
ll f[2510][2510];
struct node{int r1,c1,r2,c2;};
//map<ll,node>mp;
inline void add(int x,int y,ll z)
{
  for(int i=x;i>0;i-=i&-i)
    for(int j=y;j>0;j-=j&-j) f[i][j]+=z;
}
inline ll query(int x,int y)
{
  ll ans=0;
  for(int i=x;i<=n;i+=i&-i)
    for(int j=y;j<=m;j+=j&-j) ans+=f[i][j];
  return ans;
}
int main()
{
  cin>>n>>m>>q;
  for(int i=1,type,r1,c1,r2,c2;i<=q;i++)
  {
    scanf("%d%d%d%d%d",&type,&r1,&c1,&r2,&c2);
    if(type==1)
	{
      ll ha=r1+c1*sed+r2*sed*sed+c2*sed*sed*sed;
	  add(r2,c2,ha);
	  add(r2,c1-1,-ha);
	  add(r1-1,c2,-ha);
	  add(r1-1,c1-1,ha); 
	}
	if(type==2)
	{
	  ll ha=r1+c1*sed+r2*sed*sed+c2*sed*sed*sed;
	  add(r2,c2,-ha);
	  add(r2,c1-1,ha);
	  add(r1-1,c2,ha);
	  add(r1-1,c1-1,-ha); 
	}
	if(type==3)
	{
      ll ha1=query(r1,c1),ha2=query(r2,c2);
      if(ha1==ha2) printf("Yes\n");
      else printf("No\n");
	}
  }
  return 0;
}