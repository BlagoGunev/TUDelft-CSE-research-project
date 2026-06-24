#include<stdio.h>
int main()
{
    int i,j,k,n,a,l,b;
    char s[1005];
    scanf("%d",&n);
    scanf("%s",&s);
    a=0;
    b=0;
    for(i=0; i<n; i++)
    {
        if(s[i]=='0')
            a++;
        else
            b++;
    }
    if(b)
    {
        printf("1");
        for(i=1; i<=a; i++)
            printf("0");
    }
    else
        printf("0");
    printf("\n");
    return 0;
}