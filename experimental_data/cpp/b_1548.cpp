#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <stack>

#include <queue>

#include <cmath>

#include <tuple>

#include <cstdio>

#include <bitset>

#include <sstream>

#include <iterator>

#include <numeric>

#include <map>

#include <cstring>

#include <set>

#include <functional>

#include <iomanip>

#include <cassert>



using namespace std;



#define DEBUG_ //!!$BDs=P;~$K%3%a%s%H%"%&%H(B!!

#ifdef DEBUG_

#define dump(x)  cerr << #x << " = " << (x) << endl;

#else

#define dump(x)  ;

#endif



#define equals(a,b) (fabs((a)-(b)) < EPS)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n)  FOR(i,0,n)

#define SZ(x) ((int)(x).size())

#define pb push_back

#define eb emplace_back



//#define int long long



typedef long long LL;

typedef vector<int> VI;

typedef vector<LL> VL;

typedef vector<VI> VVI;

typedef vector<VL> VVL;

typedef vector<string> VS;

typedef pair<int, int> PII;

typedef pair<LL, LL> PLL;



template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



    template <typename T>

std::string printVector(const std::vector<T> &data)

{

    std::stringstream ss;

    std::ostream_iterator<T> out_it(ss, ", ");

    ss << "[";

    std::copy(data.begin(), data.end() - 1, out_it);

    ss << data.back() << "]";

    return ss.str();

}



template <typename T>

void print_array(const T &ary, int size){

    REP(i,size){

        cout << ary[i] << " ";

    }

    cout << endl;

}



//const int mod = 1e9+7;

const int mod = 998244353;

const LL LINF = 1001002003004005006ll;

const int INF = 1001001001;

const double EPS = (1e-10);

const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;

int dx[] = {0,0,-1,1};

int dy[] = {-1,1,0,0};



long long int gcd(long long int a, long long int b) {

    if (a < b)swap(a, b);

    while (b) {

        a %= b;

        swap(a, b);

    }

    return a;

}



template< typename Monoid >

struct SegmentTree {

    using F = function< Monoid(Monoid, Monoid) >;



    int sz;

    vector< Monoid > seg;



    const F f;

    const Monoid M1;



    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {

        sz = 1;

        while(sz < n) sz <<= 1;

        seg.assign(2 * sz, M1);

    }



    void set(int k, const Monoid &x) {

        seg[k + sz] = x;

    }



    void build() {

        for(int k = sz - 1; k > 0; k--) {

            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);

        }

    }



    void update(int k, const Monoid &x) {

        k += sz;

        seg[k] = x;

        while(k >>= 1) {

            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);

        }

    }



    Monoid query(int a, int b) {

        Monoid L = M1, R = M1;

        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {

            if(a & 1) L = f(L, seg[a++]);

            if(b & 1) R = f(seg[--b], R);

        }

        return f(L, R);

    }



    Monoid operator[](const int &k) const {

        return seg[k + sz];

    }

};



void solve(){

    int n;

    cin >> n;

    VL A(n);

    REP(i,n){

        cin >> A[i];

    }



    auto f = [](LL a, LL b){

        if (a < b)swap(a, b);

        while (b) {

            a %= b;

            swap(a, b);

        }

        return a;

    };



    SegmentTree<LL> seg(n-1,f,0);

    VL B(n-1);

    REP(i,n-1){

        B[i] = abs(A[i] - A[i+1]);

        seg.set(i,B[i]);

    }

    seg.build();

    int ans = 1;



    for(int left = 0, right = 0; left < n-1; left++){

        if(right < left){

            right = left;

        }

        LL start = seg.query(left,right);

        while(right < n-1){

            LL nxt = gcd(start,B[right]);

            if(nxt != 1){

                start = nxt;

                right++;

            }else{

                break; 

            }

        }



        chmax(ans, right-left+1);

    }



    cout << ans << endl;



}



signed main(int argc, char const *argv[])

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    cout << setprecision(12);



    int t;

    cin >> t;

    REP(i,t){

        solve();

    }



}