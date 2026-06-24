#include <bits/stdc++.h>
using namespace std;
template <int P>
class mod_int
{
    using Z = mod_int;

private:
    static int mo(int x) { return x < 0 ? x + P : x; }

public:
    int x;
    int val() const { return x; }
    mod_int() : x(0) {}
    template <class T>
    mod_int(const T &x_) : x(x_ >= 0 && x_ < P ? static_cast<int>(x_) : mo(static_cast<int>(x_ % P))) {}
    bool operator==(const Z &rhs) const { return x == rhs.x; }
    bool operator!=(const Z &rhs) const { return x != rhs.x; }
    Z operator-() const { return Z(x ? P - x : 0); }
    Z pow(long long k) const
    {
        Z res = 1, t = *this;
        while (k)
        {
            if (k & 1)
                res *= t;
            if (k >>= 1)
                t *= t;
        }
        return res;
    }
    Z &operator++()
    {
        x < P - 1 ? ++x : x = 0;
        return *this;
    }
    Z &operator--()
    {
        x ? --x : x = P - 1;
        return *this;
    }
    Z operator++(int)
    {
        Z ret = x;
        x < P - 1 ? ++x : x = 0;
        return ret;
    }
    Z operator--(int)
    {
        Z ret = x;
        x ? --x : x = P - 1;
        return ret;
    }
    Z inv() const { return pow(P - 2); }
    Z &operator+=(const Z &rhs)
    {
        (x += rhs.x) >= P && (x -= P);
        return *this;
    }
    Z &operator-=(const Z &rhs)
    {
        (x -= rhs.x) < 0 && (x += P);
        return *this;
    }
    Z operator-() { return -x; }
    Z &operator*=(const Z &rhs)
    {
        x = 1ULL * x * rhs.x % P;
        return *this;
    }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
#define setO(T, o)                                  \
    friend T operator o(const Z &lhs, const Z &rhs) \
    {                                               \
        Z res = lhs;                                \
        return res o## = rhs;                       \
    }
    setO(Z, +) setO(Z, -) setO(Z, *) setO(Z, /)
#undef setO
        friend istream &
        operator>>(istream &is, mod_int &x)
    {
        long long tmp;
        is >> tmp;
        x = tmp;
        return is;
    }
    friend ostream &operator<<(ostream &os, const mod_int &x)
    {
        os << x.val();
        return os;
    }
};
using Z = mod_int<998244353>;
Z f[200020];
bool pr[1000020];
vector<int> d[1000020];
Z g[1000020];
int mu[1000020];
int a[200020];
int n;
const int N = 1e6;
vector<int> vmu;
void init()
{
    vector<int> pr;
    bitset<1000020> flag;
    mu[1] = 1;
    vmu.push_back(1);
    for (int i = 2; i <= N; i++)
    {
        if (!flag[i])
            pr.push_back(i), mu[i] = -1, vmu.push_back(i);
        for (int j : pr)
        {
            if (i * j > N)
                break;
            flag[i * j] = 1;
            if (i % j == 0)
            {
                mu[i * j] = 0;
                break;
            }
            mu[i * j] = -mu[i];
            if (mu[i])
                vmu.push_back(i * j);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
            d[j].push_back(i);
    }
}
int main()
{
    init();
    // cout << mu[1] << '\n';
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[1] = 1;
    for (int j : d[a[1]])
        g[j] += f[1];
    Z sum = f[1];
    for (int i = 2; i <= n; i++)
    {
        f[i] = sum;
        // cout << f[i] << '\n';
        for (int j : d[a[i]])
            f[i] -= mu[j] * g[j];
        // cout << f[i] << '\n';
        // cout << mu[1] << ' ' << g[1] << '\n';
        // cout << sum << '\n';
        for (int j : d[a[i]])
            g[j] += f[i];
        sum += f[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << ' ';
    // cout << '\n';
    cout << f[n] << '\n';
    return 0;
}