#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

const int N = 100;
int n,m,k;
int a[N][N];
int f[N][N];
int dp[N][N];
int d[N][N];

main(){
   // freopen(".inp","r",stdin);
   // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
    cin >> a[i][j];
    for(int i = 1; i <= n; ++i){
        memset(d,-31,sizeof(d));
        d[0][0] = 0;
            for(int j = 1; j <= m; ++j)
            for(int q = m/2-1; q >= 0; --q)
            for(int p = 0; p < k; ++p)
            {
                if(d[p][q] < 0) continue;
                int u = (a[i][j]+p) % k;
                if(q >= m/2) continue;
                d[u][q+1] = max(d[u][q+1],d[p][q] + a[i][j]);
            }
        for(int t = 0; t < k; ++t){
            dp[i][t] = -1000000;
            for(int p = 0; p <= m/2; ++p)
                dp[i][t] = max(dp[i][t],d[t][p]);
        }
    }

    memset(f,-31,sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < k; ++j){
        if(f[i][j] < 0) continue;
        for(int t = 0; t < k; ++t){
            int u = (j+t) % k;
            f[i+1][u] = max(f[i+1][u],f[i][j] + dp[i+1][t]);
            f[i+1][u] = max(f[i+1][u],f[i][u]);
        }
    }

    cout << f[n][0];
}