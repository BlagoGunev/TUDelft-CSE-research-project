// Problem: E. Modular Sequence
// Contest: Codeforces - Codeforces Round 924 (Div. 2)
// URL: https://codeforces.com/contest/1928/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 
_/      _/    _/      _/    _/      _/   _/_/_/_/_/     _/_/       _/      _/ 
 _/    _/     _/      _/     _/    _/        _/       _/    _/     _/      _/            
  _/  _/      _/      _/      _/  _/         _/      _/      _/    _/_/  _/_/         
   _/_/       _/_/_/_/_/        _/           _/      _/      _/    _/  _/  _/          
  _/  _/      _/      _/        _/           _/      _/      _/    _/      _/          
 _/    _/     _/      _/        _/           _/       _/    _/     _/      _/          
_/      _/    _/      _/        _/           _/         _/_/       _/      _/       
 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define multi int _;cin>>_;while(_--)
#define debug(x) cerr << #x << " = " << (x) << endl;
#define int long long
#define pb push_back
#define eb emplace_back
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
mt19937_64 mrand(chrono::steady_clock().now().time_since_epoch().count());
int rnd(int l,int r){ return mrand() % (r - l + 1) + l;}
void test() {cerr << "\n";}
template<typename T, typename... Args> 
void test(T x, Args... args) {cerr << x << " ";test(args...);}
const ll MOD = 998244353;
// const ll MOD = 1e9+7;
ll ksm(ll x,ll y){ll ans=1;x%=MOD;while(y){if(y&1)ans=ans*x%MOD;x=x*x%MOD,y/=2;}return ans;}

const ll P1 = 999971, base1 = 101;
const ll P2 = 999973, base2 = 103;
const ll N = 200005;
//head

void solve(int testcase)
{
    int n, x, y, s;
    cin >> n >> x >> y >> s;
    s -= (n) * (x % y);
    if (s < 0 || s % y != 0) {
        cout << "NO\n";
        return;
    }
    int d = s / y;
    vector<int> ans(n + 2);
    ans[1] = x / y;
    vector<int> f(d + 2, 1e18), from(d + 2);
    f.assign(d + 2, 1e18);
    int sum = 0, idx = ans[1];
    for (int i = 1; i <= n; i++) {
        sum += idx;
        idx++;
        if (sum > d) break;
        f[sum] = i;
        from[sum] = 0;
    }
    idx = 1, sum = 0;

    for (int i = 1; i <= d; i++) {
        sum += idx;
        idx++;
        for (int j = 1; j + sum <= d; j++) {
            if (f[j + sum] > f[j] + i + 1) {
                from[j + sum] = j;
                f[j + sum] = f[j] + i + 1;
            }
        }
    }
    if (f[d] <= n) {
        cout << "YES\n";
        ans[1] = x;
        int x = d;
        vector<int> q;
        for (int i = f[d] + 1; i <= n; i++) {
        	ans[i] = -1;
        }
        q.push_back(f[x]);
        while (x) {
        	x = from[x];
        	q.push_back(f[x]);
        }
        reverse(q.begin(), q.end());
        for (int i = 1; i < q.size(); i++) {
        	ans[q[i] + 1] = -1;
        }
        for (int i = 2; i <= n; i++) {
        	if (ans[i] == 0) {
        		ans[i] = ans[i - 1] + y;
        	} else {
        		ans[i] = ans[i - 1] % y;
        	}
        }
        for (int i = 1; i <= n; i++) {
        	cout << ans[i] << " \n"[i == n];
        }
    } else {
        cout << "NO\n";
        
    }
}

signed main()
{  
#ifdef localfreopen
    // freopen("1.in","r",stdin);
#endif
    fastio
    int t;
    cin >> t;
    for(int i = 1 ; i <= t ; i++ )
    {
           //cout<<"Case #"<<i<<": ";
        solve(i);
    }
    return 0;
}