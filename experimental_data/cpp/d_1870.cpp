#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

int n, a[N], k;
int b[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    vector<int> v;
    int mn = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < mn)
            v.pb(i);
        mn = min(mn, a[i]);
    }
    reverse(v.begin(), v.end());
    stack<int> st;
    for (int i = 0; i < v.size(); i++) {
        b[v[i]] = k / a[v[i]];
        k %= a[v[i]];
        while (!st.empty() && k + a[st.top()] >= a[v[i]]) {
            int j = st.top();
            b[j]--;
            b[v[i]]++;
            k = k + a[j] - a[v[i]];
            if (b[j] == 0)
                st.pop();
        }
        if(b[v[i]] > 0)
            st.push(v[i]);
    }
    for (int i = n - 2; i >= 0; i--)
        b[i] += b[i + 1];
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}