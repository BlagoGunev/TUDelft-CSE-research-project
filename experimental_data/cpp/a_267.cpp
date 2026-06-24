/************************************************\

*                                                *

* Submission By Deepanshu Luhach aka DragonFist  *

* Institution Name: Army Institute of Technology *

*            Go on Hack MY Code.                 *

*                                                *

\************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define PI 3.14159265359

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        ll a,b,s=0;

        cin>>a>>b;

        while(a>0&&b>0)

        {

            ll x= max(a,b)/min(a,b);

            s+=x;

            if(a>b)

                a=a-x*b;

            else

                b=b-a*x;

        }

        cout<<s<<endl;

    }

    return 0;

}