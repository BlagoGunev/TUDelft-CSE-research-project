// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
        #ifdef LOCAL
        srand(300); 
        #else
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

#define sqr(x) ((x)*(x))
using myf = long double;
const myf EPS = 1e-9, PI = 3.1415926535897932384626433, MAXC = 1e9;

struct point
{
    myf x, y;
    point() {}
    point(myf _x, myf _y): x(_x), y(_y) {}
    bool operator < (const point & rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x; // epsilon???
    }
};
inline myf dist(point a, point b) {return hypot(b.x - a.x, b.y - a.y);}
inline myf sqdist(point a, point b) {return sqr(b.x - a.x) + sqr(b.y - a.y);}
inline bool less(myf a, myf b) {return a + EPS < b;}
inline bool greater(myf a, myf b) {return a > b + EPS;}
inline bool equal(myf a, myf b) {return abs(a - b) / max(myf(1), abs(a)) <= EPS;}
inline bool leq(myf a, myf b) {return less(a, b) || equal(a, b);}
inline bool geq(myf a, myf b) {return greater(a, b) || equal(a, b);}

inline bool btw(myf o, myf d1, myf d2) {
    return (less(d1, o) && less(o, d2)) || (less(d2, o) && less(o, d1));
}

inline bool btw(point o, point p1, point p2) {
    return btw(o.x, p1.x, p2.x) && btw(o.y, p1.y, p2.y);
}

std::istream & operator >>(std::istream & is, point & p) {
    return is >> p.x >> p.y;
}

std::ostream & operator <<(std::ostream & os, const point p) {
    return os << p.x << ' ' << p.y;
}

struct vc
{
    myf x, y;
    vc() {}
    vc(myf _x, myf _y): x(_x), y(_y) {}
    vc(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    myf length() {
        return hypot(x, y);
    }
    myf sqlength() {
        return sqr(x) + sqr(y);
    }
};

point operator +(point a, vc v) {
    return point(a.x + v.x, a.y + v.y);
}

vc operator +(vc a, vc v) {
    return vc(a.x + v.x, a.y + v.y);
}

myf operator *(vc a, vc b) {
    return a.x * b.x + a.y * b.y;
}

myf operator %(vc a, vc b) {
    return a.x * b.y - a.y * b.x;
}

vc operator *(vc v, myf x) {
    return vc(v.x * x, v.y * x);
}

vc turn_clockwise(vc a) {
    return vc(a.y, -a.x);
}

vc turn_anticlockwise(vc a) {
    return vc(-a.y, a.x);
}

struct line
{
    myf a, b, c;
    line() {}
    line(myf _a, myf _b, myf _c): a(_a), b(_b), c(_c) {
        normalize();
    }
    line(point one, point two) {
        a = one.y - two.y;
        b = two.x - one.x;
        c = -(a * one.x + b * one.y);
        normalize();
    }
    line(vc norm, point cont) {
        a = norm.x;
        b = norm.y;
        c = -(a * cont.x + b * cont.y);
        normalize();
    }
    void normalize() {
        myf div = hypot(a, b);
        a /= div;
        b /= div;
        c /= div;
    }
};

struct circle {
    point center;
    myf radius;
    circle() {}
    circle(point _center, myf _radius) : center(_center), radius(_radius) {}
    circle(point _center, vc _v) : center(_center) {
        radius = _v.length();
    }
};

const int MAXN = 1e4 + 14;
point a[MAXN];
point rcs[MAXN];
myf ss[MAXN];
int n, q;

vc rotate(vc v, myf angle) {
    return vc(v.x * cos(angle) - v.y * sin(angle), v.x * sin(angle) + v.y * cos(angle));
}


bool was = 0;

point top;
myf angle = 0;
int nump = 0;
int nums = 0;
point get(int i) {
    if (!was)
        return a[i];
    vc v(a[nump], a[i]);
    return top + rotate(v, angle);
}

int main() {

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    myf sumx = 0, sumy = 0;
    myf area = 0;
    for (int i = 3; i <= n; ++i) {
        rcs[i] = point((a[1].x + a[i - 1].x + a[i].x) / 3., (a[1].y + a[i - 1].y + a[i].y) / 3.);
        ss[i] = abs(vc(a[1], a[i - 1]) % vc(a[1], a[i])) / 2.;
        sumx += rcs[i].x * ss[i];
        sumy += rcs[i].y * ss[i];
        area += ss[i];
    }

    sumx /= area;
    sumy /= area;    
    point center(sumx, sumy);

    while (q--) {
        int type, f, t;
        cin >> type;
        if (type == 1) {
            cin >> f >> t;
            if (!was) {
                nump = f ^ 3;
                nums = t;
                top = get(nump);
                vc toc(a[nump], center);
                vc down(0, -1);
                angle = atan2(toc % down, toc * down);
                was = 1;
            } else {
                if (f == nump) {
                    top = get(nums);
                    nump = nums;
                    nums = t;
                    vc toc(a[nump], center);
                    vc down(0, -1);
                    angle = atan2(toc % down, toc * down);
                } else {
                    assert(f == nums);
                    nums = t;
                }
            }
            was = 1;
        } else {
            cin >> f;
            cout << get(f) << '\n';
        }
    }

    return 0;
}