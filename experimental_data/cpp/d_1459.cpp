#include<bits/stdc++.h>



using namespace std;



const int N = 101;



int v[N], w[N], h[N];

int f[N][N * N];

int main()

{

    int n, sum = 0;

    cin >> n;



    for(int i = 1; i <= n; i ++)

    {

        cin >> v[i] >> w[i];

        h[i] =  h[i - 1] + v[i];

        sum += w[i];

    }



    //由于我们定义的是恰好且最后求max所以把推不出来的非法数据赋最小

    memset(f, 0xcf, sizeof f);

    f[0][0] = 0;



    for(int i = 1; i<= n; i ++)

        for(int k = i; k >= 1; k --)

            for(int j = h[i]; j >= v[i]; j --)

    {

            f[k][j] = max(f[k][j], f[k - 1][j - v[i]] + w[i]);

    }





    for(int k = 1; k <= n; k ++)

    {

        double maxn = 0;

        for(int j = 0; j <= h[n]; j ++)

        {

            if(f[k][j] != 0xcfcfcfcf)

                maxn = max(maxn, min(1.0 * j, f[k][j] / 2.0 + sum / 2.0));

        }

        printf("%.10f ", maxn);

    }



    return 0;

}