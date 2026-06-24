#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
    	int n;
		cin>>n;
		vector<ll> pref(n); 
		vector< vector<ll> > v(n, vector<ll>());
    	for (int i = 0; i < n; i++) {
			ll m, p;
			cin>>m>>p;
			if(m<n-1){
				pref[m+1]++;	
			} 
			v[m+1-1].push_back(p); 
		}
		if(n==0){
			cout<<0<<"\n";
		}else{
			for(int i = 1; i < n; i++) {
				pref[i] = pref[i] + pref[i - 1]; 
			}
			for(int i = 0; i < n; i++) {
				pref[i]-=i;
			}
			ll ans = 0;
			ll bal = 0;
			multiset<ll> m;
			for(int i = n-1; i >= 0; i--) {
	    		for(auto x:v[i]){
	    			m.insert(x);	
				}
				while(pref[i] + bal < 0){ 
					ans+=(ll)*m.begin();
					m.erase(m.begin());
					bal++; 
				}  
			}
			cout<<ans<<"\n";	
		}
    }
}
/*
1
3 26
10 12
1 4
10 11
*/