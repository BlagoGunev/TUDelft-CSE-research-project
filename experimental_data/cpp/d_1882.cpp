#include <bits/stdc++.h> 
using namespace std; 
#define int long long
#define endl '\n'
#define mod 1000000007
// when constrain allows use vector insted of map.........
// set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), inserter(cd,cd.begin()));
const int N = 1e6 + 10;
void solve(){
	int n;
	cin>>n;
	vector<int> a(n + 1,0);
	for(int i=1;i<=n;i++)	cin>>a[i];
	vector<vector<int>> g(n + 1);
	for(int i=1;i<n;i++){
		int l,r;	cin>>l>>r;
		g[l].push_back(r);
		g[r].push_back(l);
	}
	a[0] = a[1];
	vector<int> cost(n + 1,0);
	vector<int> nc(n + 1,0);
	function<int(int,int)> dfs = [&](int node,int par){
		int cnt = 1;
		int ccost = 0;
		for(auto it : g[node]){
			if(it == par)	continue;
			ccost += dfs(it,node);
			cnt += nc[it];
		}
		int ca = 0;
		for(int i=0;i<32;i++){
			int b1 = a[node] & (1<<i);
			int b2 = a[par] & (1<<i);
			if(b1 != b2)	ca += (1<<i);
		}
		nc[node] = cnt;
		cost[node] = ccost;
		ccost += nc[node] * ca;
		return ccost;
	};
	dfs(1,0);
	function<int(int,int)> dif = [&](int na,int nb){
		int ca = 0;
		for(int i=0;i<32;i++){
			int b1 = a[na] & (1<<i);
			int b2 = a[nb] & (1<<i);
			if(b1 != b2)	ca += (1<<i);
		}
		return ca;
	};
	vector<int> fans( n + 1,0);
	fans[1] = cost[1];
	// for(int i=1;i<=n;i++)	cout<<cost[i]<<" ";
	// cout<<endl;
	function<void(int,int,int)> dfs1 = [&](int node,int par,int parc){
		for(auto it : g[node]){
			if(it == par)	continue;
			int itc = cost[node] - cost[it] - dif(node,it) * nc[it];
			int ca = 0;
			for(int i=0;i<32;i++){
				int b1 = a[node] & (1<<i);
				int b2 = a[it] & (1<<i);
				if(b1 != b2)	ca += (1<<i);
		    }
		    int nparc = parc + ca * (nc[1] - nc[it]) + itc;
		 	fans[it] = cost[it] + nparc;
		 	dfs1(it,node,nparc);   
		}
	};
	dfs1(1,0,0);
	for(int i=1;i<=n;i++)	cout<<fans[i]<<" ";
	cout<<endl;
}
#undef int 
int main(){
	
	int t = 1; 
	cin >> t;
	while(t--){
		solve();
	}
}