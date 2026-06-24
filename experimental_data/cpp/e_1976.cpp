#include <string.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vector<T>>;
template <typename T> using vvvc = vector<vector<vector<T>>>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

int dx4[] = {1,0,-1,0};
int dy4[] = {0,1,0,-1};

#define overload5(a, b, c, d, e, name, ...) name
#define overload4(a, b, c, d, name, ...) name
#define REP0(n) for(ll jidlsjf = 0; jidlsjf < n; ++jidlsjf)
#define REP1(i, n) for(ll i = 0; i < (n); ++i)
#define REP2(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP3(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define per0(n) for(int jidlsjf = 0; jidlsjf < (n); ++jidlsjf)
#define per1(i, n) for(ll i = (n)-1; i >= 0; --i)
#define per2(i, a, b) for(ll i = (a)-1; i >= b; --i)
#define per3(i, a, b, c) for(ll i = (a)-1; i >= (b); i -= (c))
#define per(...) overload4(__VA_ARGS__, per3, per2, per1, per0)(__VA_ARGS__)
#define setbits(j, n) for(ll iiiii = (n), j = lowbit(iiiii); iiiii; iiiii ^= 1 << j, j = lowbit(iiiii))
#define perm(v) for(bool permrepflag = true; (permrepflag ? exchange(permrepflag, false) : next_permutation(all(v)));)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define drop(s) cout << #s << endl, exit(0)
#define si(c) (int)(c).size()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define lbg(c, x) distance((c).begin(), lower_bound(all(c), (x), greater{}))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define ubg(c, x) distance((c).begin(), upper_bound(all(c), (x), greater{}))
#define rng(v, l, r) v.begin() + (l), v.begin() + (r)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
#define UNIQUE(x) SORT(x), x.erase(unique(all(x)), x.end())
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))

constexpr int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vc<int>l(q),r(q);
    rep(i,q) {
        cin >> l[i];
    }
    rep(i,q) {
        cin >> r[i];
    }
    set<int>st;
    st.insert(n);
    bool f = false;
    rep(i,q) {
        if(l[i] == r[i]) f = true;
        if(st.count(max(l[i],r[i])) && !st.count(min(l[i],r[i]))) {
            st.insert(min(l[i],r[i]));
        }
        else {
            f = true;
        }
    }
    if(f) {
        cout << 0 << "\n";
        return 0;
    }
    map<int,pii>mp;
    for(int i:st) {
        mp[i] = {i,i};
    }
    vc<int>cnt(n+1);
    per(i,q) {
        pii L = mp[l[i]];
        pii R = mp[r[i]];
        mp.erase(l[i]);
        mp.erase(r[i]);
        mp[max(l[i],r[i])] = {L.fi,R.se};
        cnt[max(L.se,R.fi)]++;
    }
    for(auto i:mp) {
        cnt[i.se.fi]++;
        cnt[i.se.se]++;
    }
    int ans = 1,res = 0;
    per(i,n+1,1) {
        res += cnt[i];
        if(!st.count(i)) {
            ans = 1ll*ans*res%mod;
            res++;
        }
    }
    cout << ans << "\n";
}