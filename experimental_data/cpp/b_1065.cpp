#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;cin >> n >> m;
	if(m==0){
		cout << n << " " << n << endl;
	}
	else{
		ll ans=0;
		for(ll i=1;i<=n;++i){
			if(i*(i-1)/2>=m){
				ans=n-i;
				break;
			}
		}
		cout << max(n-2*m,(ll)0) << " " << ans << endl;
	}
}