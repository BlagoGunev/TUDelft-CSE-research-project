#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s;
        int n, m;
        cin >> n >> m >> s;

        int h = 0, v = 0;
        int x = 1, y = 1;

        int maxX = 0, maxY = 0, minX = 0, minY = 0;

        for(char c: s)
        {
            if(c == 'L') h--;
            else if(c == 'R') h++;
            else if(c == 'U') v++;
            else if(c == 'D') v--;

            minX = min(minX, h);
            maxX = max(maxX, h);
            if(maxX - minX + 1 > m)   break;

            minY = min(minY, v);
            maxY = max(maxY, v);
            if(maxY - minY + 1 > n)   break;

            y = 1 - minX, x = 1 + maxY;
        }
        cout << x << ' ' << y << '\n';
    }
}