#include<bits/stdc++.h>
     
    using namespace std;
     
    #define fore(i, l, r) for(int i = int(l); i < int(r); i++)
    #define sz(a) int((a).size())
     
    typedef long long li;
     
    // S = sum a_i - sum b_i
    // if Bob made all steps: then S = 0 - sum (b_i - 1)
    // each Alice step: S += (a_i - 1) + (b_i - 1) i. e. the bigger (a_i + b_i) the better
     
    int n;
    vector<int> a, b;
     
    inline bool read() {
    	if(!(cin >> n))
    		return false;
    	a.resize(n);
    	b.resize(n);
    	fore (i, 0, n)
    		cin >> a[i];
    	fore (i, 0, n)
    		cin >> b[i];
    	return true;
    }
     
    inline void solve() {
    	vector<int> ids(n);
    	iota(ids.begin(), ids.end(), 0);
    	
    	sort(ids.begin(), ids.end(), [&](int i, int j) {
    		return a[i] + b[i] > a[j] + b[j];
    	});
    	
    	li S = 0;
    	fore (i, 0, n) {
    		if (i & 1)
    			S -= b[ids[i]] - 1;
    		else
    			S += a[ids[i]] - 1;
    	}
    	cout << S << endl;
    }
     
    int main() {
    #ifdef _DEBUG
    	freopen("input.txt", "r", stdin);
    	int tt = clock();
    #endif
    //	ios_base::sync_with_stdio(false);
    //	cin.tie(0), cout.tie(0);
    	cout << fixed << setprecision(15);
    	int t;
    	cin >> t;
    	for(int i = 0; i < t; i++)
    	{
    	if(read()) {
    		solve();
    		
    #ifdef _DEBUG
    		cerr << "TIME = " << clock() - tt << endl;
    		tt = clock();
    #endif
    	}
    	}
    	return 0;
    }