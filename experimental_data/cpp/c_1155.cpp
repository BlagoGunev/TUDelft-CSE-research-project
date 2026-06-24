/*
Author :: Shourov Chowdhury
............SUST_MATH14..........
*/
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { Long a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})
#define DB if(0) 
#define D(x) cout << #x " is " << x << endl
#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

using namespace std;

typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<string> VS;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; 
    x*=sgn; return ~c;
}

const int INF = 2000000009;
const int MX = 300005;
const double EPS = 1e-9;
const int MOD = 1000000007;

/**********************Code starts here*********************************/
Long x[MX],p[MX];

int main()
{
    //std::ios_base::sync_with_stdio(false);

    int n = II(),m=II();
    for (int i = 0;i<n;i++) x[i] = LL();
    Long g = 0;
    for (int i = 1;i<n;i++) g = __gcd(g,x[i]-x[i-1]);
    for (int i = 0;i<m;i++) p[i] = LL();
    for(int i = 0;i<m;i++){
        if (g%p[i]==0LL){
            printf("YES\n");
            printf("%lld %d\n",x[0],i+1 );
            return 0;
        }
    }
    printf("NO\n");
    

    return 0;
}