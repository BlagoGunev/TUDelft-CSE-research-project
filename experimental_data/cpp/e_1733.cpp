#include <iostream>

#include <cstring>

#include <algorithm>



using namespace std;



typedef long long LL;



const int N = 125;



LL f[N][N], g[N][N];



void solve() {

    memset(f, 0, sizeof f); memset(g, 0, sizeof g);

    

    LL t;

    int x, y;

    scanf("%lld%d%d", &t, &x, &y);

    

    t -= (x + y);

    f[0][0] = t + 1, g[0][0] = t;

    for (int i = 0; i <= x; i ++ )

        for (int j = 0; j <= y; j ++ ) {

            f[i + 1][j] += f[i][j] / 2;

            f[i][j + 1] += (f[i][j] + 1) / 2;

            g[i + 1][j] += g[i][j] / 2;

            g[i][j + 1] += (g[i][j] + 1) / 2;

        }

        

    if (t < 0) f[x][y] = 0;

    if (t < 1) g[x][y] = 0;

    

    if (f[x][y] == g[x][y]) puts("NO");

    else puts("YES");

}



int main()

{

    int T;

    scanf("%d", &T);

    while (T -- ) solve();

    

    return 0;

}