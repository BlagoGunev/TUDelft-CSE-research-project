// LUOGU_RID: 156229797
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=1e5+5;
int ans[N];
bool b[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int n1=n;
	while(n1--) {
		int m;
		cin>>m;
		for(int i=2; i<=m; i++) b[i]=ans[i]=0;
		b[1]=ans[1]=1;
		int cnt=1;
		for(int i=2;i<=m;i++){
			int sum=i;
			if(b[sum]==false){
				while(sum<=m){
					ans[++cnt]=sum;
					b[sum]=1;
					sum*=2;
				}
			}
		}
		for(int i=1;i<=cnt;i++) cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}