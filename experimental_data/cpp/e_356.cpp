#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
//#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <list>
#include <unordered_map>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "flow2"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll MD = 1551513443;
const ll T = 25923;
const int N = 100100;
const int M = 100100;

string s;
int n, sum[27][N];
ll ans, ans1;
ll pw[N], h[N], dp[N], d[N];

inline ll get_hash(int l, int r) {
    ll ans = h[r];
    if (l)
        ans = (ans + MD - ((h[l - 1] * pw[r - l + 1]) % MD)) % MD;
    return ans;
}

inline int calc(int l, int r, int x) {
    int ans = sum[x][r];
    if (l)
        ans -= sum[x][l - 1];
    return ans;
}

void dfs(int l, int r, ll hh) {
    ll k = r - l + 1;
    if (k > 1)
        ans1 += k * k;
    //left
    int x = l - 1;
    if (x - k >= 0 && get_hash(x - k, x - 1) == hh && calc(x - k, x - 1, s[x]) == 0)
        dfs(x - k, x + k, (((((get_hash(x - k, x - 1) * T + s[x]) % MD) * pw[k]) % MD) + hh) % MD);
    //right
    x = r + 1;
    if (x + k < n && get_hash(x + 1, x + k) == hh && calc(x + 1, x + k, s[x]) == 0)
        dfs(x - k, x + k, (((((hh * T + s[x]) % MD) * pw[k]) % MD) + get_hash(x + 1, x + k)) % MD);
}

int main() {
    //FREOPEN;
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = (pw[i - 1] * T) % MD;
    cin >> s;
    n = sz(s);
    forn(i, n) {
        s[i] -= 'a' - 1;
        if (!i) {
            h[i] = ll(s[i]);
            sum[s[i]][i]++;
        }
        else {
            h[i] = (h[i - 1] * T + ll(s[i])) % MD;
            for (int j = 1; j < 27; j++)
                sum[j][i] = sum[j][i - 1];
            sum[s[i]][i]++;
        }
    }
    for (int k = 1; k <= n; k = k * 2 + 1)
        forn(i, n)
            if (i - k >= 0 && i + k < n && get_hash(i - k, i - 1) == get_hash(i + 1, i + k) && calc(i - k, i + k, s[i]) == 1
                    && d[i - k / 2 - 1] >= k / 2 && d[i + k / 2  + 1] >= k / 2) {
                d[i] = k;
                ll j = k + k + 1;
                ans1 += j * j;
                dp[i - k] += j * j;
                dp[i + k + 1] -= j * j;
            }
    for (int i = 1; i < n; i++)
        dp[i] += dp[i - 1];
    ans = ans1;
    forn(i, n) {
        int cc = s[i];
        ll ans2 = ans1;
        for (s[i] = 1; s[i] < 27; s[i]++)
            if (s[i] != cc) {
                ans1 -= dp[i];
                dfs(i, i, s[i]);
                for (int k = 1; k <= n; k = k * 2 + 1)
                    if (i - k >= 0 && i + k < n && get_hash(i - k, i - 1) == get_hash(i + 1, i + k)
                            && calc(i - k, i - 1, s[i]) + calc(i + 1, i + k, s[i]) == 0
                                && d[i - k / 2 - 1] >= k / 2 && d[i + k / 2  + 1] >= k / 2)
                        dfs(i - k, i + k, (((((get_hash(i - k, i - 1) * T + s[i]) % MD) * pw[k]) % MD) + get_hash(i + 1, i + k)) % MD);
                    else
                        break;
                ans = max(ans, ans1);
                ans1 = ans2;
            }
        s[i] = cc;
    }
    cout << ans + n;
    return 0;
}


/*






*/