#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 1000;
const ll MOD = 998244353;

int f[N + 1], s[N + 1], val[N + 1];
int sum;

void init(int m) {
    for (int i = 0; i <= m; i++) {
        f[i] = i;
        s[i] = 1;
        val[i] = 0;
    }
    val[0] = 0;
    sum = m;
}
int find(int x) {
    if (f[x] == x)
        return x;
    else {
        val[x] ^= val[f[x]];
        f[x] = find(f[x]);
        return f[x];
    }
}
bool merge(int x, int y, int t) {
    int a = find(x), b = find(y);
    t ^= val[x] ^ val[y];
    if (a == b)
        return (t == 0);
    if (s[a] > s[b])
        swap(a, b);
    if (a == 0)
        swap(a, b);
    f[a] = b;
    s[b] += s[a];
    val[a] = t;
    sum--;
    return 1;
}

ll power[N * 3 + 1];

int main() {
    power[0] = 1;
    for (int i = 1; i <= 3 * N; i++)
        power[i] = power[i - 1] * 2 % MOD;

    string s;
    cin >> s;
    int n = (int)s.length();

    ll ans = 0;
    for (int m = 1; m < n; m++) {
        int cnt = 0;
        ll tans = 1;
        init(m);
        for (int i = 1; i <= m; i++)
            merge(i, m + 1 - i, 0);
        merge(0, 1, 1);
        for (int i = 1; 2 * i <= n + 1; i++) {
            int j = n + 1 - i;
            if (i <= m && j <= m) {
                if (s[n - i] == '?' && s[n - j] == '?')
                    cnt++;
                else if (s[n - i] != '?' && s[n - j] != '?')
                    if (!merge(i, j, s[n - i] ^ s[n - j]))
                        tans = 0;
            }
            else if (i <= m && j > m) {
                if (s[n - i] == '?' && s[n - j] == '?')
                    cnt++;
                else if (s[n - i] != '?' && s[n - j] != '?')
                    if (!merge(0, i, s[n - i] ^ s[n - j]))
                        tans = 0;
            }
            else {
                if (s[n - i] == '?' && s[n - j] == '?')
                    cnt++;
                else if ((s[n - i] ^ s[n - j]) == 1)
                    tans = 0;
            }
        }
        if (tans == 1)
            ans = (ans + power[cnt + sum]) % MOD;
    }
    printf("%lld\n", ans % MOD);
}