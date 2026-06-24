#include <bits/stdc++.h>

using namespace std;

 

#ifdef DEBUG

#include "debug.h"

#else

#define debug(x) void(37)

#endif

 

#define lsb(x) ((x)&(-x))

#define all(x) x.begin(),x.end()

#define setprec(n) cout << fixed << showpoint;cout << setprecision(n);

typedef long long ll;

typedef long double ld;

const ld eps = 1e-9;

const ll MOD1 = 1e9+7;//1000000007

const ll MOD2 = 998244353ll;

const ll LINF = (ll)1e18;

const int IINF = (int)1e9;

#define int ll





void solve(){

    int n, p, k;

    cin >> n >> p >> k;



    string str;

    cin >> str;



    int x, y;

    cin >> x >> y;



    vector<int> cnt(k);

    for(int i = p-1;i < n;i++)

        cnt[i%k] += int(str[i]-'0');

    

    int go = p-1;

    int req = (n-go)/k;

    if((n-go)%k) req++;



    int ans = (req-cnt[go%k])*x;

    cnt[go%k] -= int(str[go]-'0');



    //debug(cnt);



    int add = 0;

    while(++go < n){

        //cout << go << " " << ans << " - ";

        add += y;

        req = (n-go)/k;

        if((n-go)%k) req++;

        //cout << req << " " << cnt[go%k] << " " << (req-cnt[go%k])*x + add << "\n";

        ans = min(ans, (req-cnt[go%k])*x + add);

        cnt[go%k] -= int(str[go]-'0');

    }



    cout << ans << "\n";

}





signed main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    srand(time(NULL));



    int t = 1;

    cin >> t;

    while(t--)

        solve();

 

    return 0;

}