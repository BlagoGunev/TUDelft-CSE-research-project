#include <iostream>

#include <string.h>

#include <cstdio>

#include <algorithm>

#include <cmath>

#include <stack>

#include <set>

#include <vector>

#include <queue>

#include <map>

#include <unordered_map>

#define Lint long long

#define pi acos(-1.0)

using namespace std;

const int N = (1LL << 20) + 10;

int T, n, k;

int vis[N];

string s;

vector<int> v;

void solve()

{

    for (auto i : v)

    {

        vis[i] = 0;

    }

    v.clear();

    cin >> n >> k;

    cin >> s;

    s = " " + s;

    int cut = 0;

    for (int i = 1; i <= n; ++i)

    {

        if (s[i] == '1')

            s[i] = '0';

        else

            s[i] = '1';

    }

    for (int i = 1; i <= max(0, k - 20); ++i)

    {

        if (s[i] == '1')

        {

            cut++;

        }

    }

    int L = 1, R = max(0, k - 20);

    // n-k+1,n

    for (int i = 1; i <= n - k + 1; ++i)

    {

        //左

        if (L <= R)

        {

            if (i > 1)

            {

                if (s[L] == '1')

                    cut--;

                if (s[R + 1] == '1')

                    cut++;

                L++, R++;

            }

        }

        int ans = 0;

        for (int j = max(i, i + k - 1 - 20); j <= i + k - 1; ++j)

        {

            ans *= 2;

            ans += (s[j] - '0');

        }

        if (cut == 0)

        {

            vis[ans] = 1;

            v.push_back(ans);

        }

    }

    for (int i = 0; i <= (1LL << 20); ++i)

    {

        if (vis[i])

            continue;

        string qwq = "";

        while (i)

        {

            if (i & 1)

            {

                qwq = '1' + qwq;

            }

            else

                qwq = '0' + qwq;

            i >>= 1;

            if (qwq.size() > k)

            {

                cout << "NO\n";

                return;

            }

        }

        cout << "YES\n";

        for (int j = 1; j <= k - qwq.size(); ++j)

        {

            cout << "0";

        }

        cout << qwq << "\n";

        return;

    }

}

int main()

{

    cin.tie(0);

    cout.tie(0);

    ios::sync_with_stdio(0);

    cin >> T;

    while (T--)

        solve();

    return 0;

}