#include "bits/stdc++.h"



using namespace std;



#define flush fflush(stdout);

#define read_in freopen ("input.txt","r",stdin);

#define gen_out freopen ("output.txt","w",stdout);

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define vec vector

#define vi vec<int>

#define vll vec<ll>

#define pll pair<ll,ll>

#define pii pair<int,int>

#define pb push_back

#define clr(v, d) memset(v,d,sizeof(v))

#define lp(i, n) for(int i=0; i<(int)n; ++i)

#define lp1(i, n) for(int i=1; i<=(int)n; ++i)

#define  oo INT_MAX

#define  pq priority_queue

#define all(v) v.begin(),v.end()

typedef double dl;

typedef long long ll;

typedef unsigned long long ull;

const double PI = acos(-1.0);



void solve() {

    int n, c, mx = -1;

    cin >> n;

    vi mp(1e3 + 1, 0);

    lp1(i, n) {

        cin >> c;

        mp[c] = i;

        mx = max(mx, c);

    }

    int ans = -1;

    for (int i = 1; i <= mx; i++)

        for (int j = i; j <= mx; j++) {

            if (__gcd(i, j) != 1) continue;

            if (mp[i] && mp[j])

                ans = max(ans, mp[i] + mp[j]);

        }

    cout << ans;

}



int main() {

    IO;

    int t = 1;

    cin >> t;

    while (t--) {

        solve();

        cout << "\n";

    }

}