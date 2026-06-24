/* --- Author: Vladimir Smykalov, enot.1.10@gmail.com --- */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;

/* --- main part --- */

#define TASK "a"

const int maxn = (int)1e5 + 10;

int a[maxn];
int b[maxn];

char s[maxn];

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%s", s);
    int n = strlen(s);
    forn(i, n) a[i] = s[i] - '0';
    scanf("%s", s);
    int m = strlen(s);
    forn(i, m) b[i] = s[i] - '0';
    reverse(a, a + n);
    reverse(b, b + m);
    int mx = max(n, m);
    int res = -1;
    for (int i = mx; i >= 0; --i)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        if (a[i] > b[i])
        {
            if (a[i] > b[i] + 1 || i <= 1)
            {
                res = 0;
                break;
            }
            a[i - 1] += 1;
            a[i - 2] += 1;
        }
        if (a[i] < b[i])
        {
            if (a[i] < b[i] - 1 || i <= 1)
            {
                res = 1;
                break;
            }
            b[i - 1] += 1;
            b[i - 2] += 1;
        }
    }
    if (res == -1) printf("=\n");
    if (res == 0) printf(">\n");
    if (res == 1) printf("<\n");
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}