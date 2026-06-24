#include <cstdio>

int main()
{
    int y,k,n,m;
    int flag = 0;
    m = 0;
    scanf("%d %d %d",&y,&k,&n);
    for(int i = 1; i*k <= n; i++)
    {
        if(i*k > y)
        {
            ++m;
            flag = 1;
            if(m == 1)
                printf("%d",i*k-y);
            else
                printf(" %d",i*k-y);
        }
    }
    if(flag == 0)
        printf("-1");
    printf("\n");
    return 0;

}