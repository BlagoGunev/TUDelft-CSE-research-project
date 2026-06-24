#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
 int sum=0,p=1;char ch=getchar();
 while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
 if(ch=='-')p=-1,ch=getchar();
 while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
 return sum*p;
}

const int maxn=2e5+20;

int n,p[maxn],id[maxn],s[maxn];

void init()
{
 n=read();REP(i,1,n)p[i]=read(),id[p[i]]=i;
 REP(i,1,n-1)s[i]=s[i-1]+getchar()-'0';
}

void doing()
{
 REP(i,1,n-1)
 {
  if(i!=p[i])
  {
   int l=i,r=id[i];
   if(l>r)swap(l,r);
   if(s[r-1]-s[l-1]!=r-l){ puts("NO");return;}
   swap(id[p[l]],id[p[r]]);swap(p[l],p[r]);
  }
 }
 puts("YES");
}

int main()
{
 //freopen("c.in","r",stdin);
 //freopen("c.out","w",stdout);
 init();
 doing();
 return 0;
}