#include <bits/stdc++.h>



template<class t> using vc = std::vector<t>;



#define x first

#define y second



typedef long long ll;



ll gcd(ll a, ll b) {

    while (b) {

        a %= b;

        std::swap(a, b);

    }

    return a;

}



bool type(const std::pair<ll, ll> &a) {

    return a.x > 0 || (a.x == 0 && a.y > 0);

}



__int128 operator/(const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) {

    return (__int128) a.x * b.y - (__int128) a.y * b.x;

}



bool cmp(const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) {

    if (type(a) != type(b)) return type(a) > type(b);

    return (a / b) > 0;

}



ll a1, a2, a3;



std::pair<ll, ll> read() {

    ll x, y, z;

    std::cin >> x >> y >> z;

    std::pair<ll, ll> e = {y * (a1 + a2 + a3) - a2 * (x + y + z),

                           z * (a1 + a2 + a3) - a3 * (x + y + z)};

    return e;

}



std::pair<ll, ll> inv(std::pair<ll, ll> a) {

    a.first *= -1, a.second *= -1;

    return a;

}



int main() {

    std::cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    std::cin >> a1 >> a2 >> a3;

    int n;

    std::cin >> n;

    vc<std::pair<ll, ll>> x;

    vc<bool> good;

    std::map<std::pair<ll, ll>, int, decltype(cmp) *> nw(cmp);

    int cnt = 0, c1 = 0;

    int d = 0;

    while (n--) {

        char c;

        std::cin >> c;

        if (c == 'A') {

            auto f = read();

            ll e = gcd(abs(f.x), abs(f.y));

            if (e) f.x /= e, f.y /= e;

            x.push_back({f.x, f.y});

            if (inv(x.back()) != x.back()) {

                ++nw[x.back()];

                if (nw[x.back()] == 1) {

                    cnt += nw.count(inv(x.back()));

                    if (nw.size() != 1) {

                        auto e = nw.lower_bound(x.back());

                        std::pair<ll, ll> L, R;

                        if (std::next(e) == nw.end()) R = nw.begin()->first;

                        else R = std::next(e)->first;

                        if (e == nw.begin()) L = nw.rbegin()->first;

                        else L = std::prev(e)->first;

                        if (L != R) c1 -= L / R < 0;

                        c1 += L / x.back() < 0, c1 += x.back() / R < 0;

                    }

                }

            } else ++d;

            good.push_back(true);

        } else {

            int i;

            std::cin >> i;

            good[i - 1] = false;

            if (inv(x[i - 1]) != x[i - 1]) {

                --nw[x[i - 1]];

                if (nw[x[i - 1]] == 0) {

                    if (nw.size() != 1) {

                        auto e = nw.lower_bound(x[i - 1]);

                        std::pair<ll, ll> L, R;

                        if (std::next(e) == nw.end()) R = nw.begin()->first;

                        else R = std::next(e)->first;

                        if (e == nw.begin()) L = nw.rbegin()->first;

                        else L = std::prev(e)->first;

                        if (L != R) c1 += L / R < 0;

                        c1 -= L / x[i - 1] < 0, c1 -= x[i - 1] / R < 0;

                    }

                    cnt -= nw.count(inv(x[i - 1]));

                }

                if (!nw[x[i - 1]]) nw.erase(x[i - 1]);

            } else --d;

        }

        bool ans = !!d;

        if (ans) {

            std::cout << 1 << '\n';

        } else {

            bool ans = cnt;

            if (ans) {

                std::cout << 2 << '\n';

            } else {

                if (c1 == 0 && nw.size() > 1) {

                    std::cout << 3 << '\n';

                } else {

                    std::cout << 0 << '\n';

                }

            }

        }

    }

}