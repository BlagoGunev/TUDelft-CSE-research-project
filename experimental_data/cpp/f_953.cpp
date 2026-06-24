#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,p,m;
long long rem;
int ans;
int d[100010],t[100010];
int main()
{
 scanf("%d%d%d",&n,&p,&m);
 for(int i=1;i<=n;i++)scanf("%d%d",d+i,t+i);
 if(d[n]<m)d[++n]=m;
 for(int i=1;i<=n;i++)
 {
  ans+=(rem>=0)?max(1LL*d[i]-d[i-1]-1-rem/p,0LL):d[i]-d[i-1]-1;
  rem-=1LL*(d[i]-d[i-1])*p;
  rem+=t[i];
  if(rem<0)ans++;
 }
 printf("%d",ans);
 return 0;
}