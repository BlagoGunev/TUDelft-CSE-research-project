#include <stdio.h>
#include <string.h>

#define mod 1000000007
long long dp[100]={0};
long long binary[210]={0};

int main()
{
    binary[0]=1;
    for (int i=1; i<=200; i++)
        binary[i]=binary[i-1]*2%mod;

    char str[200];
    scanf("%s",str);
    int n=strlen(str);
    dp[0]=0;
    for (int i=1; i<=n; i++)
    {
        dp[i]=2*dp[i-1]%mod;
        if (str[n-i]=='1')
            dp[i]=(dp[i]+binary[(i-1)*2])%mod;
    }
    printf("%I64d\n",dp[n]);
    return 0;
}