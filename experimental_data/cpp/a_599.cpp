#include<cmath>

#include<cstdio>

#include<string>

#include<cstring>

#include<cctype>

#include<cstdlib>

#include<iostream>

#include<algorithm>

using namespace std;



int main()

{

    int d1,d2,d3,a,b,c,d;

    while(cin>>d1>>d2>>d3){

        a=2*d1+2*d2;

        b=2*d1+2*d3;

        c=2*d2+2*d3;

        d=d1+d2+d3;

        cout<<min(min(a,b),min(c,d))<<endl;

    }



    return 0;

}