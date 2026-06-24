#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,i,j,a[6],s=0,k,ans;

    for(i=0;i<5;i++)

    {

        cin>>a[i];

        s+=a[i];

    }

    ans=s;

    for(i=0;i<5;i++)

    {

        for(j=i+1;j<5;j++)

        {

            if(a[i]==a[j])

                ans=min(ans,s-(a[i]*2));

        }

    }

    for(i=0;i<5;i++)

    {

        for(j=i+1;j<5;j++)

        {

            for(k=j+1;k<5;k++)

            {

                if(a[i]==a[j]&&a[i]==a[k])

                {

                    ans=min(ans,s-(a[i]*3));

                }

            }

        }

    }

    cout<<ans<<endl;

    return 0;

}