#include<bits/stdc++.h>
#define N 200005
using namespace std;
inline int read(){
	int ans=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+ch-'0',ch=getchar();
	return ans;
}
int cnt=0,n,num[N],pred[N],siz[N],m;
struct node{int v;};
priority_queue<node>q[N];
inline bool operator<(node a,node b){return a.v>b.v;}
inline void add(int u,int v){q[u].push((node){v});}
inline void dfs(int p){
	siz[p]=1;
	num[p]=++cnt;
	pred[cnt]=p;
	while(!q[p].empty()){
		int v=q[p].top().v;
		q[p].pop();
		dfs(v);
		siz[p]+=siz[v];
	}
}
int main(){
	n=read(),m=read();
	for(int i=2;i<=n;++i){
		int x=read();
		add(x,i);
	}
	dfs(1);
	while(m--){
		int x=read(),k=read();
		if(siz[x]<k)puts("-1");
		else printf("%d\n",pred[num[x]+k-1]);
	}
	return 0;
}