#include <bits/stdc++.h>
using namespace std;
using ll = long long;
main() {
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		int x[n], y[n];
		for(int i=0;i<n;i++) cin>>x[i]>>y[i];
		int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
		ll mnDst = 3e18;
		for(int i=0;i<n;i++) mnDst=min(mnDst,1LL*(x[i]-xt)*(x[i]-xt)+1LL*(y[i]-yt)*(y[i]-yt));
		if(mnDst<=1LL*(xs-xt)*(xs-xt)+1LL*(ys-yt)*(ys-yt)) cout<<"nO\n";
		else cout<<"YeS\n";
	}
}