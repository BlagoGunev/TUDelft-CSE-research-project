#include<iostream>  
#include<cstdio>  
#include<cstring>  
#define ll long long  
#define N 200005  
using namespace std;  
  
int n,cnt,tot,dfsclk,pos[N],fst[N],pnt[N<<1],len[N<<1],nxt[N<<1],a[N],b[N],c[N],fa[N];  
ll f[N],u1[N],u2[N],v1[N],v2[N],ans; bool ok[N];  
void add(int x,int y,int z){  pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;  }  
void dfs(int x){  pos[x]=++dfsclk; int p;  for (p=fst[x]; p; p=nxt[p]){  int y=pnt[p];  if (y!=fa[x]){  if (!pos[y]){ fa[y]=x; c[y]=len[p]; dfs(y); }  else if (pos[y]>pos[x]){  for (; y!=x; y=fa[y]){  ok[y]=0;  a[++cnt]=y; b[cnt]=c[y];  }  ok[x]=0;  a[++cnt]=x; b[cnt]=len[p];  }  }  }  }  void dp(int x,int last){  int p;  for (p=fst[x]; p; p=nxt[p]){  int y=pnt[p];  if (ok[y] && y!=last){  dp(y,x);  ans=max(ans,f[x]+f[y]+len[p]);  f[x]=max(f[x],f[y]+len[p]);  }  }  }  int main(){  scanf("%d",&n); int i,x,y,z;  memset(ok,1,sizeof(ok));  for (i=1; i<=n; i++){  scanf("%d%d%d",&x,&y,&z);  add(x,y,z); add(y,x,z);  }  dfs(1);  ll sum=0,mx=0;  for (i=1; i<=cnt; i++) dp(a[i],0);  for (i=1; i<=cnt; i++){  sum+=b[i-1]; u1[i]=max(u1[i-1],f[a[i]]+sum);  v1[i]=max(v1[i-1],f[a[i]]+sum+mx);  mx=max(mx,f[a[i]]-sum);  }  ll tmp=b[cnt]; sum=mx=b[cnt]=0;  for (i=cnt; i; i--){  sum+=b[i]; u2[i]=max(u2[i+1],f[a[i]]+sum);  v2[i]=max(v2[i+1],f[a[i]]+sum+mx);  mx=max(mx,f[a[i]]-sum);  }  ll mn=v1[cnt];  for (i=1; i<cnt; i++) mn=min(mn,max(max(v1[i],v2[i+1]),u1[i]+u2[i+1]+tmp));  ans=max(ans,mn);  
    //printf("%lld.%d\n",ans>>1,(ans&1)?5:0);  
    cout<<ans;
    return 0;  
}