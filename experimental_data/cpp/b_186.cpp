#include <algorithm>
#include <cstdio>
#define gnom pair <double, int>
#define h first
#define num second

using namespace std;

bool Comp(gnom a, gnom b)
{
    if (a.h == b.h) return a.num < b.num;
    else return a.h > b.h;
}

int main()
{
    int n;
    float t1, t2, k;
    scanf("%i %f %f %f", &n, &t1, &t2, &k);
    int a, b;
    gnom m[n];
    for (int i(0); i < n; ++i)
    {
        scanf("%i %i", &a, &b);
        m[i].num = i + 1;
        m[i].h = max(a * t1 * (1 - k / 100) + b * t2, b * t1 * (1 - k / 100) + a * t2);
    }
    sort(m, m + n, Comp);
    for (int i(0); i < n; ++i)
        printf("%i %.2f\n", m[i].num, m[i].h);
}