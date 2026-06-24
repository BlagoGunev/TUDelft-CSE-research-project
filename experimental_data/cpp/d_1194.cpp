#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        ll n, k;
        cin >> n >> k;
        if (k % 3)
        {
            if (!(n % 3)) cout << "Bob" << '\n';
            else cout << "Alice" << '\n';
            continue;
        }
        n = n % (k + 1);
        if (n == k || n == k - 1 || n == k - 2) cout << "Alice" << '\n';
        else if (n == k - 3) cout << "Bob" << '\n';
        else if (!(n % 3)) cout << "Bob" << '\n';
        else cout << "Alice" << '\n';
    }
}