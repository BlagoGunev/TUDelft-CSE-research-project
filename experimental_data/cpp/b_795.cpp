/**
 *    author:  [itmo] enot.1.10
 *    created: 05.04.2017 20:02:09       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 1e5 + 10;

pi a[N];
pi b[N];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    forn(i, n) scanf("%d%d", &a[i].F, &a[i].S);
    forn(i, n) a[i].F *= -1;
    forn(i, m) scanf("%d%d", &b[i].F, &b[i].S);
    forn(i, m) b[i].F *= -1;
    sort(a, a + n);
    sort(b, b + m);

    ll res = 0;
    int i = 0;
    int j = 0;
    int cur = 0;
    ll val = 0;
    while (j < m && b[j].S + cur <= d)
    {
        cur += b[j].S;
        val -= b[j].F;
        j++;
    }
    while (i < n)
    {
        cur += a[i].S;
        val -= a[i].F;
        while (j >= 0 && cur > d)
        {
            j--;
            cur -= b[j].S;
            val += b[j].F;
        }
        if (cur > d) break;
        if (j > 0) res = max(res, val);
        i++;
    }
    printf("%lld\n", res);



    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}