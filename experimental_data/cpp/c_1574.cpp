#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    int m;cin>>m;
    while(m--)
    {
        ll x,y;cin>>x>>y;
        int i = lower_bound(v.begin(), v.end(), x) - v.begin();
        ll ans = 2e18;
        if (i > 0) ans = min(ans, (x - v[i - 1]) + max(0LL, y - sum + v[i - 1]));
        if (i < n) ans = min(ans, max(0LL, y - sum + v[i]));
        cout << ans << '\n';
    }

    return 0;
}