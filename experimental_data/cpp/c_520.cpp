#include<stdio.h>
#define LL long long
const int mod = 1e9+7;
const int maxn = 1e5+10;
int n,num[26];
char s[maxn];
LL quitpow(int n,int m)
{
    LL res=1,k=n;
    while(m)
    {
        if(m&1) res = (res*k)%mod;
        m>>=1;
        k=(k*k)%mod;
    }
    return res;
}
int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        num[s[i]-'A']++;
    int maxx=0,cou=0;
    for(int i=0;i<26;i++)
    {
        if(num[i]>maxx)
        {
            maxx=num[i];
            cou=1;
        }
        else if(num[i]==maxx)
            cou++;
    }
    printf("%I64d\n",quitpow(cou,n));
    return 0;
}