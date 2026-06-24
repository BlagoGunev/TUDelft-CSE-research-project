#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
//using i128 = __int128;
#define sz(a) (int)(a.size())
#define rep(x,a,b) for(int x = a; x < b; x++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uni(a) a.resize(unique(all(a)) - a.begin())
#define mp(a,b) make_pair(a,b)
#define maxe(a) max_element(all(a))
#define mine(a) min_element(all(a))
#define lb(b,val) lower_bound(b.begin(), b.end(), val) - b.begin()
#define ub(b,val) upper_bound(b.begin(), b.end(), val) - b.begin()
#define fd(b,val) find(all(b), val) - b.begin()
#define ct(b,val) count(all(b), val)
#define bp(s) __builtin_popcountll(s)
#define pii pair<int, int>
#define pli pair<ll, int>
#define mii map<int, int>
#define mli map<ll, int>
#define fi first 
#define se second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define sp setprecision
const int mod = 1e9 + 7;
//const int mod = 998244353;
inline ll read(){ll x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=1ll*x*10+ch-48;ch=getchar();}return x*f;}
template<typename T> inline void write(T X) {if (X < 0) {putchar('-'); X = ~ (X - 1);}int s[50], top = 0;while (X) {s[++top] = X % 10; X /= 10;}if (!top) s[++top] = 0;while (top) putchar(s[top--] + '0');putchar('\n');return;}
ll qmi(ll a, ll b){ll res = 1 % mod;while(b){if(b & 1) res = 1ll * res * a % mod;a = 1ll * a * a % mod;b >>= 1;}return res;}
ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
void print(vll& v) {
//	cout << v.size() << endl;
	for(auto& p : v) {
		cout << p << ' ';
	}
	cout << endl;
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    ll res = n + m - 2;
    vvll a(n, vll(m - 1, 0)), b(n - 1, vll(m, 0));
    if(k < res){
        cout << "NO" << endl;
        return;
    }
    if((k - res) % 4 == 0 || (k - res) % 4 == 2){
        cout << "YES" << endl;
        for(int i = 0; i < m - 1; i += 2) a[0][i] = 1;
        if(a[0][m - 2] == 0){
            for(int i = 0; i < n - 1; i += 2) b[i][m - 1] = 1;
            b[n - 2][m - 2] = b[n - 2][m - 1];
            a[n - 1][m - 2] = b[n - 2][m - 1] ^ 1;
            a[n - 2][m - 2] = b[n - 2][m - 1] ^ 1;
        }
        else{
            for(int i = 1; i < n - 1; i += 2) b[i][m - 1] = 1;
            b[n - 2][m - 2] = b[n - 2][m - 1];
            a[n - 1][m - 2] = b[n - 2][m - 1] ^ 1;
            a[n - 2][m - 2] = b[n - 2][m - 1] ^ 1;            
        }           
        b[0][0] = a[0][0];
        b[0][1] = a[0][0];
        a[1][0] = a[0][0] ^ 1;
        rep(i, 0, n){
            rep(j, 0, m - 1){
                if(a[i][j] == 1) cout << "R ";
                else cout << "B ";
            }
            cout << endl;
        }
        rep(i, 0, n - 1){
            rep(j, 0, m){
                if(b[i][j] == 1) cout << "R ";
                else cout << "B ";
            }
            cout << endl;
        }          
    }
    else cout << "NO" << endl;
}
signed main(){
    int _ = 1;
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin >> _;
    //_ = read();
    while(_--){
        solve();
    }
    return 0;
}