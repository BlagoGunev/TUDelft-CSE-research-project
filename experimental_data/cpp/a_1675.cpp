#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, x, y, ned = 0;
        cin >> a >> b >> c >> x >> y;

        if (x > a)
            ned += x - a;

        if (y > b)
            ned += y - b;

        if (ned > c)
            cout << "NO" << nl;
        else
            cout << "YES" << nl;
    }

    return 0;
}