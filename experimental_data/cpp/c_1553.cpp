#include <bits/stdc++.h>

using namespace std;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--)

    {

        string s;

        cin >> s;

        int n = s.length();

        vector<int> a;

        for (int i = 0; i < n; i++)

        {

            if (s[i] == '?')

                a.push_back(i);

        }

        int ans = n;

        for (int i = 0; i < (1 << a.size()); i++)

        {

            for (int j = 0; j < a.size(); j++)

            {

                if (i & (1 << j))

                    s[a[j]] = '1';

                else

                    s[a[j]] = '0';

            }

            int a = 0, b = 0;

            int x = n / 2, y = n / 2;

            for (int j = 0; j < n; j++)

            {

                if (j & 1)

                {

                    b += s[j] == '1';

                    y--;

                    if (b > a + x || b + y < a)

                    {

                        ans = min(ans, j + 1);

                        break;

                    }

                }

                else

                {

                    a += s[j] == '1';

                    x--;

                    if (a > b + y || a + x < b)

                    {

                        ans = min(ans, j + 1);

                        break;

                    }

                }

            }

        }

        cout << ans << '\n';

    }

}