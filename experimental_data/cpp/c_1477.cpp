#include <bits/stdc++.h>



using namespace std;



#define fi first

#define se second

using ll = long long;



const int N = 4e4 + 10;

const double pi = acos(-1);

const double eps = 1e-8;

typedef pair<int,int> pii;

const int mod = 1e9 + 7;

int sgn(double x) {

    return x < -eps? -1: x > eps;

}



struct P {

    int x, y, pos;

    P() {}

    P(int _x, int _y, int _id) :x(_x), y(_y), pos(_id) {}

    void in() { cin >> x >> y; }

    bool operator*(const P& h) const {

        return (ll)x * h.x + (ll)y * h.y <= 0;

    }

    P operator-(const P& h) const {

        return P{x - h.x, y - h.y, 1};

    }

};



void solve() {

    int n; cin >> n;

    vector<P> p(n);

    for(int i = 0; i < n; ++ i) {

        p[i].in();

        p[i].pos = i + 1;

    }

    for(int i = 2; i < n; ++ i) {

        for(int j = i; j < n; ++ j) {

            if((p[j] - p[j - 1]) * (p[j - 2] - p[j - 1])) {

                swap(p[j - 1], p[j]);

            }

        }

    }

    for(int i = 0; i < n; ++ i) cout << p[i].pos << ' ';

    cout << '\n';

}









signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

#ifdef ACM_LOCAL

    freopen("input", "r", stdin);

#endif

    int o = 1;

    while(o --)

        solve();

    return 0;

}