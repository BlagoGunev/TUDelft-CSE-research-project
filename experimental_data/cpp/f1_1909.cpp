#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define Dv(v) for (auto x : v) cerr << x << ' '; cerr << endl;
#define D(x) cerr << #x << " = " << x << ", "

#define int ll

ll mod = 998244353;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;

        int prev_a;
        cin >> prev_a;
        ll ans = (prev_a <= 1 ? 1 : 0);
        for(int i = 2; i <= n; ++i) {
            int a; cin >> a;
            
            if(a > i or a > prev_a+2 or a < prev_a) ans = 0;
            if(a == prev_a+1) ans = ans *(i-1-prev_a + i-prev_a)%mod;
            else if(a == prev_a+2) ans = ans *(i-1-prev_a)%mod *(i-1-prev_a)%mod;
            
            prev_a = a;
        }
        if(prev_a != n) ans = 0;
        cout << ans << '\n';
    }
}