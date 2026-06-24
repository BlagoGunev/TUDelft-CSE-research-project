#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#define INF 0x3f3f3f3f
#define LL long long
#define pii pair<int,int>
using namespace std;
const double pi = 2*acos(0.0);
const int maxn =  3e5 + 5;
const int maxm = 4e5 + 10;
const int mod = 1e9+7;


int main()
{
    LL n,k;
    cin >> n >> k;
    if(n>k*(k-1)) printf("NO\n");
    else
    {
        printf("YES\n");
        int cnt = 0;
        for(int i=1;i<=k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
                printf("%d %d\n",i,j);
                cnt++;
                if(cnt==n) return 0;
                printf("%d %d\n",j,i);
                cnt++;
                if(cnt==n) return 0;
            }
        }
    }
    return 0;
}