#pragma GCC target ("avx2")

#pragma GCC optimization ("O3")

#pragma GCC optimization ("unroll-loops")



#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define endl "\n"

#define mod (ll)(1e9+7)

#define inf 1e18

#define ll long long

#define ull unsigned long long

#define ld long double

#define set_bit __builtin_popcountll // check no of 1 set bit (x) 

#define edge(x,y) cin>>x>>y;adj[x].push_back(y);adj[y].push_back(x);

#define dedge(x,y) cin>>x>>y;adj[x].push_back(y);

#define pq_dec(i) priority_queue<i,vector<i>, greater<i>>

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define oset(x,y) tree<x, null_type, y<x>, rb_tree_tag, tree_order_statistics_node_update >



// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > oset;

// oset -> less, greater , multiset -> less_equal , greater_equal

// m.order_of_key (k) : Number of items strictly smaller than k .

//*m.find_by_order(k) : K-th element in a set (counting from zero).



#ifdef LOCAL

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif





void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(ull t) {cerr << t;}

void _print(long t) {cerr << t;}





template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(unordered_set <T> v);

template <class T , class V> void _print(unordered_map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T> void _print(priority_queue <T>v);

template <class T> void _print(priority_queue <T, vector<T>, greater<T>>);





template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(priority_queue <T> c) {cerr << "[ "; priority_queue <T> v = c; while (v.size()) {cerr << v.top() << " "; v.pop();} cerr << "]";}

template <class T> void _print(priority_queue <T, vector<T>, greater<T>> c) {cerr << "[ "; priority_queue <T, vector<T> , greater<T>> v = c; while (v.size()) {cerr << v.top() << " "; v.pop();} cerr << "]";}



/*-----------------------------------------------------------------------------------------------------------------------------------*/

ll max(ll a, ll b) {if (a > b)return a; return b;}

ll min(ll a, ll b) {if (a < b)return a; return b;}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}



void google(ll t) {cout << "Case #" << t << ": ";}

void yes(int x = 0) {if (!x)cout << "Yes" << endl; else cout << "YES" << endl;}

void no(int x = 0)  {if (x)cout << "NO" << endl; else cout << "No" << endl; }

/*-----------------------------------------------------------------------------------------------------------------------------------*/

void predefined()

{

  ios_base::sync_with_stdio(false); cin.tie(NULL); // must be disabled in interactive question

#ifdef LOCAL

  freopen("error.txt", "w", stderr);

  freopen("Input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);

#endif

}



void solve()

{

  ll n;

  cin >> n;

  vector<ll>arr(n);

  int idx = 0;

  ll mxm = INT_MAX;

  for (int i = 0; i < n; i++) {

    cin >> arr[i];



    if (mxm > arr[i])

    {

      mxm = arr[i];

      idx = i;

    }

  }



  vector<vector<ll>>ans;

  int l = idx - 1;

  int val = arr[idx] + 1;

  while (l >= 0)

    ans.push_back({idx + 1, l-- + 1, arr[idx], val++});



  l = idx + 1;

  val = arr[idx] + 1;

  while (l < n)

    ans.push_back({idx + 1, l++ + 1, arr[idx], val++});





  cout << ans.size() << endl;

  for (auto&x : ans)

  {

    for (auto& y : x)

      cout << y << " "; cout << endl;

  }

}





int main()

{

  cout << setprecision(12) << fixed;

  predefined();

  ll t;

  cin >> t;



  for (int i = 0; i < t; i++)

    solve();



}