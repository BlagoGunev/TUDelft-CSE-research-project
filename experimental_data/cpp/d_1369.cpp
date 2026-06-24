#include <bits/stdc++.h>

#define lli long long int

#define endl "\n"

#define pb push_back

#define pf push_front

#define ff first

#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

#define print(a) for(auto x:a) {cout << x;} cout << endl;

#define cnt(x) __builtin_popcountll(x)



using namespace std;



const int mod = 1000000007;

const int N = 2000000;



signed main()

{

    fastio()



    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) dp[i] = ((i >= 2 ? 2 * dp[i - 2] : 0) % mod + dp[i - 1] + (i % 3 == 0 ? 4 : 0)) % mod;



    int t;

    cin >> t;



    while (t--)

    {

        int n;

        cin >> n;



        cout << dp[n] << endl;

    }



    return 0;

}