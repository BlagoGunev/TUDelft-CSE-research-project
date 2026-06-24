#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

const int inf = 1 << 30;

const int N = 1e7 + 10;

vector<int> primes;

vector<int> p, cnt;



void solve() {

    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

        int x;

        cin >> x;

        int tmp = 1, cur = 0, cnt = 0;

        while (x != 1) {

            if (p[x] != cur) {

                if (cnt % 2 == 1) tmp *= cur;

                cur = p[x], cnt = 1;

            } else {

                cnt++;

            }

            x /= p[x];

        }

        if (cnt % 2 == 1) tmp *= cur;

        a[i] = tmp;

    }

    vector left(k + 1, vector<int>(n));

    for (int i = 0; i <= k; i++) {

        int now = 0;

        for (int r = n - 1, l = n - 1; r >= 0; r--) {

            while (l >= 0 && now + !!cnt[a[l]] <= i) {

                now += !!cnt[a[l]];

                cnt[a[l]]++;

                l--;

            }

            cnt[a[r]]--;

            if (cnt[a[r]]) now--;

            left[i][r] = l + 1;

        }

    }

    vector dp(k + 1, vector<int>(n + 1, inf));

    for (int i = 0; i <= k; i++) {

        dp[i][0] = 0;

    }

    for (int j = 1; j <= n; j++) {

        for (int i = 0; i <= k; i++) {

            for (int l = 0; l <= i; l++) {

                dp[i][j] = min(dp[i][j], dp[i - l][left[l][j - 1]] + 1);

            }

        }

    }

    int ans = inf;

    for (int i = 0; i <= k; i++) {

        ans = min(ans, dp[i][n]);

    }

    cout << ans << '\n';

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    p = vector<int>(N);

    cnt = vector<int>(N);

    for (int i = 2; i < N; i++) {

        if (!p[i]) primes.push_back(i), p[i] = i;

        for (int j = 0; primes[j] * i < N; j++) {

            p[primes[j] * i] = primes[j];

            if (i % primes[j] == 0) break;

        }

    }



    int T = 1;

    cin >> T;

    while (T--) {

        solve();

    }

    return 0;

}