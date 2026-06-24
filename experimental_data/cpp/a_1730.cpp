/** وَأَنْ لَيْسَ لِلإِنسَانِ إِلَّا مَا سَعَى ۝ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ۝ ثُمَّ يُجْزَاهُ الْجَزَاءَ الأَوْفَىِ **/



#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>





#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

#define ll long long

#define N (int)2e5+5

#define mxLL (ll)2e18+5

#define mod  998244353

#define foo(k, x, n) for(int k = x ; k <= int(n) ; ++k)

#define all(x) x.begin() , x.end()

#define memClear(v) memset(v , 0 , sizeof v)

//const long double M_PI = 3.1415926535897932384626433832795l;

#define ordered_set tree<int, null_type , greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update>



using namespace std;

using namespace __gnu_pbds;



// Grid directions

vector<int> dir1 = {-1, -1, 1, 1};

vector<int> dir2 = {-1, 1, -1, 1};



/*-----------------------------------------------------------------------*/

void Merge(int l, int mid, int i, int r);



ll ceilDiv(ll x, ll y) {

    return (x + y - 1) / y;

}



int getNoOfDigits(ll x) {

    //    int cnt{0};

    //    while (x) x /= 10, ++cnt;

    //    return cnt;

    return floor(log10(x)) + 1;

}



int sumOfDigits(ll x) {

    int sum = 0;

    while (x) sum += (x % 10), x /= 10;

    return sum;

}



ll factorial(ll val) {

    ll ans = 1;

    foo(i, 1, val) ans *= i;

    return ans;

}



ll nCr(ll k, ll r) {

    return factorial(k) / (factorial(r) * factorial(k - r));

}



ll nPr(ll k, ll r) {

    return factorial(k) / factorial(k - r);

}



ll addMod(ll a, ll b, ll m) {

    return ((a % m) + (b % m)) % m;

}



ll subMod(ll a, ll b, ll m) {

    return ((a % m) - (b % m) + m) % m;

}



ll mulMod(ll a, ll b, ll m) {

    return ((a % m) * (b % m)) % m;

}



ll binaryExponentiation(ll x, ll n) {

    ll res = 1;

    while (n > 0) {

        if (n & 1) res *= x;

        x *= x;

        n /= 2;

    }

    return res;

}



ll modularExponentiation(ll x, ll n, ll M) {

    ll res = 1;

    while (n > 0) {

        if (n & 1) res = mulMod(res, x, M);

        x = mulMod(x, x, M);

        n /= 2;

    }

    return res;

}



/*----------------------------------------------------------------------*/







void solve() {

    int n, c;

    cin >> n >> c;

    vector<int> v(n);

    map<int, int> mp;

    for (int x: v) cin >> x, mp[x]++;



    int ans = 0;

    for (auto &[i, j]: mp) {

        if (j <= c) ans += j;

        else ans += c;

    }

    cout << ans << "\n";

}



int main() {

    FAST

    int t = 1;

    cin >> t;

    while (t--)

        solve();





    return 0;

}