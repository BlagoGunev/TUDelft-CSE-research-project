#include<stdio.h>
int main()
{
    int a,b,n=0;
    scanf("%d%d",&a,&b);
    if(a==0 || b==0)
        printf("0\n");
    else
    {
        while(a<=b)
        {
            a=a*3;
            b=b*2;
            n++;
        }
        printf("%d\n",n);
    }
    return 0;
}