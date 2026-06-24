#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define f first
#define s second

#define vec vector
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cerr << (#x) << " = " << (x) << endl

template<typename T>
int sz (T &a) {
    return (int)(a.size());
}

ll pw (int a) {
    return 1ll << a;
}

using pii = pair < int, int >;
using pll = pair < ll, ll >;

const int mod = 1e9 + 7;
const int N = 1e6;
const ll OO = 1e12;

template<typename T>
bool umn (T &fi, T se) { return fi > se ? (fi = se, 1) : 0; }

template<typename T>
bool umx (T &fi, T se) { return fi < se ? (fi = se, 1) : 0; }

int l[N], r[N], s[N];

void slv () {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> l[i];
    for (int i = 0; i < n; ++i)
        cin >> r[i];

    int all = 0;
    ll ans = OO;
    priority_queue < int, vec < int >,  greater < int >  > q;
    for (int i = 0; i < n; ++i) {
        all += r[i] - l[i] + 1;

        if (all >= k) {
            int add = max(0, k - (all - (r[i] - l[i] + 1)) - 1);

            ans = min(ans, l[i] + add + 2 * 1ll * sz(q) + 2);
        }

        while (sz(q) && all - q.top() >= k) {
            all -= q.top();
            q.pop();
            int add = max(0, k - (all - (r[i] - l[i] + 1)) - 1);
            ans = min(ans, l[i] + add + 2 * 1ll * sz(q) + 2);
        }
        q.push(r[i] - l[i] + 1);
    }

    cout << (ans == OO ? -1 : ans);

}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        slv();
        cout << "\n";
    }
}