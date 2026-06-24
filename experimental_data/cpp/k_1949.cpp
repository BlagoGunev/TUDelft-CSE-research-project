#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    pair <int, int> ns[3];
    ll sums[3] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> ns[i].first;
        ns[i].second = i;
    }
    sort(ns, ns + 3);
    ll sum = 0;
    vector <int> v(n + 1), id(n + 1);
    vector <ll> sp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll maxsum = (sum - 1) / 2;
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + v[i];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int currid = -1;
        for (int j = 0; j < 3 && currid == -1; j++) {
            if (ns[j].first == 0) {
                continue;
            }
            if (sums[j] + v[i] + sp[ns[j].first - 1] <= maxsum) {
                currid = j;
            }
        }
        if (currid == -1) {
            cout << "NO\n";
            return;
        }
        sums[currid] += v[i];
        ns[currid].first--;
        id[i] = ns[currid].second;
    }
    cout << "YES\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (id[j] == i) {
                cout << v[j] << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif // LOCAL
    int nrt = 1;
    cin >> nrt;
    while (nrt--) {
        solve();
    }
	return 0;
}