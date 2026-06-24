#include <bits/stdc++.h>

    using namespace std;

 long n,m,t,a[200010],kt ,res=0,x;

    int main()

{

       

        ios_base :: sync_with_stdio(0);

        cin.tie(0);cout.tie(0);

        cin>>t;

        while (cin>>n)

        {

            res=0;



            for (long i=0;i<n;i++) cin>>a[i];

            sort (a+0,a+n);

              kt=1;

            a[n]=n+2;

            for (long i=0;i<n;i++)

            if (i>=a[i])

            {

                if (i==0) kt=0;

                x=i;

              res++;

            while (x>=a[i])

            {



                x++;

                i++;

            }

            i--;

            }

            cout<<res+kt<<'\n';

        }





}