#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s1; cin >> s1;
	string s2; cin >> s2;
	s1 = "0" + s1;
	int len = (int) s1.size() - 1;
	s2 = "0" + s2;
	int t, q;
	cin >> t >> q;
	vector<vector<int>> unblock(q + 1);
	int diffcnt = 0;
	for(int i = 1; i <= len; i++) {
		diffcnt += (s1[i] != s2[i]);
	}
	for(int i = 1; i <= q; i++) {
		for(int p : unblock[i]) {
			diffcnt += (s1[p] != s2[p]);
		}
		int op; cin >> op;
		if(op == 3) {
			if(diffcnt == 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else if(op == 1) {
			int p; cin >> p;
			diffcnt -= (s1[p] != s2[p]);
			int tt = i + t;
			if(tt < unblock.size()) {
				unblock[tt].push_back(p);
			}
		} else if(op == 2) {
			int x1, x2, p1, p2;
			cin >> x1 >> p1 >> x2 >> p2;
			if(p1 == p2) {
				if(x1 == x2) {
					// donothing
				} else {
					swap(s1[p1], s2[p2]);
				}
			} else {
				if(x1 == x2) {
					diffcnt -= (s1[p1] != s2[p1]) + (s1[p2] != s2[p2]);
					if(x1 == 1) {
						swap(s1[p1], s1[p2]);
					} else {
						swap(s2[p1], s2[p2]);
					}
					diffcnt += (s1[p1] != s2[p1]) + (s1[p2] != s2[p2]);
				} else {
					diffcnt -= (s1[p1] != s2[p1]) + (s1[p2] != s2[p2]);
					if(x1 == 1) {
						// x1 == 1 && x2 == 2 && p1 != p2
						swap(s1[p1], s2[p2]);	
					} else {
						swap(s2[p1], s1[p2]);
					}
					diffcnt += (s1[p1] != s2[p1]) + (s1[p2] != s2[p2]);
				}
			}
		}
	}
	
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
	return 0;
}