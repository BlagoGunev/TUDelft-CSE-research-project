#include <bits/stdc++.h>

 

using namespace std;

 

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        int n,s=0;

        cin>>n;

        int l=0,z=0,q=0;

        int arr[110]={0};

        for(int i=0;i<n;i++)

        {

            int x;

            cin>>x;

            arr[x]++;

        }

        for(int i=0;i<110;i++)

        {

            if(arr[i]==1)

            {

                z=z+1;

            }

            else if (arr[i]>1){

            l=l+arr[i];

            q=q+1;}

        }

        if(q==2&&z==0)

        {

            s=(l/2)+1;

        }

        else{s=z+l;}

        cout<<s<<endl;

    }

}