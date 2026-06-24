#include<bits/stdc++.h>
using namespace std;

const int N=100500;

struct Edge{int to,nex;}e[N<<1];
int n,m,h,num=0,SZ=0,a[N],lis[N];
int dfnclk=0,top=0,dfn[N],low[N],scc[N],sz[N],st[N];
bool v[N];

int I(){
 int x=0,f=1;char ch=getchar();
 for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
 for(;ch>='0'&&ch<='9';x=(x<<3)+(x<<1)+ch-'0',ch=getchar());
 return x*f;
}

void add(int x,int y){
 e[++num].to=y;e[num].nex=lis[x];lis[x]=num;
}

void tarjan(int x){
 dfn[x]=low[x]=++dfnclk;
 st[++top]=x;
 for(int i=lis[x];i;i=e[i].nex){
  if(!dfn[e[i].to]){
   tarjan(e[i].to);
   low[x]=min(low[x],low[e[i].to]);
  }
  else if(!scc[e[i].to])
   low[x]=min(low[x],dfn[e[i].to]);
 }
 if(low[x]==dfn[x]){
  int now=0;++SZ;sz[SZ]=0;
    while(now!=x){
     now=st[top--];
   scc[now]=SZ;
   sz[SZ]++;
    }
 }
}

void rebuild(){
 for(int i=1;i<=n;++i)
  for(int j=lis[i];j;j=e[j].nex)
   if(scc[e[j].to]!=scc[i])
    v[scc[i]]=1;
 int mn=2000000000,k=0;
 for(int i=1;i<=SZ;++i)
  if(!v[i]&&sz[i]<mn){
   mn=sz[i];
   k=i;
  }
 printf("%d\n",mn);
 for(int i=1;i<=n;++i)if(scc[i]==k)printf("%d ",i);
 puts("");
}

int main(){
 n=I();m=I();h=I();
 for(int i=1;i<=n;++i)a[i]=I();
 while(m--){
  int x=I(),y=I();
  if((a[y]+1)%h==a[x])add(y,x);
  if((a[x]+1)%h==a[y])add(x,y);
 }
 for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
 
 rebuild();
 return 0;
}