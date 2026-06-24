//Redstar
//scj1226
//G
#include<bits/stdc++.h>
#define INT long long
#define bctz __builtin_ctz
#define endl '\n'
using namespace std;
const int NN = 5e5 + 10;
int A[NN];
vector<int> adj[NN];
int n;
int p[NN][20], deep[NN];
int dp[NN][20][2];
int val[NN][20];
int B[NN];
int bit;
struct LCA {
	void dfs(int u, int fa=0){
		val[u][bit] = val[fa][bit];
		if(B[u]) val[u][bit]++;
		for(int i = 0; i < 2; i++){
			dp[u][bit][i] = dp[p[u][bit]][bit][i ^ 1];
			int res = val[u][bit] - val[p[u][bit]][bit];
			if(i == 0) dp[u][bit][i] += res;
			else dp[u][bit][i] += min(deep[u],(1 << bit)) - res;
		}
	}
	void mp(int u,int fa = 0){
		p[u][0]=fa;
		deep[u]=deep[fa]+1;
		
		for(int i=1; i<20; i++) p[u][i]=p[p[u][i-1]][i-1];
	}
	void start(){
		queue<int> que;
		que.push(1);
		vector<int> flag(n + 1,0);
		flag[1] = 1;
		if(bit == 0) mp(1,0);
		dfs(1,0);
		while(!que.empty()){
			auto p = que.front();
			que.pop();
			for(auto r : adj[p]){
				if(flag[r] == 1) continue;
				if(bit == 0) mp(r,p);
				dfs(r,p);
				que.push(r);
				flag[r] = 1;
			}
		}
	}
	int k_th(int u, int k){
		for(; k; ) u = p[u][bctz(k&-k)], k-=k&-k;
		return u;
	}
	int lca(int a, int b){
		if(deep[a]>deep[b]) swap(a, b);
		b=k_th(b, deep[b]-deep[a]);
		if(a==b) return a;
		for(int i=19; i>=0; i--){
			if(p[a][i]!=p[b][i]) a=p[a][i], b=p[b][i];
		}
		return p[a][0];
	}
} lca;
int match(int u,int v,int bit,int r){	
	int lc = lca.lca(u,v);
	int plus = (val[u][bit] + val[v][bit] - 2 * val[lc][bit] + ((A[lc] >> bit) & 1));
	int ans = 0;
	if(r == 0) ans += plus;
	else ans += (deep[v] - deep[lc] + deep[u] - deep[lc] + 1 - plus);
	return ans;
}
int calc(int u,int v,int bit,int rev){
	if(deep[u] < deep[v]) swap(u,v);
	int res = deep[u] - deep[v];
	int temp = res % (1 << bit);
	if(temp) assert(0);
	res = res / (1 << bit);
	res = res % 2;
	return dp[u][bit][rev] - dp[v][bit][rev ^ res];
}
int _calc(int u,int v,int bit,int r){
	if(deep[u] < deep[v]) swap(u,v);
	int res = deep[u] - deep[v];
	int temp = res % (1 << bit);
	res /= (1 << bit);
	int other = lca.k_th(u,deep[u] - deep[v] - res * (1 << bit));
	r = (r + res) % 2;
	int xx = val[u][bit] - val[other][bit];
	if(r) xx = deep[u] - deep[other] - xx;
	return calc(other,v,bit,r ^ 1) + xx;
	
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i < n ;i++) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 1; i <= n; i++){
			cin >> A[i];
		}
		for(bit = 0; bit < 20; bit++){
			for(int i = 1; i <= n; i++) {
				B[i] = ((A[i] >> bit) & 1);
			}
			lca.start();
		}
		int q;
		cin >> q;
		while(q--){
			int u,v;
			cin >> u >> v;
			int lc = lca.lca(u,v);
			INT ans = 0;
			for(int i = 0; i < 20; i++){
				int dep = deep[u] - deep[lc];
				int top = dep / (1 << i);
				int node = lca.k_th(u,(1 << i) * top);
				ans += (1ll << i)  * calc(u,node,i,0);
				int r = ((deep[u] - deep[node]) / (1 << i)) % 2;
				if(deep[v] - deep[lc] + deep[node] - deep[lc] + 1 <= (1 << i)){
					ans += (1ll << i) * match(node,v,i,r);
					continue;
				}
				int other = lca.k_th(v,deep[v] - deep[lc] - ((1 << i) - (deep[node] - deep[lc]) - 1));
				ans += (1ll << i) * match(node,other,i,r);
	//			cerr << i << " " << node << " " << other << " " << bit << " " << r << " " <<match(node,other,bit,r) << endl;
				r++;
				r %= 2;
				ans += (1ll << i) * _calc(other,v,i,r);
			}
			cout << ans << endl;
			
		}
		
		for(int i = 1; i <= n; i++) adj[i].clear();
	}
}