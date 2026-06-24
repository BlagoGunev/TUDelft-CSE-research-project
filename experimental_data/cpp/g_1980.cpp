#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define vi vector <int>
#define vvi vector <vi>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 998244353, N = 2e5 + 5, M = 2e5 + 5;

struct Trie
{
	Trie (){};
	Trie (int k) {
		init(k);
	}
	int** son; int* siz;
	int idx;
	void init(int k){
		son = (int**)malloc(sizeof(int*) * ((k << 5) + 1));
		siz = (int*)malloc(sizeof(int) * ((k << 5) + 1));
		for(int i = 0; i <= (k << 5); i ++){
			son[i] = (int*)malloc(sizeof(int) * (2));
			son[i][0] = son[i][1] = siz[i] = 0;
		}
		idx = 0;
	}
	void ins(ll x){
		int p = 0;
		for(int i = 30; i >= 0; i --){
			int u = (x >> i) & 1;
			if(!son[p][u]) son[p][u] = ++ idx;
			p = son[p][u];
			siz[p] ++;
		}
	}
	ll query(ll x, int rk){
		int p = 0; ll ret = 0;
		for(int i = 30; i >= 0; i --){
			int u = (x >> i) & 1;
			if(son[p][u ^ 1] && siz[son[p][u ^ 1]] >= rk){
				if(u ^ 1) ret |= 1ll << i;
				p = son[p][u ^ 1];
			}
			else{
				if(u) ret |= 1ll << i;
				rk -= siz[son[p][u ^ 1]];
				p = son[p][u];
			}
		}
		return x ^ ret;
	}
};

void solve()
{
	int n, m; cin >> n >> m;
	vector <vector <pair <int, ll> > > adj(n + 1);
	for(int i = 1; i < n; i ++){
		int u, v; ll w; cin >> u >> v >> w;
		adj[u].push_back({v, w}), adj[v].push_back({u, w});
	}
	
	vector <ll> dis(n + 1, 0);
	vi ddis(n + 1, 0);
	
	Trie trodd(n), treven(n);
	int sizodd = 0, sizeven = 0;
	auto dfs = [&](auto&& self, int p, int fa, int k, int d) -> void {
		dis[p] = k, ddis[p] = d;
		if(d) trodd.ins(dis[p]), sizodd ++;
		else treven.ins(dis[p]), sizeven ++;
		for(auto [s, val] : adj[p]){
			if(s == fa) continue;
			self(self, s, p, k ^ val, d ^ 1);
		}
	};
	
	dfs(dfs, 1, 0, 0, 0);
	
	ll prey = 0;
	for(int i = 1; i <= m; i ++){
		char op; cin >> op;
		if(op == '^'){
			ll y; cin >> y;
			prey ^= y;
		}
		else{
			int v; ll x; cin >> v >> x;
			ll mxa = -1, mxb = -1;
			if(ddis[v]){
				mxa = trodd.query(dis[v] ^ x, 1);
				if(mxa == x){
					if(sizodd >= 2) mxa = trodd.query(dis[v] ^ x, 2);
					else mxa = -1;
				}
				mxb = treven.query(dis[v] ^ x ^ prey, 1);
			}
			else{
				mxa = treven.query(dis[v] ^ x, 1);
				if(mxa == x){
					if(sizeven >= 2) mxa = treven.query(dis[v] ^ x, 2);
					else mxa = -1;
				}
				mxb = trodd.query(dis[v] ^ x ^ prey, 1);
			}
			cout << max(mxa, mxb) << ' ';
		}
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); //cout.tie(0);
	
	int t = 1;
	cin >> t; 
	while(t --) solve();
	
	return 0;
}
/*
  神秘题意。
  修改：^ y --- 将树中每条边 xor y
  查询：? v x --- 选择一个 u，使得 xor [u->v] xor x 最大
  
  修改操作只需要记录一下 prey 就行。而显然的是，如果 dis[u->v] 为奇，则需要将答案 ^prey，否则不用。
  记 (x xor prey) 为 k
  
  在树上做一遍前缀 xor，并将与根节点距离的奇偶关系分类，分别将值插入 01-Trie
  
  细节是 u != v，所以 ans != k，找到 ans == k 就要找次大值
 */