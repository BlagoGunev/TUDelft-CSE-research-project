#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int)(a).size()
template <typename KEY> using ve = std::vector<KEY>;

using namespace std;

typedef vector<int> vi;
const int mod = 1000 * 1000 * 1000;
const int INF = INT32_MAX;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

bool w(int n) {
    if (n % 10 == n / 60 / 10 && n % 60 / 10 == n / 60 % 10) return true;
    return false;
}

void solve() {
    string s; cin >> s;
    int n, h, m, q, k = 24 * 60, cnt = 0; cin >> n;
    h = (s[0] - '0') * 10 + (s[1] - '0'), m = (s[3] - '0') * 10 + s[4] - '0';
    q = h * 60 + m;
    if (w(q)) ++cnt;
    q = (q + n) % k;
    while (q != h * 60 + m) {
        if (w(q)) ++cnt;
        q = (q + n) % k;
    }
    cout << cnt << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}