// Author: Mkswll
// Date: 2024-08-04 22:35:16
// Problem: C. Light Switches
// Contest: Codeforces - Codeforces Round 963 (Div. 2)
// URL: https://codeforces.com/contest/1993/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pdd;
#define debug(x) cout << '[' << #x << ": " << x << "] "
#define cio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define cases int _; cin >> _; while(_--)
#define pb push_back
#define eb emplace_back
#define space << " " <<
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define mset(x) memset(x, 0, sizeof(x))
#define sflush fflush(stdout)
#define cflush cout.flush()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define lyes cout << "Yes\n"
#define lno cout << "No\n"
#define nl cout << "\n";
#define vt vector
#define ar array
#define uid uniform_int_distribution 

template <typename T> 
istream& operator >> (istream& in, vector<T>& a){
	for(auto &x : a) in >> x; 
	return in;
}

template <typename T> 
ostream& operator << (ostream& out, vector<T>& a){
	for(auto &x : a) out << x << ' '; 
	return out;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

ll read(){
    int w = 1, c;
    ll ret;
    while((c = getchar()) > '9' || c < '0'){
        w = (c == '-' ? -1 : 1);
    }
    ret = c - '0';
    while((c = getchar()) >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
    }
    return ret * w;
}

ll rd(){
	ll in;
	cin >> in;
	return in;
}
 
void write(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9){
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5, MAXM = 2e5 + 5, INF = 1e9 + 5, MOD = 1e9 + 7;
const ll LMOD = (ll) 1e18 + 9;
const ll LINF = 1e18 + 5;
const ld ep = 1e-8, Pi = acos(-1.0);

int n, m, k, x; 
int a[MAXN];
string s;



void clear(){
    
}

int main(){
    cio;
    cases{
        cin >> n >> k;
        int mx = 0;
        map <int, int> dif;
        for(int i = 1; i <= n; ++i){
        	cin >> a[i];
        	mx = max(mx, a[i]);
        	int t = a[i] % (k * 2);
        	if((t + k) % (k * 2) < t){
        		dif[t]++;
        		dif[k * 2]--;
        		dif[0]++;
        		dif[(t + k) % (k * 2)]--;
        	}
        	else{
	        	dif[t]++;
	        	dif[(t + k) % (k * 2)]--;
        	}
        }
        ll ans = LINF;
        int cur = 0;
        for(auto [u, v] : dif){
        	cur += v;
        	if(cur == n){
        		if(mx % (k * 2) > u){
        			ans = min(ans, ((ll) mx + k * 2) / (k * 2) * (k * 2) + u);
        		}
        		else{
        			ans = min(ans, (ll) mx + u % (k * 2) - mx % (k * 2));
        		}
        	}
        }
        if(ans == LINF) ans = -1;
        cout << ans << "\n";
        clear();
    }
    return 0;
}