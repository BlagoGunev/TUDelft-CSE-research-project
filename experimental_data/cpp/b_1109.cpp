//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define pb push_back
#define F first
#define S second
#define lll long long
#define lld long double

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N = 3e5;
const int M = 1e9 + 83;
const int M2 = 1e9 + 7;
const int MM = 1e9 + 7;
const int mod = 998244353;
const int rx[8] = {1, 1, -1, -1, -2, -2, 2, 2};
const int ry[8] = {-2, 2, -2, 2, 1, -1, 1, -1};
const lld eps = 1e-8;
const double pi = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("dictionary.in", "r", stdin);
//    freopen("dictionary.out", "w", stdout);
#endif
    string t, s, now;
    cin >> t;
    int f = 0, mem = 0;
    int n = int(t.size());
    for (int i = 1; i < n / 2; ++i) {
        if (t[i] != t[0]) {
            f = 1;
        }
    }
    if (!f) {
        cout << "Impossible";
        return 0;
    }
    int k = 0;
    f = 0;
    for (int len = 1; len <= n / 2; ++len) {
        now += t[len - 1];
        s = now;
        reverse(s.begin(), s.end());
        if (now != s) {
            continue;
        }
        if ((n / 2) % len) {
            continue;
        }
        f = 0;
        for (int i = len; i < (n / 2); ++i) {
            if (t[i] != t[i % len]) {
                f = 1;
                break;
            }
        }
        if (!f) {
            mem = 1;
        }
        if (!f && len % 2 == 0) {
            k = 1;
            break;
        }
        if (!f) {
            break;
        }
    }
    if (!mem || (n % 2)) {
        cout << 1 + (n % 2);
    } else {
        cout << 2 - k;
    }
    return 0;
}