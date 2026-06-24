#include <bits/stdc++.h>
using namespace std;
const int M = 5000001;
int n,m;
bool vis[M];
bool vis1[M],vis2[M];
void dfs(int u,int type){
	if(type == 1)vis1[u] = true;
	else vis2[u] = true;
	if(type == 1){
		int to = u ^ ((1 << n) - 1);
		if(!vis2[to])dfs(to,2);
	}
	else{
		if(vis[u] && !vis1[u])dfs(u,1);
		for(int i=0;i<n;i++) if(u & (1 << i)){
			if(!vis2[u ^ (1 << i)])dfs(u ^ (1 << i),2);
		}
	}
}
int ans = 0;
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<(1 << n);i++)vis[i] = vis1[i] = vis2[i] = false;
	for(int i=1;i<=m;i++){
		int value;
		scanf("%d",&value);
		vis[value] = true;
	}
	for(int i=0;i<(1 << n);i++) if(vis[i] && !vis1[i])ans++,dfs(i,1);
	printf("%d\n",ans);
	return 0;
}