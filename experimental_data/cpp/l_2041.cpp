#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, n) for (int i = 0; i < (n); i += 1)

mt19937 rnd(234);
const ll inf = 1e18;

const ld eps = 1e-10;

ld sq(ld x) {
    return x * x;
}

int sign(ld x) {
    if (x < -eps) {
        return -1;
    }
    if (x > eps) {
        return 1;
    }
    return 0;
}

#define vec point

struct point {
    ld x, y;

    // auto operator<=>(const point &) const = default;
};

ld operator*(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

ld operator%(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

point operator-(const point &a, const point &b) {
    return {a.x - b.x, a.y - b.y};
}

point operator+(const point &a, const point &b) {
    return {a.x + b.x, a.y + b.y};
}

point operator*(const point &a, ld b) {
    return {a.x * b, a.y * b};
}

point operator/(const point &a, ld b) {
    return {a.x / b, a.y / b};
}

bool operator<(const point &a, const point &b) {
    if (sign(a.y - b.y) != 0) {
        return a.y < b.y;
    } else if (sign(a.x - b.x) != 0) {
        return a.x < b.x;
    }
    return 0;
}

ld len2(const point &a) {
    return sq(a.x) + sq(a.y);
}

ld len(const point &a) {
    return sqrt(len2(a));
}

point norm(point a) {
    return a / len(a);
}

int half(point a) {
    return (sign(a.y) == -1 || (sign(a.y) == 0 && a.x < 0));
}

point ort(point a) {
    return {-a.y, a.x};
}

bool cmpHalf(const point &a, const point &b) {
    if (half(a) != half(b)) {
        return half(b);
    } else {
        int sgn = sign(a % b);
        if (!sgn) {
            return len2(a) < len2(b);
        } else {
            return sgn == 1;
        }
    }
}

struct line {
    ld a, b, c;

    void norm() {
        ld d = len({a, b});
        assert(sign(d) > 0);
        a /= d;
        b /= d;
        c /= d;
    }

    ld eval(point p) const {
        return a * p.x + b * p.y + c;
    }

    bool isIn(point p) const {
        return sign(eval(p)) >= 0;
    }

    bool operator==(const line &other) const {
        return sign(a * other.b - b * other.a) == 0 &&
               sign(a * other.c - c * other.a) == 0 && sign(b * other.c - c * other.b) == 0;
    }
};

line getln(point a, point b) {
    line res;
    res.a = a.y - b.y;
    res.b = b.x - a.x;
    res.c = -(res.a * a.x + res.b * a.y);
    res.norm();
    return res;
}

bool intersect(line l, line m, point &I) {
    ld d = l.b * m.a - m.b * l.a;
    if (sign(d) == 0) {
        return false;
    }
    ld dx = m.b * l.c - m.c * l.b;
    ld dy = m.c * l.a - l.c * m.a;
    I = {dx / d, dy / d};
    return true;
}

vec getPoint(line l) {
    return {-l.b, l.a};
}

bool bad(line a, line b, line c) {
    point x;
    assert(intersect(b, c, x) == 1);
    return a.eval(x) < 0;
}

vector<point> hpi(vector<line> lines) {
    sort(all(lines), [](line al, line bl) -> bool {
        point a = getPoint(al);
        point b = getPoint(bl);
        if (half(a) != half(b)) {
            return half(a) < half(b);
        }
        return a % b > 0;
    });

    vector<pair<line, int>> st;
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i < (int)lines.size(); i++) {
            bool flag = false;
            while (!st.empty()) {
                if (len(getPoint(st.back().first) - getPoint(lines[i])) < eps) {
                    if (lines[i].c >= st.back().first.c) {
                        flag = true;
                        break;
                    } else {
                        st.pop_back();
                    }
                } else if (getPoint(st.back().first) % getPoint(lines[i]) < eps / 2) {
                    return {};
                } else if (st.size() >= 2 && bad(st[st.size() - 2].first, st[st.size() - 1].first, lines[i])) {
                    st.pop_back();
                } else {
                    break;
                }
            }
            if (!flag) {
                st.push_back({lines[i], i});
            }
        }
    }

    vector<int> en(lines.size(), -1);
    vector<point> ans;
    for (int i = 0; i < (int)st.size(); i++) {
        if (en[st[i].second] == -1) {
            en[st[i].second] = i;
            continue;
        }
        for (int j = en[st[i].second]; j < i; j++) {
            point I;
            assert(intersect(st[j].first, st[j + 1].first, I) == 1);
            ans.push_back(I);
        }
        break;
    }
    return ans;
}

ld get_square(vector<point> bebra) {
    ld result = 0;
    for (int i = 0; i < bebra.size(); i += 1) {
        int j = (i + 1) % bebra.size();
        result += bebra[i] % bebra[j];
    }
    return abs(result) / 2;
}

ld get_square(vector<point> p, point c) {
    vector<line> lines;
    vector<point> q;
    for (auto f : p) {
        q.push_back(c * 2 - f);
    }
    for (auto poly : {p, q}) {
        for (int i = 0; i < poly.size(); i += 1) {
            int j = (i + 1) % poly.size();
            lines.push_back(getln(poly[i], poly[j]));
        }
    }
    vector<point> bebra = hpi(lines);
    if (bebra.empty()) {
        return 0;
    }
    return get_square(bebra);
}

int32_t main() {
    if (1) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    // vector<point> poly = {
    //     point{0, 0},
    //     point{2, 0},
    //     point{2, 2},
    //     point{0, 2},
    // };
    // point c{0.5, 0.5};
    // cout << get_square(poly, c) << "\n";
    int n;
    cin >> n;
    vector<point> poly(n);
    rep(i, n) {
        cin >> poly[i].x >> poly[i].y;
    }
    ld mn = poly[0].x, mx = poly[0].x;
    rep(i, n) {
        mn = min(mn, poly[i].x);
        mx = max(mx, poly[i].x);
    }
    auto intersect_poly = [&](ld x) {
        ld mn = 1e18;
        ld mx = -1e18;
        for (int i = 0; i < n; i += 1) {
            int j = (i + 1) % n;
            point a = poly[i];
            point b = poly[j];
            if (a.x > b.x) {
                swap(a, b);
            }
            if (a.x - eps < x and b.x + eps > x) {
                line lnab = getln(a, b);
                line lnvert = getln(point{x, 0}, point{x, 1});
                point I;
                if (intersect(lnab, lnvert, I)) {
                    mn = min(mn, I.y);
                    mx = max(mx, I.y);
                }
            }
        }
        return make_pair(mn, mx);
    };
    auto get_val = [&](ld x) -> ld {
        auto [tl, tr] = intersect_poly(x);
        if (tl + eps >= tr) {
            return 0;
        }
        rep(itr, 100) {
            ld tm1 = (2 * tl + tr) / 3;
            ld tm2 = (tl + 2 * tr) / 3;
            ld s1 = get_square(poly, point{x, tm1});
            ld s2 = get_square(poly, point{x, tm2});
            if (s1 > s2) {
                tr = tm2;
            } else {
                tl = tm1;
            }
        }
        return get_square(poly, point{x, (tl + tr) / 2});
    };
    ld tl = mn;
    ld tr = mx;
    rep(itr, 100) {
        ld tm1 = (2 * tl + tr) / 3;
        ld tm2 = (tl + 2 * tr) / 3;
        ld s1 = get_val(tm1);
        ld s2 = get_val(tm2);
        if (s1 > s2) {
            tr = tm2;
        } else {
            tl = tm1;
        }
    }
    ld result = get_square(poly) - get_val((tl + tr) / 2);
    cout << fixed << setprecision(15) << result << "\n";
    return 0;
}