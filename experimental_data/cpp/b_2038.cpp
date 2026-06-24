#include<cstdio>
#include<iostream>
using namespace std;
const long long N=1e6+10,inf=1e10;
long long T,n,a[N],b[N],maxx;
long long l,r,mid,ans;
struct node
{
    long long xx,yy;
};
long long ck1(long long x)
{
    long long ans2=0,y=x;
    for(long long i=1;i<=n;i++)
    {
        long long sum=x+b[i];
        if(sum&1) ans2=1;
        if(sum<0) return 1;
        x=sum/2;
    }
    return (x-y)*2+ans2;
}
long long qy2(long long x)
{
    long long anss=0;
    for(long long i=1;i<=n;i++)
    {
        long long sum=x+b[i];
        x=sum/2;
        anss+=x;
    }
    return anss;
}
long long ck(long long x)
{
    for(long long i=1;i<=n;i++) b[i]=a[i]-x;
    long long ll=0,rr=inf,ss=-1,midd;
    while(ll<=rr)
    {
        midd=(ll+rr)/2;
        long long sum=ck1(midd);
        if(sum<0) rr=midd-1;
        else if(sum>0) ll=midd+1;
        else
        {
            ss=midd;
            break;
        }
    }
    return ss;
}
long long qy1(long long x)
{
	for(long long i=1;i<=n;i++) b[i]=a[i]-x;
    long long ll=0,rr=inf,ss=-1,midd;
    while(ll<=rr)
    {
        midd=(ll+rr)/2;
        long long sum=ck1(midd);
        if(sum>0) ll=midd+1;
        else if(sum<0) rr=midd-1;
        else
        {
            ss=midd;
            break;
        }
    }
    return qy2(ss);
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        maxx=0;
        for(long long i=1;i<=n;i++) scanf("%lld",&a[i]),maxx=max(maxx,a[i]);
        l=0,r=maxx,ans=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            long long sum=ck(mid);
            if(sum!=-1) l=mid+1,ans=mid;
            else r=mid-1;
        }
        if(ans==-1) printf("-1\n");
        else printf("%lld\n",qy1(ans));
    }
}