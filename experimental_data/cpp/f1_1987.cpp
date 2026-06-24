#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <array>
#include <utility>
#define fileio(PATH) (freopen(PATH ".in", "r", stdin), freopen(PATH ".out", "w", stdout))
using std::pair, std::vector, std::array;
using ll = long long;
using ull = unsigned long long;
const int N = 105;
int n, a[N], f[N][N][N];
void solve(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n;++i)
        scanf("%d", a + i);
    memset(f, 0, sizeof(f));
    for (int l = 2; l <= n; ++l)
    {
        for (int i = 1; i + l - 1 <= n;++i)
        {
            int j = i + l - 1;
            for (int k = 0; 2 * k <= i;++k)
            {
                for (int mid = i; mid < j;++mid)
                {
                    int pre = f[i][mid][k];
                    int suf = f[mid + 1][j][k + pre];
                    f[i][j][k] = std::max(f[i][j][k], pre + suf);
                }
                if((a[i] + i) % 2 == 0 && a[i] <= i && i - 2 * k <= a[i])
                {
                    f[i][j][k] = std::max(f[i][j][k], f[i + 1][j - 1][(i - a[i]) / 2] + 1);
                }
            }
        }
    }
    printf("%d\n", f[1][n][0]);
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    return;
}
int main(void)
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        solve();
    }
    return 0;
}