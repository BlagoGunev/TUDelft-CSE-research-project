#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define ld long double

#define fi first

#define se second



int a[200005];



int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int tc;

    cin >> tc;

    while (tc--) {

    	vector<pair<int, int>> ans;

    	int n;

    	cin >> n;

    	for (int i = 1; i <= n; i++) cin >> a[i];

    	int sum = a[0], l = 1;

    	for (int i = 1; i <= n; i++) {

    		if (i == l) sum += a[i];

    		else if (sum == 0) {

    			if (a[i] == 0) {

    				ans.push_back({l, i});

    				l = i + 1;

    			}

    			else {

    				ans.push_back({l, i - 1});

    				sum += a[i];

    				l = i;

    			}

    		}

    		else if (sum == 1) {

    			if (a[i] == -1) {

    				sum--;

    				ans.push_back({l, i - 1});

    				ans.push_back({i, i});

    				l = i + 1;

    			}

    			else if (a[i] == 1) {

    				if (l < i - 1) {

    					sum--;

    					ans.push_back({l, i - 2});

    					ans.push_back({i - 1, i});

    					l = i + 1;

    				}

    				else {

    					sum--;

    					ans.push_back({l, i});

    					l = i + 1;

    				}

    			}

    		}

    		else {

    			if (a[i] == 1) {

    				sum++;

    				ans.push_back({l, i - 1});

    				ans.push_back({i, i});

    				l = i + 1;    				

    			}

    			else if (a[i] == -1) {

    				if (l < i - 1) {

    					sum++;

    					ans.push_back({l, i - 2});

    					ans.push_back({i - 1, i});

    					l = i + 1;

    				}

    				else {

    					sum++;

    					ans.push_back({l, i});

    					l = i + 1;

    				}    				

    			}

    		}

    	}

    	if (sum != 0) cout << -1 << "\n";

    	else {

    		if (ans.size() == 0) ans.push_back({1, n});

    		else if (ans.back().se != n) ans.push_back({l, n});

    		cout << ans.size() << "\n";

    		for (auto x : ans) cout << x.fi << " " << x.se << "\n";

    	}

    }

}