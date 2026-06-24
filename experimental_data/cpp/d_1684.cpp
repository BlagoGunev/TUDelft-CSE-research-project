#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

#define PI 3.14159265358979323846;

const int INF = 0x3f3f3f3f;

ll a[maxn];

vector<pair<ll, ll>> v;

bool flag[maxn];

void solve()

{

    v.clear();

    // memset(flag, 0, sizeof(flag));

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)

        flag[i] = 0;

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

        v.push_back({a[i] + i, i});

    }

    sort(v.begin(), v.end());

    for (int i = n - k; i < n; i++)

        flag[v[i].second] = 1;

    ll idx = 0;

    ll ans = 0;

    for (int i = 0; i < n; i++)

        if (flag[i])

            idx++;

        else

            ans += (a[i] + idx);

    cout << ans << endl;

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int Times;

    cin >> Times;

    while (Times--)

        solve();

    return 0;

}