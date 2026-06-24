#include <bits/stdc++.h>
using namespace std;

int v[200001];
long long aint[800001][2][2];

void update(int nod, int st, int dr, int poz, int val)
{
    if(poz < st || dr < poz)
        return;
    if(st == dr)
    {
        aint[nod][1][1] = val;
        aint[nod][0][1] = (long long)-1e15;
        aint[nod][1][0] = (long long)-1e15;
        return;
    }
    int mid = (st + dr) / 2;
    update(2 * nod, st, mid, poz, val);
    update(2 * nod + 1, mid + 1, dr, poz, val);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            aint[nod][i][j] = (long long)-1e15;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int k2 = 0; k2 < 2; k2++)
                    if(k + k2 != 2)
                        aint[nod][i][j] = max(aint[nod][i][j], aint[2 * nod][i][k] + aint[2 * nod + 1][k2][j]);
}

int main()
{
#ifdef HOME
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif // HOME
    int n, k, x, q;
    long long s = 0;
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
        if(n > 3)
            update(1, 2, n - 2, i, v[i]);
        s += v[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> k >> x;
        s += x - v[k];
        v[k] = x;
        if(n > 3)
            update(1, 2, n - 2, k, x);
        if(n <= 3)
            cout << 2LL * s << '\n';
        else
            cout << 2LL * (s - max(max(aint[1][0][0], aint[1][0][1]), max(aint[1][1][0], aint[1][1][1]))) << '\n';
    }
    return 0;
}