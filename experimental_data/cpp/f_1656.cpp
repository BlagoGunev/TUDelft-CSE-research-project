#include<bits/stdc++.h>

using namespace std;

#define int long long

#define For(i,j,k) for(int i=(j);i<=(k);i++)

#define Rof(i,j,k) for(int i=(j);i>=(k);i--)

int n,a[200010];

void work(){

	cin>>n;

	For(i,1,n) cin>>a[i];

	sort(a+1,a+n+1);

	int sum=0;

	For(i,1,n) sum+=a[i];

	if((n-2)*a[n]+sum<0||(n-2)*a[1]+sum>0){cout<<"INF"<<endl;return;}

	int now=(1-n)*a[n]*a[n],k=(n-2)*a[n]+sum,mx=now;

	Rof(i,n-1,1){

		now+=k*(a[i+1]-a[i]);

		mx=max(mx,now);

		k+=a[1]-a[n];

	}

	cout<<mx<<endl;

}

signed main(){

	ios::sync_with_stdio(false);cin.tie(0);

	int T;cin>>T;

	while(T--) work();

}