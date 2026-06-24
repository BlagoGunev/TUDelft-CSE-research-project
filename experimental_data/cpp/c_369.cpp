#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <fstream>
using namespace std;


//LOOP
#define FF(i, a, b) for(int i = (a); i < (b); ++i)
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FED(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)


//OTHER
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()


//INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RIV(n, m, k, p) scanf("%d%d%d%d", &n, &m, &k, &p)
#define RV(n, m, k, p, q) scanf("%d%d%d%d%d", &n, &m, &k, &p, &q)
#define RS(s) scanf("%s", s)


//OUTPUT
#define WI(n) printf("%d\n", n)
#define WS(n) printf("%s\n", n)


//debug
//#define online_judge
#ifndef online_judge
#define debugt(a) cout << (#a) << "=" << a << " ";
#define debugI(a) debugt(a) cout << endl
#define debugII(a, b) debugt(a) debugt(b) cout << endl
#define debugIII(a, b, c) debugt(a) debugt(b) debugt(c) cout << endl
#define debugIV(a, b, c, d) debugt(a) debugt(b) debugt(c) debugt(d) cout << endl
#else
#define debugI(v)
#define debugII(a, b)
#define debugIII(a, b, c)
#define debugIV(a, b, c, d)
#endif

#define sqr(x) (x) * (x)
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
const int MOD = 100000007;
const int MAXN = 100100;
const double PI = acos(-1.0);

int f[MAXN];
int cnt[MAXN];

int get(int n)
{
    if (f[n] != n)
        f[n] = get(f[n]);
    return f[n];
}

void merge(int a, int b)
{
    int fa = get(a), fb = get(b);
    if (fa < fb) swap(fa, fb);
    f[fa] = fb;
}

void init()
{
    REP(i, MAXN)
        f[i] = i;
}


int main()
{
//    freopen("in.txt", "r", stdin);
    int n, a, b, flag;
    while (~RI(n))
    {
        init();
        vector<int> ans;
        CLR(cnt, 0);

        REP(i, n - 1)
        {
            RIII(a, b, flag);
            if (flag == 1)
                merge(a, b);
            else
            {
                cnt[get(a)]++;
                cnt[get(b)]++;
            }
        }
        FE(i, 1, n)
        {
            if (get(i) != i)
            {
                cnt[get(i)] += cnt[i];
                cnt[i] = 0;
            }
        }
        FE(i, 2, n)
        {
            if (cnt[i] == 1)
                ans.push_back(i);
        }
        cout << ans.size() << endl;
        REP(i, ans.size())
        {
            if (i != 0) putchar(' ');
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}