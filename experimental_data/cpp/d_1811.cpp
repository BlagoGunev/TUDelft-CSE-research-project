// ॐ नमः शिवाय
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#define cina(a, n)              \
    for (int i = 0; i < n; i++) \
        std::cin >> a[i];
template <class T>
bool is_prime(T x)
{
    if (x < 2)
        return false;
    for (T i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            return false;
        }
    return true;
}
template <class T>
vector<T> prime_factors(T x)
{
    vector<T> ans;
    for (T i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            ans.push_back(i);
            x /= i;
        }
    }
    if (x > 1)
        ans.push_back(x);
    return ans;
}
int powfast(int a, int b)
{
    int value = 1;
    while (b)
    {
        if (b & 1)
            value *= a;
        a *= a;
        b >>= 1;
    }
    return value;
}
int fib[47];
signed main()
{
        std::cout << std::fixed << std::setprecision(25);
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i < 47; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        int tc;
        std::cin >> tc;
        while (tc--)
        {
            int n, rc, cc;
            cin >> n >> rc >> cc;
            int rs = 1, re = fib[n];
            int cs = 1, ce = fib[n + 1];
            bool res = 1;
            for (int i = n; i >= 1;)
            {

                if (rs + fib[i] > rc)
                {
                    re = rs + fib[i] - 1;
                }
                else if (re - fib[i] < rc)
                {
                    rs = re - fib[i] + 1;
                }
                else
                {
                    res = 0;
                    break;
                }
                i--;
                if (cs + fib[i] > cc)
                {
                    ce = cs + fib[i] - 1;
                }
                else if (ce - fib[i] < cc)
                {
                    cs = ce - fib[i] + 1;
                }
                else
                {
                    res = 0;
                    break;
                }
                i--;
            }
            (res) ? cout << "YES\n" : cout << "NO\n";
        }
        return 0;
}