#include <bits/stdc++.h>

#define loop(i,n) for(int i = 0;i < (n);i++)

#define range(i,a,b) for(int i = (a);i <= (b);i++)

#define all(A) A.begin(),A.end()

#define PI acos(-1)

#define pb push_back

#define mp make_pair

#define sz(A) ((int)A.size())

#define vi vector<int>

#define vl vector<long long>

#define vd vector<double>

#define vp vector<pair<int,int> >

#define ll long long

#define pi pair<int,int>

#define point pair<double,double>

#define pl pair<ll,ll>

#define popcnt(x) __builtin_popcount(x)

#define LSOne(x) ((x) & (-(x)))

#define xx first

#define yy second

#define PQ priority_queue

#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl

#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";

#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl

#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)

using namespace std;



vi G[101 * 2],rG[101*2];

int vis[101*2];

int ord[101*2],compID[101*2],e;





void addOrEdge(int a,int b){

	//cerr << (a^1) << " " << b << endl;

	//cerr << (b^1) << " " << a << endl;	

	G[a ^ 1].pb(b);

	G[b ^ 1].pb(a);

}



void addXorEdge(int a,int b){

	a <<= 1,b <<= 1;

	addOrEdge(a,b);

	addOrEdge(a | 1,b | 1);		

}



void addNotXorEdge(int a,int b){

	a <<= 1,b <<= 1;

	addOrEdge(a,b | 1);

	addOrEdge(a | 1,b);

} 



void dfs(int u){

	if(vis[u]) return;

	vis[u] = 1;

	for(int v : G[u]) dfs(v);

	ord[e++] = u;

}



void dfs(int u,int id){

	if(vis[u]) return;

	vis[u] = 1;

	compID[u] = id;

	for(int v : rG[u]) dfs(v,id); 

}



int main(){

	int n,m; scanf("%d %d",&n,&m);

	loop(i,m){

		int a,b,c; scanf("%d %d %d",&a,&b,&c);

		a--,b--;

		if(c) addNotXorEdge(a,b);

		else addXorEdge(a,b);

	}

	loop(i,2*n) dfs(i);

	loop(u,2*n){

		for(int v : G[u]) rG[v].pb(u);

	}



	memset(vis,0,sizeof vis);

	int ctr=  0;

	for(int i = 2*n-1;i>=0;i--) if(!vis[ord[i]]) {

		dfs(ord[i],++ctr);

	}

	

	for(int i = 0;i < 2*n;i += 2){

		if(compID[i] == compID[i | 1]){

			cout << "Impossible" << endl;

			return 0;

		}	

	}

	memset(vis,0,sizeof vis);

	vi ans ;

	loop(i,2*n){

		if(ord[i] & 1) vis[ord[i]] = 1;

		else if(!vis[ord[i] ^ 1]) ans.pb(ord[i]/2 + 1);

	}

	printf("%d\n",sz(ans));

	loop(i,sz(ans)) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);

	return 0;

}