#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int edge;
int head[300001];
int scc,cnt;
bool v[300001];
int s[400001],top;
int dfn[400001],low[400001],belong[400001];
int indeg[400001],outdeg[400001],sdeg[400001];
struct map
{
     int s,t;
     int next;
}a[300001];
inline void add(int s,int t)
{
	 a[edge].next=head[s];
     head[s]=edge;
     a[edge].s=s;
     a[edge].t=t;
}
inline void tarjan(int d)
{
     int i,x;
     cnt++;
     dfn[d]=cnt;
     low[d]=cnt;
     top++;
     s[top]=d;
     v[d]=true;
     for(i=head[d];i!=0;i=a[i].next)
     {
     	  x=a[i].t;
          if(dfn[x]==0)
          {
               tarjan(x);
               low[d]=min(low[d],low[x]);
          }
          else if(v[x]&&low[d]>dfn[x])
               low[d]=dfn[x];
     }
     if(dfn[d]==low[d])
     {
          scc++;
          x=s[top];
          top--;
          while(x!=d)
          {    
			   v[x]=false;
               belong[x]=scc;
               x=s[top];
               top--;
          }
          v[x]=false;
          belong[x]=scc;
     }
}
inline void count_edge()
{
	 int i,j,d;
     for(i=1;i<=n;i++)
     	  sdeg[belong[i]]++;
}
int father[400001];
int sx[400001];
inline int find(int x)
{
     if(father[x]!=x)
          father[x]=find(father[x]);
     return father[x];
}
inline int count_edgeex()
{
	 int i,j,d;
	 int fx,fy;
	 int s=0;
     for(i=1;i<=n;i++)
     {
          for(j=head[i];j!=0;j=a[j].next)
          {
               d=a[j].t;
               fx=find(belong[i]);
               fy=find(belong[d]);
               if(fx!=fy)
               {
               	    if(sx[fx]==1||sx[fy]==1)
               	         s++;
                    father[fx]=fy;
                    if(sx[fx]!=1||sx[fy]!=1)
                    {
                         sx[fx]+=sx[fy];
                         sx[fy]=sx[fx];
                    }
               }
          }
     }
     return s;
}
int main()
{
     int m;
     scanf("%d%d",&n,&m);
     int i;
     int s,t;
     for(i=1;i<=m;i++)
     {
          scanf("%d%d",&s,&t);
          edge++;
          add(s,t);
     }
     for(i=1;i<=n;i++)
          if(!belong[i])
               tarjan(i);
     count_edge();
     for(i=1;i<=scc;i++)
     {
          father[i]=i;
          sx[i]=sdeg[i];
     }
     int ans=0;
     for(i=1;i<=scc;i++)
          if(sdeg[i]!=1)
               ans+=sdeg[i];
     ans+=count_edgeex();
     /*if(ans>n)
          ans=n;*/
     printf("%d\n",ans);
     return 0;
}