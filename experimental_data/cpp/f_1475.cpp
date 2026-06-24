#include<bits/stdc++.h>

using namespace std;
//ifstream in ("g.in");
//ofstream out ("g.out");
#define ll long long
#define pb push_back
#define s second
#define f first
const ll mod = 1e9 + 7;
vector <int> v;
int dp[1005];
char a[1005][1005];
char b[1005][1005];
int c[1005][1005];
int oplin[1005];
int opcol[1005];
void solve()
{
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i] + 1;
    for (i = 1; i <= n; i++)
        cin >> b[i] + 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] != b[i][j])
                c[i][j] = 1;
            else
                c[i][j] = 0;
        }
    for (i = 1; i <= n; i++)
        oplin[i] = opcol[j] = -1;
    oplin[1] = 0;
    for (j = 1; j <= n; j++)
        opcol[j] = c[1][j];
    for (i = 2; i <= n; i++)
        oplin[i] = (c[i][1] - opcol[1] + 2) % 2;
    int ok = 1;
    for (i = 1; ok && i <= n; i++)
        for (j = 1; ok && j <= n; j++)
            if ((oplin[i] + opcol[j]) % 2 != c[i][j])
                ok = 0;
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
	return 0;
}