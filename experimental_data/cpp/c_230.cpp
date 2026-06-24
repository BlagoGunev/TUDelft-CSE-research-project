#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int sum[10001],arr[10001],tol;

int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    bool ok=true;
    for(int i=0;i<n;i++)
    {
        tol=1;
        for(int j=0;j<m;j++)
        {
            if(getchar()=='1')
            {
                arr[tol++]=j;
            }
        }
        getchar();
        if(tol==1)
        {
            ok=false;
            continue;
        }
        arr[0]=arr[tol-1]-m;
        arr[tol]=arr[1]+m;
        int idx=0,l,r;
        for(int j=0;j<m;j++)
        {
            r=j-arr[idx];
            l=arr[idx+1]-j;
            if(l==0)
                ++idx;
            sum[j]+=min(r,l);
        }
    }
    if(ok)
    {
        printf("%d\n",*min_element(sum,sum+m));
    }
    else
        printf("-1\n");
    return 0;
}