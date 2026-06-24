#include <bits/stdc++.h>

typedef long long LL;

#define int long long

using namespace std;

const int MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
int o_t;
#define Flush fwrite(o_str,1,o_t,stdout), o_t = 0
#define space pc(' ')
#define enter pc('\n')

inline char gc() {
    if (i_s == i_t) {
        i_s = i_str;
        i_t = i_s + fread(i_str, 1, MAXL, stdin);
        return i_s == i_t ? EOF : *i_s++;
    } else
        return *i_s++;
}

inline int read() {
    int x = 0, f = 0;
    char ch = gc();
    for (; ch < '0' || ch > '9'; ch = gc())
        if (ch == '-')
            f = 1;
    for (; ch >= '0' && ch <= '9'; ch = gc())
        x = x * 10 + (ch ^ 48);
    return f ? -x : x;
}

inline void pc(char x) {
    o_str[o_t++] = x;
    if (o_t == MAXL)
        Flush ;
    return ;
}

void write(int x) {
    if (x < 0)
        pc('-'), x = -x;
    if (x > 9)
        write(x / 10);
    pc(x % 10 ^ 48);
    return ;
}

const int N = 1e6 + 6, mod = 1e9 + 7;

int n, ans, cur, lim, p, ed;

int a[N], b[N], pre[N], lst[N];

inline void Solve() {
	n = read(); 
	for (register int i = 1; i <= n; ++i) {
		a[i] = read();
        if (pre[a[i]] == 0)
            pre[a[i]] = i;
        lst[a[i]] = i;
    }
    ans = 0, cur = 0, lim = 0, p = 1, ed = lst[a[1]];
	for (register int i = 1; i <= n; ++i) {
		if (i == 1)
			continue ; 
        if (i > p && i < ed)
            b[i] = 1;
        if (i == ed) {
            if (ed > cur && ed < lim)
                b[cur] = 0, b[ed] = 1;
            p = cur, ed = lim;
        } else if (i > ed)
            p = i, ed = lst[a[i]];
        if (lst[a[i]] > lim)
            lim = lst[a[i]], cur = pre[a[i]];
    }
    ans = 0;
    for (register int i = 1; i <= n; ++i)
        ans += b[i];
    write(ans), enter ;
    return ;
}

signed main() {
	int T = 1;
	while (T--)
		Solve();
	Flush ;
	return 0;
}