// Author: Maksiwelle
// Date: 2024-07-11 22:35:17
// Problem: E. Novice's Mistake
// Contest: Codeforces - Codeforces Round 957 (Div. 3)
// URL: https://codeforces.com/contest/1992/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define binary(len, num) bitset <len> (num)
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

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
uid <int> rnd(0, 1e9);

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
        cin >> n;
        vt <pii> ans;
        for(int i = 1; i <= 10000; ++i){
        	string s = "";
        	string sn = to_string(n);
        	for(int j = 1; j <= min(i, 10); ++j){
        		s += sn;
        	}
        	int len = (int) sn.size();
        	int tot = i * len;
        	for(int j = max(tot - 5, 1); j < tot; ++j){
        		string t = s.substr(0, tot - j);
        		// cout << i space j space t << "\n";
        		if(i * n - j == stoi(t)){
        			ans.eb(i, j);
        		}
        	}
        	
        }
        cout << ans.size() << "\n";
        for(auto [u, v] : ans) cout << u space v << "\n";
        clear();
    }
    return 0;
}