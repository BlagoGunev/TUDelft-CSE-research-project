#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define int long long
typedef unsigned long long ull;
typedef long double lld;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // *find_by_order, order_of_key

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef Subhadip
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define deb(x,n) cerr << #x <<" "; _print(x,n); cerr << endl;
#else
#define debug(x);
#define deb(x,n);
#endif

#define debugd(a,b) debug(a) debug(b)
#define debugt(a,b,c) debug(a) debug(b) debug(c)

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
template <class T> void _print(T* arr, int n);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(T* arr, int n) {cerr << "[ "; for (int i = 0; i < n; i++) {_print(arr[i]); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int binpow(int a, int b) {int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
int expo(int a, int b, int mod) {int res = 1; a %= mod; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void precision(int a) {cout << setprecision(a) << fixed;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*---------------------------------------------------------------------------------------------------------------------------*/

set<pair<int,int>> v;
set<int> s;

void f(int a,int b){
    if(v.count({a,b}) || v.count({b,a})){
        return;
    }
    int d=abs(a-b);
    s.insert(a);
    s.insert(b);
    v.insert({a,b});
    if(d!=0){
        f(d,b);
        f(a,d);
    }
}

void solve() {
    int a,b,x;
    cin>>a>>b>>x;
    if(a<b)
        swap(a,b);
    while(b!=0){
        int v=a%b;
        if(x>a){
            cout<<"NO \n";
            return;
        }
        else if((x-v)%b==0){
            cout<<"YES \n";
            return;
        }
        a=b;
        b=v;
        debugt(a,b,v)
    }
    cout<<"NO \n";
}

signed main() {
#ifdef Subhadip
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int t = 1;
    cin>>t;
    auto start1 = high_resolution_clock::now();
    while (t--)
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Subhadip
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}