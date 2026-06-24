#include <bits/stdc++.h>
using namespace std;
int n, ara[55];
int dp[55][2];
int fun (int pos, int h) {
    int& ret = dp[pos][h];
    if (ret != -1) return ret;
    if (pos > n) return 0;
    if (h) return ret = max (ara[pos] + fun (pos+1, 1-h), fun (pos+1, h));
    return ret = min (fun (pos+1, 1-h), ara[pos] + fun (pos+1, h));
}
int main ()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
        sum += ara[i];
    }
    memset (dp, -1, sizeof (dp));
    int res = max (fun (1, 0), fun (1, 1));
    cout << sum-res << " " << res << endl;
}