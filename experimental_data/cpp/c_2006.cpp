#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[400005],b[400005],ans;
int st[20][400005];
bool check2(int x){return x!=0&&x==(x&-x);}
bool check(int l,int r){
	int len=__lg(r-l+1);
	return check2(__gcd(st[len][l],st[len][r-(1<<len)+1]));
}
signed main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i) scanf("%lld",&b[i]);
		for(int i=1;i<n;++i)
			if(b[i]>b[i+1]) a[i]=b[i]-b[i+1];
			else a[i]=b[i+1]-b[i];
		ans=n;
		--n;
		for(int i=1;i<=n;++i) st[0][i]=a[i];
		for(int i=1;i<20;++i)
			for(int j=1;j+(1<<i)-1<=n;++j) st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<i-1)]);
//		for(int i=1;i<=n;++i) cout<<a[i]<<" ";
//		cout<<endl;
		for(int i=1,j=0;i<=n;++i){
			while(j<i&&check(j+1,i)) ++j;
			ans+=j;
//			cout<<i<<" "<<j<<endl;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0) ++cnt;
			else cnt=0;
			ans+=cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}