#pragma GCC optimaze(3)

#pragma -Ofast

#include<bits/stdc++.h>

using namespace std;

const int md=31607,kk=3973;



int n,ret;

int dp[1<<22],f[1<<22],a[22][22],b[22][1<<22];



void work()

{

	for (int i=0;i<4;i++)

    {

        for (int j=0;j<(1<<n);j++)

        {

            if ((__builtin_popcount(j)+__builtin_popcount(i))&1)

				f[j]=1;

			else f[j]=md-1;

		}

        for (int j=1;j<=n;j++)

        {

            for(int k=0;k<1<<n;k++)

            {

                int s=k;

                if (i&1) s|=1<<(j-1);

                if (i&2) s|=1<<(n-j);

                f[k]=1ll*f[k]*b[j][s]%md*(1-b[j][((1<<n)-1)^s]+md)%md;

            }

        }

        for (int i=0;i<(1<<n);i++)

			ret=(ret+f[i])%md;

    }

}



int main()

{

    scanf("%d",&n);

    for (int i=1;i<=n;i++)

    {

        for (int j=1;j<=n;j++)

        {

			scanf("%d",&a[i][j]);

			a[i][j]=1ll*a[i][j]*kk%md;

		}

	}

    dp[1]=1;

    for (int i=2;i<=(1<<n);i++)

    {

		dp[i]=dp[i>>1]+1;

	}

    for (int i=1;i<=n;i++)

    {

        b[i][0]=1;

        for (int j=1;j<(1<<n);j++)

        {

            int k=j&(-j);

            b[i][j]=1ll*b[i][j^k]*a[dp[k]][i]%md;

//            cout<<b[i][j]<<endl;

        }

    }

    work();

    printf("%d",(ret+1)%md);

    return 0;

}