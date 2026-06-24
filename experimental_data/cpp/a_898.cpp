#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if (n % 10 > 5)
        n = n + (10-n%10);
    else
        n = n - n%10;
    printf("%d",n);

}