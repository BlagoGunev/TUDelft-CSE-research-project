#include <bits/stdc++.h>

// #define endl '\n'

#define x first

#define y second

// #define int LL

#define gg ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)



using namespace std;



typedef long long LL;

typedef unsigned long long uLL;

typedef pair<int, int> PII;

typedef pair<LL, LL> PLL;

const int N = 1e5 + 10;

const int mod = 998244353, inf = 0x3f3f3f3f;

const LL INF = 0x3f3f3f3f3f3f3f3f;

const double eps = 1e-8;



int n, st[110], f[110][110];

int fact[110], inv[110];

PII a[110];

bitset<110> s[110];



int ksm(int base, int b) {

    int res = 1;

    while (b) {

        if (b & 1) res = (LL)res * base % mod;

        base = (LL)base * base % mod;

        b >>= 1;

    }

    return res;

}



int get(int i, int j) { return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y); }



void init() {

    fact[0] = 1;

    inv[0] = 1; 

    for (int i = 1; i < 110; i++) {

        fact[i] = (LL)fact[i - 1] * i % mod;

        inv[i] = ksm(fact[i], mod - 2);

    }

}



int main() {

    gg;

    cin >> n;

    init();

    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    for (int i = 0; i < n; i++) {

        int minn = inf;

        for (int j = 0; j < n; j++) {

            if (i == j) continue;

            minn = min(minn, get(i, j));

        }

        for (int j = 0; j < n; j++) {

            if (get(i, j) <= minn) s[i][j] = 1;

        }

    }

    vector<int> np;

    for (int i = 0; i < n; i++) {

        if (st[i]) continue;

        st[i] = 1;

        bitset<110> temp = s[i];

        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {

                if (temp[k]) temp |= s[k];

            }

        }

        bool ok = true;

        for (int j = 0; j < n; j++) {

            if (temp[j] && s[j] != temp) {

                ok = false;

                break;

            }

        }

        if (ok) {

            for (int j = 0; j < n; j++) {

                if (temp[j]) st[j] = 1;

            }

            np.push_back(temp.count());

        } else {

            np.push_back(1);

        }

    }

    int m = np.size();

    f[0][0] = 1;

    for (int i = 0; i < m; i++) {

        int cnt = np[i];

        for (int j = 1; j <= n; j++) {

            f[i + 1][j] = ((LL)f[i + 1][j] + (LL)f[i][j - 1]) % mod;

        }

        if (cnt > 1) {

            for (int j = cnt; j <= n; j++) {

                //(f[i + 1][j] += (LL)f[i][j - cnt]) % mod;

                 f[i + 1][j] = ((LL)f[i + 1][j] + (LL)f[i][j - cnt]) % mod;

            }

        }

    }

    int ans = 0; 

    for (int i = 1; i <= n; i++)

        ans = (ans + (LL)f[m][i] * fact[n] % mod * inv[n - i] % mod) % mod;

    cout << ans;

}