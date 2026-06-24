#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define fi first

#define se second

#define Pii pair <int, int>



int n, a[100005], cnt[100005];

vector <int> fac[100005];

bool vis[100005];

int prime[100005], len = 0, mu[100005];

int suc[100005];

ll ans = 0;



void MySolve() {

    memset(vis, true, sizeof(vis));

    vis[1] = false, mu[1] = 1;

    for (int i = 2; i <= 1e5; ++i) {

        if (vis[i]) prime[ ++len ] = i, mu[i] = -1;

        for (int j = 1; j <= len && i * prime[j] <= 1e5; ++j) {

            vis[ i * prime[j] ] = false;

            if (i % prime[j] == 0) {

                mu[ i * prime[j] ] = 0;

                break;

            }

            mu[ i * prime[j] ] = -mu[i];

        }

    }

    cin >> n;

    for (int i = 1; i <= n; ++i) {

        cin >> a[i];

        ++cnt[ a[i] ];

    }

    for (int i = 1; i <= 1e5; ++i) {

        if (cnt[i] >= 2) {

            ans = max(ans, 1ll * i);

        }

    }

    for (int i = 1; i <= 1e5; ++i) {

        int V = 1e5 / i;

        for (int j = 1; j <= V; ++j) {

            fac[j].clear();

            suc[j] = 0;

        }

        for (int j = 1; j <= V; ++j) {

            for (int k = j; k <= V; k += j) {

                fac[k].push_back(j);

            }

        }

        int p = 1;

        for (int j = 1; j <= V; ++j) {

            for (auto d : fac[j]) {

                suc[d] += mu[d] * cnt[ i * j ];

            }

        }

        for (int j = V; j; --j) if (cnt[ i * j ]) {

            auto calc = [&] () {

                int sum = 0;

                for (auto d : fac[j]) {

                    sum += suc[d];

                }

                return sum;

            };

            while (p <= j && calc()) {

                for (auto d : fac[p]) {

                    suc[d] -= mu[d] * cnt[ i * p ];

                }

                ++p;

            }

            if (p > j) break;

            ans = max(ans, 1ll * i * (p - 1) * j);

        }

    }

    cout << ans << '\n';

}



int main() {

    ios :: sync_with_stdio(0), cin.tie(0);

    int t = 1;

    while (t--) {

        MySolve();

    }

    return 0;

}