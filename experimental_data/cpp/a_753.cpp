#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int q=0,biaoji=0;
    for(int i=1; i<=n; i++)
    {
        q+=i;
        if(q<=n)
            biaoji=i;
        else
            break;
    }
    printf("%d\n",biaoji);
    q=0;
    for(int i=1; i<biaoji; i++)
    {
        printf("%d ",i),q+=i;

    }
    printf("%d\n",n-q);
}