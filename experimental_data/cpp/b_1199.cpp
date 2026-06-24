#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,l;
    cin>>h>>l;
    long long int a = h+l;
    a=a*(l-h);
    h=2*h;
    long long int d = a/h;
    cout<<d<<".";
    d = a%h;
    d=d*10;
    for(int i=0;i<13;i++)
    {
        long long int x = d/h;
        cout<<x;
        d = d%h;
        d=d*10;
    }
}