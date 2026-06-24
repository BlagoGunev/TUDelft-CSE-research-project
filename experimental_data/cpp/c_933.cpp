#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <bitset>
#include <ctime>

using namespace std;

#define pau system("pause")
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define clr(a, x) memset(a, x, sizeof(a))
#define pdd pair<double, double>

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

struct circle {
    ll x, y, r;
} c[3];
ll n;
vector<pdd> vec;
bool equ(pdd p1, pdd p2) {
    double x1 = p1.first, y1 = p1.second;
    double x2 = p2.first, y2 = p2.second;
    return fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS;
}
ll pow2(ll x) {return x * x;}
bool in(circle c1, circle c2) {
    int x1 = c1.x, y1 = c1.y, r1 = c1.r;
    int x2 = c2.x, y2 = c2.y, r2 = c2.r;
    int d1 = pow2(r1 - r2);
    int d2 = pow2(x1 - x2) + pow2(y1 - y2);
    return d1 > d2;
}
bool out(circle c1, circle c2) {
    int x1 = c1.x, y1 = c1.y, r1 = c1.r;
    int x2 = c2.x, y2 = c2.y, r2 = c2.r;
    int d1 = pow2(r1 + r2);
    int d2 = pow2(x1 - x2) + pow2(y1 - y2);
    return d1 < d2;
}
bool Insec(circle c1, circle c2) {
    ll x1 = c1.x, y1 = c1.y, r1 = c1.r;
    ll x2 = c2.x, y2 = c2.y, r2 = c2.r;
    if (x1 == x2 && y1 == y2) return false;
    const ll con = pow2(x2) + pow2(y2) + pow2(r1) - pow2(x1) - pow2(y1) - pow2(r2);
    if (x1 == x2) {
        ll a = 4 * (pow2(y2 - y1) + pow2(x2 - x1));
        ll b = 4 * (x1 - x2) * (con - 2 * (y2 - y1) * y1) - 8 * x1 * pow2(y2 - y1);
        ll c = 4 * pow2(y2 - y1) * pow2(x1) + pow2(con - 2 * (y2 - y1) * y1) - pow2(r1) * 4 * pow2(y2 - y1);
        ll det = b * b - 4 * a * c;
        //printf("%lld %lld %lld %lld\n", con, a, b, c);
        if (det < 0) {
            return false;
        } else if (!det) {
            double _x1 = 1.0 * (-b) / (2 * a);
            double _y1 = (2 * (x1 - x2) * _x1 + con) / (2 * (y2 - y1));
            vec.pb(mp(_x1, _y1));
        } else {
            double sqr_det = sqrt(det);
            double _x1 = 1.0 * (-b + sqr_det) / (2 * a);
            double _x2 = 1.0 * (-b - sqr_det) / (2 * a);
            double _y1 = (2 * (x1 - x2) * _x1 + con) / (2 * (y2 - y1));
            double _y2 = (2 * (x1 - x2) * _x2 + con) / (2 * (y2 - y1));
            vec.pb(mp(_x1, _y1));
            vec.pb(mp(_x2, _y2));
        }
    } else {
        ll a = 4 * (pow2(x2 - x1) + pow2(y2 - y1));
        ll b = 4 * (y1 - y2) * (con - 2 * (x2 - x1) * x1) - 8 * y1 * pow2(x2 - x1);
        ll c = 4 * pow2(x2 - x1) * pow2(y1) + pow2(con - 2 * (x2 - x1) * x1) - pow2(r1) * 4 * pow2(x2 - x1);
        ll det = b * b - 4 * a * c;
        if (det < 0) {
            return false;
        } else if (!det) {
            double _y1 = 1.0 * (-b) / (2 * a);
            double _x1 = (2 * (y1 - y2) * _y1 + con) / (2 * (x2 - x1));
            vec.pb(mp(_x1, _y1));
        } else {
            double sqr_det = sqrt(det);
            double _y1 = 1.0 * (-b + sqr_det) / (2 * a);
            double _y2 = 1.0 * (-b - sqr_det) / (2 * a);
            double _x1 = (2 * (y1 - y2) * _y1 + con) / (2 * (x2 - x1));
            double _x2 = (2 * (y1 - y2) * _y2 + con) / (2 * (x2 - x1));
            vec.pb(mp(_x1, _y1));
            vec.pb(mp(_x2, _y2));
        }
    }
    return true;
}
int main() {
    scanf("%d", &n);
    for (ll i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &c[i].x, &c[i].y, &c[i].r);
    }
    ll ans = 2;
    for (ll i = 1; i < n; ++i) {
        vec.clear();
        int flag = 1;
        for (ll j = 0; j < i; ++j) {
            if (!Insec(c[i], c[j])) {
                flag = 0;
            }
        }
        sort(vec.begin(), vec.end());
        ll tt = vec.size();
        for (ll j = 0; j < (ll)vec.size() - 1; ++j) {
            if (equ(vec[j], vec[j + 1])) --tt;
        }
        if (i == 2 && (in(c[0], c[1]) || out(c[0], c[1])) && flag) --tt;
        ans += max(tt, 1ll);
        /*for (ll j = 0; j < vec.size(); ++j) {
            printf("%.3f %.3f\n", vec[j].first, vec[j].second);
        }*/
    }
    printf("%d", ans);
    return 0;
}