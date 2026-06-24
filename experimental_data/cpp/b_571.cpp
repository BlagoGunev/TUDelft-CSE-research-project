#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#define N 524288
#define K 8192
int a[N],dpa[K],dpb[K];
int main()
{
    int n,k,x,y,dx,dy,t;
    scanf("%d%d",&n,&k);
    y=n%k,x=k-y;
    dx=n/k,dy=dx+1;
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    std::sort(a,a+n);
    t=a[n-1]-a[0];
    for(int i=n-1;i;--i)a[i]-=a[i-1];
    dpa[0]=0;
    for(int i=1;i<=y;++i)dpa[i]=dpa[i-1]+a[i*dy];
    for(int i=1;i<=x;++i)
    {
        dpb[0]=dpa[0]+a[i*dx];
        for(int j=1;j<=y;++j)
        {
            dpb[j]=std::max(dpa[j],dpb[j-1])+a[i*dx+j*dy];
        }
        memcpy(dpa,dpb,sizeof(dpa));
    }
    printf("%d\n",t-dpa[y]);
    return 0;
}