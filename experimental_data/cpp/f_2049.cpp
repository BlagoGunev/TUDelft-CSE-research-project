#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define lb(x,y) lower_bound(all(x),y)-begin(x)

mt19937 rng;

vector<int> part(vector<int> a, vector<pair<int, int>> queries, int K) {
	int N = sz(a);
	vector<int> group(N, -1);
	vector<map<int, int>> freq;
	vector<int> left, right;
	map<int, int> freqRange;
	for (int i = 0; i < N; i++) {
		if (a[i] >= K) continue;
		int j = i;
		while (j + 1 < N && a[j + 1] < K) j++;
		map<int, int> mp;
		for (int k = i; k <= j; k++) {
			group[k] = sz(freq);
			mp[a[k]]++;
		}
		freq.pb(mp);
		left.pb(i);
		right.pb(j);
		if (sz(mp) == K) freqRange[j - i + 1]++;
		i = j;
	}
	vector<int> res;
	for (auto &p : queries) {
		int i = p.first, k = p.second;
		if (a[i] < K) {
			if (sz(freq[group[i]]) == K) {
				int n = right[group[i]] - left[group[i]] + 1;
				freqRange[n]--;
				if (!freqRange[n]) freqRange.erase(n);
			}
			freq[group[i]][a[i]]--;
			if (!freq[group[i]][a[i]]) freq[group[i]].erase(a[i]);
			a[i] += k;
			if (a[i] < K) {
				freq[group[i]][a[i]]++;
				if (sz(freq[group[i]]) == K) freqRange[right[group[i]] - left[group[i]] + 1]++;
			} else {
				int g = group[i];
				int l = left[g], r = right[g];
				int l1 = l, r1 = i - 1, l2 = i + 1, r2 = r;
				if (i - l > r - i) {
					swap(l1, l2);
					swap(r1, r2);
				}
				map<int, int> mp;
				int g2 = sz(freq);
				for (int j = l1; j <= r1; j++) {
					mp[a[j]]++;
					freq[g][a[j]]--;
					if (!freq[g][a[j]]) freq[g].erase(a[j]);
					group[j] = g2;
				}
				left[g] = l2;
				right[g] = r2;
				freq.pb(mp);
				left.pb(l1);
				right.pb(r1);
				if (left[g] <= right[g]) {
					if (sz(freq[g]) == K) freqRange[right[g] - left[g] + 1]++;
				}
				if (left[g2] <= right[g2]) {
					if (sz(freq[g2]) == K) freqRange[right[g2] - left[g2] + 1]++;
				}
			}
		}
		res.pb(freqRange.empty() ? 0 : prev(freqRange.end())->first);
	}
	return res;
}

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < a.size(); i++) cin >> a[i];
    vector<pair<int, int>> queries;
    for (int q = 0; q < Q; q++) {
    	int i, k; cin >> i >> k; i--;
    	queries.pb({i, k});
    }
    vector<int> res(Q, 0);
    for (int i = 0; i < 17; i++) {
    	vector<int> p = part(a, queries, 1 << i);
    	for (int j = 0; j < Q; j++) {
    		res[j] = max(res[j], p[j]);
    	}
    }
    for (int i : res) cout << i << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}