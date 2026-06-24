#include<stdio.h>

int n;
int a,b,c;

int main()
{
    while(scanf("%d",&n)!=-1)
    {
        if(n==1)
        {
            scanf("%d",&a);
            printf("1\n");
        }
        else if(n==2)
        {
            scanf("%d %d",&a,&b);
            printf("2\n");
        }
        else
        {
            scanf("%d %d",&a,&b);
            int _max=2;
            int result=2;
            for(int i=3;i<=n;i++)
            {
                scanf("%d",&c);
                if(a+b==c)
                {
                    result++;
                }
                else
                    result=2;
                if(result>_max)
                    _max=result;
                a=b;
                b=c;
            }
            printf("%d\n",_max);
        }
    }
    return 0;
}