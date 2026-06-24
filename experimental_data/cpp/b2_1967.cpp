#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
using namespace std;
const int inf = 1000000007;
const ll longinf = 1ll << 60;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 2; i <= n + m; i++) {
        for(int s = i; s <= min(n, m); s += i) {
            int maa = n / s, mab = m / s;
            for(int a = max(1, i - mab); a <= min(maa, i - 1); a++) {
                int b = i - a;
                if(gcd(a, b) == 1)
                    ++ans;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}