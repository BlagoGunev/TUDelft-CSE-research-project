#include <bits/stdc++.h>



using namespace std;



#define Waheed  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define ll long long

#define ld long double

#define INF 1e18

#define pp push_back

#define all(a)  (a).begin(), (a).end()

#define MP make_pair

#define e '\n'

#define sp " \n"[i == n - 1]

#define inarr(arr, n) for(int ar = 0; ar < (n); ar++)cin >> (arr)[ar];

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};

int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

const ll MOD = 1e9 + 7;

const int N = 1e7 + 5;

const ll md = 1000000000007;



void solve() {

    ll a,b,c,d;

    cin >> a >> b >> c >> d;

    ll z = a*b;

    for (ll i = a+1; i <= c; ++i) {

        ll y = (z / gcd(z,i));

        if (y > b && y <= d){

            cout << i << " " << y << e;

            return;

        }

        ll k = (b / y + 1);

        if (k*y <= d){

            cout << i << " " << k*y << e;

            return;

        }

    }

    cout << -1 << " " << -1 << e;

}



int main() {

    Waheed

    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

}