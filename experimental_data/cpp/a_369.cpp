#include <iostream>

#include <cstdio>

using namespace std;



main()

{

    int n , b , p , fir = 0 , sec = 0;

    int ans = 0;

    cin>>n>>b>>p;

    int f;

    for(int i=0 ; i<n ; i++)

    {

        cin>>f;



        if(f==1)

            fir++;

        else

            sec++;

    }



    b -= fir;

    if(b<0)

    {

        ans += b*-1;

        p -= sec;

        if(p < 0)

            ans += p*-1;

    }

    else

    {

        p+=b;

        p-=sec;

        if(p<0)

            ans += p*-1;

    }



    cout<<ans<<"\n";





}