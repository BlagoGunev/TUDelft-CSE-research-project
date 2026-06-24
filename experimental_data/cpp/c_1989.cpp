#include <bits/stdc++.h>

using namespace std;
using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        int x = 0, y = 0, k = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] > b[i])
                x += a[i];
            else if(a[i] < b[i])
                y += b[i];
            else if(a[i] != 0)
            {
                if(a[i] == -1)
                    x--, y--;

                k++;
            }
        }

        while(k--)
        {
            if(x < y)
                x++;
            else y++;
        }

        cout << min(x, y) << "\n";
    }
}