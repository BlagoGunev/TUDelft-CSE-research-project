#include<bits/stdc++.h>
using namespace std;
#define D isdigit(c=getchar())
inline int getint(){
    int c,l=0,x;
    for (;!D;l=c)if(c==EOF)return 1<<31;
    for (x=c-'0';D;x=x*10+c-'0')if(c==EOF) break;
    return l=='-'?-x:x;
}
typedef long long ll;
const int N=1000100;
int fa[N],sz[N],a[N],n;
struct edge{
 int u,v;
 bool operator < (const edge&x)const{
  if(a[v]!=a[x.v])return a[v]<a[x.v];
  return v<x.v;
 }
}egs[N];
int find(int x){
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
ll ans;
void solve(){
 for(int i=1;i<=n;i++){
  fa[i]=i;sz[i]=1;ans+=a[i];
 }
 for(int i=1;i<n;i++){
  if(egs[i].u>egs[i].v)swap(egs[i].u,egs[i].v);
  if(a[egs[i].u]>a[egs[i].v])swap(egs[i].u,egs[i].v);
 }
 sort(egs+1,egs+n);
 for(int i=1;i<n;i++){
  int v=egs[i].u,u=egs[i].v;
  if(fa[u]!=u)exit(1);v=find(v);
  ans+=(ll)sz[u]*sz[v]*a[u];
  sz[u]+=sz[v];fa[v]=u;
 }
}
int main(){
 n=getint();
 for(int i=1;i<=n;i++)a[i]=getint();
 for(int i=1;i<n;i++){egs[i].u=getint();egs[i].v=getint();}
 solve();
 for(int i=1;i<=n;i++)a[i]=-a[i];
 solve();
 cout<<ans;
 return 0;
}