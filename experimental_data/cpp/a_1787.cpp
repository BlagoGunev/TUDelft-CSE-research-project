#pragma GCC optimize ("O3")

#include <bits/stdc++.h>



#define F first

#define S second

#define pb push_back

#define pbb pop_back

#define ep emplace_back

#define ll long long

#define ull unsigned ll

#define pii pair<int,int>

#define pll pair<ll,ll>

#define pss pair<string,string>

#define endl '\n'





#define all(v) v.begin(), v.end()

#define SORT(v) sort(all(v))

#define REV(v) reverse(all(v))



using namespace std;



/*****************************/



int is_prime (int n) {

    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))

        return 0;

    for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t)

        if (n % i == 0)

            return 0;

    return 1;

}





ll powmod (ll a, ll b, ll mod) {

    int res = 1; a %= mod;

    for (; b; b >>= 1) {

        if (b & 1) {

            res = 1LL * res * a % mod;

        }

        a = 1LL * a * a % mod;

    }

    return res;

}

/*****************************/



const int MOD = 2147483647;

const int inf = 1000000007;

const ll iinf = 1e18;

const int N = 100007;



int a[N];

map<int, bool> used;

map<int, vector<int>> g;



void solve() {

    int n;

    cin >> n;

    if(n % 2) {

        cout << -1 << endl;

    } else {

        cout << 1 << " " << n/2 << endl;

    }

}





int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int T = 1;

    cin >> T;

    while(T--) {

        solve();

    }

    return 0;

}