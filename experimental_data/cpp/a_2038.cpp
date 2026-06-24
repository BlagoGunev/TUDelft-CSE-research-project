#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
const int mod = 998244353, N = 100007;

int n;
ll k,a[N],b[N],res[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n; ++i) cin >> b[i];
	for(int i=0; i<n; ++i) res[i]=a[i]/b[i];
	ll tot=0;
	for(int i=0; i<n; ++i) tot+=res[i];
	if(tot<k){
		for(int i=0; i<n; ++i){
			cout << 0;
			if(i+1<n) cout << ' ';
			else cout << '\n';
		}
		return 0;
	}
	for(int i=0; i<n; ++i){
		ll x=min(tot-k,res[i]);
		tot-=x,res[i]-=x;
	}
	for(int i=0; i<n; ++i){
		cout << res[i];
		if(i+1<n) cout << ' ';
		else cout << '\n';
	}
}