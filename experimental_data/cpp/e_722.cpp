#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Mod
{
    static const auto P = int(1e9+7);
    int k;

    Mod() = default;
    Mod(const int k) : k(k) {}
};

Mod operator+(const Mod a, const Mod b) { return (a.k + b.k) % Mod::P; }
Mod operator-(const Mod a, const Mod b) { return (a.k - b.k + Mod::P) % Mod::P; }
Mod operator*(const Mod a, const Mod b) { return int((ll(a.k) * b.k) % Mod::P); }
Mod power(const Mod a, const int k)
{
    if (k == 0) return 1;
    else if (k%2 == 0) return power(a*a, k/2);
    else return a * power(a*a, k/2);
}
Mod inverse(const Mod a) { return power(a, Mod::P-2); }
Mod operator/(const Mod a, const Mod b) { return a * inverse(b); }
Mod& operator+=(Mod& a, const Mod b) { return a = a+b; }
Mod& operator-=(Mod& a, const Mod b) { return a = a-b; }

struct Point { int r, c; };
bool operator<(const Point p, const Point q)
{
    if (p.r != q.r) return p.r < q.r;
    else return p.c < q.c;
}

namespace lut
{
    vector<Mod> factorials, inverse_factorials;

    void precompute(const int max)
    {
        factorials.resize(max+1);
        factorials[0] = 1;
        for (auto i = 1; i <= max; i++)
            factorials[i] = factorials[i-1] * i;

        inverse_factorials.resize(max+1);
        inverse_factorials[max] = inverse(factorials[max]);
        for (auto i = max; i >= 1; i--)
            inverse_factorials[i-1] = i * inverse_factorials[i];
    }

    Mod binomial(const int n, const int k)
    {
        if (k < 0 || k > n) return 0;
        else return factorials[n] * inverse_factorials[k] * inverse_factorials[n-k];
    }

    Mod npaths(const Point a, const Point b)
    {
        const auto dr = b.r - a.r, dc = b.c - a.c;
        return binomial(dr+dc, dr);
    };
}

int main()
{
    int N, M, K, S;
    cin >> N >> M >> K >> S;

    lut::precompute(2*max(N, M));

    auto points = vector<Point>({{1, 1}});
    for (auto k = 0; k < K; k++)
    {
        int r, c; cin >> r >> c;
        points.push_back({r, c});
    }
    K++;
    sort(begin(points), end(points));

    auto remaining = vector<Mod>(K);
    for (auto k = 0; k < K; k++)
        remaining[k] = lut::npaths(points[k], {N, M});

    auto pre = new Mod[2001][2001];
    for (auto k1 = 0; k1 < K; k1++) for (auto k2 = 0; k2 < K; k2++)
        pre[k1][k2] = lut::npaths(points[k1], points[k2]);

    auto numerator = Mod(0);
    for (; S > 1; S -= S/2)
    {
        auto ways = vector<Mod>(K);
        for (auto k1 = K-1; k1 >= 0; k1--)
        {
            ways[k1] = remaining[k1];
            for (auto k2 = k1+1; k2 < K; k2++)
                ways[k1] -= pre[k1][k2] * ways[k2];
        }

        numerator += S * ways[0];

        for (auto k = 0; k < K; k++)
            remaining[k] -= ways[k];
    }
    numerator += remaining[0];

    const auto denominator = lut::npaths({1, 1}, {N, M});

    cout << (numerator/denominator).k << endl;
}