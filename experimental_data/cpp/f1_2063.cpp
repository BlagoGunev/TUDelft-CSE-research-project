#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
vector<ll> cata;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n * 2 + 2, -1);
    arr[0] = 0;
    arr[n * 2 + 1] = 0;

    for (int i = 1; i <= n; ++i) {
        ll ans = 1;
        stack<int> stack;
        vector<int> f(i + 1, 0);

        for (int j = 0; j < arr.size(); ++j) {
            if (arr[j] != -1) {
                if (stack.empty() || stack.top() != arr[j]) {
                    stack.push(arr[j]);
                } else {
                    stack.pop();
                }
            } else {
                f[stack.top()]++;
            }
        }

        for (int x : f) {
            ans = (ans * cata[x / 2]) % MOD;
        }

        cout << ans << " ";

        int ll, rr;
        cin >> ll >> rr;
        arr[ll] = i;
        arr[rr] = i;
    }

    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cata.resize(5001, 0);
    cata[0] = 1;
    for (int i = 1; i < 5001; ++i) {
        for (int j = 0; j < i; ++j) {
            cata[i] = (cata[i] + (cata[j] * cata[i - 1 - j]) % MOD) % MOD;
        }
    }

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }

    return 0;
}