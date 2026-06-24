#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <map>

#include <cmath>

#include <queue>

#include <set>



#define INF 1000000001

#define mp make_pair

#define pb push_back

#define F first

#define S second

#define MOD 1000000007



typedef long long ll;



using namespace std;



int n, k;

string a;

string b;



bool in(int i, int x)

{

    return (x >> i) & 1;

}



long long solve()

{

    int mp[26] = {0};

    int l = 0;

    for (int i = 0; i < n; i++)

    {

        if (!mp[a[i] - 'a'])

            mp[a[i] - 'a'] = ++l;

    }

    long long ans = 0;

    for (int x = 0; x < (1 << 10); x++)

    {

        int cnt = 0;

        for (int j = 0; j < 10; j++)

        {

            if (in(j, x))

                cnt++;

        }

        if (cnt > k)

            continue;

        long long good = 0;

        int l = 0;

        for (int r = 0; r < n; r++)

        {

            if (a[r] == b[r] || in(mp[a[r] - 'a'] - 1, x))

            {

                good += (r - l) + 1;

            }

            else if (a[r] != b[r])

            {

                l = r + 1;

            }

        }

        ans = max(ans, good);

        // cout << "\n";

    }

    return ans;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t;

    cin >> t;

    while (t--)

    {

        cin >> n >> k;

        cin >> a;

        cin >> b;

        cout << solve() << "\n";

    }

    return 0;

}