#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,t,u,v,f[1000010],x[1000010],a[1000010],b[1000010];
inline void dfs(int i)
{
    int j;
    for(j=a[i];j>0;j=b[j])
      {
       dfs(j);
       x[i]+=x[j];
       if(f[j])
         if(!f[i])
           f[i]=f[j];
         else
           {
            u=f[i];
            v=f[j];
           }
      }
    if(i==t)
      return;
    if(f[i] && x[i]==2*m)
      {
       u=f[i];
       v=i;
      }
    if(x[i]==m)
      f[i]=i;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
       scanf("%d%d",&j,&x[i]);
       b[i]=a[j];
       a[j]=i;
       if(!j)
         t=i;
       m+=x[i];
      }
    if(m%3)
      {
       printf("-1");
       return 0;
      }
    m/=3;
    dfs(t);
    if(u)
      printf("%d %d\n",u,v);
    else
      printf("-1");
	return 0;
}