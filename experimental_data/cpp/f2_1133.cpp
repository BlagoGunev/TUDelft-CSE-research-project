#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;

bool vis[maxn+1],mark[maxn+1];
vector<int> g[2][maxn+1];

void sub2(){
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(int i=0;i<g[1][curr].size();++i){
			int next = g[1][curr][i];
			if(vis[next]) continue;
			q.push(next);
			vis[next] = 1;
			cout<<curr<<" "<<next<<"\n";
		}
	}
}

vector<int> root;

void sub3(){
	queue<int> q;
	vis[1] = 1;
	for(int i=0;i<root.size();++i){
		cout<<1<<" "<<root[i]<<"\n";
		q.push(root[i]);
		vis[root[i]] = 1;
	}
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(int i=0;i<g[1][curr].size();++i){
			int next = g[1][curr][i];
			if(vis[next]) continue;
			q.push(next);
			vis[next] = 1;
			cout<<curr<<" "<<next<<"\n";
		}
	}
}

void bfs(int node){
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(int i=0;i<g[0][curr].size();++i){
			int next = g[0][curr][i];
			if(vis[next]) continue;
			q.push(next);
			vis[next] = 1;
			//cout<<curr<<" "<<next<<"\n";
		}
	}
}

int getComponents(int n){
	int cnt = 0;
	for(int i=0;i<g[1][1].size();++i){
		int next = g[1][1][i];
		if(vis[next]) continue;
		
		++cnt;
		root.push_back(next);
		mark[next] = 1;
		bfs(next);
	}
	
	//for(int i=0;i<root.size();++i) cout<<root[i]<<" ";
	
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n,m,d;
	cin>>n>>m>>d;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[1][u].push_back(v);
		g[1][v].push_back(u);
		
		if(u == 1 || v == 1) continue;
		g[0][u].push_back(v);
		g[0][v].push_back(u);
	}
	
	if(g[1][1].size() < d) cout<<"NO";
	else if(g[1][1].size() == d){
		cout<<"YES\n";
		sub2();
	}
	else{
		if(getComponents(n) > d) cout<<"NO";
		else{
			cout<<"YES\n";
			if(root.size() < d){
				for(int i=0;i<g[1][1].size();++i){
					int next = g[1][1][i];
					if(root.size() == d) break;
					if(!mark[next]) root.push_back(next);
				}
			}
			memset(vis,0,sizeof vis);
			sub3();
		}
	}
}