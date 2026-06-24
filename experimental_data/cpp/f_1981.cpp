#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 25005
using namespace std;
vector<ll> op[N];
ll T,n,a[N],x,i,j,f[N][3864],ans;
const ll up = 3863;
inline void dfs(ll x){
	if(op[x].size()==0){
		for(ll i=1;i<=up;i++) f[x][i]=(i==a[x]?inf:0);
		return ;
	}
	if(op[x].size()==1){
		ll minx = inf;
		dfs(op[x][0]);
		for(ll i=1;i<=up;i++) if(i!=a[x]) minx = min(minx,f[op[x][0]][i]+i);
		for(ll i=1;i<=up;i++) f[x][i]=(i==a[x]?inf:min(minx,f[op[x][0]][i]));
		return ;
	}
	ll u1 = op[x][0],u2 = op[x][1],minx = inf,miny = inf;
	dfs(u1),dfs(u2);
	for(ll i=1;i<=up;i++) if(i!=a[x]) minx=min(minx,f[u1][i]+i),miny=min(miny,f[u2][i]+i);
	ll val = minx+miny;
	for(ll i=1;i<=up;i++) if(i!=a[x]) val=min(val,f[u1][i]+f[u2][i]+i);
	if(x==1) ans=min(ans,val);
	for(ll i=1;i<=up;i++) f[x][i]=(i==a[x]?inf:min(min(minx+f[u2][i],miny+f[u1][i]),val));
}
int main(){
	memset(f,0x3f,sizeof(f));
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		ans = inf;
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=2;i<=n;i++) cin>>x,op[x].push_back(i);
		dfs(1);
		for(i=1;i<=up;i++) ans=min(ans,f[1][i]+i);
		cout<<ans<<endl;
		for(i=1;i<=n;i++) for(j=1;j<=up;j++) f[i][j]=inf;
		for(i=1;i<=n;i++) op[i].clear();
	}
	return 0;
}