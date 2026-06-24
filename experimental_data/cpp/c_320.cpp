#include <stdio.h>
#include <string.h>
long long ans,such,so,the;
char a[200];
int main()
{
    while(scanf("%s",a)!=EOF)
    {
        int len=strlen(a);
        such=1;
        for(int i=0;i<len-1;i++)
        such=(such*2%1000000007);
        the=0;
        for(int i=0;i<=len-1;i++)
        the=(the*2+a[i]-'0')%1000000007;
        so=such;
        so=so*the%1000000007;
        printf("%I64d\n",so);
    }
}