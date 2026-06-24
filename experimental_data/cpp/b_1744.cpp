// LUOGU_RID: 101144162
/*

coder:sunshine

school:njupt

*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n' //交互题删掉

#define x first

#define y second

typedef long long ll;

typedef pair<int, int> pii;

const int mod = 1e9 + 7;



void solve()

{

    int n, q;

    cin >> n >> q;

    ll sum1 = 0, sum2 = 0, num1 = 0, num2 = 0;

    while (n--)

    {

        int a;

        cin >> a;

        if (a & 1)

        {

            sum1 += a;

            num1++;

        }

        else

        {

            sum2 += a;

            num2++;

        }

    }

    while (q--)

    {

        int ty, b;

        cin >> ty >> b;

        if (ty == 1)

        {

            if (b & 1)

            {

                sum2 += sum1 + num1 * b;

                num2 += num1;

                num1 = 0;

                sum1 = 0;

                cout << sum1 + sum2 << endl;

            }

            else

            {

                sum1 += num1 * b;

                cout << sum1 + sum2 << endl;

            }

        }

        else

        {

            if (b & 1)

            {

                sum1 += sum2 + num2 * b;

                num1 += num2;

                num2 = 0;

                sum2 = 0;

                cout << sum1 + sum2 << endl;

            }

            else

            {

                sum2 += num2 * b;

                cout << sum1 + sum2 << endl;

            }

        }

    }

}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}