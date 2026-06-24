#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int T,n,p[N],dp[N];
vector<int>e[N];
multiset<int>nw[N];
void dfs(int x){
	if(!e[x].size()){
		dp[x]=0;
		return;
	}
	nw[x].clear();
	for(auto v:e[x]){
		dfs(v);
		nw[x].insert(dp[v]);
	}
	if(nw[x].size()==1){
		dp[x]=((*nw[x].begin())+1);
	}else{
		while(nw[x].size()>1){
			auto u=(*nw[x].begin());
			nw[x].erase(nw[x].begin());
			auto v=(*nw[x].begin());
			nw[x].erase(nw[x].begin());
			nw[x].insert(max(u,v)+1);
		}
		dp[x]=(*nw[x].begin());
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=2;i<=n;i++){
			cin>>p[i];
			e[p[i]].push_back(i);
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		cout<<dp[1]<<"\n";
	}
	return 0;
}