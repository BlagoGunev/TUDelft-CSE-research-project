#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

#define MOD 1000000007
#define MAXN 100010

int pa[MAXN], ra[MAXN];
void init(int n) {
	REP(i,n)  {
		pa[i] = i;
		ra[i] = 0;
	}
}
int find(int x) {
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}
// 0: already united;  1: successfully united;
int unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return 0;
	if(ra[x] < ra[y]) {
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

VI Map[MAXN];
int vis[MAXN];

int cnt;
int f = 0;
void dfs(int u, int c = 1) {
	vis[u] = c;
	cnt ++;
	REP(i,Map[u].size()) {
		int v = Map[u][i];
		if(!vis[v]) {
			dfs(v, 3 - c);
		}else if(vis[v] == vis[u]) f = 1;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	VII vec;
	REP(i,m) {
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x); u--; v--;
		if(x == 1) unite(u, v);
		else vec.PB(MP(u,v));
	}
	REP(i,vec.size()) {
		int u = vec[i].X;
		int v = vec[i].Y;
		if(find(u) == find(v)) {
			cout<<"0"<<endl;
			return 0;
		}else{
			u = find(u);
			v = find(v);
			Map[u].PB(v);
			Map[v].PB(u);
		}
	}
	ll cc = 0;
	REP(i,n) {
		if(find(i) == i && !vis[i]) {
			cnt = 0;
			dfs(i);
			if(f) {
				cout<<"0"<<endl;
				return 0;
			}else{
				cc += 1;
			}
		}
	}
	//cout<<cc<<endl;
	ll ans = 1;
	REP(i,cc-1) ans = ans*2%MOD;
	cout<<ans<<endl;
	return 0;
}