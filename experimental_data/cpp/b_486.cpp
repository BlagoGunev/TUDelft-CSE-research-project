#include<bits/stdc++.h>

#define scn(n) scanf("%d",&n)

#define scnll(n) scanf("%I64d",&n)

#define scnch(n) scanf("%c",&n)

#define scns(n) scanf("%s",&n)

#define loop(i,n,m) for(i=n;i<=m;i++)

#define revloop(i,n,m) for(i=n;i>=m;i--)

#define print(n) printf("%d ",n)

#define printc(n) printf("%c",n)

#define printll(n) printf("%I64d ",n)

#define prints(n) printf("%s",n)

#define next printf("\n")

#define ll long long

#define MAX(x,y) ((x)>(y)?(x):(y))

#define mod 1000000007

using namespace std;

int main()

{

    int n,m,i,j,a,b,t;

    scn(n);scn(m);

    int arr[n][m];

        loop(i,0,n-1)

    {

        loop(j,0,m-1)

        {

            scn(arr[i][j]);

        }

    }

    int flag=1;int k;

    int row[n],col[m];

    loop(i,0,n-1)

    row[i]=1;

    loop(j,0,m-1)

    col[j]=1;

    loop(i,0,n-1)

    {

        loop(j,0,m-1)

        {

            if(arr[i][j]==0)

            {

                row[i]=0;

                break;

            }

        }

    }

    loop(i,0,m-1)

    {

        loop(j,0,n-1)

        {

            if(arr[j][i]==0)

            {

                col[i]=0;

                break;

            }

        }

    }

    loop(i,0,n-1)

    {

        //cout<<row[i]<<' ';

        if(row[i]==0)

        loop(j,0,m-1)

        {

            if(arr[i][j]==1)

            {

                loop(k,0,n-1)

                {

                    if(arr[k][j]!=1)

                    {

                        prints("NO");

                        return 0;

                    }

                }

            }

        }

        else

        {

            flag=0;

                loop(j,0,m-1)

        {



                if(col[j]==1)

                {

                    flag=1;

                }



        }

        if(flag==0)

        {

prints("NO");

                        return 0;

        }

        }

    }

   // next;

    loop(j,0,m-1)

    {

        //cout<<col[j]<<' ';

        if(col[j]==0)

        loop(i,0,n-1)

        {

            if(arr[i][j]==1)

            {

                loop(k,0,m-1)

                {

                    if(arr[i][k]!=1)

                    {

                        prints("NO");

                        return 0;

                    }

                }

            }

        }

        else

        {

               flag=0;

        loop(i,0,n-1)

        {



                if(row[i]==1)

                {

                    flag=1;

                }



        }

        if(flag==0)

        {

prints("NO");

                        return 0;

        }

        }

    }

    prints("YES");

    next;

    loop(i,0,n-1)

    {

        if(row[i]==0)

        {

            loop(j,0,m-1)

            {

                print(0);

            }

            next;

        }

        else

        {

            loop(j,0,m-1)

            {

                if(col[j]==1)

                {

                    print(1);

                }

                else

                    print(0);

            }

            next;

        }

    }





}