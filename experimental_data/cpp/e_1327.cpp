// ඞ

#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/assoc_container.hpp>



using namespace std;

using namespace __gnu_pbds;



#ifdef LOCAL

#include "debug.h"

#define dbg(...) debug_out(splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

#else

#define dbg(...)

#endif



#define int long long

#define ALL(v) (v).begin(), (v).end()

#define mem(a, x) memset(a , x , sizeof(a))

#define F first

#define S second

#define pb push_back

#define popCnt __builtin_popcountll



typedef long long ll;

typedef long double ld;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef vector<vector<int>> vvi;

typedef pair <int, int> pii;

typedef vector<pair <int, int>> vpii;

typedef vector<vector<char>> vvc;



const int mod = 998244353;

const int oo = 0x5f5f5f5f;

const long double PI = acos(-1.0L);





int Log2 (int x) {return 31 - __builtin_clz(x);}

int ceiledLog2 (int x){return Log2(x) + (__builtin_popcount(x) != 1);}

ll toLL (int first, int second, int mx){return (1LL*first*mx) + second;}

vi Unique(vi x){sort(ALL(x));x.resize(distance(x.begin(),unique(ALL(x))));return x;}

template <class T, class U> T GCD (T a, U b) {return (!b ? a : GCD(b, a%b));}

template <class T, class U> T LCM (T a, U b) {return ((a/GCD(a, b)) * b);}

template <class T> bool isSquare (T n) {T sq = sqrt(n);  return (sq*sq)==n;}

template <typename T>

using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//bool sortBySecond (pii &a, pii &b) {return a.second < b.second;} //asc



int ys[] = {-1, -1, 0, 1, 1, 1, 0, -1};     //edges [0, 2, 4, 6]

int xs[] = {0, 1, 1, 1, 0, -1, -1, -1};



//-----------------------------------------------------------------------------//



//const int N = ?e5 + 5;

// RESET ALL GLOBALS

void run_test ()

{

    int n, p = 1;

    cin >> n;



    int ans[n];

    ans[0] = 10;

    for (int i = 1; i < n; ++i) {

        ans[i] = (81*i + 99);

        ans[i] = (ans[i] * p)%mod;

        p = (p*10)%mod;

    }



    for (int i = n-1; i >= 0; i--)

        cout << ans[i] << ' ';

}



void initialize(char _mode = 's');

int32_t main()

{

    initialize();

    //cout << fixed << setprecision (9);



    int tc = 1;

    //cin >> tc;

    for (int t=1; t <= tc; t++) {

        //cout << "Case #" << t << ": ";

        run_test();

    }

    cerr << "$time taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;

}

void initialize(char _mode){  //s,d,c,x

    if (_mode == 's' || _mode == 'c'){

        ios::sync_with_stdio(false);

        cin.tie(nullptr);

    }

#ifdef LOCAL

    if (_mode == 's' || _mode == 'd'){

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    }

#endif

}