#include <bits/stdc++.h>

#define FF first
#define SS second
#define PB push_back
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1000000007;
const int N = 1 * 1000000;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ii> v;
    for (int i = 0; i < m; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v.PB({t1, t2});
    }
    string ans = "";
    for (int i = 0; i < n / 2; ++i)
        ans += "01";
    if (n & 1)
        ans += "0";
    cout << ans << endl;
}