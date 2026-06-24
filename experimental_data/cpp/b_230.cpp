#include<bits/stdc++.h>

#define SIZE 100001

#define N 1000001

using namespace std;



vector<long long int>prime;



long long int cnt, n, x[SIZE], root, result;

bool arr[N], res[SIZE];

void sieve()

{

    long long int k=sqrt(N);

    for(int i=3; i<=k; i+=2)

    {

        if(arr[i]==0)

        {

            for(long long int j=i*i; j<N; j+=2*i)

            {

                arr[j]=1;

            }

        }

    }

    arr[1]=1;

    for(long long int i=4; i<N; i+=2)

    {

        arr[i]=1;

    }



    prime.push_back(2);



    for(long long int i=3; i<N; i+=2)

    {

        if(arr[i]==0)

        {

            prime.push_back(i);

        }

    }

}



int main()

{

    sieve();

    scanf("%lld",&n);

    for(int i=0; i<n; i++)

    {

        scanf("%lld",&x[i]);

        root=sqrt(x[i]);

        result=root*root;

        if(result==x[i])

        {

            if(arr[root]==0)

                res[i]=1;

            else

                res[i]=0;

        }

        else

            res[i]=0;



    }

    for(int j=0; j<n; j++)

    {

        if(res[j]==1)

            printf("YES\n");

        else

            printf("NO\n");

    }

    return 0;

}