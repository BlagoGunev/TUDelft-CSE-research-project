#include<bits/stdc++.h>



using namespace std;



long long int n,m;

long long int arr[100100];



void cal()

{



    long long int idx=-1;

    long long int mn=2000000000;

    for(long long int i=1;i<=n;i++) mn=min(mn,arr[i]);



    for(long long int i=m;i>=1;i--)

    {

        if(arr[i]==mn)

        {

            idx=i;

            break;

        }

    }

    if(idx==-1)

    {

        for(long long int i=n;i>=1;i--)

        {

            if(arr[i]==mn)

            {

                idx=i;

                break;

            }

        }

    }

    long long int ans;

    long long int val=0;

    if(idx==m)

    {

        for(long long int i=1;i<=n;i++) arr[i]-=mn;

        ans=mn*n;

    }

    else if(idx<m)

    {

        for(long long int i=1;i<=n;i++) arr[i]-=mn;

        for(long long int i=idx+1;i<=m;i++)

        {

            arr[i]--;

            val++;

        }

        ans=n*mn;

    }

    else

    {

        for(long long int i=1;i<=n;i++) arr[i]-=(mn+1);

        for(long long int i=m+1;i<=idx;i++)

        {

            arr[i]++;

            val--;

        }

        ans=n*(mn+1);

    }



    //long long int ans=n*mn;

    ans=ans+val;

    arr[idx]=ans;

    //if(idx==m) arr[idx]--;



    for(long long int i=1;i<=n;i++)

    {

        printf("%lld ",arr[i]);

    }

    printf("\n");





}



int main()

{

    scanf("%lld%lld",&n,&m);



    for(long long int i=1;i<=n;i++)

    {

        scanf("%lld",&arr[i]);

    }



    cal();



    return 0;

}