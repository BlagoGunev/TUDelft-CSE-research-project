#include <bits/stdc++.h>

using namespace std;

#define ll long long 

#define rep(i,n) for(int i=0;i<n;i++)

int main()

{

    int n,m;

    cin>>n>>m;

    int c=0;

    if(n>=m)

        cout<<n-m<<endl;

    else

    {

        while(m>n)

        {

            if(m%2==0)

            {

                m/=2;

                c++;

            }

            else

            {

                m=(m+1)/2;

                c+=2;

            }

        }

        if(m<n)

            c+=n-m;

        cout<<c<<endl;

    }

    return 0;

}