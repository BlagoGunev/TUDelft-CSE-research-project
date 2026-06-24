#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb emplace_back
#define pi pair<int,int>
using namespace std;
const int maxn = 104;

int n, m;
int x, y;
vector<pi> v;
vector<pi> g[maxn];
int mi[maxn];

int main(){
	// freopen("scc", "r", stdin);
	// freopen("in.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (int i = 0; i < m; ++i){
		cin>>x>>y;
		v.pb(x, y);
	}
	for (int i = 1; i <= n; ++i){
		g[i].pb(i * 10000, i * 10000);
		mi[i] = 1;
	}
	for (int i = 0; i < m; ++i){
		tie(x, y) = v[i];
		g[x].pb(x * 10000, y * 10000-mi[y]);
		g[y].pb(y * 10000, y * 10000-mi[y]);
		mi[y]++;
	}
	for (int i = 1; i <= n; ++i){
		cout<<g[i].size()<<'\n';
		for (auto j: g[i]){
			cout<<j.F<<' '<<j.S<<'\n';
		}
	}
}