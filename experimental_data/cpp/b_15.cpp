#include <iostream>


int main()
{
    int tests;
    scanf("%d", &tests);
    for(int asdf = 0; asdf < tests; asdf++)
    {
        int n, m, x1, y1, x2, y2;
        scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
        /*int dx = min(x1, x2);
        int dy = min(y1, y2);
        x1 -= dx;
        x2 -= dx;
        y1 -= dy;
        y2 -= dy;*/
        long long dx = abs(x1 - x2);
        long long dy = abs(y1 - y2);
        long long sx = n - dx;
        long long sy = m - dy;
        x1 = sx;
        y1 = sy;
        x2 = n - sx + 1;
        y2 = m - sy + 1;
        long long ans = (long long)n * (long long)m - sx * sy * 2;
        if(x1 >= x2 && y1 >= y2)
            ans += (long long)(x1 - x2 + 1) * (long long)(y1 - y2 + 1);
        printf("%lld\n", ans);
    }
}