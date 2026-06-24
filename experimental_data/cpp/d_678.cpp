#include <bits/stdc++.h>



#define left nadnlassad

#define right asdaslknd

#define y1 kjdajasjdsas

#define nxt accepted

#define prev why_would_you_call_when_you_are_high



#define pb push_back

#define mp make_pair

#define mt make_tuple



#define f first

#define s second



#define ll long long

#define ld long double

#define ull unsigned ll



#define _hash pair<ll, ull>

#define pii pair<int, int>

#define uint unsigned int

#define puu pair<uint, uint>



#define sqr(x) ((x) * 1LL * (x))



#define vec vector<int>

#define sz(v) int(v.size())

#define all(v) v.begin(), v.end()

#define endl "\n"

#define _bits(x) __builtin_popcountll(x)

#define forn(i, n) for(int i = 1; i <= (int) n; i++)



using namespace std;



void rf() {

    #define fname "sparse"

    #ifdef SONY

        freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);

    #else

        //freopen(fname".in", "r", stdin);

        //freopen(fname".out", "w", stdout);

    #endif //SONY

}



const int nx[8] = {2, -2, -2, 2, 1, 1, -1, -1};

const int ny[8] = {1, 1, -1, -1, 2, -2, -2, 2};

const int Nx[4] = {0, 0, -1, 1};

const int Ny[4] = {1, -1, 0, 0};



const ll LINF = (ll) 5e18;

const int INF = 1e9 + 7;



const int N = 6e5 + 1;

const int MAXN = 1e6 + 50;

const double EPS = 1e-9, PI = 3.14159265359;



inline int get_int() {

    char x = getchar();

    int ret = 0;

    bool neg = 0;

    while (!('0' <= x && x <= '9')) {

        if (x == '-')

            neg = 1; 

        x = getchar();

    }

    while ('0' <= x && x <= '9') {

        ret = ret * 10 + x - '0';

        x = getchar();

    }

    if (neg) ret *= -1;

    return ret;

}



ll add(ll x, ll y) {

    x += y;

    if (x >= INF)

        x -= INF;

    return x;

}



ll mult(ll x, ll y) {

    return x * y % INF;

}



ll bp(ll x, ll y) {

    ll ret = 1;

    while (y) {

        if (y & 1)

            ret = mult(ret, x);

        x = mult(x, x);

        y >>= 1;

    }

    return ret;

}



  

int main() {

    srand(time(0));

    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    rf();

    ll a, b, n, x;

    cin >> a >> b >> n >> x;

    ll res = mult(bp(a, n), x);

    if (a == 1) {

        res = add(res, mult(b, n % INF));   

    } else {

        res = add(res, mult(b, mult((bp(a, n) - 1 + INF) % INF, bp(a - 1, INF - 2))));

    }

    cout << res; 

    return 0;

}