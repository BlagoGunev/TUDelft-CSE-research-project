#include <stdio.h>
#include <algorithm>
#define MAX 5003

using namespace std;

int inp[MAX],last[MAX];

int main()
{
    int n,m,i,mlen,lo,hi,mid;
    double x;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) scanf("%d%lf",&inp[i],&x);
    mlen=0;
    for (i=0;i<n;i++)
    {
        lo=0;
        hi=mlen;
        while (lo<hi)
        {
            mid=(lo+hi+1)/2;
            if (last[mid]<=inp[i]) lo=mid;
            else hi=mid-1;
        }
        if (lo==mlen)
        {
            mlen++;
            last[mlen]=inp[i];
        }
        else last[lo+1]=min(last[lo+1],inp[i]);
    }
    printf("%d\n",n-mlen);
    return 0;
}