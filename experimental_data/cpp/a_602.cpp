#include<bits/stdc++.h>

    using namespace std;

    long long fast_pow(int a,int n)

{

    long long result = 1;

    long long power = n;

    long long value = a;

    while(power>0)

    {

        if(power&1)

            {result = result*value;

            result = result;}

        value = value*value;

        value = value;

        power /= 2;

    }

    return result;

}

    int main(){

    ios_base::sync_with_stdio(false);

   unsigned long long n,bx,z,by;

   cin>>n>>bx;

   unsigned long long r1=0,r2=0;

   unsigned long long p,c;

   for(int i=0;i<n;i++)

   {

       cin>>p;

       r1+=fast_pow(bx,n-1-i)*p;

   }

   cin>>z>>by;

    for(int i=0;i<z;i++)

   {

       cin>>c;

       r2+=fast_pow(by,z-1-i)*c;

   }

   if(r2==r1)

    cout<<'=';

   else if(r1<r2)

    cout<<'<';

   else

    cout<<'>';





        return 0;

    }