#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
ll mod2 = 998244353;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
        ll n,m,d;
        cin>>n>>m>>d;
        vector<ll>a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        ll sum=0;
        multiset<ll>s;
        ll ans=0;
        for (ll i = 0; i < n; ++i) {
            if (a[i]>0){
                ans= max(ans,sum+a[i]-d*(i+1));
                if (m!=1){
                    if (s.size() < m - 1) {
                        s.insert(a[i]);
                        sum += a[i];
                    } else if (*s.begin() < a[i]) {
                        sum -= *s.begin();
                        s.erase(s.begin());
                        s.insert(a[i]);
                        sum += a[i];
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}