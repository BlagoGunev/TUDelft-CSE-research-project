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

        int n;

        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)

            cin >> a[i];

        sort(a, a + n);

        if (binary_search(a, a + n, 1))

        {

            if (a[0] == 0)

                cout << "NO\n";

            else

            {

                int index = upper_bound(a, a + n, 1) - a;

                bool virgin = true;

                while (index < n)

                {

                    virgin &= ((a[index] == a[index - 1]) || (a[index] != a[index - 1] && a[index] - a[index - 1] > 1));

                    index++;

                }

                cout << (virgin ? "YES\n" : "NO\n");

            }

        }

        else

            cout << "YES\n";

    }

}