#include <functional>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include <bitset>
#include <string>
#include <cstdio>
#include <math.h>
#include <complex>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

#define mp make_pair
#define int64 long long

#ifdef _DEBUG
    const int N = 1010;
#else
    const int N = 100010;
#endif

const double inf = 1e18;
const double pi = acos(-1.0);
const double eps = 1e-9;

int n, xp, yp, x[N], y[N];

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &xp, &yp);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
    {
        x[i] -= xp;
        y[i] -= yp;
    }
    x[n + 1] = x[1];
    y[n + 1] = y[1];
    double mindist = inf, maxdist = -inf;
    for (int i = 1; i <= n; i++) 
    {
        double tmp = 1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]; 
        double A = y[i] - y[i + 1];
        double B = x[i + 1] - x[i];
        double C = -A * x[i] - B * y[i];
        double d = C * C / (A * A + B * B);
        double xc = -A * C / (A * A + B * B);
        double yc = -B * C / (A * A + B * B);
        if (d < mindist && xc > min(x[i], x[i + 1]) - eps && xc < max(x[i], x[i + 1]) + eps && yc > min(y[i], y[i + 1]) - eps && yc < max(y[i], y[i + 1]) + eps)
            mindist = d;
        maxdist = max(maxdist, tmp);
        mindist = min(mindist, tmp);
    }
    double ans = pi * (maxdist - mindist);
    cout << fixed << setprecision(9) << ans;
    return 0;
}