#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
vector<int> gra[MAXN];
int dp[MAXN][20][2];
long long ans;

void DFS(int k, int pre)
{
    ans += a[k];
    for(int i = 0; i < 20; i++)
    if(a[k] & (1 << i)) dp[k][i][1]++;
    else dp[k][i][0]++;

    for(vector<int>::iterator iter = gra[k].begin(); iter != gra[k].end(); iter++)
    if(*iter != pre)
    {
        DFS(*iter, k);

        for(int i = 0; i < 20; i++)
        {
            ans += (long long) dp[k][i][0] * dp[*iter][i][1] * (1 << i);
            ans += (long long) dp[k][i][1] * dp[*iter][i][0] * (1 << i);

            if(a[k] & (1 << i))
            {
                dp[k][i][1] += dp[*iter][i][0];
                dp[k][i][0] += dp[*iter][i][1];
            }
            else
            {
                dp[k][i][0] += dp[*iter][i][0];
                dp[k][i][1] += dp[*iter][i][1];
            }

        }

    }

    return;
}

int main()
{
    int n;

    // freopen("D:\\1.in", "r", stdin);
    // freopen("D:\\1.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1, a, b; i < n; i++) scanf("%d%d", &a, &b), gra[a].push_back(b), gra[b].push_back(a);

    DFS(1, 1);
    printf("%I64d\n", ans);

    return 0;
}