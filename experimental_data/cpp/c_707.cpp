#include<bits/stdc++.h>

using namespace std ;

int main()

{

    long long n , x;

    while(cin>>x)

    {

        if(x<3)

        {

            cout<<-1 <<endl ;

            continue ;

        }

        n = x ;

        n = n*n ;

        if(x&1)

            cout<<((n-1)/2)<<" " <<((n+1)/2)  <<endl ;

        else

            cout<<((n-4)/4)<<" " <<((n+4)/4)  <<endl ;

    }

    return 0 ;

}