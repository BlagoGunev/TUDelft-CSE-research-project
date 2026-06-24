#include <cstdio>

#include <cmath>



using namespace std;



int x[1024], b[1024], pre[1024], ans[1024], cnt;

double dp[1024];



int main()

{

    int n, ll;

    scanf("%d%d", &n, &ll);

    for (int i = 0; i < n; i++)

    {

        scanf("%d %d", x + i, b + i);

    }

    double l = 0, r = 1e6;

    while (fabs(l - r) > 1e-8)

    {

        double t = (l + r) / 2.;

        for (int i = 0; i < n; i++)

        {

            dp[i] = sqrt(fabs(x[i] - ll)) - t * b[i];

            for (int j = 0; j < i; j++)

            {

                double tmp = dp[j] + sqrt(fabs(x[i] - x[j] - ll)) - t * b[i];

                if (tmp < dp[i])

                {

                    dp[i] = tmp;

                }

            }

        }

        //printf("%.3f %.3f\n", t, dp[n - 1]);

        if (dp[n - 1] > 1e-3)

        {

            l = t;

        }

        else

        {

            r = t;

        }

    }

    double t = (l + r) / 2;

    //t = 0.0869565217F;

    for (int i = 0; i < n; i++)

    {

        dp[i] = sqrt(fabs(x[i] - ll)) - t * b[i];

        pre[i] = -1;

        for (int j = 0; j < i; j++)

        {

            double tmp = dp[j] + sqrt(fabs(x[i] - x[j] - ll)) - t * b[i];

            if (tmp < dp[i])

            {

                dp[i] = tmp;

                pre[i] = j;

            }

        }

    }

    cnt = 0;

    int x = n - 1;

    while (x >= 0)

    {

        ans[cnt++] = x;

        x = pre[x];

    }

    for (int i = cnt - 1; i >= 0; i--)

    {

        printf("%d ", ans[i] + 1);

    }

    printf("\n");

    return 0;

}