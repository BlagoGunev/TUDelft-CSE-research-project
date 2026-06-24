#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 200005;


int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll sta = 0;
        while (sta < n and v[sta] == 1)
            sta++;
        ll ans = 0;
        ll power = 0;
        ll f = 0;
        for (ll i = sta + 1; i < n; i++)
        {
            if (v[i] == 1)
            {
                f = 1;
                break;
            }
            ll cnt=0;
            ll e=v[i];
            while(e<v[i-1]){
                e*=e;
                cnt++;
            }
 
            e=v[i-1];
 
            while(power>0 and e*e<=v[i]){
                e*=e;
                power--;
            }
 
            cnt+=power;
            ans+=cnt;
            power=cnt;
            
        }
        if (f == 1)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
}