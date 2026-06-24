#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<string>
#include<functional>
using namespace std;
int n,a[25][61],ans;
int main()
{
    ios::sync_with_stdio(false);
    int i,xx,yy;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>xx>>yy;
        a[xx][yy]++;
        if(a[xx][yy]>ans)
            ans=a[xx][yy];
    }
    cout<<ans;
    return 0;
}