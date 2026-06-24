#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 200005;
#define ll long long
ll gi()
{
 ll x=0,w=1;char ch=getchar();
 while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
 if (ch=='-') w=0,ch=getchar();
 while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
 return w?x:-x;
}
struct node{
 int id;ll val;
 bool operator < (const node &b) const
  {return val>b.val;}
};
struct edge{int to,next;ll w;}a[N<<1];
int n,m,head[N],cnt,vis[N];
ll val[N],ans[N];
priority_queue<node>Q;
int main()
{
 n=gi();m=gi();
 for (int i=1;i<=m;++i)
 {
  int u=gi(),v=gi();ll w=gi();
  a[++cnt]=(edge){v,head[u],w};head[u]=cnt;
  a[++cnt]=(edge){u,head[v],w};head[v]=cnt;
 }
 for (int i=1;i<=n;++i)
 {
  val[i]=gi();
  Q.push((node){i,val[i]});
 }
 while (!Q.empty())
 {
  node x=Q.top();Q.pop();
  if (vis[x.id]) continue;
  vis[x.id]=1;
  ans[x.id]=x.val;
  for (int e=head[x.id];e;e=a[e].next)
  {
   int v=a[e].to;
   if (val[v]>a[e].w*2+x.val)
   {
    val[v]=a[e].w*2+x.val;
    Q.push((node){v,val[v]});
   }
  }
 }
 for (int i=1;i<=n;++i) printf("%I64d ",ans[i]);
 return 0;
}