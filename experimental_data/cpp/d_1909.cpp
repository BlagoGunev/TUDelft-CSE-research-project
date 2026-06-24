#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define FOR(i, x, n) for(LL i = x; i < n; i++)
#define F0R(i, n) FOR(i, 0, n)
#define ROF(i, x, n) for(LL i = n - 1; i >= x; i--)
#define R0F(i, n) ROF(i, 0, n)

#define WTF cout << "WTF" << endl

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define EP emplace_back

#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x,rend()

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int LOG = 22;
const int A = 26;
const int SQ = 320;
const int MOD = 1e9 + 7;

LL n, k;
LL ns[N];

void solve() {
    cin >> n >> k;

    bool small = 0, big = 0, eq = 0;
    bool ne = 0;
    F0R(i, n) {
        cin >> ns[i];
        if (ns[i] == k) eq = 1;
        if (ns[i] < k) small = 1;
        if (ns[i] > k) big = 1;
    }
    FOR(i, 1, n) if (ns[i] != ns[i - 1]) ne = 1;

    if (!ne) {
        cout << 0 << endl;
        return;
    }

    if (eq || (small && big)) {
        cout << -1 << endl;
        return;
    }

    sort(ns, ns + n);

    LL gc = 0;
    F0R(i, n) gc = gcd<long long> (gc, abs(ns[i] - k));

    LL ans = 0;
    if (big)
        F0R(i, n) ans += (ns[i] - k - gc) / gc;

    if (small)
        F0R(i, n) ans += (k - ns[i] - gc) / gc;

    cout << ans << endl;
}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) solve();
}