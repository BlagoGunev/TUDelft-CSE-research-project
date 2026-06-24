#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define lowbit(x) ((x)&-(x))
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod =1e9+7,N=2e5+10;

void solve(){
	ll a,b,c,d;	cin >> a >> b >> c >> d;
	if (a > b * c) return cout << "-1\n",void();
	ll x=a/b/d+1;
	ll ans = max(a,a*x-b*x*(x-1)/2*d);
	cout << ans << endl;
}
/*

*/
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
return 0;
}