#include <bits/stdc++.h>

using namespace std;

#define int long long

#define debug(x) cout<<"[" << #x << " is:" << x << "] "<<endl;

#define endl '\n' 



// .*.*.*.*.*.*.*. YOU HAVE THE CHANCE .*.*.*.*.*.*.*.

// .*.*.*.*.*.*.*. JUST INVEST IT .*.*.*.*.*.*.*.

// CODED BY : RAGHAD SALEM . 



void solve() {

    int n ; cin >> n ;

    string s , t ; cin >> s >> t ;

    int o = 0 , z = 0 ;

    int ans = 0 ;

    for (int i=0 ; i<n ; i++)

    {

        o += ((s[i] == '1') + (t[i] == '1')) ; 

        z += ((s[i] == '0') + (t[i] == '0')) ;

        if (o && z)

        {

            ans += ((z / 2) + (z & 1) + 1) ;

            //debug (i) ; debug (o) ; debug (z) ; debug (ans) ;

            o = 0 ; z = 0 ;

        }

    }

    ans += (z / 2) ;

    cout << ans << endl;

    

} 

int32_t main() {

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);

    int t = 1;  cin >> t;

    //sieve() ;

    for (int x = 0 ; x < t; x++) {solve();}

    return 0;

}