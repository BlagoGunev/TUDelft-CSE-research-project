#include <bits/stdc++.h>

using namespace std;



int main()

{

    int n;

    cin>>n;

    int a[n],b[n];

    int count1=0,count2=0;

    for(int i=0;i<n;i++)

    {

        cin>>a[i];

    }

    for(int i=0;i<n;i++)

    {

        cin>>b[i];

    }

    for(int i=0;i<n;i++)

    {

        if(a[i]==1 && b[i]==0)

            count1++;

        else if(a[i]==0 && b[i]==1)

            count2++;

    }

    if(count1==0)

    {

        cout<<"-1"<<endl;

        return 0;

    }

    int p = count2/count1+1;

    cout<<p<<endl;

    return 0;

}