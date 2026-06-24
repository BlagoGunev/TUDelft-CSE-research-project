#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,k;
    cin>>n>>k;
    int s=min(k-1,n-k);
    s+=n*3;
    if(n==2 )
        s=6;
    cout<<s;
    return 0;
}