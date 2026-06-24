#include <bits/stdc++.h>

#define rep(a, b) for (num a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define many int t; cin >> t; while (t--)
#define yesno cout << (solve() ? "YES" : "NO") << '\n'
#define print cout << solve() << '\n'
#define call solve()

using namespace std;

using num = long long int;
using seq = vector<num>;
using par = pair<num,num>;
using Graph = vector<vector<num>>;
using WGraph = vector<vector<par>>;
template<typename T, typename U> istream& operator>>(istream& is, pair<T,U>& p) { return is >> p.first >> p.second; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }

void solve() {
    num x;
    cin >> x;
    // Can we express x as the sum of twice the zero bits?
    if (x & 1) {
        cout << -1 << '\n';
        return;
    }
    rep(i, 31) {
        if ((x & (1 << i)) && (x & (1 << (i+1)))) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << (x | (x >> 1)) << ' ' << (x >> 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    many call;
    return 0;
}