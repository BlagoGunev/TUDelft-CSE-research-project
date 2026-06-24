#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
int cas,n,k,a[200009];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n>>k;
		int sum=0;
		for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
		sort(a+1,a+1+n);
		for(int i=n;i;i--){
			int mx=(sum+k)/i;
			if(mx*i>=sum&&mx>=a[n]){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}