#include <bits/stdc++.h>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-10
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define zero(a) fabs(a)<eps
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;
long long dp1[5005];
long long dp2[5005];
int main()
{
    int n,m,k;
    long long num[5005],max1;
    scanf("%d%d%d",&n,&m,&k);
    num[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
        num[i]+=num[i-1];
    }
    for(int i=1;i<=k;i++)
    {
        clearall(dp2,0);
        max1=0;
        for(int j=0;j<=n-m*k;j++)
        {
            max1=max(max1,dp1[j]);
            //printf("%lld ",dp1[j]);
            dp2[j]=max1+num[i*m+j]-num[(i-1)*m+j];
        }
        //puts("");
        memcopyall(dp1,dp2);
    }
    max1=-1ll;
    for(int i=0;i<=n-m*k;i++)
    {
        max1=max(max1,dp1[i]);
    }
    printf("%lld\n",max1);
    return 0;
}