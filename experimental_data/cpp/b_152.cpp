#include <bits/stdc++.h>
#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int MaxN = 1e4 + 10;

const int INF = 0x3f3f3f3f;

typedef long long LL;

int dx[MaxN] , dy[MaxN];



int main()

{

    LL n , m , x , y , k;

    scanf("%lld %lld", &n , &m);

    scanf("%lld %lld", &x , &y);//printf("***x = %zd , y = %d",x ,y);

    scanf("%lld",&k);

    for(int i = 0 ; i < k ; i++){

        scanf("%lld %lld",&dx[i] , &dy[i]);

    }

    int  a , b;

    LL ans = 0;

    for(int i = 0 ; i < k ; i++){

        if(dx[i] == 0) a = INF;

        if(dy[i] == 0) b = INF;

        if(dx[i] < 0){

            a = (1 - x)/dx[i];

        }

        else if(dx[i] > 0){

            a = (n - x)/dx[i];

        }

        if(dy[i] < 0){

            b = (1 - y)/dy[i];

        }

        else if(dy[i] > 0){

            b = (m - y)/dy[i];

        }

        a = min(a,b);

        //printf("***a = %lld x = %lld y = %lld\n",a,x , y);

        x += dx[i]*a;

        y += dy[i]*a;

        ans += a;

        //printf("a = %d x = %lld y = %d\n",a,x , y);

    }

    printf("%lld\n",ans);

    return 0;

}