#include<iostream>

#include<stdio.h>

#include<string.h>

#include<math.h>

#include<algorithm>

#include<map>

#include<unordered_map>

#define fi first

#define se second

using namespace std;

typedef int T;

struct point{

    // integer complex number

    T x, y;

    point(){x = y = 0;}

    point(T _x, T _y) : x(_x), y(_y) {}

    inline friend point conj(const point &p){

        return point(p.x, -p.y);

    }

    bool operator < (const point& that){

        return x < that.x || (x == that.x && y == that.y);

    }

    friend point operator *(const point &a, const point &b){

        return point(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);

    }

    point operator *(const int& val){

        return point(x * val, y * val);

    }

    point operator /(const int& val){

        return point(x / val, y / val);

    }

    friend point operator +(const point &a, const point &b){

        return point(a.x + b.x, a.y + b.y);

    }

    friend point operator -(const point &a, const point &b){

        return point(a.x - b.x, a.y - b.y);

    }

};

inline void scan(point &p){

    scanf("%d%d", &p.x, &p.y);

}

inline T lenSqr(const point &p){

    return (p.x * p.x + p.y * p.y);

}

// in the next rotate functions the positions after rotation are not correct due to the r term multiplication in the complex number

// but the relative positions after rotation shall be correct

inline point orotate(const point& p, const point& v){

    return p * v;

}

struct line{

    // Ax + By + C = 0

    T A, B, C;

    void reduce(int &a, int &b){

        if(!a) {b = 1; return;}

        if(!b) {a = 1; return;}

        int g = __gcd(a, b);

        a /= g, b /= g;

        if(b < 0) a *= -1, b *= -1;

    }

    line() { A = B = C = 0;}

    line(const point& a, const point& b){

        A = round(b.y - a.y);

        B = round(a.x - b.x);

        reduce(A, B);

        C = - A * a.x - B * a.y;

    }

    long long compress(){

        return ((1LL * A * 33333 + B ) * 33333 + C);

    }

    line perpendicular(const point& p){

        line ret;

        ret.A = -B, ret.B = A;

        reduce(ret.A, ret.B);

        ret.C = - ret.A * p.x - ret.B * p.y;

        return ret;

    }

    friend bool operator < (const line& l1, const line& l2){

        return l1.A < l2.A || (l1.A == l2.A && (l1.B < l2.B || (l1.B == l2.B && l1.C < l2.C)));

    }

};

struct circle{

    point c;

    int r;

}cir[1550];

int n, m;

unordered_map<long long, map<int, int> > mp;

unordered_map<long long, pair<point, point> > e;

int main(){

    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; ++i){

        point a, b;

        scan(a), scan(b);

        line l(a = a * 2, b = b * 2);

        if(!e.count(l.compress())) e[l.compress()] = {a, conj(b - a)};

        pair<point, point> trans = e[l.compress()];

        a = orotate(a - trans.fi, trans.se), b = orotate(b - trans.fi, trans.se);

        if(a.x > b.x) swap(a, b);

        ++mp[l.compress()][a.x], --mp[l.compress()][b.x + 1];

    }

    for(auto it = mp.begin(); it != mp.end(); ++it)

        for(auto i = it->se.begin(); i != it->se.end(); ++i)

            if(i != it->se.begin())

                i->se += prev(i)->se;

    long long ans = 0;

    for(int i = 0; i < m; ++i){

        scan(cir[i].c);

        scanf("%d", &cir[i].r);

        cir[i].c = cir[i].c * 2, cir[i].r <<= 1;

        for(int j = 0; j < i; ++j){

            point a = cir[i].c, b = cir[j].c;

            point mid = (a + b) / 2;

            line l = line(a, b).perpendicular(mid);

            if(cir[i].r == cir[j].r && lenSqr(b - a) > (cir[i].r * cir[i].r * 4) && e.count(l.compress())){

                mid = orotate(mid - e[l.compress()].fi, e[l.compress()].se);

                auto it = upper_bound(mp[l.compress()].begin(), mp[l.compress()].end(), pair<const int, int>(mid.x, 1 << 30));

                if(it != mp[l.compress()].begin())

                    ans += prev(it)->se;

            }

        }

    }

    #ifdef LOCAL

        cout << ":" << ans << endl;

    #else

        printf("%I64d\n", ans);

    #endif // LOCAL

    return 0;

}