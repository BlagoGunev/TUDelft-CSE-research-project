#include <bits/stdc++.h>
#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <cstdlib>

#include <algorithm>

#include <queue>

#include <stack>

#include <map>

#include <set>

#include <vector>

#include <string>

#define INF 0x3f3f3f3f

#define eps 1e-8

#define SIZE (2000+10)

#define Ri(a) scanf("%d", &a)

#define Rl(a) scanf("%lld", &a)

#define Rf(a) scanf("%lf", &a)

#define Rs(a) scanf("%s", a)

#define Pi(a) printf("%d\n", (a))

#define Pf(a) printf("%lf\n", (a))

#define Pl(a) printf("%lld\n", (a))

#define Ps(a) printf("%s\n", (a))

#define CLR(a, b) memset(a, (b), sizeof(a))

#define INT_MAX 2147483647

#define LL_MAX 9223372036854775807

#define ll int64_t

#define lson l, mid, rt<<1

#define rson mid+1, r, rt<<1|1

#define PI acos(-1.0)

const long long MOD = 1000000007;

using namespace std;

/*

    关于异或的性质：首先，连续取2个相邻数的话，异或和很可能就为1 ；连续取4个相邻数的话，异或和很可能就为0 ；

    显然的是，在5个连续数a,b,c,d,e中， a^b^c^d和b^c^d^e必然有一个为0。

    所以我们dfs的范围可以非常小，当k>=4时，我们在区间的前5个连续的数中一定能找到异或为0的答案

*/

ll l,r,k,top;

ll a[20],b[20];

ll ans,ansnum;

void dfs(ll p,ll v,ll num)

{

    if(num && v < ans)

    {

        ans = v;

        ansnum = num;

        memcpy(b,a,sizeof(b));           //把数组a copy到数组b

    }

    if(p > top || num == k)     return ;

    dfs(p+1,v,num);

    a[num+1] = p;

    dfs(p+1,v^p,num+1);

}

int main()

{

    Rl(l),Rl(r),Rl(k);

    if(k == 3)

    {

        ll x,y,z;

        for(ll i = 2; i <= r; i<<=1)

        {

            if(i <= l)

                continue;

            z = i-1;

            y = z + i/2;

            x = z^y;

            if(z >= l && x <= r)

            {

                printf("0\n3\n");

                printf("%lld %lld %lld\n",x,y,z);

                return 0;

            }

        }

    }                   //如果k == 3情况 取三个数 直接找到了异或为0的答案就结束了；如果没找到，还要在这里接着找

    top = min(r,l+4);

    ans = 1e18;

    dfs(l,0,0);

    Pl(ans);

    Pl(ansnum);

    for(int i = 1; i <= ansnum; i++)

        printf("%lld ",b[i]);

    printf("\n");

    return 0;

}