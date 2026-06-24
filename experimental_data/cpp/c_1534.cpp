#include <bits/stdc++.h>

using namespace std;



const int64_t MAX = 1e9 + 7;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--)

    {

        int n;

        cin >> n;

        int a[n], b[n], c[n + 1], vis[n + 1];

        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++)

            cin >> a[i];

        for (int i = 0; i < n; i++)

            cin >> b[i];

        for (int i = 0; i < n; i++)

            c[a[i]] = b[i];

        int64_t ans = 1;

        for (int i = 0; i < n; i++)

        {

            if (vis[a[i]])

                continue;

            int x = a[i];

            while (!vis[x])

            {

                vis[x] = 1;

                vis[c[x]] = 1;

                x = c[c[x]];

            }

            ans = (ans * 2LL) % MAX;

        }

        cout << ans << '\n';

    }

}