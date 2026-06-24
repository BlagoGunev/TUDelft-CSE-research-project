#include <iostream>



using namespace std;



int main()

{

    int n,i;

    cin>>n;

    int a[n];

    cin>>a[0];

    for(i=1;i<n;i++)

        {cin>>a[i];

        if(i%2==0)

            a[i]-=a[0];

        else a[i]+=a[0];

        if(a[i]>=n)

            a[i]-=n;

        else if(a[i]<0)

            a[i]+=n;

        }

        a[0]=0;

    for(i=0;i<n;i++)

        {

            if(a[i]==i)

        continue;

        else break;

        }

        if(i==n)

            cout<<"YES";

        else cout<<"NO";



}