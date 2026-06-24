// LUOGU_RID: 101193124
#include <iostream>

#include <map>

#include <vector>



using namespace std;



int n, p, a[105], fr, bk, ans;



int main()

{

    ios::sync_with_stdio(false);

    int t;

    cin >> t;

    for (int i = 0;i < t;i++)

    {

        a[0] = 0;

        vector <int> b;

        map <int, bool> num;

        cin >> n >> p;

        for (int j = 1;j <= n;j++)

        {

            cin >> a[j];

            num[a[j]] = true;

        }

        fr = p - 1, bk = 0;

        while (fr != -1 && num[fr]) fr--;

        while (bk != p && num[bk]) bk++;

        if (fr == -1)

        {

            cout << 0 << endl;

        }

        else if (a[n] <= bk)

        {

            cout << fr - a[n] << endl;

        }

        else

        {

            int j;

            for (j = n - 1;++a[j] >= p;j--)

            {

                a[j] = 0;

            }

            num[a[j]] = true, num[0] = true;

            fr = a[n] - 1;

            while (fr != -1 && num[fr]) fr--;

            if (fr == -1)

            {

                cout << p - a[n] << endl;

            }

            else

            {

                cout << (p - a[n]) + fr << endl;

            }

        }

    }

    return 0;

}