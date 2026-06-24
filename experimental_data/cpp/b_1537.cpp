/*

 *  created by makrav.io

 *  author is stupid

 */



#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

typedef long double ld;

typedef vector<int> vei;

typedef vector<vei> vevei;



#define all(a) (a).begin(), (a).end()

#define con cout << "NO\n"

#define coe cout << "YES\n";

#define str string

#define pb push_back

#define ff first

#define sc second

#define pii pair<int, int>

#define mas int n;cin>>n; vector<int>a(n);for(auto&u:a)cin>>u

#define masnk int n, k; cin >> n >> k; vector<int> a(n); for (auto &u : a) cin >> u;

#define mxe max_element

#define mne min_element

#define stf shrink_to_fit

#define f(i, l, r) for (int i = (l); i < (r); i++)

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int ll



const int mod = 998244353;

const int MAXN = 200010;



int gcd(int a, int b) {

    while (b) {

        a%=b;swap(a,b);

    }

    return a;

}



void solve() {

    int n, m, i, j; cin >> n >> m >> i >> j;

    cout << "1 1 " << n << ' ' << m << '\n';

}



signed main() {



    ios_base::sync_with_stdio(false);

    cout.tie(nullptr);

    cin.tie(nullptr);





    int tt=1; cin >> tt;

    while (tt--) {

        solve();

    }

}