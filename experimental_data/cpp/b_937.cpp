#include<stdio.h>
long long n,m;
int init(long long tem)
{
    for(long long i=2; i*i<=tem&&i<=n; i++)
    {
        if(tem%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        long long flag=0;
        for(long long i=m; i>n; i--)
        {
            if(init(i))
            {
                flag=i;
                break;
            }
        }
        if(flag)
        {
            printf("%lld\n",flag);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}