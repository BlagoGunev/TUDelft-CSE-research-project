#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

#define F first

#define S second

#define vi vector<ll> 

#define rep(i,x,y) for(ll i=x; i<y; i++)

#define fill(a,b) memset(a, b, sizeof(a))

#define pii pair<ll, ll>

#define mii map<ll, ll> 

#define bc __builtin_popcountll

#define inf INT64_MAX

#define mkp make_pair

#define mod 1000000007

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ll binP(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}

ll nCr(ll n , ll r){

if (n < r) return 0;

if (r > n - r) r = n - r;

ll ans = 1; ll i;

for (i = 1; i <= r; i++){ans = (ans*(n - r + i));ans /= i;} return ans;}

ll modinv(ll a , ll m ) {return binP( a, m-2 , m);} // m is prime

const int N = 31625;

const ll MAX = 1e7+1;

          

           

int main()

{

    fastio;

  ll t;

   t = 1;

  cin>>t;

  while(t--)

  {



    ll n;

    cin>>n;

    string s;

    cin>>s;

   map<char,ll> mp;

    for(ll i=0;i<n;i++)

      mp[s[i]]++;



    bool fl = true;

    if(mp['T']!=1)

    fl = false;





     if(mp['i']!=1)

    fl = false;





     if(mp['m']!=1)

    fl = false;





     if(mp['u']!=1)

    fl = false;

    if(mp['r']!=1)

    fl = false;

    



    



    if(n>5)

    cout<<"NO\n";

    else if(fl)

    cout<<"YES\n";

    else

    cout<<"NO\n";



  }





}