#include<bits/stdc++.h>
#define pii pair < int, int >
#define int long long

using namespace std;

const int N = 2e5 + 10;
const int inf = 1e9;


int a[N], b[N];
void solve() {

     int n, m;
     cin >> n >> m;

     for(int i = 1; i <= n; i++) cin >> a[i];
     for(int i = 1; i <= n; i++) cin >> b[i];

     int ans = 0;
     for(int i = m + 1; i <= n; i++) ans += min(a[i], b[i]);

     int res = 1e18;

     for(int i = m; i >= 1; i--) {
         res = min(res, ans + a[i]);
         ans += min(a[i], b[i]);
     }

     cout << res << endl;


}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #else

    #endif // LOCAL


    int test;
    cin >> test;
    while(test--) solve();



    return 0;
}