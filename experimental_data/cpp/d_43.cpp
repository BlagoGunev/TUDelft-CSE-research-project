#include<bits/stdc++.h>

using namespace std;





int main()

{



    int n,m;

    scanf("%d%d",&n,&m);

    if(n==1||m==1||(n%2&&m%2))

    {

        if((n==1&&m==2)||(n==2&&m==1))

        {

            puts("0");

            printf("1 1\n");

            printf("%d %d\n",n,m);

            printf("1 1\n");

            return 0;

        }

        puts("1");

        printf("%d %d 1 1\n",n,m);

        if(n==1)

        {

            for(int i=1; i<=m; i++)

            {

                printf("%d %d\n",n,i);

            }

        }

        else if(m==1)

        {

            for(int i=1; i<=n; i++)

            {

                printf("%d %d\n",i,m);

            }

        }

        else

        {

            int ff=1;

            for(int i=1; i<=n; i++)

            {

                for(int j=1; j<=m; j++)

                {

                    if(i%2)

                        printf("%d %d\n",i,j);

                    else

                        printf("%d %d\n",i,m-j+1);

                }

                ff^=1;

            }

        }

        puts("1 1");

    }

    else

    {

        puts("0");

        if(m%2==0)

        {

            for(int i=1;i<=m;i++)

            {

                printf("%d %d\n",1,i);

            }

            for(int j=m;j>=1;j--)

            for(int i=2;i<=n;i++)

            {

                if(j%2==m%2)

                    printf("%d %d\n",i,j);

                else

                   printf("%d %d\n",n-i+2,j);

            }

            puts("1 1");

        }

        else if(n%2==0)

        {

             for(int i=1;i<=n;i++)

            {

                printf("%d %d\n",i,1);

            }

            for(int j=n;j>=1;j--)

            for(int i=2;i<=m;i++)

            {

                if(j%2==n%2)

                    printf("%d %d\n",j,i);

                else

                   printf("%d %d\n",j,m-i+2);

            }

            puts("1 1");

        }

    }

}