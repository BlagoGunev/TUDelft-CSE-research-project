#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define txt                        \
    freopen("ip.txt", "r", stdin); \
    freopen("op.txt", "w", stdout)
#define a3 INT_MAX
#define i3 INT_MIN
#define a6 INT64_MAX
#define i6 INT64_MIN
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define quickie                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define div2(a) (!(a & 1))
#define deb(x) cout << (#x) << " " << (x) << "\n";
#define newl cout << "\n"
#define pi 3.14159265358979323846
#define mod 1000000007
#define fp(x) fixed << setprecision(x) <<
void solve()
{
    int n;
    int k;
    cin >> n >> k;
    bool a = 0, b = 0;
    if (div2(k))
    {
        b = 1;
    }
    if (div2(n))
    {
        a = 1;
    }
    if (k <= n)
    {
        if (a == b)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
    else
    {
        cout<<k-n;
    }
}
int main()
{
    quickie;
    // txt;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        newl;
    }
    return 0;
}