#include<bits/stdc++.h>

using namespace std;

#define rint register int

#define sfi ({rint x;scanf("%d",&x);x;})

int main()

{

    rint n=sfi,sum1=0,sum2=0;

    for(rint i=1;i<=n;i++)

    {

        rint x=sfi;

        sum1=sum1|x;

    }

    for(rint i=1;i<=n;i++)

    {

        rint x=sfi;

        sum2=sum2|x;

    }

    cout<<sum1+sum2;

}