#include<stdio.h>
int main()
{
    long long n, i, s = 0;
    scanf("%lld", &n);
    for(i= 1; i < n; i++)
    {
        if((n - i) % i == 0)
        {
            s++;
        }
    }
    printf("%lld", s);
    return 0;
}