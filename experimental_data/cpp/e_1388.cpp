#pragma GCC target("popcnt")

#pragma GCC optimize("Ofast")



#include<bits/stdc++.h>



#define fi first

#define se second

#define ld long double

#define ll long long

#define int ll

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define mpa make_pair

#define pb emplace_back

using namespace std;



mt19937 gen(time(0));

mt19937 gen2(228);

mt19937_64 gen64(time(0));



int inf = (int)1e13 + 228;

const int mod = 998244353;



const ld PI = acos(-1);

ld eps = 1e-12;



int crossProduct(pair<int, int> a, pair<int, int> b) {

    return a.fi * b.se - a.se * b.fi;

};



struct line{

    int k, b;

    ld x;

    line(){};

    line(int k, int b): k(k), b(b){};

    ld getValue(ld argument) {

        return k * argument + b;

    }

};



struct CHT{

    vector<line> c;

    vector<ld> x;

    CHT() {}

    int ptr = 0;

    void addLine(line l) {

        l.x = -inf;

        while (c.size() && c.back().getValue(x.back()) < l.getValue(x.back())) {

            c.pop_back();

            x.pop_back();

        }

        ld intersection = -inf;

        if (c.size()) {

            if (c.back().k == l.k) {

                return;

            } else {

                intersection = (ld)(l.b - c.back().b) / (ld)(c.back().k - l.k);

            }

        }

        l.x = intersection;

        c.pb(l);

        x.pb(l.x);

    }

    ld ask(ld argument) {

        ptr = 0;

        while (ptr + 1 < c.size() && x[ptr + 1] < argument) {

            ++ptr;

        }

        return c[ptr].getValue(argument);

    }

};



signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    cout << fixed << setprecision(15);

    int n;

    cin >> n;

    vector<int> l(n), r(n), y(n);

    vector<pair<int, int>> lines;

    for (int i = 0; i < n; ++i) {

        cin >> l[i] >> r[i] >> y[i];

        lines.pb(y[i], l[i]);

        lines.pb(y[i], r[i]);

    }

    ld ansFlat = *max_element(all(r)) - *min_element(all(l));

    if (*max_element(all(y)) == *min_element(all(y))) {

        cout << ansFlat << '\n';

        return 0;

    }

    vector<array<int, 3>> events;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            if (y[i] <= y[j]) {

                continue;

            }

            pair<int, int> vec1 = mpa(r[j] - l[i], y[j] - y[i]);

            pair<int, int> vec2 = mpa(l[j] - r[i], y[j] - y[i]);

            if (crossProduct(vec1, vec2) < 0) {

                swap(vec1, vec2);

            }

            array<int, 3> L = {vec1.fi, vec1.se, -1ll};

            array<int, 3> R = {vec2.fi, vec2.se, 1ll};

            events.pb(L);

            events.pb(R);

        }

    }

    sort(all(events), [&](array<int, 3> a, array<int, 3> b){

        int d = crossProduct(mpa(a[0], a[1]), mpa(b[0], b[1]));

        if (d == 0) {

            return a[2] > b[2];

        } else {

            return d > 0;

        }

    });

    sort(all(lines));

    CHT cMax, cMin;

    for (auto [k, b] : lines) {

        cMax.addLine(line(k, b));

    }

    reverse(all(lines));

    for (auto [k, b] : lines) {

        cMin.addLine(line(-k, -b));

    }

    int bal = 0;

    ld ans = inf;

    ld lastArg = -inf;

    pair<int, int> bestL = mpa(inf, inf), bestR = mpa(inf, inf);

    for (auto [x, y, t] : events) {

        if (bal == 0) {

            assert(-(ld)x / (ld)y >= lastArg);

            lastArg = -(ld)x / (ld)y;

            ld argument = -(ld)x / (ld)y;

            ld minX = -cMin.ask(argument);

            ld maxX = cMax.ask(argument);

            ans = min(ans, maxX - minX);

        }

        bal += t;

        if (bal == 0) {

            ld argument = -(ld)x / (ld)y;

            ld minX = -cMin.ask(argument);

            ld maxX = cMax.ask(argument);

            ans = min(ans, maxX - minX);

        }

    }

    cout << ans << '\n';

}