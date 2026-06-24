#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}

const int N = 2e5 + 5;

int fa[N], mmax[N], mmin[N];
int getfa(int x)
{
    return fa[x] ? fa[x] = getfa(fa[x]) : x;
}
void work(int u, int v)
{
    int ufa = getfa(u), vfa = getfa(v);
    if (ufa > vfa)
        swap(ufa, vfa);
    if (ufa != vfa)
    {
        fa[ufa] = vfa;
        mmin[vfa] = min(mmin[ufa], mmin[vfa]);
    }
}

int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        mmax[i] = mmin[i] = i;
    for (int i = 1; i <= m; i++)
        work(read(), read());
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= mmin[i]; j--)
            if (getfa(j) != i)
            {
                ans++;
                work(i, j);
            }
        i = mmin[i];
    }
    printf("%d", ans);
    return 0;
}