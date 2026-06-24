#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
double pi = acos(-1.0);
const ll M = 1e9 + 7;
using vec = vector<ll>;
#define pb push_back
#define all(v) (v).begin(), (v).end()

void sol()
{
    ll n;
    cin >> n;
    vector<ll> vc1(n);
    vector<ll> vc2(n);
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> vc1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vc2[i];
        mx = max(mx, vc1[i] - vc2[i]);
    }
    
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (vc1[i] - vc2[i] == mx)
        {
            st.insert(i + 1);
        }
    }

    cout << st.size() << endl;
    for (auto x : st)
    {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        sol();
    }

    return 0;
}