#include <bits/stdc++.h>

#define fo(i, x, y) for (int i = int(x); i <= int(y); ++i)

#define fd(i, x, y) for (int i = int(x); i >= int(y); --i)

#define fi first

#define se second



using namespace std;

using i64 = long long;

using pii = pair<int, i64>;



constexpr int P = 998244353;

constexpr i64 inf = 1e9 + 7;



template <class T>

T power(T a, int b)

{

    T res = 1;

    for (; b; b >>= 1, a *= a)

        if (b & 1)

            res *= a;

    return res;

}



int norm(int x)

{

    if (x < 0) x += P;

    if (x >= P) x -= P;

    return x;

}

struct Z

{

    int x;

    Z(int x = 0) : x(norm(x)) {}

    int val() const

    {

        return x;

    }

    Z operator-() const

    {

        return Z(norm(P - x));

    }

    Z inv() const

    {

        assert(x != 0);

        return power(*this, P - 2);

    }

    Z &operator*=(const Z &rhs)

    {

        x = i64(x) * rhs.x % P;

        return *this;

    }

    Z &operator+=(const Z &rhs)

    {

        x = norm(x + rhs.x);

        return *this;

    }

    Z &operator-=(const Z &rhs)

    {

        x = norm(x - rhs.x);

        return *this;

    }

    Z &operator/=(const Z &rhs)

    {

        return *this *= rhs.inv();

    }

    friend Z operator*(const Z &lhs, const Z &rhs)

    {

        Z res = lhs;

        res *= rhs;

        return res;

    }

    friend Z operator+(const Z &lhs, const Z &rhs)

    {

        Z res = lhs;

        res += rhs;

        return res;

    }

    friend Z operator-(const Z &lhs, const Z &rhs)

    {

        Z res = lhs;

        res -= rhs;

        return res;

    }

    friend Z operator/(const Z &lhs, const Z &rhs)

    {

        Z res = lhs;

        res /= rhs;

        return res;

    }

};



void work()

{

    int n;

    cin >> n;

    vector<pii> rec(n);

    i64 sum = 0;

    for (auto &[op, x] : rec)

    {

        cin >> op;

        if (op != 3) cin >> x;

        if (op == 2) sum = min(sum + x, inf);

        if (op == 3) x = sum, sum = min(sum * 2, inf);

    }

    reverse(rec.begin(), rec.end());

    vector<i64> s;

    i64 del = 0;

    Z ans = 0, k = 1;

    for (auto &[op, x] : rec)

    {

        if (op == 1)

        {

            i64 x0 = x - del;

            if (x0 <= 0) continue;

            auto cal = [](i64 x0, const vector<i64> &s)->Z

            {

                int sz = s.size();

                Z res = 1;

                fo(i, 0, sz - 1)

                {

                    if (s[i] >= x0) continue;

                    res += ((1ll << (sz - i - 1))) % P;

                    x0 -= s[i];

                }

                return res;

            };

            ans += k * cal(x0, s);

        }

        else if (op == 2)

        {

            del = min(del + x, inf);

        }

        else

        {

            if (!x) k *= 2;

            else if (x < inf) s.emplace_back(x);

        }

    }

    cout << ans.val() << '\n';

}



int main()

{

    ios::sync_with_stdio(0); cin.tie(0);

    #ifdef LC

    freopen("t.in", "r", stdin);

    freopen("t.out", "w", stdout);

    #endif

    // int T;

    // cin >> T;

    // while (T--)

        work();

    return 0;

}