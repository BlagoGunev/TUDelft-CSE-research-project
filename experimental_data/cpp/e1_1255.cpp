#include<bits/extc++.h>
#ifndef __unix__
#define getchar_unlocked _getchar_nolock
#endif
#ifdef _debug 
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#include<bits/stdc++.h>
#define dout(i) 0&&0
#endif
#pragma GCC optimize("unroll-loops,no-stack-protector,O3")
#define priority_queue __gnu_pbds::priority_queue
#define unordered_map __gnu_pbds::gp_hash_table
#define rep(_n) for(int __i = _n;__i--;)
#define rep0(_i, _n) for(int _i = 0; (_i)<(_n) ;++_i)
#define rep1(_i, _n) for(int _i = 1; (_i)<=(_n) ;++_i)
#define yn(i) ((i)?"Yes" : "No")
#define eout(i) {cout << (i) << '\n';exit(0);}
#define rout(i) {return cout << (i) << '\n', 0;}
#define multi int _T;for(read(_T);_T--;)
using namespace std;
using ll = long long;using ull = unsigned long long;using ul = unsigned;using db = double;
using __gnu_pbds::null_type;
inline void read(char &a){static char p; while(isspace(p = getchar_unlocked())); a = p; }
inline void read(char *a){static char p; while(isspace(p = getchar_unlocked())); *a = p, ++a; while(!isspace(p = getchar_unlocked()))*a = p, ++a;}
inline void read(string &a){static char p; while(isspace(p = getchar_unlocked())); a = p; while(!isspace(p = getchar_unlocked()))a.push_back(p);}
template<typename T> inline void read(T& a){static char p; static bool b;while (!isdigit(p = getchar_unlocked()))b = p == '-'; a = p ^ '0'; while (isdigit(p = getchar_unlocked())) a *= 10, a += p ^ '0'; if(b)a *= -1; }
template<typename T1, typename T2> inline void read(pair<T1, T2> &a){read(a.first), read(a.second);}
template<typename T> inline void read(T begin, const T &end){while(begin != end)read(*begin), ++begin;}
inline void R(){} template<class T1, class... T2> inline void R(T1 &h, T2 &... e){read(h), R(e...);}
template<typename T> inline void write(T begin, const T &end){while(begin != end)cout << *begin << " \n"[next(begin) == end], ++begin;}
template<typename T> using rbtree = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T> inline ostream& operator << (ostream &ou, const vector<T> &a){for(auto it = a.begin();it != a.end();++it)ou << (it != a.begin() ? " " : "") << *it;return ou;}
template<typename T1, typename T2>inline istream& operator >> (istream &in, pair<T1, T2> &a){return in >> a.first >> a.second;}
template<typename T1, typename T2>inline ostream& operator << (ostream &ou, const pair<T1, T2> &b){return ou << b.first << ' ' << b.second;}
template<typename T> inline long long pow(long long v, long long t, const T &p){long long res = 1;for(;t;t >>= 1, v = v * v % p)if(t & 1)res = res * v % p;return res;}
const int maxn = 300010;
ll n, a[maxn], sum;
bool cmp(int a, int b){
    return abs(a) < abs(b);
}
ll cal(int x){
    ll cur = 0;
    ll cost = 0;
    rep0(i, n){
        ll v = (a[i]+cur) % x;
        if(v+v > x){
            cur = v-x;
        }
        else cur = v;
        cost += abs(cur);
    }
    // dout(x) << cost << '\n';
    return cost;
}
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    R(n), read(a, a+n);
    rep0(i, n)sum += a[i];
    if(sum == 1)rout(-1);
    vector<int> fa;
    for(ll i = 2;i * i <= sum;++i){
        if(sum % i == 0)fa.emplace_back(i);
        while(sum % i == 0)sum /= i;
    }    
    if(sum != 1)fa.emplace_back(sum);
    ll res = 1ll << 59;
    for(int i : fa)res = min(res, cal(i));
    cout << res << '\n';
}