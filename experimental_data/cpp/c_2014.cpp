#include<bits/stdc++.h>
#define int long long
#define rep(i,x,n) for(int i=x;i<=n;i++)
using namespace std; 

const int N = 2e5+10,mod = 1e9+7;

int t,n,k,x;
int a[N];

main() {
	for(cin >> t;t--;) {
	    cin >> n;
	    int s=0;
	    rep(i,1,n) cin >> a[i],s+=a[i];
	    sort(a+1,a+n+1);
	    int ans=0,p=n/2+1;
	    ans = a[p]*n*2-s+1;
	    if(ans<0) ans=0;
	    if(p>=n) ans=-1;
	    cout << ans << "\n";
	}
}