//%std
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define lovelive long long
#define lc son[x][0]
#define rc son[x][1]
#define lowbit(x) (x&(-x))
const int N=1e5+100;
const lovelive mod=998244353;
template<typename T>void read(T &x)
{
  int p=1;
  x=0;
  char c=getchar();
  while(c<'0'||c>'9')
  {
    if(c=='-')
	  p=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9')
  {
  	x=x*10+c-48;
  	c=getchar();
  }
  x*=p;
}
int a[20];
int main()
{
  lovelive ans=0,n,x,tmp,pt;
  read(n);
  for(int i=1;i<=n;i++)
  {
    read(x);
    memset(a,0,sizeof(a));
    for(int i=1;i<=10;i++)
    {
      if(!x)
        break;
      a[i]=x%10;
      x/=10;
    }
    tmp=0;
    pt=10;
    while(!a[pt])
      --pt;
    for(int i=pt;i>=1;i--)
    {
      tmp=tmp*100+a[i]*11;
      tmp%=mod;
    }
    ans+=tmp;
    if(ans>=mod)
      ans-=mod;
  }
  cout<<ans*n%mod;
  return 0;
}