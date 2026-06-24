#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

long long n,i,j,k,q,a[1000],m;

int main()
{
    cin>>n>>m;
    if(n==1 || m==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=2;i<=n;i+=2)
    {
        for(j=2;j<=m;j+=2)
        {
            q+=(n+1-i)*(m+1-j);
        }
    }
    cout<<q<<endl;
    return 0;
}