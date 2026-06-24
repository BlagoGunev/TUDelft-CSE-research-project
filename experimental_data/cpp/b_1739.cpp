#include<bits/stdc++.h>

#define ll                  long long

#define pll                 pair<ll,ll>

#define vpp                 vector<pair<ll,ll>>

#define vec                 vector<ll>

#define um                  unordered_map

#define us                  unordered_set

#define read(v)             for(auto &x: v) cin>>x

#define all(x)              (x).begin(), (x).end()

#define pb                  push_back

#define f                   first

#define mne                 min_element

#define mxe                 max_element

#define s                   second

#define nn                  endl

#define rsort(v)            sort(all(v),greater<int>())

#define pv(v)               for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout << endl;

#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define loop(i,a,b)         for(ll i=a; i<b; i++)

#define rloop(i,a,b)        for(ll i=a; i>=b; i--)

#define yes                 cout<<"YES"<<nn

#define no                  cout<<"NO"<<nn

#define set_bits            __builtin_popcountll

using namespace std;

const ll MOD = 1000000007;

/***********************************************************************************************************************************/

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];}  //for non prime b

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m 

/***********************************************************************************************************************************/



bool is_Prime(int n){if (n <= 1) return false;for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}

int fact(ll n){return (n==1 || n==0) ? 1: n * fact(n - 1);}

bool twopower(int n){ if (n == 0) return false; return (ceil(log2(n)) == floor(log2(n)));}

bool isPerfectSquare(ll x){if(x >= 0){ll sr = sqrt(x); return (sr*sr == x);} return false;}

ll factmod(ll n, ll p){if(n>=p) return 0;ll result = 1;loop(i,1,n+1) result =(result*i)%p;return result;}



void SR(){



    ll n; cin>>n;

    vec v(n),b(n); read(v);

    b[0] = v[0];

    loop(i,1,n){

        ll x = v[i]+b[i-1];

        ll y = b[i-1]-v[i];

        if(x>=0 and y>=0 and x!=y){

            cout << -1 <<nn;

            return;

        }

        else{

            if(x>=0) b[i] = x;

            else b[i] = y;

        }

    }

    pv(b);

}



signed main(){

    fast_io

    int t; cin >> t; while(t--)

    SR();

    return 0;

}