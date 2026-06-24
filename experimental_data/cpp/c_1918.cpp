#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// author: aykhn
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mpr make_pair
#define eb emplace_back
#define pb push_back
#define ts to_string
#define fi first
#define se second
#define ins insert
#define inf 0x3F3F3F3F
#define infll 0x3F3F3F3F3F3F3F3FLL
#define bpc __builtin_popcount
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int ll

struct BIT
{
    int n;
    vector<int> ft;
    void init(int N)
    {
        n = N + 5;
        ft.assign(n + 5, 0);
    }
    void add(int pos, int val)
    {
        for (pos = pos + 1; pos <= n; pos += pos & -pos) ft[pos] += val;
    }
    int get(int pos)
    {
        int res = 0;
        for (pos = pos + 1; pos > 0; pos -= pos & -pos) res += ft[pos];
        return res;
    }
};

void _()
{
    int a, b, r;
    cin >> a >> b >> r;
    if (a > b) swap(a, b);
    int c = 0;
    int res = 0;
    int f = 0;
    for (int i = 61; i >= 0; i--)
    {
        if (((a >> i & 1LL) ^ (b >> i & 1LL))) 
        {
            f = i;
            break;
        }
    }
    for (int i = f - 1; i >= 0; i--)
    {
        if (!(a >> i & 1LL) && (b >> i & 1LL) && (res | (1LL << i)) <= r) res |= (1LL << i);
    }
    // cout << res << '\n';
    cout << abs((a ^ res) - (b ^ res)) << '\n';
}
// 00
// 11
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        _();
    }
}