/*Dev Karan Singh Sisodia*/

#include <bits/stdc++.h>

 

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

 

using namespace std;

using namespace __gnu_pbds;

 

#define pyes cout << "YES" << "\n";

#define pno cout << "NO" << "\n";

#define br cout << "\n";

#define ff first

#define ss second

#define pb push_back

#define ppb pop_back

#define sz(x) ((long long)(x).size())

#define MOD 998244353

#define mod 1000000007

#define inf 9223372036854775807

#define all(x) (x).begin(),(x).end()

 

typedef long long ll;

typedef unsigned long long ull;

typedef long double lld;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

 

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;

#else

#define debug(x)

#endif

 

void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(lld t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(ull t) {cerr << t;}

 

template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll gcd(ll a, ll b){ if (a == 0ll) { return b;} return gcd(b % a, a);}



void solve(){

    int n;

    cin >> n;

    char c;

    cin >> c;

    string s;

    cin >> s;

    if(c == 'g'){

        cout << 0 << endl;

        return;

    }

    vector<int> vec;

    for(int i = 0; i < n; i++){

        if(s[i] == 'g'){

            vec.pb(i);

        }

    }

    debug(vec)

    int m = sz(vec);

    int ans = 0;

    for(int i = 0; i < n; i++){

        if(s[i] == c){

            int next = upper_bound(vec.begin(), vec.end(), i) - vec.begin();

            next %= m;

            // cout << vec[next] << endl;

            ans = max(ans, (vec[next] - i + n) % n);

        }

    }

    cout << ans << endl;

}



int main(){

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    freopen("Error.txt", "w", stderr);

#endif // ONLINE_JUDGE

    

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

 

    //code here

    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){

        //cout << "Case #" << i << ": ";

        solve();

    }

    //end

 

    return 0;

}