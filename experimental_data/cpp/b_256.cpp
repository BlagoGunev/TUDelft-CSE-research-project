#include <bits/stdc++.h>
#define sqr(x) ((x)*(x))
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int64_t n,x,y,c,ans,p=1,t,q=1;
int main()
{
    cin>>n>>x>>y>>c;
    while(p<c)
    {
        ans++,p=q+ans*4,q=p;
        if(x+ans>n) p-=sqr(x+ans-n);
        if(y+ans>n) p-=sqr(y+ans-n);
        if(x-ans<1) p-=sqr(ans-x+1);
        if(y-ans<1) p-=sqr(ans-y+1);
        if(ans>=2*n+2-x-y) t=ans-2*n+x+y,p+=t*(t-1)/2;
        if(ans>=n+1-x+y) t=ans-n+x-y+1,p+=t*(t-1)/2;
        if(ans>=n+1-y+x) t=ans-n+y-x+1,p+=t*(t-1)/2;
        if(ans>=x+y) t=ans-x-y+2, p+=t*(t-1)/2;
    }
    cout<<ans<<endl;
}