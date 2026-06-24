#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define print(a)                             \
    for (int i = 0; i < (a).size() - 1; i++) \
        cout << (a)[i] << " ";               \
    cout << (a)[(a).size() - 1] << endl;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((b + c) % 2 == 0)
    {
        cout << "1 ";
    }
    else
    {
        cout << "0 ";
    }
    if ((a + c) % 2 == 0)
    {
        cout << "1 ";
    }
    else
    {
        cout << "0 ";
    }
    if ((a + b) % 2 == 0)
    {
        cout << "1 ";
    }
    else
    {
        cout << "0";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}