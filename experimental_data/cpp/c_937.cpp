#include<stdio.h>
long long t,k,d,ans;
int main()
{
    scanf("%lld%lld%lld",&k,&d,&t);
    long long x;
    if(k%d)
    {
        x=(k/d+1)*d;
    }
    else
    {
        x=k;
    }
    t*=2;
    long long y=t/(x+k);
    ans+=y*x;
    t-=y*(x+k);
    if(t>=2*k)
    {
        ans+=t-k;
        printf("%lld.0\n",ans);
    }
    else
    {
        ans+=t/2;
        if(t%2)
            printf("%lld.5\n",ans);
        else
            printf("%lld.0\n",ans);
    }
    return 0;
}