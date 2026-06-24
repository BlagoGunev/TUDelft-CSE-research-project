//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/range/adaptor/reversed.hpp>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace __gnu_pbds;

using namespace std;
//using namespace boost::multiprecision;


#define sp << ' '
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define MOD 1000000007ll
#define b_rev boost::adaptors::reverse
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<pair<ll, ll>> vii;
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define nl <<'\n'

template<class T> using ordered_set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;

template<class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using min_queue = priority_queue<T, vector<T>, greater<>>;

// Pair addition
template<typename T, typename U, typename V, typename W>
auto operator+(const std::pair<T, U> &l, const std::pair<V, W> &r)
-> std::pair<decltype(l.first + r.first), decltype(l.second + r.second)> {
    return {l.first + r.first, l.second + r.second};
}

template<typename T>
T getValue() {
    T value;
    std::cin >> value;
    return value;
}

void printVec(vector<int> v) {
    for (const auto &i: v) { cout << i sp; }
    cout nl;
}

void printVec(vector<ll> v) {
    for (const auto &i: v) { cout << i sp; }
    cout nl;
}

void printVec(vector<vi> v) {
    for (const auto &item: v)printVec(item);
}

void printVec(vector<vector<ll>> v) {
    for (const auto &item: v)printVec(item);
}

void printPair(pair<ll, ll> x) { cout << x.first sp << x.second nl; }

int lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

short int sign(ll x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    else return 0;
}

void solve();

int main(int argc, char *argv[]) {
    if (argc > 1 && argv[1][0] - '0') {
        freopen("out.txt", "w", stdout);
        freopen("in.txt", "r", stdin);
    }
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    int t = 1;
//    precompute();
    cin >> t;
    for (int i = 0; i < t; ++i) {
//        cout << "Case " << i + 1 << ": ";
        solve();
    }
}


void solve() {
    string s;
    cin >> s;
    vector<pair<char, int>> v(1);
    v[0] = {s[0], 0};
    for (char c:s){
        if (c == v.back().first) v.back().second++;
        else v.push_back({c, 1});
    }
    ll ans1 = 0, ans2 = 1;
    for (int i = 0; i < v.size(); ++i) {
        ans1 += (v[i].S - 1);
    }
    ll fac = 1;
    for (int i = 1; i <= int(s.size()) - (int)v.size(); ++i) {
        (fac *= i) %= 998244353;
    }
    ans2 = fac;
    for (int i = 0; i < v.size(); ++i) {
        (ans2 *= v[i].S) %= 998244353;
    }
    cout << ans1 sp << ans2 nl;
}