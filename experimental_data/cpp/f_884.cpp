#include <bits/stdc++.h>
using namespace std;

typedef long long lint; typedef pair<int, int> ii;
const int MOD = 1'000'000'007, MOD2 = 1'000'000'009;
const int INF = 0x3f3f3f3f; const lint BINF = 0x3f3f3f3f3f3f3f3fLL;

class MinCostFlow{
	private:
		int n, s, t;

		struct Edge{
			int from, to, cap, wei;
			Edge *rev;

			Edge(int u, int v, int c, int w) :
		 		from(u), to(v), cap(c), wei(w), rev(nullptr) {}
		};

		vector<vector<Edge *>> g;

		vector<int> dist, vis;
		vector<Edge *> par;

		void spfaSP(){
			fill(dist.begin(), dist.end(), INF);
			fill(vis.begin(), vis.end(), 0);
			fill(par.begin(), par.end(), nullptr);

			queue<int> q;
			dist[s] = 0; q.push(s);
			while(!q.empty()){
				int u = q.front(); q.pop(); vis[u] = 0;
				for(Edge *e: g[u]){
					if(e->cap <= 0) continue;
					int v = e->to, l = e->wei;
					if(dist[u] + l < dist[v]){
						dist[v] = dist[u] + l;
						par[v] = e;
						if(!vis[v]) q.push(v), vis[v] = 1;
					}
				}
			}
		}

		int augmentFlow(){
			int curFlow = INF;
			for(int u = t; u != s; u = par[u]->from)
				curFlow = min(curFlow, par[u]->cap);
			for(int u = t; u != s; u = par[u]->from){
				par[u]->cap -= curFlow;
				par[u]->rev->cap += curFlow;
			}
			return curFlow;
		}

	public:
		MinCostFlow(int num, int source, int dest) :
			n(num), s(source), t(dest) {
				g.resize(n);
				dist.resize(n); vis.resize(n);
				par.resize(n);
			}

		~MinCostFlow(){
			for(int i=0;i<n;i++) for(Edge *e: g[i]) delete e;
		}

		void addEdge(int u, int v, int c, int w){
			Edge *uv = new Edge(u, v, c, w);
			Edge *vu = new Edge(v, u, 0, -w);
			uv->rev = vu; vu->rev = uv;
			g[u].push_back(uv); g[v].push_back(vu);
		}

		void setKFlow(int k){
			int newSource = n++;
			g.resize(n); dist.resize(n); vis.resize(n); par.resize(n);
			addEdge(newSource, s, k, 0);
			s = newSource;
		}

		int getCost(){
			int mxFlow = 0;
			int cost = 0;
			for(;;){
				spfaSP();
				if(dist[t] == INF) break;
				int fo = augmentFlow();
				mxFlow += fo;
				cost += dist[t] * fo;
			}
			return cost;
		}

		int getSource(){
			return s;
		}

		int getSink(){
			return t;
		}

};

int n, b[105];
string s;

int solve(){
	cin >> n >> s;
	for(int i=0;i<n;i++) cin >> b[i];
	// 1 source
	// 26 in
	// 26 * (n / 2)[i == n - i - 1]
	// n out
	// 1 sink
	// n + 13 * n + 26 + 2
	MinCostFlow myFlow(14 * n + 28, 14 * n + 26, 14 * n + 27);

	for(int i=0;i<n;i++)
		myFlow.addEdge(i, myFlow.getSink(), 1, 0);

	for(int i=0;i<n/2;i++) for(int j=0;j<26;j++)
		myFlow.addEdge(n + 26 * i + j, i, 1, ('a'+j)==s[i] ? -b[i] : 0);

	for(int i=n/2;i<n;i++) for(int j=0;j<26;j++)
		myFlow.addEdge(n + 26 * (n - i - 1) + j, i, 1, ('a'+j)==s[i] ? -b[i] : 0);

	int cnt[26]={};
	for(int i=0;i<(int)s.size();i++) cnt[s[i]-'a']++;

	for(int j=0;j<26;j++)
		myFlow.addEdge(myFlow.getSource(), 14 * n + j, cnt[j], 0);

	for(int i=0;i<n/2;i++) for(int j=0;j<26;j++)
		myFlow.addEdge(14 * n + j, n + 26 * i + j, 1, 0);

	cout << -myFlow.getCost() << endl;
    return 0;
}

int main(){
	ios::sync_with_stdio(0);
	// int t; cin >> t; while(t--)
	solve();
	// cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}