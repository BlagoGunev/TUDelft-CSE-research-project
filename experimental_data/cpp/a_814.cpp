#include <bits/stdc++.h>
using namespace std;
#define MX 105

int a[MX];
int b[MX];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=k;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+1+k,cmp);
    int t=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==0)
        {
            a[i]=b[t++];
        }
    }
    int ok=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]<a[i-1])
            ok=0;
    }
    if (ok)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}