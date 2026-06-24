#include<bits/stdc++.h>

#include<math.h>

#include<string.h>

#include<cstring>

#include<string>

#include<vector>

#include<stdlib.h>

#include <ext/pb_ds/exception.hpp>

#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp> 

#include <ext/pb_ds/detail/type_utils.hpp>

#include <ext/pb_ds/detail/hash_fn/mask_based_range_hashing.hpp>

#include <ext/pb_ds/detail/hash_fn/mod_based_range_hashing.hpp>

#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define MOD 1000000007

#define INF 1e18

#define ff first

#define ss second

#define PI 3.141592653589793238462   

#define set_bits __builtin_popcountll

#define sz(x) ((int)(x).size())

#define all(x) (x).begin(), (x).end()

#define small 0

const int N = 2000005;

#define MAXN   100001

#define endl "\n"

using namespace std;

using namespace __gnu_pbds;

#define debug(x) cerr << #x << " " << x << endl;

#define debug1(x) cerr << #x << " " << x << " ";

typedef long long int ll;

typedef long double lld;

#define timeset ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 

/*#define debug(x);

printf(x);*/

 

void init()

{

  #ifndef ONLINE_JUDGE

  freopen("input.txt" , "r"  ,stdin); 

  freopen("output.txt" , "w" ,stdout);

  #endif

} 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds_pair; 

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

int modpow(int b, int e){int ans = 1;b %= MOD;while(e){if(e & 1) ans = (ans * b) % MOD;e >>= 1;b = (b * b) % MOD;}return ans;}

int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}

int max(int a, int b) {if (a > b) return a; else return b;}

int min(int a, int b) {if (a < b) return a; else return b;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void debug_vector(vector<ll> v){for(auto i:v){cerr << i << " ";}}

void debug_map(map<ll,ll> mp){for(auto i:mp){cerr << i.ff  << " " << i.ss << endl;}}

void debug_set(set<ll> v){for(auto i:v){cerr << i << " ";}}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll Testcase_generator(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

void testcase_generator(ll n,ll l,ll r){for(int i=0;i<n;i++){cerr << Testcase_generator(l,r) << endl;}}

 

void precision(lld a) 

{

  cout  << setprecision(a) << fixed;

}

 

// {

//  reference

//  cerr << "0th element: " << *A.find_by_order(0) << endl;

//  cerr << "No. of elements smaller than 6: " << A.order_of_key(6) << endl; // 2

//  cerr << "Lower Bound of 6: " << *A.lower_bound(6) << endl;

//  cerr << "Upper Bound of 6: " << *A.upper_bound(6) << endl;

// }

  

//** pritishcf307 **//

//**------------------------------------------------------------------------------------------------------**//

//** code starts here **//



void solve(){

  ll a,b,c,d;

  cin >> a >> b >> c >> d;

  ll sum = 0;

  ll x = max(c + 1,a + b);

  for(int i = x;i<=(b + c);i++){

    sum += (min(d + 1,i)-c)*(min(i - b,b) - max(i - c,a) + 1);

  }

  cout << sum << endl;

}  



 

int main(){ 

  init();

  IOS;

  ll t=1;

  // cin >> t;

  while(t--){

    solve();

  }

}