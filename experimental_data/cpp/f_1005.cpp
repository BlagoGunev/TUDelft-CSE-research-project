#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<pair<int,int>>g[N];
vector<int>edges[N];
int n,m,dis[N],k;
vector<vector<int>>ans;
queue<int>q;
void bfs(){
	for(int i = 0;i < N;i++)dis[i] = 1e9;
	q.push(0);
	dis[0] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto i : g[x]){
			if(dis[i.first] < dis[x] + 1)continue;
			if(dis[i.first] > dis[x] + 1)edges[i.first].clear();
			edges[i.first].push_back(i.second);
			if(dis[i.first] == dis[x] + 1)continue;
			dis[i.first] = dis[x] + 1;
			q.push(i.first);
		}
	}
}
vector<int>temp;
void calc(int u){
	if(u == n){
		ans.push_back(temp);
		return;
	}
	for(auto i : edges[u])
		if(ans.size() < k){
			temp.push_back(i);
			calc(u + 1);
			temp.pop_back();
		}else break;
}
int main(){
// 	freopen("readin.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0,a,b;i < m;i++){
		scanf("%d%d",&a,&b);
		g[--a].push_back({--b,i});
		g[b].push_back({a,i});
	}
	bfs();
	edges[0].push_back(-1);
	calc(0);
	printf("%d\n",ans.size());
	for(auto i : ans){
		int r = 0;
		sort(i.begin(),i.end());
		for(int j = 0;j < m;j++){
			while(r + 1 < i.size() && i[r] < j)r++;
			printf("%d",i[r] == j);
		}
		puts("");
	}
}