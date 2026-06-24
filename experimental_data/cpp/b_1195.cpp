#include <bits/stdc++.h>
using namespace std;
void tknp(long n,long k)
{
    long d=1,c=n;
    while(d<=c)
    {
        long long g=(d+c)/2;
        if(g*(g+1)/2-n+g==k) {cout<<n-g;return;}
        else if(g*(g+1)/2-n+g<k) d=g+1;
        else c=g-1;
    }
}
int main()
{
    long n,k;
    cin>>n>>k;
    tknp(n,k);
    return 0;
}