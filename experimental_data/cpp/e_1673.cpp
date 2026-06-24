#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



const int N=1<<20;

int n,k,a[N];

bitset<N> ans;



void upd(int l,int r){

	int res=0;

	for(int i=l+1;i<=r;++i)res+=a[i];

	if(res>=20||((ll)a[l]<<res)>=N)return;

	ans.flip(a[l]<<res);

}



bool B(int n,int m){

	if(!n)return 1;

	if(!m)return 0;

	--n,--m;

	return (n&m)==m;

}



int main(){

	ios::sync_with_stdio(0);cin.tie(0);

	cin>>n>>k;

	for(int i=0;i<n;++i)cin>>a[i];

	for(int l=1;l<=min(21,n-k);++l){

		if(l==n){upd(0,n-1);continue;}

		if(B(n-l-1,max(0,k-1)))upd(0,l-1),upd(n-l,n-1);

		if(l==n-1||!B(n-l-2,max(0,k-2)))continue;

		for(int i=l;i<=n-2;++i)upd(i-l+1,i);

	}

	bool flag=0;

	for(int i=N-1;i;--i)if(flag||ans[i])flag=1,cout<<ans[i];

	cout<<ans[0]<<'\n';

}