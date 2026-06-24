#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
int sum[30];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(sum , 0, sizeof(sum));
    char tmp;
    getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%c", &tmp);
        sum[tmp-'A'] ++;
    }
    sort(sum, sum+26);
    int rest = k;
    long long res = 0;
    for(int i = 25; i >= 0 && rest!=0; i--)
    {
        if(rest >= sum[i])
            res += (long long )sum[i]*sum[i], rest -= sum[i];
        else
        {
            res += (long long )rest*rest;
            break;
        }
    }
    printf("%I64d",res);
    return 0;
}