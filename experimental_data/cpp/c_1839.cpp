#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 5e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    if (v1[n - 1] == 1)
    {
        no return;
    }
    i = n - 1;
    yes while (1)
    {
        while (i >= 0 && v1[i] == 0)
        {
            cout << 0 << ' ';
            i--;
        }
        if (i < 0)
            break;
        ll c = 0;
        while (i >= 0 && v1[i] == 1)
        {
            i--;
            c++;
        }
        ll temp = c - 1;
        while (temp--)
            cout << 0 << ' ';
        cout << c << ' ';
    }

    cout << endl;
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}