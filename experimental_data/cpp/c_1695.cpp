#include <bits/stdc++.h>



#define x first

#define y second

#define pb push_back

#define pp pop_back

#define IOS ios::sync_with_stdio(false);cin.tie(0);

#define all(x) x.begin(), x.end()

#define alls(x, a, b) x + a, x + a + b

#define DG(x) x << ' '



using namespace std;



typedef long long LL;

typedef pair<int, int> PII; typedef pair<LL, LL> PLL;

const int N = 150005, mod = 998244353, INF = 0x3f3f3f3f, M = 3e5 + 5; 

const double eps = 1e-6;

const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

LL qmi(LL a,LL b,int mod){LL res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=1LL*a*a%mod;b>>=1;}return res;}



void solve()

{

    int n, m; cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1)), mx(n + 1, vector<int>(m + 1)), mn(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= m; j++)

        {

            cin >> a[i][j];

        }

    if ((n + m) % 2 == 0)

    {

        cout << "NO\n"; return;

    }

    for (int i = 1; i <= n; i++)

    {

        for (int j = 1; j <= m; j++)

        {

            if (i == 1) mx[i][j] = mx[i][j - 1], mn[i][j] = mn[i][j - 1];

            else if (j == 1) mx[i][j] = mx[i - 1][j], mn[i][j] = mn[i - 1][j];

            else

            {

                mx[i][j] = max(mx[i][j - 1], mx[i - 1][j]);

                mn[i][j] = min(mn[i][j - 1], mn[i - 1][j]);

            }

            mx[i][j] += a[i][j]; mn[i][j] += a[i][j];

        }

    }

    //判断最终的最大值最小值是否满足条件

    if (mx[n][m] < 0 || mn[n][m] > 0) cout << "NO\n";

    else cout << "YES\n";

}



int main()

{

    IOS 

    int _; cin >> _;

    while (_--)

    {

        solve();

    }

    return 0;

}