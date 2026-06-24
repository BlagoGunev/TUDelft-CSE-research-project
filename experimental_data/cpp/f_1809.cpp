#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	int a[n], b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	long long pos[n+1];
	pos[0]=0;
	for(int i=0;i<n;i++) pos[i+1]=pos[i]+a[i];
	vector<long long> ones;
	for(int i=0;i<n;i++) if(b[i]==1) ones.push_back(pos[i]);
	int s = ones.size();
	if(!s) {
		for(int i=0;i<n;i++) cout<<2*pos[n]<<" ";
		cout << "\n";
		return;
	}
	for(int i=0;i<s;i++) ones.push_back(pos[n]+ones[i]);
	ones.push_back(2*pos[n]+ones[0]);
	long long ans = 2 * pos[n];
	for(int i=0;i<s;i++) ans -= min(k*1LL,ones[i+1]-ones[i]);
	// step 1: calculate default answer (with wrap arounds)
	// step 2: calculate the amount lost.
	// This is defined as next - prev
	for(int i=0;i<n;i++) {
		auto it = lower_bound(ones.begin(),ones.end(),pos[n]+pos[i]);
		cout << ans + min(k*1LL,(*it) - (*(it-1))) - min(k*1LL,pos[n]+pos[i]-(*(it-1))) << " ";
	}
	cout << "\n";
}
main() {
	int t; cin >> t;
	while(t--) solve();
}