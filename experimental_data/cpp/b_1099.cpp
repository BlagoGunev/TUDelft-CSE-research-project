#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {

    ll t,n,i,j,a,b,w,h,u1,d1,u2,d2,x,y,dif;

     cin>>n;



    x=sqrt(n);
    y=ceil(double(sqrt(n)));

    if(n==1)
        a=2;

    else if(x==y)
    {
     a=2*x;
    }

    else
    {
     dif=n-(x*x);
     a=(2*x)+(ceil(double(dif)/x));

    }



     cout<<a;

  return 0;

}