#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define oo !=EOF

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        getchar();
        LL ans[10] = {0};
        LL sum = 0;
        char ch;
        while((ch = getchar())!='\n')
        {
            ans[ch - '0'] ++;
            sum += ch - '0';
        }
        int temp = 0;
        LL tans = 0;
        while(sum < k)
        {
            if(sum + ans[temp]*(9-temp)<=k)
            {
                sum += ans[temp]*(9-temp);
                tans += ans[temp];
            }
            else
            {
                LL t = (k - sum)/(9-temp);
                tans += t;
                if((k-sum)%(9-temp)!=0)
                    tans ++;
                sum = k;
            }
            temp++;
        }
        printf("%lld\n",tans);
    }
    return 0;
}