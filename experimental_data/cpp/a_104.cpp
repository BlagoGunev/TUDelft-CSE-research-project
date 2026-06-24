#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n<11||n>21)
        printf("0");
    else
    if(n==20)
        printf("15");
    else
        printf("4");
    return 0;
}