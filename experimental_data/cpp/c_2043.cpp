#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <cmath>
#include <unordered_map>
#include <iomanip>

using namespace std;
template <typename T, typename Y>
ostream& operator<<(ostream &out, pair <T, Y> &a) {
    cout << a.first << ' ' << a.second << '\n';
    return out;
}

#define int long long
template <typename T>
ostream& operator<<(ostream &out, vector <T> &a) {
    for (auto &i : a) cout << i << ' ';
    cout << '\n';
    return out;
}
void deb_out() { cerr << endl; }
template <typename Head, typename... Tail> void deb_out(Head H, Tail... T) {
  cerr << " " << H;
  deb_out(T...);
}
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", deb_out(__VA_ARGS__)

signed main() {
    int t, n, m, k;
    cin >> t;
    while (t--) {
        k = 0;
        cin >> n;
        vector <int> a(n);
        set <int> ans;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (abs(a[i]) != 1) k = i;
        }
        int mn = 0, mx = 0, resmx = 0, resmn = 0, cur = 0;
        for (int i = 0; i < k; i++) {
            cur += a[i];
            resmx = max(cur - mn, resmx);
            resmn = min(cur - mx, resmn);
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        for (int i = resmn; i <= resmx; i++) ans.insert(i);
        mn = 0, mx = 0, resmx = 0, resmn = 0, cur = 0;
        for (int i = k + 1; i < n; i++) {
            cur += a[i];
            resmx = max(cur - mn, resmx);
            resmn = min(cur - mx, resmn);
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        for (int i = resmn; i <= resmx; i++) ans.insert(i);
        mn = 0, mx = 0, resmx = 0, resmn = 0, cur = 0;
        for (int i = k - 1; i > -1; i--) {
            cur += a[i];
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        for (int i = resmn; i <= resmx; i++) ans.insert(i);
        resmx = 0, resmn = 0, cur = 0;
        for (int i = k + 1; i < n; i++) {
            cur += a[i];
            resmx = max(resmx, cur);
            resmn = min(resmn, cur);
        }
        for (int i = a[k] + mn + resmn; i <= resmx + a[k] + mx; i++) ans.insert(i);
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << " ";
        cout << '\n';
    }
}