#include<bits/stdc++.h>

using namespace std;
int i,j,sum=0,a[200],n;
int main()
{
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1){cout<<0<<endl;return 0;}
    for(i=2;i<=n;i++)
    {
        sum+=(i-1)*4*a[i];
    }
    cout<<sum<<endl;
}