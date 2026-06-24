#include <bits/stdc++.h>
using namespace std;
int pr[100005],n,d[100005];
int main()
{
    int i,t1,t2;
    scanf("%d",&n);
    memset(pr,-1,sizeof(pr));
    for (i=0; i<n; i++)
    {
        scanf("%d",&t1);
        if (pr[t1] == -1)
        {
            pr[t1]=i;
            d[t1]=0;
        }
        else if (pr[t1] != -1 && pr[t1] != -2)
        {
            if (d[t1] == 0)
            {
                d[t1]=i-pr[t1];
                pr[t1]=i;
            }
            else
            {
                if (d[t1] != i-pr[t1])
                    pr[t1]=-2;
                else
                    pr[t1]=i;
            }
        }
    }
    t2=0;
    for (i=1; i<=100000; i++)
    {
        if (pr[i] == -1 || pr[i] == -2)
            continue;
        t2++;
    }
    printf("%d\n",t2);
    for (i=1; i<=100000; i++)
    {
        if (pr[i] == -1 || pr[i] == -2)
            continue;
        printf("%d %d\n",i,d[i]);
    }
    return 0;
}