/*

最黯淡的一个　梦最为炽热

万千孤单焰火　让这虚构灵魂鲜活

至少在这一刻　热爱不问为何

存在为将心声响彻

*/

#include <bits/stdc++.h>

#define pii pair<int, int>

#define mp(x, y) make_pair(x, y)

#define pb push_back

#define eb emplace_back

#define fi first

#define se second

#define int long long

#define mem(x, v) memset(x, v, sizeof(x))

#define mcpy(x, y, n) memcpy(x, y, sizeof(int) * (n))

#define lob lower_bound

#define upb upper_bound

using namespace std;



inline int read() {

	int x = 0, w = 1;char ch = getchar();

	while (ch > '9' || ch < '0') { if (ch == '-')w = -1;ch = getchar(); }

	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();

	return x * w;

}



inline int min(int x, int y) { return x < y ? x : y; }

inline int max(int x, int y) { return x > y ? x : y; }



const int MN = 2e5 + 5;

const int MS = MN << 5;

const int Mod = 998244353;



inline int qPow(int a, int b = Mod - 2, int ret = 1) {

    while (b) {

        if (b & 1) ret = ret * a % Mod;

        a = a * a % Mod, b >>= 1;

    }

    return ret;

}



// #define dbg



int N, x, cnt = 1, a[MN], ch[MS][2], sz[MS], pw[MN];

inline void insert(int x) {

    int p = 1;

    sz[p]++;

    for (int i = 30; ~i; i--) {

        int c = x >> i & 1;

        if (!ch[p][c]) ch[p][c] = ++cnt;

        sz[p = ch[p][c]]++;

    }

}

inline void add(int &x, int y) {

    x += y; if (x >= Mod) x -= Mod;

}

inline int DFS(int u1, int u2, int d) {

    if (!u1) return pw[sz[u2]];

    if (!u2) return pw[sz[u1]];

    if (u1 == u2) {

        if (d < 0) return pw[sz[u1]];

        int lc = ch[u1][0], rc = ch[u1][1];

        if (x >> d & 1) return DFS(lc, rc, d - 1);

        else return (DFS(lc, lc, d - 1) + DFS(rc, rc, d - 1) - 1 + Mod) % Mod;

    } else {

        if (d < 0) return pw[sz[u1] + sz[u2]];

        int lc1 = ch[u1][0], rc1 = ch[u1][1], lc2 = ch[u2][0], rc2 = ch[u2][1];

        if (x >> d & 1) return DFS(lc1, rc2, d - 1) * DFS(lc2, rc1, d - 1) % Mod;

        else {

            int res = (DFS(lc1, lc2, d - 1) + DFS(rc1, rc2, d - 1) - 1 + Mod) % Mod;

            add(res, (pw[sz[lc1]] - 1 + Mod) * (pw[sz[rc1]] - 1 + Mod) % Mod);

            add(res, (pw[sz[lc2]] - 1 + Mod) * (pw[sz[rc2]] - 1 + Mod) % Mod);

            return res;

        }

    }

}

inline void Work() {

    N = read(), x = read();

    for (int i = 1; i <= N; i++) a[i] = read(), insert(a[i]);

    pw[0] = 1;

    for (int i = 1; i <= N; i++) add(pw[i] = pw[i - 1], pw[i - 1]);

    printf("%lld\n", (DFS(1, 1, 30) - 1 + Mod) % Mod);

}



signed main(void) {

    int T = 1;

    while (T--) Work();

    return 0;

}