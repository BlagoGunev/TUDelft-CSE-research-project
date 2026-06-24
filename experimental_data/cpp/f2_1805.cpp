#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
#define FD(i, r, l) for(ll i = r; i > (l); --i)

#define K first
#define V second
#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define F(i, l, r) for (ll i = l; i < (r); ++i)

#define NN
#define M 1000000007 // 998244353


int main(){
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(20);
    G(n)
    vl a(n);for (auto &x: a) cin >> x;sort(A(a));
    ll gans = 0;

    vl p2(n, 1);
    F(i, 1, p2.size()) p2[i] = p2[i-1]*2%M;

    ll bad_iters = 0;

    while (a.size() > 1) {
        assert(++bad_iters <= 50);

        vl b;
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        vl ptr(a.size());
        iota(A(ptr), 1ll);
        F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
        while (b.size() < a.size() - 1) {
            auto [score, i] = pq.top(); pq.pop();
            b.push_back(score);
            if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
        }
        a=b;
        ll mn = a[0];
        for (auto &x: a) x -= mn;
        gans += mn * p2[a.size() - 1]%M;

        if (a.size() >= 3 and !(a[0]|a[1]|a[2])) break;

        if (a.size() >= 4 and 2 * a[3] > a.back()) { 
            ll asz = a.size(), sumsubs = 0;
            while (asz >= 4 and 2 * a[2] < (a[3] - sumsubs)) {
                asz--;
                gans += a[1] * p2[asz - 1]%M; 
                sumsubs += a[1];
                a[1] = a[2] - a[1];
            }
            while (a.size() > asz) a.pop_back();
            F(i, 3, a.size()) a[i] -= sumsubs;
        }
    }

    cout << (gans + a[0])%M << endl;
}