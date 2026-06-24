#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a;
char s[5555];
int sum[5555];
int t[55555];
int main()
{
    scanf("%d", &a);
    scanf("%s", s);
    int len = strlen(s);
    int k = 0;
    for(int i = 0; i < len; i++)
    {
        sum[i + 1] = sum[i] + s[i] - '0';

    }
    long long ans = 0;
    int tmp = 0;
    for(int i = 1; i <= len; i++)
    {
        for(int j = i; j <= len; j++)
        {
            int x = sum[j] - sum[i - 1];
            t[x]++;
            tmp++;
        }
    }
    if(a == 0)
    {
        ans+= (long long)t[0] * (long long)tmp * 2LL -  (long long)t[0]* (long long)t[0];
    }
    else
    {
        for(int i = 1; i <= 40000; i++)
        {
            if( a % i == 0 )
            {
                int z = a /i;
                if(z < 40000) ans +=(long long) t[i] *  (long long)t[z];
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}