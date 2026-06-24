//.           /\___/\
//.           )     (
//.          =\     /=
//.            )   (
//.           /     \
//.           )     (
//.          /       \
//.          \       /
//MEOW________\__ __/__________
//.              ))
//.             //
//.            ((
//.             \)
#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define fi first
#define se second
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fo(i,j,n,m) for(i=0;i<n;i++) for(j=0;j<m;j++)
#define foo(i,j) for(i=0;i<=1;i++) for(j=0;j<=1;j++)
#define open(s) ifstream fcin(s".inp"); ofstream fcout(s".out");
#define close fcin.close();fcout.close();
const int MAXN = 200005;
const int N = 100005;
const int base = 1000000007;
const int mod = 1000000007;
typedef ll mt[2][2];
using namespace std;
const string smll = "9223372036854775807";
const string smint = "2147483647";
const ll MAXNUM = 1e18;
const ll MINNUM = -1e18;
const double eps = 1e-7;
typedef pair<ll,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double, double> pdd;
typedef int arr[N];
typedef ll llarr[N];
//open("CAU5");
//mt a ={1,1,1,0},t;
bool cmp1(pii a, pii b){return a.fi<b.fi;}
bool cp(ll x){ll i = sqrt(x);return (i*i==x);}
ll sqr(ll x){x = abs(x); return x*x;}
ll po(ll a, int n, ll mod){ll res = 1;while (n){if (n&1) res = (res*a) % mod;a = (a*a) % mod;n >>= 1;}return res;}
ll poww(ll a, ll n){ll res = 1;while (n){if (n&1) res = res*a;a = a*a;n >>= 1;}return res;}
bool getbit(int i, int n){return (n&(1<<i));}
int markbit(int i, int n){if (getbit(i,n)) return n; else return n+(1<<i);}
void markbit(int i, int &n){if (getbit(i,n)) return;n+=(1<<i);}
ll gcd(ll a, ll b){if (b==0) return a; else return gcd(b,a%b); }
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll max3(ll a, ll b, ll c){return max(a,max(b,c));}
ll max4(ll a, ll b, ll c, ll d){return max(max(a,b),max(c,d));}
ll min4(ll a, ll b, ll c, ll d){return min(min(a,b),min(c,d));}
bool bang(double x, double y){return fabs(x-y)<=eps;}
bool lon(double x, double y){return x-y>eps;}
bool nho(double x, double y){return lon(y,x);}
ll pow2(ll x){return (1ll<<x);}

/*-------------------------------------------------------------------------------------*/
void solve(){
    ll l, r, g, res = -1, r1 = -1, r2 = -1;
    cin>>l>>r>>g;
    ll x = (l-1)/g + 1;
    ll y = r/g;
    for(int i = 0; i<=30 && g*(x+i)<=r; i++) for (int j = 0; j<=30 && g*(y-j)>=l; j++){
        if (gcd(x+i,y-j)==1) {
            if (abs((x+i)-(y-j))>res) {
                res = abs((x+i)-(y-j));
                r1 = g*(x+i);
                r2 = g*(y-j);
            }
        }
    }
    cout<<r1<<' ' <<r2<<'\n';
}
signed main()
{
    fio;
    int T = 1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}