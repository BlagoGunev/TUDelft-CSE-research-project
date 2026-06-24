#include<bits/stdc++.h>
using namespace std;

#define int int64_t
#define pb push_back
#define st first
#define nd second
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int val = 0;
		bool tak = true;
		for(int i=0;i<n;i++) {
			int x;
			cin >> x;
			if((x|k)==k and tak) val|=x;
			else tak = false;
		}
		tak = true;
		for(int i=0;i<n;i++) {
			int x;
			cin >> x;
			if((x|k)==k and tak) val|=x;
			else tak = false;
		}
		tak = true;
		for(int i=0;i<n;i++) {
			int x;
			cin >> x;
			if((x|k)==k and tak) val|=x;
			else tak = false;
		}
		if(val==k) cout << "Yes\n";
		else cout << "No\n";
	}
}