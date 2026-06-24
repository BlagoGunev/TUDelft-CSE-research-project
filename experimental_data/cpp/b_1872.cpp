#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--) {
		int n, ans = 1000;
		cin>>n;
		for(int i=0;i<n;++i) {
			int x,y;
			cin>>x>>y;
			ans = min(ans, x + y/2 + y%2);
		}
		cout<<ans-1<<endl;
	}
	return 0;
}