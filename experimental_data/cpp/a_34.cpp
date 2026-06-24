#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int N;
    int i,j,k;
    int rec[200];
    cin>>N;
    for(i=1;i<=N;i++)
        cin>>rec[i];
    int ans=500000,x,y;
    for(i=1;i<N;i++)
    {
        int tt=rec[i+1]-rec[i];
        if(tt<0)tt=-tt;
        if(tt<ans)
        {
            ans=tt;
            x=i,y=i+1;
        }
    }
    int tt=rec[1]-rec[N];
    if(tt<0)tt=-tt;
    if(ans>tt)
    {
        ans=tt;
        x=i,y=1;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}