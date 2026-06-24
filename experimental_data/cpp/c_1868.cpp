#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
const int N=3e5+10;
int f[N],cnt[N];
int pw[N],base[200][200];
int pre[200][N];
int n,m;

array<int,64> dfs(int x,int d){
	array<int,64> res={0};
	res[0]=1;
	if(x*pw[d+1]<=n&&x*pw[d+1]+pw[d+1]-1<=n){
		for(int i=0;i<=d+1;i++) res[i]=pw[i]%P;
		for(int i=0;i<128;i++) cnt[i]=(cnt[i]+base[d+1][i])%P;
	}
	else if(x*pw[d+1]>n&&x*pw[d+1]+pw[d+1]-1>n){
		for(int i=0;i<=d;i++) res[i]=pw[i]%P;
		for(int i=0;i<128;i++) cnt[i]=(cnt[i]+base[d][i])%P;
	}
	else{
		array<int,64> tmp1=dfs(x*2,d-1);
		array<int,64> tmp2=dfs(x*2+1,d-1);
		for(int i=1;i<64;i++) res[i]=(tmp1[i-1]+tmp2[i-1])%P;
		res[1]--;
		for(int i=0;i<64;i++) for(int j=0;j<64;j++){
			cnt[i+j+1]=(cnt[i+j+1]+(tmp1[i]%P)*(tmp2[j]%P))%P;
		}
	}
	return res;
}
int qpow(int x,int y){
	int res=1,base=x;
	while(y){
		if(y&1) res=res*base%P;
		base=base*base%P;
		y/=2;
	}
	return res;
}
void solve(){
	cin>>n>>m;
	int pos=upper_bound(pw+1,pw+64+1,n)-pw-2;
	for(int i=0;i<=2*pos+1;i++) cnt[i]=0;
	dfs(1,pos);
	int ans=0;
	for(int i=1;i<=2*pos+1;i++) ans=(ans+cnt[i]*pre[i][m]%P*qpow(m,n-i)%P)%P;
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pw[0]=pw[1]=1;
	for(int i=2;i<=64;i++) pw[i]=pw[i-1]*2;
	
	for(int i=1;i<=128;i++){
		for(int j=1;j<=1e5;j++){
			pre[i][j]=(pre[i][j-1]+j*(qpow(j,i)-qpow(j-1,i)+P)%P)%P;
		}
	}
	
	for(int k=1;k<=64;k++){
		for(int i=0;i<k;i++) for(int j=0;j<k;j++){
			base[k][i+j+1]=(base[k][i+j+1]+(pw[i]%P)*(pw[j]%P))%P;
		}
		for(int i=1;i<=2*k-1;i++) base[k][i]=(base[k][i]+2ll*base[k-1][i]%P)%P;
	}
	
	int _=1;
	cin>>_;
	while(_--) solve();
	return 0;
}
/*
10
17592186044416 1
35184372088832 1
70368744177664 1
140737488355328 1
281474976710656 1
562949953421312 1
1125899906842624 1
2251799813685248 1
4503599627370496 1
9007199254740992 1

3
2251799813685246 1
2251799813685247 1
2251799813685248 1

1
137438953471 1
68719476735 1
274877906944 1
549755813888 1

68719476736 1
8589934592 1
1073741824 1
4294967296 1
1099511627776 1

1
1099511627776 1

1
4095 1
11111111111111 1



1
332582601390102672 100000
*/