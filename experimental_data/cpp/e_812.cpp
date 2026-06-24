#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)	for(int i=j;i<=n;i++)
#define down(i,j,n)	for(int i=j;i>=n;i--)
#define cmax(a,b)	a=max(a,b)
#define cmin(a,b)	a=min(a,b)

const int MAXN=2e5+5;

int mark[20000005],N,fa[MAXN],a[MAXN],deg[MAXN],now=0,tag[MAXN];
deque<int>q;
ll ans=0,cnt=0;

namespace solution{
	void Prepare(){
		scanf("%d",&N);
		up(i,1,N)scanf("%d",&a[i]);
		up(i,2,N){
			scanf("%d",&fa[i]);
			deg[fa[i]]++;
		}
		up(i,1,N)if(!deg[i]){
			q.push_back(i);
			tag[i]=0;
		}
	}
	void Solve(){
		while(!q.empty()){
			int node=q.front();q.pop_front();
			if(!tag[node]){
				now^=a[node];
				mark[a[node]]++;
				cnt++;
			}
			if(!--deg[fa[node]]){
				q.push_back(fa[node]);
				tag[fa[node]]=tag[node]^1;
			}
		}
		if(!now)ans=cnt*(cnt-1)/2+(N-cnt)*(N-cnt-1)/2;
		up(i,1,N)if(tag[i])ans+=mark[a[i]^now];
		cout<<ans<<endl;
	}
}

int main(){
	//freopen("input.in","r",stdin);
	using namespace solution;
	Prepare();
	Solve();
	return 0;
}