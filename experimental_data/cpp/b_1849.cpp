#include "bits/stdc++.h"

#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define len(a) (int)a.size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const double EPS = 1e-10;
const ll INF = 1e+17;
const ll MOD = 998244353;
const int MAXI = 1e9 + 100;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MY_DEBUG
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(all(a), [&](pair<int, int> p, pair<int, int> q) {
           int p1 = p.first % k ? p.first % k : k;
           int q1 = q.first % k ? q.first % k : k;
           if (p1 != q1)
               return p1 > q1;
           return p.second < q.second;
        });
        for (auto [val, idx] : a)
            cout << idx + 1 << " ";
        cout << endl;
    }
}