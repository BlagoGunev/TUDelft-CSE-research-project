#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e5+5,MAXM=60+5;
int T,n,ch[MAXN][2];
LL a[MAXN],b[MAXN],f[MAXN][MAXM],s[MAXN],top;
void dfs(int u) {
	for(int i=0;i<=60;++i) f[u][i]=a[u];
	if(ch[u][0]) {
		dfs(ch[u][0]);
		for(int i=60;i>=0;--i) {
			LL mx=2e18;
			for(int j=0;j<=i;++j) mx=min(mx,max(f[u][i-j],f[ch[u][0]][j]));
			f[u][i]=mx;
		}
	}
	if(ch[u][1]) {
		dfs(ch[u][1]);
		for(int i=60;i>=0;--i) {
			LL mx=2e18;
			for(int j=0;j<=i;++j) mx=min(mx,max(f[u][i-j],f[ch[u][1]][j]));
			f[u][i]=mx;
		}
	}
	for(int i=1;i<=60;++i) f[u][i]=min(f[u][i],(f[u][i-1]-1)/b[u]+1);
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;++i) ch[i][0]=ch[i][1]=0;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=n;++i) cin>>b[i];
		top=0;
		for(int i=1;i<=n;++i) {
			int k=top;
			while(k&&b[s[k]]>b[i]) --k;
			if(k) ch[s[k]][1]=i;
			if(k<top) ch[i][0]=s[k+1];
			s[++k]=i,top=k;
		}
		dfs(s[1]);
		for(int i=0;i<=60;++i) {
			if(f[s[1]][i]==1) {
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}