#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dou double

double getdis(dou x1,dou y1,dou x2,dou y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve(){
	double px,py,ax,ay,bx,by;
	cin >> px >> py >> ax >> ay >> bx >> by;
	dou midx = (ax+bx)/2.0;
	dou midy = (ay+by)/2.0;
	cout << min({
		(dou)max(getdis(px,py,ax,ay),getdis(ax,ay,0.0,0.0)),
		(dou)max(getdis(px,py,bx,by),getdis(bx,by,0.0,0.0)),
		(dou)max({getdis(0.0,0.0,ax,ay),getdis(px,py,bx,by),getdis(ax,ay,midx,midy)}),
		(dou)max({getdis(0.0,0.0,bx,by),getdis(px,py,ax,ay),getdis(bx,by,midx,midy)}),
	}) << '\n';
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int t; cin >> t;
	cout<<fixed<<setprecision(10);
	while(t--){
		solve();
	}
	return 0;
}