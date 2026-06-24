#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<tuple>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<deque>
#include<cassert>

using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,sse4")

#define ll long long
#define int ll
#define itn int
#define X first
#define Y second
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define ld long double

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
    for (auto &item : arr) in >> item;
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    for (auto &item : arr) out << item << ' ';
    return out;
}

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxn = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k >= n - 1) {
        cout << 1 << '\n';
    } else {
        cout << n << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    int ttt = 1;
    cin >> ttt;
    while (ttt--) {
        solve();
    }
#ifdef LOCAL
    auto end = chrono::high_resolution_clock::now();
    cerr << "TIME: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
#endif
}