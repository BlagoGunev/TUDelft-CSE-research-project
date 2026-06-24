#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

pair<int, int> a[500001];

bool csort1(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return 1;
	else if (a.first == b.first && a.second > b.second)
		return 1;
	return 0;
}

bool csort2(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)
		return 1;
	else if (a.second == b.second && a.first > b.first)
		return 1;
	return 0;
}

int Max[500001];

void solve() {
    int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1, csort1);
	Max[n] = a[n].second;
	for (int i = n - 1; i >= 1; i--)
		Max[i] = max(Max[i + 1], a[i].second);
	int Min = 2e9;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		int x;
		if (i == n)
			x = -1e9;
		else x = Max[i + 1];
		Min = min(Min, abs(a[i].first - x));
		if (s.size() != 0){
			auto it = s.lower_bound(a[i].first);
			if (it != s.end() && *it > x)
				Min = min(Min, abs(a[i].first - *it));
			if (it != s.begin()) {
				it--;
				if (*it > x) 
					Min = min(Min, abs(a[i].first - *it));
			}
		}
		s.insert(a[i].second);	
	}
	s.clear();
	sort(a + 1, a + n + 1, csort2);
	Max[n] = a[n].first;
	for (int i = n - 1; i >= 1; i--)
		Max[i] = max(Max[i + 1], a[i].first);
	for (int i = 1; i <= n; i++) {
		int x;
		if (i == n)
			x = -1e9;
		else x = Max[i + 1];
		Min = min(Min, abs(a[i].second - x));
		if (s.size() != 0){
			auto it = s.lower_bound(a[i].second);
			if (it != s.end() && *it > x)
				Min = min(Min, abs(a[i].second - *it));
			if (it != s.begin()) {
				it--;
				if (*it > x) 
					Min = min(Min, abs(a[i].second - *it));
			}
		}
		s.insert(a[i].first);	
	}
	cout << Min << '\n';
}

int main() {
    fast
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}