#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//const long long MOD = 1000000007;
const long long MOD = 998244353;
const long double PI = 3.14159265358979;
const long long INF = 1LL<<60;
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
#define deb(var) do{cout << #var << " : "; view(var);}while(0)
template<typename T> void view(T e){cout << e << endl;}
void view(vector<string>& v){cout << endl;for(auto& s :v){view(s);}cout << endl;}
template<typename T> void view(vector<T>& v){for(auto& e :v){cout << e << " ";}cout << endl;}
template<typename T> void view(vector<vector<T>>& vv){cout << endl;for(auto& v:vv){view(v);}}
ll gcd(ll a, ll b){if (b == 0) return a;else return gcd(b, a % b);}
ll lcm(ll x,ll y){return ll(x/gcd(x,y))*y;}
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long

void solve() {
    string s; cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '0') a++;
        if (s[i] == '1') b++;
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            if (a > 0) a--;
            else {
                ans = n - i;
                break;
            }
        }
        else {
            if (b > 0) b--;
            else {
                ans = n - i;
                break;
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}