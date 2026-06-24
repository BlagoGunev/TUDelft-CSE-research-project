#include <bits/stdc++.h>
#include <algorithm>

#include <bitset>

#include <cassert>

#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <deque>

#include <fstream>

#include <iostream>

#include <list>

#include <map>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <vector>



using namespace std;



#define pi acos(-1)

#define gcd(a,b) __gcd(a,b)

#define PB push_back

#define SIZE(x) (int)x.size()

#define clr(x,y) memset(x,y,sizeof(x))

#define MP(x,y) make_pair(x,y)

#define ALL(t) (t).begin(),(t).end()

#define FOR(i,n,m) for (int i = n; i <= m; i ++)

#define ROF(i,n,m) for (int i = n; i >= m; i --)

#define RI(x) scanf ("%d", &(x))

#define RII(x,y) RI(x),RI(y)

#define RIII(x,y,z) RI(x),RI(y),RI(z)

#define lson l , m , rt << 1

#define rson m + 1 , r , rt << 1 | 1





typedef long long ll;

typedef long long LL;

typedef unsigned int uint;

typedef unsigned long long ull;





const ll mod = 1e9+7;

const int INF = 1e9;

const double EPS = 1e-8;



/**************************************END************************************/



int a,b,c,l;ll ans;



ll f(int a,int b,int c){

    ll res=0;

    for (int i=0;i<=l;i++){

        int t=min(l-i,c+i-a-b);

        if (t>=0) res+=1ll*(t+2)*(t+1)/2;

    }

    return res;

}



int main(){

    scanf("%d%d%d%d",&a,&b,&c,&l);

    for (int i=0;i<=l;i++) ans+=1ll*(i+2)*(i+1)/2;

    ans-=f(c,b,a),ans-=f(b,a,c),ans-=f(c,a,b);

    printf("%lld\n",ans);

    return 0;

}