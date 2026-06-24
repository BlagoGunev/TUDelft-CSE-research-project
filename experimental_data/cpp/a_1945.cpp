#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll INF = LLONG_MAX, MOD = 1e9 + 7, P = 239;
const ld PI = 3.1415926535897938462643383279502, EPS = 1e-7;

template <typename T>
inline ll sz(const T &a) {
    return a.size();
}

template <typename T, typename C>
istream &operator >> (istream &in, pair<T, C> &a) {
    return in >> a.first >> a.second;
}

template <typename T, typename C>
ostream &operator << (ostream &out, pair<T, C> a) {
    return out << a.first << ' ' << a.second;
}

template <typename T>
istream & operator >> (istream &in, vector<T> &a) {
    for (auto &i : a) {
        in >> i;
    }
    return in;
}

template <typename T>
ostream &operator << (ostream &out, vector<T> a) {
    for (auto i : a) {
        out << i << ' ';
    }
    return out;
}

template <typename T>
void print(vector<T> a, string c = "\n") {
    for (T i : a) {
        cout << i << c;
    }
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c < (3 - b % 3) % 3) {
        return void(cout << -1);
    }
    cout << a + (b + c + 2) / 3;
}

signed main() {
#ifdef LOCAL
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);

    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int times = 1;
    cin >> times;
    while (times--)
        solve(), cout << '\n';

#ifdef LOCAL
    auto end_time = clock();
    cerr << setprecision(3) << fixed << "Execution time: " << (end_time - start_time) * (int) 1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}