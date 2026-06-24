#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n]={};
    int f[605]={};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=600;i++)
        if(f[i]>=1)
            cnt++;
    cout<<cnt<<endl;
    return 0;
}