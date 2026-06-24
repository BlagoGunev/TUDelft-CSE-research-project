#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);
 
#define inf (int)1e9+7
 
#define F first
#define S second
 
#define pb push_back
#define ppb pop_back
 
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
 
#define sz(x) x.size()
 
#define all(x) x.begin(),x.end()
 
#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define int ll

using namespace std;

void solve(){

	int l, r, a;
	cin >> l >> r >> a;
	
	if(a > r || a == 1){
		cout << r << '\n';
		return;
	}
	
	int ans = -inf;
	int u = a, lq = 1, rq = r;
	
	while(lq <= rq){
		int md = (lq + rq) / 2;
		if(u * md <= r){
			lq = md + 1;
		}
		else{
			rq = md - 1;
		}
	}
	
	u = u * (lq - 1);
	if(u - 1 >= l){
		u--;
		ans = (floor((double)u / a)) + (u % a);
	}
	
	ans = max(ans, (ll)(floor((double)r / a)) + (r % a));
	
	cout << ans << '\n';
	
}

main(){
	
	NFS

	int tt;
	cin >> tt;
	
	while(tt--){
		solve();
	}
	
	ioi
}