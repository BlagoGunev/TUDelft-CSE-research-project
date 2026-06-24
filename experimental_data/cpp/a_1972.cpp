#include<bits/stdc++.h>
#define ll long long
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
#define all(a) (a).begin() , (a).end()
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
//#define endl '\n'
#define ar array
#define ld long double
using namespace std;
void readFromFile(string input = "input.txt",string output="output.txt") {
    #ifndef ONLINE_JUDGE
        freopen(input.c_str(),"r",stdin);
        freopen(output.c_str(),"w",stdout);
    #endif
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));
ll rand(ll x, ll y) {
    return uniform_int_distribution<ll>(x, y)(rng);
}
const int INF = 0x3f3f3f3f;
const ll INFLL = 2e18;
const int mod= 998244353;
const ld eps = 1e-6;
int mul(int x,int y,int mod=mod){return (long long) x*y%mod;}
int add(int x,int y,int mod=mod){x+=y; return x<mod?x:x-mod;}
int sub(int x,int y,int mod=mod){x-=y;return x<0?x+mod:x;}
int power(int x,ll y,int mod=mod){if(!y)return 1;int ret=power(x,y/2,mod);
ret = mul(ret,ret,mod);if(y&1) ret = mul(ret,x,mod);return ret;}
const int N = 1e2+3;
int n,a[N],b[N];
void solve() {
    cin >> n;
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    for(int i = 0 ; i < n ; i++)cin >> b[i];
    int ans = 0 , i = 0;
    for(int j = 0 ; j < n ; j++) {
        if(a[i] <= b[j]) {
            i++;
            continue;
        }else ans++;
    }
    cout << ans << endl;
}


int32_t main() {
    readFromFile();
    SD;
    int t = 1;
    cin >> t;
    for(int i = 0 ; i < t ; i++) {
        solve();
    }
}