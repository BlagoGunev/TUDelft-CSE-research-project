#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,i,j,s,sum=0,k;

    cin>>n>>s;

    int arr[n],x[n];



    for(i=0;i<n;i++)

    {

        cin>>arr[i];

        x[i]=arr[i];

    }



    sort(arr,arr+n);



    for(i=0;i<n;i++)

    {

        sum=sum+arr[i];

        if(sum>s)

            break;

    }



    cout<<i<<endl;



    if(i!=0)

    {

        for(j=0;j<i;j++)

        {

            for(k=0;k<n;k++)

            {

                if(arr[j]==x[k])

                {

                    cout<<k+1<<" ";

                    x[k]=-1;

                    break;

                }

            }

        }

    }



    return 0;

}