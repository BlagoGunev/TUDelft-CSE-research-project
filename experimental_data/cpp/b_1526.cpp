#include <bits/stdc++.h>

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define cout(x) copy(x.begin(), x.end(), ostream_iterator<ll>(cout," "))

#define ll long long

#define ld long double

#define str string

#define ulli unsigned long long int

#define vc vector

#define pb push_back

#define all(s) (s).begin(), (s).end()

#define fr(i, n) for (int i = 0; i < (n); ++i)

#define endl '\n'

#define INF 1000000000;

using namespace std;

ll cons = 1e7 + 10;

const ld   pi = 3.14159265358979323846L;

const ll   mod = 1e9 + 7;

str letters = "abcdefghijklmnopqrstuvwxyz";

ll const N = 1e7 + 10;

int32_t main() {

    ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);

    //freopen("adam.in","r",stdin);

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    ll t = 1;

    cin >> t;

    while (t--) {

        ll i ;

        cin >> i;

        cout<<(i<i%11*111?"NO":"YES")<<endl;

    }

}