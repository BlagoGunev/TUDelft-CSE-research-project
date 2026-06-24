#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int pre=1,n,m,i,t;
    scanf("%d%d",&n,&m);
    long long ans=0;
    for(i=0;i<m;i++)
    {
        scanf("%d",&t);
        if(t<pre) ans+=n;
        pre=t;
    }
    ans+=pre-1;
    cout<<ans<<endl;
    return 0;
}