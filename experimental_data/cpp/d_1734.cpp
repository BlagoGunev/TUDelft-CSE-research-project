#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PII pair<ll, ll>

#define endl "\n"

const int MAX = 1e9;

const int INF = 0x3f3f3f3f;

const int MOD = 1e9 + 7;

const double eps = 1e-9;

const int N = 200010;



int n, k;

ll a[N];



bool check()

{

    vector<PII> eihi;

    ll sum = 0, mn = 0;

    for (int i = k + 1; i <= n; i++)

    {

        sum += a[i];

        mn = min(mn, sum);

        if (sum > 0)

        {

            eihi.push_back({sum, mn});

            sum = 0, mn = 0;

        }

    }

    ll cur = 0;

    int id = 0;

    for (int i = k; i >= 1; i--)

    {

        cur += a[i];

        while (id < eihi.size() && cur + eihi[id].second >= 0)

        {

            cur += eihi[id].first;

            id++;

        }



        if (cur < 0)

        {

            return false;

        }

    }

    return true;

}



void solve()

{

    cin >> n >> k;

    for (int i = 1; i <= n; i++)

        cin >> a[i];

    if (check())

    {

        cout << "YES" << endl;

        return;

    }

    reverse(a + 1, a + 1 + n);  

    k = n - k + 1;

    if (check())

    {

        cout << "YES" << endl;

        return;

    }

    cout << "NO" << endl;

}



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int T = 1;

    cin >> T;

    while (T--)

        solve();

    return 0;

}