#include<bits/stdc++.h>
using namespace std;

const int N=5010;

struct city{
	int a,b,c;
}ct[N];

struct node{
	int tm,val;
	bool operator < (const node &t) const{
		return tm<t.tm;
	}
}nd[N];

int n,m,k; 

int dp[N][N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>ct[i].a>>ct[i].b>>ct[i].c;
		nd[i]={i,ct[i].c};
	}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		nd[v].tm=max(nd[v].tm,u);
	}
	sort(nd+1,nd+1+n);
	int cnt=1;
	memset(dp,0xf0,sizeof(dp));
	for(int i=0;i<=k;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=ct[i].a;j<=5000;j++)
			dp[i][j+ct[i].b]=max(dp[i][j+ct[i].b],dp[i-1][j]);
		while(cnt<=n&&nd[cnt].tm==i){
			for(int j=0;j<=5000;j++)
				dp[i][j]=max(dp[i][j],dp[i][j+1]+nd[cnt].val);
			cnt++;
		}
	}
	int ans=-1;
	for(int i=0;i<=5000;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans;
	return 0;
}