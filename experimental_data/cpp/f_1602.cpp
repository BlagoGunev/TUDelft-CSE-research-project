//#define _GLIBCXX_DEBUG

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//
//using namespace __gnu_pbds;
//
//template<typename T>
//using ordered_set = tree<T, null_type, less < T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using normal_queue = priority_queue<T, vector<T>, greater<>>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define trace(x) cout << #x << ": " << (x) << endl;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define uniq(x) x.resize(unique(all(x)) - begin(x))
#define ld long double
#define sz(s) ((int) size(s))
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define int128 __int128
#define pb push_back
#define eb emplace_back


template<typename T>
bool ckmn(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool ckmx(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

int bit(int x, int b) {
    return (x >> b) & 1;
}

int rand(int l, int r) { return (int) ((ll) rnd() % (r - l + 1)) + l; }

const ll infL = 3e18;
const int infI = 1000000000 + 7;
const int infM = 2139062143;
const ll infML = 9187201950435737471LL;
const int N = 200001;
const ll mod = 998244353;
const ld eps = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i][1] >> v[i][2];
        v[i][0] = max(v[i][1], v[i][2]);
    }
    sort(all(v));
    int ans = 0;
    for (auto to : v) {
        if (to[1] >= d) {
            ++ans;
            ckmx(d, to[2]);
        }
    }
    cout << ans;
    return 0;
}