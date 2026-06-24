#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=2e5+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,de[N],u,v;
struct edge{
    int v,ne;
}e[N<<1];
int h[N],cnt;
inline void ins(int u,int v){
    cnt++;
    e[cnt].v=v;e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].ne=h[v];h[v]=cnt;
}
int ans,col[N],fa[N],now[N];
void dfs(int u){
	for(int i=h[u];i;i=e[i].ne){
		int v=e[i].v;
		if(v==fa[u]) continue;
		fa[v]=u;
		now[u]++;
		while(now[u]==col[u]||now[u]==col[fa[u]]) now[u]++;
		col[v]=now[u];
		dfs(v);
	}
}
int main(){
	//freopen("in","r",stdin);
    n=read();
    for(int i=1;i<n;i++) u=read(),v=read(),de[u]++,de[v]++,ins(u,v);
    for(int i=1;i<=n;i++) ans=max(ans,de[i]+1);
	printf("%d\n",ans);
	fa[1]=0;col[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++) printf("%d ",col[i]);
}