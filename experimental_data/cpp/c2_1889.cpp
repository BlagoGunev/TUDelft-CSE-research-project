#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void chmax(T& x,T y){x<y&&(x=y);}
template<typename T>inline void chmin(T& x,T y){x>y&&(x=y);}
const int inf=0x3f3f3f3f;
int t,n,m,K;
pair<int,int> a[200005];
unordered_map<int,int> dp[200005][12];
int calc(int l,int r,int p){
	l=max(l,p+1);
	return max(r-l+1,0);
}
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=m;++i) scanf("%d%d",&a[i].first,&a[i].second);
		sort(a+1,a+m+1,[&](pair<int,int> x,pair<int,int> y){return x.first==y.first?x.second<y.second:x.first<y.first;});
		dp[0][0][0]=0;
		for(int i=0;i<m;++i){
			for(int j=0;j<=K&&j<=i;++j){
				for(auto p:dp[i][j]){
					int k=p.first;
					if(!dp[i+1][j+1].count(k)) dp[i+1][j+1][k]=inf;
					chmin(dp[i+1][j+1][k],dp[i][j][k]);
					if(!dp[i+1][j].count(a[k].second<a[i+1].second?i+1:k)) dp[i+1][j][a[k].second<a[i+1].second?i+1:k]=inf;
					chmin(dp[i+1][j][a[k].second<a[i+1].second?i+1:k],dp[i][j][k]+calc(a[i+1].first,a[i+1].second,a[k].second));
				}
			}
		}
//		for(int i=1;i<=m;++i)
//			for(int j=0;j<=K&&j<=i;++j)
//				for(int k=0;k<=j;++k){
//					cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"]="<<dp[i][j][k]<<endl;
//				}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=K;++i)
			for(auto p:dp[m][i]) chmin(ans,p.second);
		printf("%d\n",n-ans);
		for(int i=0;i<=m;++i)
			for(int j=0;j<=11;++j) dp[i][j].clear();
	}
	return 0;
}