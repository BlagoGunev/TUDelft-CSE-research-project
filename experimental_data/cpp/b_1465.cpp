#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()

{



    int t, i, j;

    cin >> t;

    while (t)

    {

        ll n;

        cin>>n;

        while(true)

        {

            ll tn=n,flag=0;

           // cout << n<<"\n";

            while(tn>0)

            {

              

               int x=tn%10;

               tn=tn/10;

               if(x!=0 && n%x!=0)

               {

                   flag=1;

                   break;

               }

            }

            if(flag==0)

            {

                cout<<n<<"\n";

                break;

            }

            n++;

        }

        t--;

    }

}