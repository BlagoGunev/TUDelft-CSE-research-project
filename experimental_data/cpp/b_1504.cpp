#include <bits/stdc++.h>
#define M 1000000007
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define d(x) cout << #x << " " << x << "\n";
#define min(x1, x2) (x1 > x2 ? x2 : x1)
#define max(x1, x2) (x1 < x2 ? x2 : x1)
#define min3(x1, x2, x3) (x3 > min(x1, x2) ? min(x2, x1) : x3)
#define max3(x1, x2, x3) (x3 < max(x1, x2) ? max(x1, x2) : x3)
#define ll long long int
#define ul unsigned long long int
#define p pair<ll, ll>
#define ld long double
#define dv(v)                            \
    cerr << #v << "  ";                  \
    for (int i = 0; i < (v).size(); i++) \
        cerr << v[i] << " ";             \
    cerr << "\n";
#define inf INT_MAX
#define mp(x, y) make_pair(x, y)
using namespace std;

int main()
{
    fio;
    ll t, n, x, y, k;
    cin >> t;
    while (t--)
    {
        string s;
        string s1;
        cin >> n >> s >> s1;
        int z = 0, ones = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            s[i] == '0' ? ++z : ++ones;
        }
        int c = 0;
        bool b = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == s1[i] && c % 2 == 0)
            {
                s[i] == '0' ? --z : --ones;
                continue;
            }
            else if (s[i] != s1[i] && c % 2)
            {
                s[i] == '0' ? --ones : --z;
                continue;
            }
            if (ones == z) // s[i]!=b[i]
            {
                ++c;
                swap(ones, z);
                if (c % 2 == 0)
                {
                    s[i] == '0' ? --z : --ones;
                }
                else
                {
                    s[i] == '0' ? --ones : --z;
                }
            }
            else
            {
                b = 0;
                break;
            }
        }
        if (!b)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}