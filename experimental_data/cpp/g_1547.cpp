#include <bits/stdc++.h>

typedef long long ll;
const int N = 4e5+5;
std::vector<int> g[N];
int ans[N];
bool visited[N];
bool visited2[N];
bool visited3[N];
bool cycle[N];
std::pair<int,int> timer[N];
int n,m;
int ct;	//curr time;

void dfs(int u, int p){
	timer[u].first = ct++;
	timer[u].second = INT_MAX;
	visited[u] = true;
	if(ans[u] == 0) {
		ans[u] = 1;
	}

	for(int v:g[u]) {
		if(visited[v]) {
			if(timer[v].second == INT_MAX) {
				ans[v] = -1;
				cycle[v] = true;
			} else if(!cycle[v]){
				ans[v] = 2;
			}
		} else {
			dfs(v, u);
		}
	}
	timer[u].second = ct++;
}

void dfs2(int u, int p){
	visited2[u] = true;
	ans[u] = -1;
	for(int v:g[u]) {
		if(!visited2[v]) {
			ans[v] = -1;
			cycle[v] = true;
			dfs2(v, u);
		}
	}
}

void dfs3(int u, int p){
	visited3[u] = true;
	if(ans[u] == 1){
		ans[u] = 2;
	}
	for(int v:g[u]) {
		if(!visited3[v]) {
			// ans[v] = 2;
			// cycle[v] = true;
			dfs3(v, u);
		}
	}
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t; std::cin >> t;
	while(t--) {
		std::cin >> n >> m;

		ct = 0;
		for(int i=0;i<n;i++) {
			visited[i] = false;
			visited2[i] = false;
			visited3[i] = false;
			cycle[i] = false;
			ans[i] = 0;
			g[i].clear();
		}

		for(int i=0;i<m;i++) {
			int u,v;
			std::cin >> u >> v;
			u--;v--;
			g[u].push_back(v);
		}
		ans[0] = 1;
		dfs(0,0);
		for(int i=0;i<n;i++) {
			if(!visited2[i] && cycle[i]) {
				dfs2(i, i);
			}
		}
		for(int i=0;i<n;i++) {
			if(!visited3[i] && ans[i] == 2) {
				dfs3(i, i);
			}
		}

		for(int i=0;i<n;i++) {
			std::cout << ans[i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}