#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,mod=998244353;
#define A(x,y) x=(x+y)%mod
int t,n,a[N];
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=2*n;i++)cin>>a[i];
		sort(a+1,a+2*n+1);int asw=0;
		for(int i=n;i;i--)asw+=a[2*i-1];
		cout<<asw<<"\n";
	}
}