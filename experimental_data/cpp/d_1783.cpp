#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

const int P = 998244353;

int f[305][N << 1 + 1];

void solve()

{

    long long n, ans = 0;

    cin >> n;

    vector<int> ar(n + 1);

    for (int i = 1; i <= n; i++)

        cin >> ar[i];

    f[0][ar[2] + N] = 1;

    for (int i = 0; i < n - 2; i++)

        for (int j = -N; j <= N; j++)

            if (f[i][j + N])

            {

                f[i + 1][j + N + ar[i + 3]] = (f[i + 1][j + N + ar[i + 3]] + f[i][j + N]) % P;

                if (j)

                    f[i + 1][ar[i + 3] - j + N] = (f[i + 1][ar[i + 3] - j + N] + f[i][j + N]) % P;

            }

    for (int i = -N; i <= N; i++)

        ans = (ans + f[n - 2][i + N]) % P;

    cout << ans;

}

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(nullptr);

    solve();

}