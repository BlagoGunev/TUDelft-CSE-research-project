#include <bits/stdc++.h>



using namespace std;



using ll = long long;

using db = long double;

using VS = vector<string>;

using VLL = vector<ll>;

using VVLL = vector<VLL>;

using VVVLL = vector<VVLL>;

using PLL = pair<ll, ll>;

using MLL = map<ll, ll>;

using SLL = set<ll>;

using QLL = queue<ll>;

using SS = stringstream;



#define rep(x, l, u) for (ll x = l; x < u; x++)

#define rrep(x, l, u) for (ll x = l; x >= u; x--)

#define fe(x, a) for (auto x : a)

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define mst(x, v) memset(x, v, sizeof(x))

#define sz(x) (ll) x.size()



#define umap unordered_map

#define uset unordered_set

#define mset multiset



// clang-format off

// --------------------------------- DEBUG ---------------------------------

namespace Debug {

const string open = "[", sep = ", ", close = "]";

struct Second {}; struct First : Second {};



template <typename T>

auto one(T t, First) -> decltype(cerr << t, string()) { stringstream ss; ss << t; return ss.str(); }

template <typename T>

auto one(T t, Second) -> decltype(t.first, t.second, string()) { return open + one(t.first, First()) + ", " + one(t.second, First()) + close; }

template <typename T>

auto one(T t, Second) -> decltype(t.begin(), t.end(), string() ) { string ans = open; for (auto a : t) { ans += (ans == open ? "" : sep) + one(a, First()); } return ans + close; }



string mult() { return ""; }

template <typename A, typename... B>

string mult(A a, B... b) { return one(a, First()) + " " + mult(b...); }

}  // namespace Debug

#ifdef DEBUG

#define debug(...) do { cerr << Debug::mult("[" + string(#__VA_ARGS__) + "]:", __VA_ARGS__) << endl; } while (false)

#else

#define debug(...) do {} while (false)

#endif

// --------------------------------- DEBUG ---------------------------------



ll ob(ll i, ll n) { return i < 0 || i >= n; }

ll tp(ll x) { return ( 1LL << x ); }

ll rup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }

ll sign(ll x) {	return x == 0 ? 0 : x / abs(x); }

VS ssplit(string s) { VS ans; SS ss(s); while (ss >> s) { ans.push_back(s); } return ans; }



void makemod(ll& x, ll m) { x %= m; if (x < 0) { x += m; } }

ll getmod(ll x, ll m) { makemod(x, m); return x; }

void addmod(ll &a, ll b, ll m) { a += b; if (a >= m) a -= m; }

ll powmod(ll a, ll b, ll m) { if (b == 0) return 1; ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }

ll invmod(ll a, ll m) { return powmod(a, m - 2, m); }



template<typename A, typename B> void upmin(A& x, B v) { x = min(x, (A)v); }

template<typename A, typename B> void upmax(A& x, B v) { x = max(x, (A)v); }

template<typename A> A reversed(const A& a) { A b = a; reverse(all(b)); return b; }



const VLL di = {0, 0, 1, -1, 1, -1, 1, -1};

const VLL dj = {1, -1, 0, 0, -1, -1, 1, 1};

const VLL mods = {1'000'000'007, 998'244'353, 1'000'000'207, 1'000'003};

const ll mod = mods[0];

const ll inf = (ll)1e18 + 5;

const db eps = 1e-10;

const db pi = acos(0) * 2;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



// clang-format on



ll dp[2000 * 60 + 50][6];



void solve() {

    umap<char, ll> colorInd = {{'w', 0}, {'g', 1}, {'r', 2}, {'y', 3}, {'b', 4}, {'o', 5}};



    ll k, m;

    cin >> k >> m;



    uset<ll> S;

    umap<ll, ll> M;



    rep(i, 0, m) {

        ll ind;

        string s;

        cin >> ind >> s;



        ll c = colorInd.at(s[0]);

        M[ind] = c;

        while (ind && !S.count(ind)) {

            S.insert(ind);

            ind /= 2;

        }

    }



    VVLL E(6);

    rep(i, 0, 6) {

        rep(j, 0, 6) {

            if (i % 3 == j % 3) continue;

            E[i].push_back(j);

        }

    }



    VLL A(all(S));

    sort(all(A));

    ll n = A.size();



    umap<ll, ll> inds;

    rep(i, 0, n) inds[A[i]] = i;



    rrep(i, n - 1, 0) {

        const ll ind = A[i];

        auto it = M.find(ind);

        ll fix = it == M.end() ? -1 : it->second;



        VLL childs;

        rep(child, 2 * ind, 2 * ind + 2) {

            auto it2 = inds.find(child);

            if (it2 == inds.end()) continue;

            childs.push_back(it2->second);

        }



        rep(c, 0, 6) {

            if (fix != -1 && fix != c) {

                dp[i][c] = 0;

                continue;

            }



            ll ans = 1;

            fe(nextInd, childs) {

                ll cur = 0;

                fe(cc, E[c]) addmod(cur, dp[nextInd][cc], mod);



                ans *= cur;

                ans %= mod;

            }

            dp[i][c] = ans;

        }

    }



    ll ans = 0;

    rep(c, 0, 6) addmod(ans, dp[0][c], mod);



    ll rest = powmod(4, tp(k) - 1 - n, mod);

    cout << ans * rest % mod << '\n';

}



int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);



    ll t = 1;

    // cin >> t;

    rep(i, 0, t) solve();

    return 0;

}