#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
#define MOD 1000000007

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

const int mod = 65536;
const int N = 100002;
struct hmap {
    pair<int, string> key[N + 1];
    unsigned ll ck[N + 1];
    int val[N + 1], nx[N + 1], last[mod], hc;
    hmap() {
        reset();
    }
    inline void reset() {
        memset(last, -1, sizeof(last));
        hc = 0;
    }
    inline unsigned ll gh(const pair<int, string> &k) {
        unsigned ll h = 1;
        h = (h * 1000000009) ^ (k.x + 101);
        rept(i, L(k.y)) {
            h = (h * 10000019) ^ (k.y[i] + 2);
        }
        return h;
    }
    inline int &add(const pair<int, string> &k) {
        unsigned ll h = gh(k);
        int th = h & (mod - 1);
        for (int w = last[th]; w >= 0; w = nx[w]) {
            if (ck[w] == h) return val[w];
        }
        key[hc] = k; ck[hc] = h; val[hc] = 0; nx[hc] = last[th]; last[th] = hc++;
        return val[hc - 1];
    }
};

int a,b,c,d,n,m,k;
hmap dp[2];
//map<pair<int, string>, int> cur, nx;
char now[52], tmp[52];
int ce[102][102];
inline void decode(string s, char *a) {
    memset(a, 0, 52 * sizeof(char));
    rept(i, min(51, L(s))) {
        a[i] = s[i] - 1;
    }
}
inline void code(char *a, string &s) {
    int last = 0;
    rept(i, 51) {
        if (a[i]) last = i;
    }
    s.resize(last + 1);
    rept(i, last + 1) {
        s[i] = a[i] + 1;
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    rept(i, 101) {
        ce[i][0] = ce[i][i] = 1;
        rep(j, i - 1) {
            ce[i][j] = ce[i - 1][j - 1] + ce[i - 1][j];
            if (ce[i][j] > 101) ce[i][j] = 101;
        }
    }

    scanf("%d%d%d", &n, &m, &k);
    int cur = 1, nx = 0;
    rep(i, 50) {
        C(now);
        now[i] = 1;
        string s;
        code(now, s);
        int &t = dp[nx].add(mp(n - i, s));
        t  = 1;
    }

    int ans = 0;
    int ms = 0;
    FOR(i, 2, m) {
        swap(cur, nx);
        ms = max(ms, dp[cur].hc);
        dp[nx].reset();
        rept(it, dp[cur].hc) {
            int cd = dp[cur].val[it];
            if (!cd) continue;
            decode(dp[cur].key[it].y, now);
            int can = dp[cur].key[it].x, last = 0;
            rept(j, 51) {
                if (now[j]) last = j;
            }
            rep(cadd, can) {
				if (cadd > 50) break;
                C(tmp);
                rep(fr, last) {
                    if (!now[fr]) continue;
                    if (cadd < fr) break;
                    int ways = now[fr];
                    ways *= ce[cadd - 1][fr - 1];
                    if (ways > k) ways = k + 1;
                    if (cadd - fr == 0) {
                        if (ways <= k && ways) {
                            ans = (ans + (ll)cd * (m - i + 1)) % MOD;
                        }
                        continue;
                    }
                    tmp[cadd - fr] += ways;
                    if (tmp[cadd - fr] > k) tmp[cadd - fr] = k + 1;
                }
                int ns = can - cadd;
                rep(j, last) {
                    if (j > ns) {
                        tmp[j] = 0;
                    }
                    if (tmp[j] > k) {
                        FOR(z, j, last) tmp[z] = 0;
                        ns = min(ns, j - 1);
                        break;
                    }
                }
                if (!ns) continue;
                string h;
                code(tmp, h);
                
                int &t = dp[nx].add(mp(ns, h));
                add(t, cd);
            }
        }
    }
    printf("%d\n", ans);
}