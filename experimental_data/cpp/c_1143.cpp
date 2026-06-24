#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
#define jh(x, y) x ^= y ^=x ^= y
#define loc(x, y) (x - 1) * m + y
#define rg register
#define inl inline
#define PI 3.141592654
typedef long long ll;
typedef long double ld;
const int N = 5e5 + 5, mod = 1e9 + 7;
const ld lim = 1e18;
using namespace std;
namespace fast_IO {
    inl ll read() {
        rg char c;
        rg ll x = 0;
        rg bool flag = false;
        while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
        if (c == EOF)return c; if (c == '-')flag = true; else x = c ^ 48;
        while ((c = getchar()) != ' ' && c != '\n' && c != '\r'&&~c)
            x = (x << 1) + (x << 3) + (c ^ 48);
        if (flag)return -x; return x;
    }
    inl int sread(char *s) {
        rg char c;
        rg int len = 0;
        while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
        s[len++] = c;
        while ((c = getchar()) != ' ' && c != '\n' && c != '\r'&&~c)
            s[len++] = c;
        s[len] = 0;
        return len;
    }
    inl ll max(rg ll a, rg ll b) { if (a > b)return a; return b; }
    inl ll min(rg ll a, rg ll b) { if (a < b)return a; return b; }
    void write(rg ll x) { if (x < 0)putchar('-'), x = -x; if (x >= 10)write(x / 10); putchar(x % 10 ^ 48); }
}
int fa[N], c[N], nt[N], b[N], p[N], num, ans[N];
priority_queue<int, vector<int>, greater<int> >pq;
inl void add(rg int x, rg int y) {
    b[++num] = y, nt[num] = p[x], p[x] = num;
    b[++num] = x, nt[num] = p[y], p[y] = num;
}
void dfs(rg int x) {
    rg bool flag = c[x];
    for (rg int e = p[x]; e; e = nt[e])
        if (b[e] != fa[x]) {
            dfs(b[e]);
            flag &= c[b[e]];
        }
    if (flag)pq.push(x);
}

int main(void) {
    rg int n = fast_IO::read(), rt;
    for (rg int i = 1; i <= n; ++i) {
        fa[i] = fast_IO::read(), c[i] = fast_IO::read();
        if (~fa[i])add(i, fa[i]); else rt = i;
    }
    dfs(rt);
    while (!pq.empty()) {
        rg int x = pq.top(); pq.pop();
        ans[++*ans] = x;
    }
    if (!*ans)puts("-1");
    for (rg int i = 1; i <= *ans; ++i)fast_IO::write(ans[i]), putchar(' ');
    return 0;
}