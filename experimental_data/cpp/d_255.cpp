#include <iostream>
#include <algorithm>

using namespace std;

long long f(int t, int w, int h)
{
    if(w > h)
        swap(w, h);
    if(w <= 0)
        return 0;
    if(t <= w)
        return 1LL * (t + 1) * t / 2;
    if(t <= h)
        return 1LL * (w + 1) * w / 2 + 1LL * w * (t - w);
    if(t <= h + w - 1)
        return 1LL * (w + 1) * w / 2 + 1LL * w * (h - w) + 1LL * (w - 1) * w / 2 - 1LL * (w + h - 1 - t) * (w + h - t) / 2;
    return 1LL * w * h;
}

long long sum(int t, int n, int x, int y)
{
    long long res = f(t - 1, x - 1, y - 1) + f(t - 1, n - x, y - 1) + f(t - 1, n - x, n - y) + f(t - 1, x - 1, n - y);
    res += t + 1 >= x ? x : t + 1;
    res += t + 1 >= y ? y : t + 1;
    res += t + 1 >= n - x + 1 ? n - x + 1 : t + 1;
    res += t + 1 >= n - y + 1 ? n - y + 1 : t + 1;
    return res - 3;
}

int main()
{
    int n, x, y;
    long long c;
    cin >> n >> x >> y >> c;
    int l = -1, r = 1 << 30, m;
    while(r - l > 1)
    {
        m = (r + l) / 2;
        if(sum(m, n, x, y) < c)
            l = m;
        else
            r = m;
    }
    cout << r << endl;
    return 0;
}