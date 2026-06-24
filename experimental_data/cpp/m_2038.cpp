//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define double long double
#define N 5010
using namespace std;
int num[21][3]={
{0,0,5},{0,1,4},{0,2,3},{0,3,2},{0,4,1},{0,5,0},
{1,0,4},{1,1,3},{1,2,2},{1,3,1},{1,4,0},
{2,0,3},{2,1,2},{2,2,1},{2,3,0},
{3,0,2},{3,1,1},{3,2,0},
{4,0,1},{4,1,0},
{5,0,0}};
int C[60][6];
int n,cnt=0,sum[N],sum2[N];
double f[N][35],g[N][35];
vector<int> st[N],vt[N];
vector<pair<int,int> > nt[N];
map<int,int> id0;
map<vector<int>,int> idx;
int getid(int x,int y,int z){return id0[x*100+y*10+z];}
void work(int x,int s,vector<int> v){
	if(x==n){
		sum[cnt]=s;
		sum2[cnt]=0;
		for(auto i:v) sum2[cnt]+=num[i][1];
		st[cnt]=v;
		idx[v]=cnt++;
		return;
	}
	for(int i=(v.empty()?0:v.back());i<21;i++) if(s+num[i][0]<=5){
		vector<int> nv=v;
		nv.push_back(i);
		work(x+1,s+num[i][0],nv);
	}
	return;
}
void dfs0(int id,int x,vector<int> v){
	if(x==n){
		vector<int> nw;
		for(int i=0;i<n;i++) nw.push_back(getid(v[i*3],v[i*3+1],v[i*3+2]));
		sort(nw.begin(),nw.end());
		vt[id].push_back(idx[nw]);
		return;
	}
	while(v[x*3]>=0){
		dfs0(id,x+1,v);
		v[x*3]--,v[x*3+2]++;
	}
	return;
}
void dfs1(int id,int x,int s,vector<int> v){
	if(x==n){
		vector<int> nw;
		int coef=1;
		for(int i=0;i<n;i++){
			nw.push_back(getid(v[i*3],v[i*3+1],v[i*3+2]));
			coef*=C[num[st[id][i]][1]][v[i*3+1]];
		}
		sort(nw.begin(),nw.end());
		nt[id].push_back(make_pair(idx[nw],coef));
		return;
	}
	while(v[x*3+1]>=0&&s<=5){
		dfs1(id,x+1,s,v);
		v[x*3+1]--,v[x*3]++,s++;
	}
	return;
}
double getg(int x,int y);
double getf(int x,int y){
	if(f[x][y]>-100) return f[x][y];
	f[x][y]=1e18;
	vector<int> v=st[x];
	bool ok=false;
	for(auto i:v){
		if(num[i][0]==5) return f[x][y]=0;
		if(num[i][2]==0) ok=true;
	}
	if(!ok) return f[x][y];
	for(auto u:vt[x]) f[x][y]=min(f[x][y],getg(u,y)+1);
	return f[x][y];
}
double getg(int x,int y){
	if(g[x][y]>-100) return g[x][y];
	if(sum[x]+sum2[x]+y<5) return 1e18;
	g[x][y]=0;
	for(auto [u,c]:nt[x]){
		int req=5-sum[x];
		if(y<req-(sum[u]-sum[x])) continue;
		int coef=C[y][req-(sum[u]-sum[x])]*c;
		g[x][y]+=(double)coef/(double)C[y+sum2[x]][req]*getf(u,y-(req-(sum[u]-sum[x])));
	}
	return g[x][y];
}
int main(){
	for(int i=0;i<60;i++){
		C[i][0]=1;
		for(int j=1;j<=i&&j<=5;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	cout<<fixed<<setprecision(12);
	for(int i=0;i<21;i++) id0[num[i][0]*100+num[i][1]*10+num[i][2]]=i;
	cin>>n;
	work(0,0,vector<int>{});
	for(int i=0;i<cnt;i++){
		vector<int> v;
		for(int j=0;j<n;j++){
			v.push_back(num[st[i][j]][0]);
			v.push_back(num[st[i][j]][1]);
			v.push_back(num[st[i][j]][2]);
		}
		dfs0(i,0,v);
		dfs1(i,0,sum[i],v);
	}
	for(int i=0;i<cnt;i++) for(int j=0;j<=n*8;j++) f[i][j]=g[i][j]=-114514;
	vector<int> v(n,getid(0,5,0));
	cout<<getg(idx[v],n*8)<<'\n';
	return 0;
}