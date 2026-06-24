#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<functional>

#include<cassert>

#include<iostream>

#include<queue>

#include<set>

#include<bitset>

using namespace std;

const int oo = 0x3f3f3f3f;

#define disp(x) cout << #x << "=" << x

#define mp make_pair

#define pb push_back

#define sp putchar(' ')

#define ln putchar('\n')

#define x first

#define y second

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<int, pii> ipii;

template<typename T>bool chkmin(T &a, T b){return b < a ? a = b, true : false;}

template<typename T>bool chkmax(T &a, T b){return b > a ? a = b, true : false;}

template<class T>void read(T &x)

{

    char c; int flag = 1;

    while((c = getchar()) < '0' || c > '9')

        if(c == '-') flag = -1;

    x = c - '0';

    while((c = getchar()) >= '0' && c <= '9')

        x = x * 10 + c - '0';

    x *= flag;

}

template<class T>void write(T x)

{

    if(x < 0) putchar('-'), x = -x;

    static char s[20]; int top = 0;

    while(x) s[++top] = x % 10 + '0', x /= 10;

    if(top == 0) putchar('0');

    while(top) putchar(s[top--]);

}

const int MAXN = 1e6 + 100;

const int mod = 1e9 + 7;

ll pwr(ll x, ll k, ll p) {ll ret = 1; for(; k; k >>= 1, x = x * x % p) if(k & 1) ret = ret * x % p;return ret;}

int id = 0;

int mex[MAXN];

int N, M;

int sg(int n)

{

    if(!M) {

        if(n == 1) return 1;

        if(n == 2) return 2;

        return n & 1 ? 0 : 1;

    }



    if(n == 1 || n == 3) return 1;

    if(n == 2) return 0;

    if(n == 4) return 2;

    if(n & 1) return 0;

    return (sg(n >> 1) == 1) ? 2 : 1;

}

int main()

{

    read(N), read(M); M = M & 1;

//    memset(sg, 0, sizeof(sg));



    int SG = 0;

    for(int i = 1, x; i <= N; ++i)

        read(x), SG ^= sg(x);

    puts(SG != 0 ? "Kevin" : "Nicky");



//    for(int i = 1; i <= 100; i ++)

//        printf("%3d  %2d\n", i, sg[i]);

//        write(i), sp, sp, write(sg[i]), ln;

    return 0;

}