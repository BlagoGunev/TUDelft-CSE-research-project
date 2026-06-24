#include <map>

#include <set>

#include <stack>

#include <queue>

#include <cmath>

#include <string>

#include <vector>

#include <cstdio>

#include <cctype>

#include <cstring>

#include <sstream>

#include <cstdlib>

#include <iostream>

#include <algorithm>

#pragma comment(linker,"/STACK:102400000,102400000")



using namespace std;

#define   MAX           100005

#define   MAXN          1000005

#define   maxnode       105

#define   sigma_size    2

#define   lson          l,m,rt<<1

#define   rson          m+1,r,rt<<1|1

#define   lrt           rt<<1

#define   rrt           rt<<1|1

#define   middle        int m=(r+l)>>1

#define   LL            long long

#define   ll            long long

#define   ull           unsigned long long

#define   mem(x,v)      memset(x,v,sizeof(x))

#define   lowbit(x)     (x&-x)

#define   pii           pair<int,LL>

#define   bits(a)       __builtin_popcount(a)

#define   mk            make_pair

#define   limit         10000



//const int    prime = 999983;

const int    INF   = 0x3f3f3f3f;

const LL     INFF  = 0x3f3f;

//const double pi    = acos(-1.0);

const double inf   = 1e18;

const double eps   = 1e-9;

const LL     mod   = 998244353;

const ull    mx    = 133333331;



/*****************************************************/

inline void RI(int &x) {

      char c;

      while((c=getchar())<'0' || c>'9');

      x=c-'0';

      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';

 }

/*****************************************************/

/****/

/****/

int a[300010] ;

double p[3] ;

int n ;

bool judge(double d){

    double cnt = -1 ;

    int nt = 0 ;

    double k[3] ;

    for(int i=1;i<=n;i++){

        if(a[i] > cnt){

            if(nt == 3){

                return false ;

            }

            k[nt ++] = a[i] + d ;

            cnt = a[i] + 2*d ;

        }

    }

    for(int i=nt;i<3;i++) k[i] = 0 ;

    for(int i=0;i<3;i++) p[i] = k[i] ;

    return true ;

}

int main(){

    cin >> n ;

    for(int i=1;i<=n;i++){

        scanf("%d" , a+i) ;

    }

    sort(a+1 , a+n+1) ;

    double l = 0 , r = 2e9+1 ;

    double ans = 0 ;

    int num = 200 ;

    while(r - l > 1e-7 && num != 0 ){

        double m = (l + r) / 2.0 ;

        ///cout << l << " " << r << endl ;

        ///cout << m << endl ;

        int res = judge(m) ;

        if(res == 1) {

            ans = m ; r = m ;

        }

        else l = m ;

        num -- ;

    }

    printf("%.6f\n" , ans) ;

    for(int i=0;i<3;i++){

        printf("%.6f" , p[i]) ;

        if(i == 2) printf("\n") ;

        else printf(" ") ;

    }

}