#include<bits/stdc++.h>

#include <stdio.h>

//#define mod 1000000007

//static int ans[100001][2];// 0 lowercase

using namespace std;



int main()

{

    long long int d,k,a,b,t;

    cin>>d>>k>>a>>b>>t;

    if(d<=k)

        cout<<d*a<<endl;

    else

    {

        if(t+k*a>=k*b)

            cout<<k*a+(d-k)*b<<endl;

        else

        {

            long long int ans=k*a+((d-k)/k)*t+((d-k)/k)*k*a;

            long long int disleft=(d-k)-((d-k)/k)*k;

            long long int temp=min(t+disleft*a,disleft*b);

            cout<<ans+temp<<endl;

        }

    }

 	return 0;

}