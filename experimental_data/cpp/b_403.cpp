#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define forv(i, v) for(int i=0;i<v.size();++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 5000 + 3, INF = 1000*1000*1000;
const ld  eps = 1e-9;

int n, m;
int a[N];
set<int> b;
int g[N];
map<int, int> cache;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int calc(int x) {
    if (cache.count(x))
        return cache[x];
    int y = x;
    int res = 0;
    for(int i = 2; i * i <= x; i++) {
        if (x % i)
            continue;
        while (x % i == 0) {
            res += b.count(i) ? -1 : 1;
            x /= i;
        }
    }
    if (x != 1)
        res += b.count(x) ? -1 : 1;     
    cache[y] = res;
    return res;
}

map<int, int> z;

bool solve() {
    if (scanf("%d%d", &n, &m) != 2)
        return false;
    forn(i, n)
        scanf("%d", &a[i]);
    b.clear();
    forn(i, m) {
        int t; 
        scanf("%d", &t);
        b.insert(t);
    }
    g[0] = a[0];
    for(int i = 1; i < n; i++) {
        g[i] = gcd(a[i], g[i - 1]);
    }
    z.clear();
    z[1] = 0;
    for(int i = n - 1; i >= 0; i--) {
        map<int, int> next;
        for(map<int, int>::iterator it = z.begin(); it != z.end(); it++) {
            int j = it->ft;
            int val = it->sc;
            int d = calc(a[i] / j);

            if (!next.count(j)) {
                next[j] = val + d;
            }
            next[j] = max(next[j], val + d);

            int nj = g[i];

            if (nj == j)
                continue;
            d = calc(a[i] / nj);
            if (!next.count(nj)) {
                next[nj] = val + d;
            }
            next[nj] = max(next[nj], val + d);
        }
        z = next;
    }

    int ans = -INF;
    for(map<int, int>::iterator it = z.begin(); it != z.end(); it++) {
        ans = max(ans, it->sc);
    }   
    cout << ans << endl;
    
    return true;
}

int main () {   
#ifdef IKAR
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (solve())
        puts("");
}