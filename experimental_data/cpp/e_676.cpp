#include <cstdio>
#include <iostream>

using std::getchar;
using std::cout;

typedef long long ll;
typedef long double ld;

ll n, k, a[100001];
ll q(0);
const ll inf = 1E14;

bool input(ll &x);
void add(ll &x, char c);

int main()
{
    ll n, k;
    input(n);
    input(k);
    for (int i(0); i <= n; ++i)
        if (!input(a[i])) q++;
    if (!k)
    {
        if (a[0] == -10001)
        {
            if ((n + 1 - q) % 2) cout << "Yes";
            else cout << "No";
        }
        else if (a[0]) cout << "No";
        else cout << "Yes";
    }
    else
    {
        if (!q)
        {
            ll sum = a[n];
            for (int i(n - 1); i >= 0; --i)
            {
                sum = sum * k + a[i];
                if (sum > inf) sum = inf;
                if (sum < -inf) sum = -inf;
            }
            if (sum == 0) cout << "Yes";
            else cout << "No";
            return 0;
        }
        else if (n % 2) cout << "Yes";
        else cout << "No";
    }
}

bool input(ll &x)
{
    char c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '?')
    {
        x = -10001;
        return false;
    }
    else
    {
        short sign(1);
        x = 0LL;
        if (c == '-') sign = -1;
        else add(x, c);
        c = getchar();
        while (c != ' ' && c != '\n')
        {
            add(x, c);
            c = getchar();
        }
        x *= sign;
        return true;
    }
}

void add(ll &x, char c)
{
    x = x * 10 + c - '0';
}