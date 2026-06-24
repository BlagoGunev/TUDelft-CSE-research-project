#include <bits/stdc++.h>

#define M_PI 3.1415926535



using namespace std;



using ll = long long;

using ull = unsigned long long;

using ld = long double;



using pll = pair<ll, ll>;

using vll = vector<ll>;

using vpll = vector<pll>;



struct dbg_ {template<typename T> dbg_ & operator ,(const T & x) { cerr << x << ' '; return *this;}} dbg_t;

#define dbg(args ...) { cerr << "|" << __LINE__ << "| "; dbg_t,args;cerr << endl; }



#define pb push_back

#define FOR(i, m, n) for (ll i(m); i < n; i++)

#define REP(i, n) FOR(i, 0, n)

#define F(n) REP(i, n)

#define FF(n) REP(j, n)

#define D(x) cout << "|" << #x << " : " << x << endl

#define EPS (1e-10)

#define INF (1LL<<61)

#define CL(A,I) (memset(A,I,sizeof(A)))

#define all(x) begin(x),end(x)

#define IN(n) ll n;cin >> n;

#define x first

#define y second



#define x real()

#define y imag()

#define eq(x,y) abs(x-(y)) < EPS

using ptt = double;

using pt = complex<ptt>;

#define dot(a,b) (conj(a)*(b)).x // dot product

#define crs(a,b) (conj(a)*(b)).y // cross product



pt rotp(pt a, pt p, ptt ang) { return (a-p) * polar(1.0, ang) + p; } // rotate point around p ang radians

pt ins(pt a, pt b, pt p, pt q) { // intersection; lines are represented by start and endpoint

        auto c1 = (conj(p - a)*(b - a)).y, c2 = (conj(q - a)*(b - a)).y;

            return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel

}



int main(void) {

    ios_base::sync_with_stdio(false);

    ll n,r;

    cin>>n>>r;

    pt a(0,r);

    pt b = rotp(a, pt(0, 0), (ll(n/2)+1)*((2*M_PI)/n));

    pt c = rotp(a, pt(0, 0), (ll(n/2)-1)*((2*M_PI)/n));

    pt d = rotp(a, pt(0, 0), -((2*M_PI)/n));

    pt I = ins(a, b, c, d);

    pt vb = d + 0.5*(a-d);

    ptt v = abs(I-vb);

    ptt ba = abs(a-d);

    ptt TR = v * ba / 2;

    ptt al = (2*M_PI)/n;

    ptt S = (r*r/2.0)*(al - sin(al)) + TR;

    cout <<fixed<<setprecision(12)<< (M_PI * r * r - n*S) << endl;

    

    return 0;

}