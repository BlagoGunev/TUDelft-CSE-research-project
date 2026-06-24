#include<bits/stdc++.h>

using namespace std;

#define int long long

#define ll long long

#define vi vector<int> 

#define fi first

#define se second

#define pii pair<int,int>

#define pb push_back

#define all(v) v.begin(),v.end()

const double eps=1e-7;

const double pi=acos(-1);

const int N=1e5+5;

vi bad[N],good[N];

int pre[N];

int find(int x){

	return pre[x]==x?pre[x]:pre[x]=find(pre[x]);

}

int a[N],son[N],vis[N];

void dfs(int u){

	vis[u]=1;

	for(auto j:bad[u]){

		if(vis[j]==0) continue;

		a[u]++;

		if(!son[j]){

			a[j]++;

		}

		else{

			a[1]++;

			a[son[j]]--;

		}

	}

	for(auto j:good[u]){

		if(vis[j]) continue;

		son[u]=j;

		dfs(j);

	}

	son[u]=0;

}

void dfs1(int u,int fa){

	for(auto j:good[u]){

		if(j==fa) continue;

		a[j]+=a[u];

		dfs1(j,u);

	}

}

signed main(){

	ios::sync_with_stdio(false);cin.tie(0);

	int n,m;

	cin>>n>>m;

	vector<pii> v;

	for(int i=1;i<=m;i++){

		int x,y;

		cin>>x>>y;

		v.pb({x,y});

	}

	for(int i=1;i<=n;i++) pre[i]=i;

	for(auto [x,y]:v){

		int fx=find(x),fy=find(y);

		if(fx==fy){

			bad[x].pb(y);

			bad[y].pb(x);continue;

		}

		pre[fx]=fy;

		good[x].pb(y);

		good[y].pb(x);

	}

	dfs(1);

	dfs1(1,0);

	for(int i=1;i<=n;i++){

		if(a[i]==m-(n-1)) cout<<1;

		else cout<<0;

	}

	return 0;

}