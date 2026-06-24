// in the name of god
#include <bits/stdc++.h>
using namespace std;

#define f 	first
#define s 	second
#define pp 	push
#define pb 	push_back
#define pf 	push_front
#define mp 	make_pair

typedef unsigned long long int ulld;
typedef long long int 	lld;
typedef long double 	ldb;

typedef vector<int> 	vi;
typedef vector<lld> 	vl;
typedef pair<int,int> 	pii;
typedef pair<lld,lld> 	pll;
typedef map<int,int> 	mii;
typedef map<lld,lld> 	mll;
typedef set<int> 	si;
typedef set<lld> 	sl;
typedef vector<pii> 	vii;
typedef vector<pll> 	vll;

#define pi(x) 	printf("%d", x)
#define gi(x) 	scanf("%d", &x)
#define gl(x) 	scanf("%lld", &x)
#define pl(x) 	printf("%lld", x)
#define g64(x) 	scanf("%I64d", &x)
#define p64(x) 	printf("%I64d", x)
#define gc(x)	scanf("%c", &x)
#define pc(x)	printf("%c", x)
#define nl 	printf("\n")
#define sp 	printf(" ")

#define all(c) c.begin(),c.end()
#define tr(it,c) for(__typeof(c.begin()) it = c.begin(); it!=c.end(); ++it)
#define fre freopen("output.txt","wt",stdout);freopen("input.txt","rt",stdin)
#define dbg(x) cerr << #x << " = " << x << endl

template <typename T> vector<T> readVector(int n) {
	vector<T> res(n);
	for (int i = 0 ; i < n ; i++) cin >> res[i];
	return res;
}

template <typename T> void printVector(vector <T> in) {
	int n = in.size();
	for (int i = 0 ; i < n ; i++){
		cout << in[i] << " \n"[i==n-1];
	}
}
#define eps 1e-7
#define INF 1e9
#define MAX 60
const lld mod = 1e9 + 7;

lld from[MAX];
lld source, sink, n;
lld capacity[MAX][MAX];
vi adj[MAX];
bool vis[MAX];

lld bfs(){
	queue<lld> Q;
	Q.pp(source);
	
	for(lld i = 0; i <= n; i++){
		vis[i] = 0;
		from[i] = -1;
	}
	vis[source] = 1;
	lld where, prev;
	bool flag = 0;
	while(!Q.empty()){
		where = Q.front();
		
		Q.pop();
		for(auto i: adj[where]){
			if(!vis[i] and capacity[where][i] > 0){
				Q.pp(i);
				vis[i] = 1;
				from[i] = where;
				if(i==sink){
					flag = 1;
					break;
				}
			}
		}
		if(flag) break;
	}
	if(!flag) return 0;
	lld path_cap = INF + 10;
	for(where = sink; where!=source; where = from[where]){
		prev = from[where];
		path_cap = min(path_cap, capacity[prev][where]);
	}
	for(where = sink; where!=source; where = from[where]){
		prev = from[where];
		capacity[prev][where] -= path_cap;
		capacity[where][prev] += path_cap;
	}
	if(path_cap == INF+10) return 0;
	else return path_cap;
}

lld ford_fulkerson(){
	lld maxflow = 0;
	while(1){
		lld ret = bfs();
		if(ret == 0) break;
		maxflow+=ret;
	}
	return maxflow;
}

vii vct;
lld x;
lld init[MAX][MAX];

bool check(ldb t){
	for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) {
		ldb tp = (init[i][j]/t + eps);
		if(tp>1e9) tp = 1e7;
		capacity[i][j] = tp;
	}
	lld mz = ford_fulkerson();
	//cout << mz;
	if(mz >= x) return true;
	return false;
}


main(){
	int m;
	cin >> n >> m >> x;
	source = 1; sink = n;
	for(int i=0, x, y, z; i<m; i++){
		scanf("%d%d%d", &x, &y, &z);
		adj[x].pb(y);
		vct.pb({x,y});
		init[x][y] = z;
		
	}
	
	ldb hi = 10000000, lo = 1.0/x, md;
	for(int i = 0; i<100; i++){
		md = (lo + hi)/2;
		if(check(md)){
			lo = md;
		}
		else{
			hi = md;
		}
	}
	cout << fixed << setprecision(10) << lo*x << endl;
}