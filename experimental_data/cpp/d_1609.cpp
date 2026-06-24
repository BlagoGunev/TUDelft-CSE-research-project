#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

int n, m, other;
int f[maxn], s[maxn];
vector<int> tmp;

int find(int t)
{
    int c = t;
    while (t != f[t])
        t = f[t];
    while (c != f[c])
    {
        int tmp = f[c];
        f[c] = t;
        c = tmp;
    }
    return t;
}

void connect(int a, int b)
{
    f[a] = b;
    s[b] += s[a];

    tmp.clear();
    for (int i = 1; i <= n; i++)
        if (f[i] == i)
            tmp.push_back(s[i]);

    sort(tmp.begin(), tmp.end(), [](const int &a, const int &b)
         { return a > b; });
}

int calc(int v)
{
    int re = 0;
    for (int i = 0; i < v && i < tmp.size(); i++)
        re += tmp[i];
    return re;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i, s[i] = 1;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int fa = find(a), fb = find(b);
        if (fa != fb)
            connect(fa, fb);
        else
            other++;

        printf("%d\n", min(calc(other + 1) - 1, n - 1));
    }

    return 0;
}