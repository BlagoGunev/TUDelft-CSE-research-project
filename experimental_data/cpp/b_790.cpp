#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional> 

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep0(i,n) for(register int (i)=0;(i)<(n);++(i))
#define rep(i,st,ed) for(register int (i)=(st);(i)<=(ed);++(i))
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> inline T qmin(const T a,const T b) {return a<b?a:b;}
template<typename T> inline T qmax(const T a,const T b) {return a>b?a:b;}
template<typename T> inline void getmin(T &a,const T b) {if(a>b) a=b;}
template<typename T> inline void getmax(T &a,const T b) {if(a<b) a=b;}

inline void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=1e9+7;
const ll linf=1e17+7;
const int N=4e5+7,M=N<<1;

int v[M],nxt[M],head[N];
ll f[N][7],num[N][7],ans;
int n,k;

il void addedge(int p,int x,int y){
	v[p]=y,nxt[p]=head[x],head[x]=p;
}

il int calc(int x){
	return (x+k-1)/k;
}

il void dfs(int u,int par){
	ll tot=0;
	num[u][0]=1;
	for(int e=head[u];e;e=nxt[e]){
		int t0=0,t1=0,t2=0;
		if(v[e]==par) continue;
		dfs(v[e],u);
		//
		for(int i=0;i<k;++i){
			ll f1=f[u][i],n1=num[u][i];
			if(!n1) continue;
			for(int j=0;j<k;++j){
				ll f2=f[v[e]][j],n2=num[v[e]][j];
				if(!n2) continue;
				ans+=f1*n2+f2*n1+n1*n2*calc(i+j+1);
			//	tot+=f1+f2+n1*n2*calc(i+j+1); 
			//	if(!j) t0+=f1+f2+n1*n2*calc(i+j+1);
			//	else if(j==1) t1+=f1+f2+n1*n2*calc(i+j+1);
			//	else t2+=f1+f2+n1*n2*calc(i+j+1);
			}
		}
	/*	if(u==2){
			for(int i=0;i<k;++i) cerr<<i<<": "<<f[u][i]<<" "<<num[u][i]<<endl;
			cerr<<"v="<<v[e]<<"  ans="<<tot<<" "<<t0<<" "<<t1<<" "<<t2<<endl;
		}
	*/	//
		f[u][0]+=f[v[e]][k-1]+num[v[e]][k-1];
		num[u][0]+=num[v[e]][k-1];
		for(int i=1;i<k;++i){
			f[u][i]+=f[v[e]][i-1];
			num[u][i]+=num[v[e]][i-1];
		}
	}
//	cerr<<u<<" is "<<tot<<endl;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(lch(i),x,y);
		addedge(rch(i),y,x);
	} 
	dfs(1,-1);
	printf("%I64d\n",ans);
	return 0;
}