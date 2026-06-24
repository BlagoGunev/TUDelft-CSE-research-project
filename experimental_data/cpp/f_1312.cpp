/*************************************

*    author: marvinthang             *

*    created: 10.01.2023 09:36:50    *

*************************************/



#include <bits/stdc++.h>



using namespace std;



#define                  fi  first

#define                  se  second

#define                left  ___left

#define               right  ___right

#define                TIME  (1.0 * clock() / CLOCKS_PER_SEC)

#define             MASK(i)  (1LL << (i))

#define             FULL(i)  (MASK(i) - 1)

#define           BIT(x, i)  ((x) >> (i) & 1)

#define  __builtin_popcount  __builtin_popcountll

#define              ALL(v)  (v).begin(), (v).end()

#define           REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)

#define        FOR(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 

#define       FORD(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i) 

#define        scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)

#define       print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)

#ifdef LOCAL

    #include "debug.h"

#else

    #define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

    #define DB(...) 23

    #define db(...) 23

    #define debug(...) 23

#endif



template <class T> scan_op(vector <T>)  { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }

template <class U, class V> scan_op(pair <U, V>)  { return in >> u.fi >> u.se; }

template <class U, class V> print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }

template <class Con, class = decltype(begin(declval<Con>()))> typename enable_if <!is_same<Con, string>::value, ostream&>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }

template <size_t i, class T> ostream & print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")";  else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }

template <class ...U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }



// end of template



const double PI = 3.1415926535897932384626433832795; // acos(-1.0); atan(-1.0);

const int dir[] = {1, 0, -1, 0, 1, 1, -1, -1, 1}; // {2, 1, -2, -1, -2, 1, 2, -1, 2};



void process(void) {

    int n, x, y, z; cin >> n >> x >> y >> z;

    vector <long long> a(n); cin >> a;

    vector <vector <int>> dp(37, vector<int>(3, 0));

    int ma = max({x, y, z});

    map <vector <vector <int>>, int> states;

    int cycle = -1, first = -1;

    FOR(i, 1, 36) {

        REP(j, 3) {

            vector <int> List;

            List.push_back(dp[max(0, i - x)][0]);

            if (j != 1) List.push_back(dp[max(0, i - y)][1]);

            if (j != 2) List.push_back(dp[max(0, i - z)][2]);

            sort(ALL(List));

            for (int x: List) if (dp[i][j] == x) ++dp[i][j];

        }

        if (i >= ma - 1) {

            vector <vector <int>> v(dp.begin() + i - ma + 1, dp.begin() + i + 1);

            if (!states.count(v)) states[v] = i;

            else {

                first = states[v];

                cycle = i - first;

                break;

            }

        }

    }

    auto get_dp = [&] (long long i, int j) {

        if (i < first) return dp[max(0LL, i)][j];

        return dp[(i - first) % cycle + first][j];

    };

    int xor_all = 0;

    for (long long a: a) xor_all ^= get_dp(a, 0);

    int res = 0;

    for (long long a: a) {

        int cur_xor = xor_all ^ get_dp(a, 0);

        if (!(cur_xor ^ get_dp(a - x, 0))) ++res;

        if (!(cur_xor ^ get_dp(a - y, 1))) ++res;

        if (!(cur_xor ^ get_dp(a - z, 2))) ++res;

    }

    cout << res << '\n';

}



int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); // cout.tie(nullptr);

    file("test");

    int t; cin >> t; while (t--) 

        process();

    cerr << "Time elapsed: " << TIME << " s.\n";

    return (0^0);

}