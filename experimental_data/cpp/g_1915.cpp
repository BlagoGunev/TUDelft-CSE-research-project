// Problem: G. Bicycles
// Contest: Codeforces - Codeforces Round 918 (Div. 4)
// URL: https://codeforces.com/contest/1915/problem/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Genshin Impact launch
// ZYB TXDY
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define INF 0x7fffffff
#define MAXN 1005
#define eps 1e-9
#define foru(a,b,c)	for(int a=b;a<=c;a++)
#define RT return 0;
#define LL long long
#define LXF int
#define RIN rin()
#define HH printf("\n")
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
inline LXF rin(){
	LXF x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){ 
	if(ch=='-') w=-1;
	ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
	x=x*10+(ch-'0');
	ch=getchar();
	}
	return x*w;
}
int n,m;
int s[MAXN],rs[MAXN];
vector<int> ls;
LL dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<int,LL>> e[MAXN];
priority_queue<pair<LL,pair<int,int>>,vector<pair<LL,pair<int,int>>>,greater<pair<LL,pair<int,int>>>> q;
signed main(){
	int T=RIN;
	while(T--){
		n=RIN,m=RIN;
		foru(i,1,n){
			e[i].clear();
		}
		foru(i,1,m){
			int u=RIN,v=RIN,w=RIN;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		ls.clear();
		foru(i,1,n){
			s[i]=RIN;
			ls.push_back(s[i]);
		}
		ls.push_back(-100);
		sort(all(ls));
		ls.erase(unique(all(ls)),ls.end());
		foru(i,1,ls.size()-1){
			rs[ls[i]]=i;
			// cout<<ls[i]<<endl;
		}
		foru(i,1,n){
			foru(j,1,n){
				vis[i][j]=0;
				dis[i][j]=LLONG_MAX;
			}
		}
		dis[1][rs[s[1]]]=0;
		q.push({0,{1,rs[s[1]]}});
		while(!q.empty()){
			auto [ds,u]=q.top();
			q.pop();
			if(vis[u.fi][u.se])	continue;
			vis[u.fi][u.se]=1;
			for(auto [v,w]:e[u.fi]){
				int nrs=min(u.se,rs[s[v]]);
				if(dis[v][nrs]>dis[u.fi][u.se]+w*ls[u.se]){
					dis[v][nrs]=dis[u.fi][u.se]+w*ls[u.se];
					if(!vis[v][nrs]){
						q.push({dis[v][nrs],{v,nrs}});
					}
				}
			}
		}
		LL ans=LLONG_MAX;
		foru(i,1,ls.size()-1){
			ans=min(ans,dis[n][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}