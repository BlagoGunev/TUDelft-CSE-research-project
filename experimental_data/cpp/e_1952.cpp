#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 5;

int a[MXN];
int dp[MXN][2][2][2];

int f(int i, int x, int y, int z)
{
    if (i == 0 && (x + y) == 0) return 1;
    if (a[i] != x + z) return 0;
    if (i == 1 && x) return 0;
    if (dp[i][x][y][z] != -1) return dp[i][x][y][z];
    return dp[i][x][y][z] = (f(i - 1, 0, x, y) + f(i - 1, 1, x, y)) % 20240401;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < MXN; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++) dp[i][j][k][l] = -1;
    int n;
    cin >> n;
    int dp[n + 1][2][2];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = 0;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++)
        {
            res = (res + f(n, i, j, 0)) % 20240401;
        }
    }
    cout << res << '\n';
}