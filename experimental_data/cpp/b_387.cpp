#include <bits/stdc++.h>
#define input(n, a) for (int x(0); x < n; ++x) cin >> a[x]

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    input(n, a);
    input(m, b);
    sort(a, a + n);
    sort(b, b + m);
    int j(0), ans(0);
    for (int i(0); i < n; ++i)
    {
        while (j < m && b[j] < a[i]) ++j;
        if (j == m) ++ans;
        else ++j;
    }
    cout << ans;
}