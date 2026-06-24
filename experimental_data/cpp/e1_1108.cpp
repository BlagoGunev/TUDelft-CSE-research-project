#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int c[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int b[m][2];
    for(int i=0;i<m;i++)
        cin>>b[i][0]>>b[i][1];
    int ma=-2000000,flag=-1;
    for(int i=0;i<n;i++)
    {
        memset(c,0,sizeof(c));
        for(int j=0;j<m;j++)
        {
            if(i>=b[j][0]-1 && i<=b[j][1]-1){
                c[b[j][0]-1]-=1;
                c[b[j][1]]+=1;
            }
        }
        for(int j=1;j<n;j++)
            c[j]+=c[j-1];
        int mini=2000000,maxi=-2000000;
        for(int j=0;j<n;j++)
        {
            if(a[j]+c[j]<mini)
                mini=a[j]+c[j];
            if(a[j]+c[j]>maxi)
                maxi=a[j]+c[j];
        }
        if(maxi-mini>ma){
            ma=maxi-mini;
            flag=i;
        }
    }
    cout<<ma<<endl;
    int count=0;
    for(int i=0;i<m;i++)
    {
        if(flag>=b[i][0]-1 && flag<=b[i][1]-1)
            count++;
    }
    cout<<count<<endl;
    for(int i=0;i<m;i++)
    {
        if(flag>=b[i][0]-1 && flag<=b[i][1]-1)
            cout<<i+1<<" ";
    }
    return 0;
}