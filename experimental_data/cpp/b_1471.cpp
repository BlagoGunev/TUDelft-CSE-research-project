#include<bits/stdc++.h>
using namespace std;

///// Defines /////
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f(i, beg, end) for(int i=beg; i<end; i++)
#define rf(i, beg, end) for(int i=beg; i>=end; i--)
#define ms(x, a) memset(x, a, sizeof(x))
#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
#define max_ *max_element
#define min_(a, n) *min_element(a, a+n)
#define lg(base, x) (log(x)/log(base))
#define endl '\n'
#define ln cout << '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define imp cout << "-1\n"
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()
#define in insert
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define len length()
#define ub upper_bound
#define lb lower_bound

///// Data types and Containers /////
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator viit;
typedef vector<char> vc;
typedef vector<char>::iterator vcit;

///// Constants /////
const long long MOD = 1e9+7;

const int N = 2e5+5;

///// F(X)'s /////
template <typename T> inline T abs(T x) {return x < 0? -x : x;}
inline ll pow_mod(ll x,ll n) {ll r=1;while(n){if(n%2)r=(r*x)%MOD;x=(x*x)%MOD;n/=2;}return r;}
inline ll pow_(ll x,ll n) {ll r=1;while(n){if(n%2)r=(r*x);x=(x*x);n/=2;}return r;}

inline void solve()
{
    int n, x; cin >> n >> x;
    vi a(n);
    f(i,0,n) cin >> a[i];
    ll sum = 0;
    ll mn = INT_MAX, t, ind = -1;
    f(i,0,n) {
        sum += a[i], t = 0;
        int y = a[i];
        while(y%x==0) {
            y /= x;
            t++;
        }
        if(mn>t) mn = t, ind = i;
    }
    
    f(i,0,n) {
        if(ind>i) sum += (mn + 1)*a[i];
        else sum += mn*a[i];
    }
    
    cout << sum << endl;
}
int main()
{
    FAST
    int t=1; cin >> t;
    while(t--) solve();
}