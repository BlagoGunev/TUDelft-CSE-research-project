#include<bits/stdc++.h>
#define debug(x) cout<<#x<<"="<<x<<endl
typedef long long ll;
using namespace std;
const int maxn = 100009;

ll a[maxn],sum[maxn],f[maxn],q1[maxn],q2[maxn];
int n,m,h1,t1,h2,t2;

inline int read()
{
 int x=0,f=1;char ch=getchar();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
 return x*f;
}

int main()
{
 n=read();m=read();
 for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
 if(m>n){printf("%I64d\n",sum[n]);return 0;}
 h1=h2=1;
 for(int i=1;i<m;i++)
 {
  f[i]=sum[i];
  while(h1<=t1&&a[i]<a[q1[t1]]) t1--;
  q1[++t1]=i;
  while(h2<=t2&&f[i]-sum[i]<f[q2[t2]]-sum[q2[t2]]) t2--;
  q2[++t2]=i;
 }
 for(int i=m;i<=n;i++)
 {
  while(h1<=t1&&q1[h1]<=i-m) h1++;
  while(h1<=t1&&a[i]<a[q1[t1]]) t1--;
  q1[++t1]=i;
  while(h2<=t2&&q2[h2]<i-m) h2++;
  f[i]=sum[i]-sum[i-m]+f[i-m]-a[q1[h1]];
  f[i]=min(f[i],sum[i]+f[q2[h2]]-sum[q2[h2]]);
  while(h2<=t2&&f[i]-sum[i]<f[q2[t2]]-sum[q2[t2]]) t2--;
  q2[++t2]=i;
 }
 cout<<f[n]<<endl;
 return 0;
}