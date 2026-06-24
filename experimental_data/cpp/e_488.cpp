#include <stdio.h>

typedef long long INT64;
const int N=100001;
char sieve[N+1];
int a[4]={1,3,2,4};
INT64 inv[N+1];

int main(int argc, char* argv[])
{
    int i, j, n;
    scanf("%d", &n);
    for(i=2;i<=N;i++)
    {
        if(!sieve[i])
        {
            for(j=i+i;j<=N;j=j+i)
            {
                sieve[j]=1;
            }
        }
    }
    if(n==4)
    {
        printf("YES\n");
        for(i=0;i<4;i++)
        {
            printf("%d\n", a[i]);
        }
    }
    else if(n==1)
    {
        printf("YES\n");
        printf("%d\n", 1);
    }
    else if(sieve[n]==0)
    {
        inv[1]=1;
        for(i=2;i<=n;i++)
        {
            inv[i]=inv[n%i]*(n - n/i)%n;
        }
        printf("YES\n");
        printf("%d\n", 1);
        for(i=2;i<n;i++)
        {
            int _inv=inv[i-1]*i%n;
            printf("%d\n", _inv);
        }
        printf("%d\n", n);
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}