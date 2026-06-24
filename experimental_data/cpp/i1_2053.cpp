#ifdef LOCAL
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> //gp_hash_table
// using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define fora(x, o) for(auto& x : o)
#define bitat(x, i) (((x)>>(i))&1)

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vll = vector<ll>;

template<class T, class U> istream& operator>>(istream &is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& vec) { for(auto &x : vec) cin >> x; return is; } 
template<class T, class U> ostream& operator<<(ostream &os, const pair<T, U>& p) { os << "<" << p.first << "," << p.second << ">"; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for(auto x : vec) os << x << " "; return os; }

void solve() {
    int n;
    cin >> n;

    vll arr(n); cin >> arr;

    ll tot = accumulate(all(arr), 0ll);

    ll l = 0, r = 0, b = 0;
    for (int i = 0; i < n; i++) {
        l += arr[i], r += arr[i];
        if (l > tot) {
            l = arr[i], r = tot, b++;
        }
        else if (r < 0) {
            l = 0, r = tot + arr[i], b++;
        }
        l = max(l, 0ll);
        r = min(r, tot);
    }
    // cerr << "tot: " << tot << endl;
    cout << b + n + (r < tot) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t; cin >> t; while (t--)
    solve();

    return 0;
}