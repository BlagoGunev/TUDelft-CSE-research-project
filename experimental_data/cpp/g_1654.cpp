#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
#define pc putchar
#define sp pc(' ')
#define en pc('\n')
#define gc getchar()
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define fs fflush(stdout)
#define ump unordered_map
#define pq priority_queue
#define clz __builtin_clz
#define ctz __builtin_ctz
#define sz(x) (int)x.size()
#define np next_permutation
#define clzl __builtin_clzll
#define par __builtin_parity
#define ctzl __builtin_ctzll
#define ppc __builtin_popcount
#define parl __builtin_parityll
#define all(x) x.begin(),x.end()
#define ppcl __builtin_popcountll
#define fpi(x) freopen(x,"r",stdin)
#define fpo(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define dbg(x) cerr<<"In Line "<<__LINE__<<' '<<#x<<'='<<(x)<<'\n'
template<class T> inline T &re(T &x){
	x=0;int f=1;char ch=gc;
	while(ch<48||ch>57){if(ch==45) f=-f;ch=gc;}
	while(ch>47&&ch<58) x=(x<<1)+(x<<3)+(ch^48),ch=gc;
	return x*=f;
}
template<class T> inline void pr(T x){
	static char buf[40];static int cnt=0;
	if(x<0) pc(45),x=-x;
	do buf[++cnt]=x%10^48;while(x/=10);
	do pc(buf[cnt--]);while(cnt);
}
#define mod 998244353
#define inf 0x3f3f3f3f
int a[200005],n,dis[200005],f[200005],g[200005];
vector<int> edge[200005],v[200005];
void bfs(){
	ms(dis,0x3f);queue<int> q;
	for(int i=1;i<=n;i++) if(a[i]) dis[i]=0,q.push(i);
	while(!q.empty()){
		int f=q.front();q.pop();
		for(int v:edge[f]) if(dis[v]>dis[f]+1) dis[v]=dis[f]+1,q.push(v); 
	}
}
int main(){
	re(n);int i,j;ms(g,0x3f);
	for(i=1;i<=n;i++) re(a[i]);
	for(i=1;i<n;i++){int u=re(u),v=re(v);edge[u].eb(v),edge[v].eb(u);}bfs();
	for(i=1;i<=n;i++) for(int j:edge[i]) if(dis[i]==dis[j]) v[dis[i]].eb(i);
	for(i=0;i<=n;i++) sort(all(v[i])),v[i].erase(unique(all(v[i])),v[i].end());
	for(i=0;i<=n;i++) if(!v[i].empty()){
		deque<int> q;ms(f,0x3f);
		for(int pos:v[i]) f[pos]=i+1,q.push_back(pos);
		while(!q.empty()){
			int u=q.front();q.pop_front();
			for(int v:edge[u]){
				if((dis[u]==dis[v]||(dis[u]<dis[v]&&f[u]==dis[u]))&&f[v]>f[u]+1) f[v]=f[u]+1,q.push_back(v);
				if(dis[u]<dis[v]&&f[u]>dis[u]&&f[v]>f[u]) f[v]=f[u],q.push_front(v);
			}
		}
		for(j=1;j<=n;j++) if(f[j]==dis[j]&&g[j]==inf) g[j]=i;
	}
	for(i=1;i<=n;i++){if(g[i]^inf) pr((dis[i]<<1)-g[i]);else pr(dis[i]);sp;}
	return 0;
}//fwho