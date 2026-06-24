#include <bits/stdc++.h>

using namespace std;



int main()

{

    long long int n,m,x;

    //arr[110];

    long long int arr[110][110],candid[110]={0};



    scanf("%lld %lld",&n,&m);



    long long int candidate=1,maxi=0;

   // arr[0]=0;

    for(int i=1;i<=m;i++)

    {

        candidate=1,maxi=0;

        for(int j=1;j<=n;j++)

        {

            scanf("%lld",&x);

            arr[i][j]=x;

            if(arr[i][j]>maxi)

            {

                maxi=arr[i][j];

                candidate=j;

            }

        }

        candid[candidate]++;

    }



    //sort(candid,candid+n);

    maxi=0;

    candidate=1;

    for(int i=1;i<=n;i++)

    {

        if(candid[i]>maxi)

        {

            maxi=candid[i];

            candidate=i;

        }

    }



    printf("%lld",candidate);







    return 0;

}