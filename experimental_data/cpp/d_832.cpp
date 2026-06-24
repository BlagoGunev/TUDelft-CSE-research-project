#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,pi,ai,bi,ci,ge[100002],et,gq[100002],qt,s[100002][5],st[100002],dep[100002],low[100002],f[100002];
bool v[100002];
struct s1
{int t,next;
}e[200000];
struct s2
{int t,id,next;
}qus[600002];
void addedge(int s,int t)
{e[++et].next=ge[s];
 ge[s]=et,e[et].t=t;
 return;
}
void addqus(int s,int t,int id)
{qus[++qt].next=gq[s];
 gq[s]=qt,qus[qt].t=t,qus[qt].id=id;
 return;
}
int F(int id)
{while(id!=f[id])
  id=f[id]=f[f[id]];
 return id;
}
void tarjan(int id,int d)
{dep[id]=d,f[id]=id;
 for(int i=ge[id];i;i=e[i].next)
  if(!dep[e[i].t])
  {tarjan(e[i].t,d+1);
   f[e[i].t]=F(id);
  }
 v[id]=true;
 for(int i=gq[id];i;i=qus[i].next)
  if(v[qus[i].t])
   s[qus[i].id][++st[qus[i].id]]=dep[id]+dep[qus[i].t]-2*dep[F(qus[i].t)];
 return;
}
int main()
{scanf("%d%d",&n,&q);
 for(int i=2;i<=n;++i)
 {scanf("%d",&pi);
  addedge(pi,i),addedge(i,pi);
 }
 for(int i=1;i<=q;++i)
 {scanf("%d%d%d",&ai,&bi,&ci);
  addqus(ai,bi,i),addqus(bi,ci,i),addqus(ci,ai,i);
  if(ai!=bi)
   addqus(bi,ai,i);
  if(bi!=ci)
   addqus(ci,bi,i);
  if(ci!=ai)
   addqus(ai,ci,i);
 }
 tarjan(1,1);
// for(int i=1;i<=q;++i)
//  cout<<s[i][1]<<" "<<s[i][2]<<" "<<s[i][3]<<endl;
 for(int i=1;i<=q;++i)
  printf("%d\n",(s[i][1]+s[i][2]+s[i][3]-2*min(s[i][1],min(s[i][2],s[i][3])))/2+1);
 return 0;
}