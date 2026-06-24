#include <bits/stdc++.h>



using namespace std;



int m, l, c;



main()

{

    cin >> m;

    for (l = 5; c < m; l += 5)

    {

        int x = l;

        while (x && x % 5 == 0)

        {

            ++c;

            x /= 5;

        }

    }

    if (c > m)

    {

        cout << 0;

        return 0;

    }

    l -= 5;

    cout << "5\n";

    for (int j = l; j <= l + 4; ++j)

        cout << j << " ";

}