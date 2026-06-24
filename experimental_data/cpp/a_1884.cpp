#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll t, n, k;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (ll i = n; i < n + 20; ++i) {
            string s = to_string(i);
            ll x = 0;
            for (auto& i : s) x += i - '0';
            if (x % k == 0) {
                n = i;
                break;
            }
        }
        cout << n << '\n';
    }
    return 0;
}