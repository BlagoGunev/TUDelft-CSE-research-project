#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,i,index;
    cin>>n>>x;
    int a[n];
    int hash[101]={0};
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        hash[a[i]]++;
    }

        int count=0;
        for(i=0;i<x;i++)
        {
            if(hash[i]==0)
            count++;
        }
        if(hash[x]==1)
        count=count+1;
        cout<<count;
    return 0;
}