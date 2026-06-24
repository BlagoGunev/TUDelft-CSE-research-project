#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e5;
const lli infty = 1e18;
int n;

lli ProcessPen(lli StartDay, lli Ink)
{
    if (Ink == 0) return StartDay;
    lli d = StartDay;
    lli sumA = 0;
    for (int i = 0; i < 7; i++)
    {
        if (d % 7 < 6) sumA++;
        d = (d + n) % 7;
    }
    if (sumA == 0) return infty;
    lli res = StartDay - 1;
    if (Ink > sumA)
    {
        lli CircleLen = 7 * n;
        lli nrep = (Ink - sumA) / sumA;
        res += nrep * CircleLen;
        Ink -= nrep * sumA;
    }
    d = StartDay % 7;
    while (true)
    {
        if (d % 7 < 6) Ink--;
        if (Ink == 0) return res + 1;
        res += n;
        d = (d + n) % 7;
    }
    return res;
}

void Solve()
{
    cin >> n;
    lli res = infty;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        lli t = ProcessPen(i, a);
        //cout << "Process " << i << ' ' << t << endl;
        if (t < res)
        {
            res = t;
            k = i;
        }
    }
    cout << k + 1;
}

int main()
{
    #ifndef hoang
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    Solve();
}