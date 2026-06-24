#include<stdio.h>
int main()
{
    int t,i;
    int a[5005];
    while(~scanf("%d",&t))
    {
        for(i=1; i<=t; i++)
        {
            scanf("%d",&a[i]);
        }
        int flag=0;
        for(i=1; i<=t; i++)
        {
            int x=a[a[i]];
            if(a[x]==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}