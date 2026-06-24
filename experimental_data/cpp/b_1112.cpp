#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    k = min(k, n);
    vector<pair<int, int> > order(k);
    int p = 0;
    for (p = 0; p < k; p++) {
        order[p] = make_pair(1, p);
    }

    int m = 0;
    int ans = 0;
    vector<bool> used(n);
    while (m < n) {
        double q = floor(100.0 * ((double)m / (double)(n)) + 0.5);
        for (int i = 0; i < k; i++) {
			if (order[i].first == -1) continue;
            if (order[i].first == q && !used[order[i].second]) {
                used[order[i].second] = true;
                ans++;
            }
        }
        for (int i = 0; i < k; i++) {
			if (order[i].first == -1) continue;
			if (a[order[i].second] == order[i].first) {
                m++;
                if (p < n) {
                    order[i] = make_pair(1, p++);
                }
				else {
					order[i] = make_pair(-1, -1);
				}
            }
            else {
                order[i].first++;
            }
        }
    }
    cout << ans;
}