#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,k,m,arr[103],pos[103];

    scanf("%d %d %d",&n,&k,&m);

    for(int i=1; i<=m; i++)

    {

        scanf("%d",&arr[i]);

        //pos[arr]

    }

    long long sum=0;

    int x,tmp,val;

    for(int i=0; i<n; i++)

    {

        for(int j=0; j<k; j++)

        {

            scanf("%d",&x);

            for(int k=1; k<=m; k++)

            {

                if(arr[k]==x)

                {

                     tmp=k;

                     sum+=k;

                     val=arr[k];

                    break;

                }

            }

            for(int t=tmp; t>1; t--)

            {

                arr[t]=arr[t-1];

            }

            arr[1]=val;

        }

    }

    printf("%lld\n",sum);

    //cout<<sum<<endl;

}