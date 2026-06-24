#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define sp " "
#define mod 1000000007
#define INF 999999999999999

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, j, k, i, sol = 0,mx = 0;
        cin >> n >> k;
        vector<ll> ar, ar1;
        for (i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (a >= 0)
            {
                mx = max(a,mx);
                ar.push_back(a);
            }
            else
            {
                mx = max(mx,abs(a));
                ar1.push_back(abs(a));
            }
        }
        sort(ar.begin(), ar.end(),greater<ll>());
        sort(ar1.begin(), ar1.end(),greater<ll>());
        for (i = 0; i < ar.size(); i++)
        {
            j = 1;
            sol += ar[i];
            while (j < k && i + j < ar.size())
            {
                sol += abs(ar[i + j]-ar[i+j-1]);
                j++;
            }
            sol += ar[i+j - 1];
            i = i+j - 1;
        }
        for (i = 0; i < ar1.size(); i++)
        {
            j = 1;
            sol += ar1[i];
            while (j < k && i + j < ar1.size())
            {
                sol += abs(ar1[i + j]-ar1[i+j-1]);
                j++;
            }
            sol += ar1[i+j - 1];
            i = i+j - 1;
        }
        sol -= mx;
        cout << sol << nl;
    }
    return 0;
}