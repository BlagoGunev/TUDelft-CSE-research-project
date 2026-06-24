#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==0&&b==0)
    printf("NO");
    else if(a==b||a+1==b||b+1==a)
    printf("YES");
    else
    printf("NO");
}