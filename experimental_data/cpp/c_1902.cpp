#include <bits/stdc++.h>

using namespace std;

using LL = long long;
#define endl '\n'
using db = double;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    LL ans = 0;
    LL g = 0;
    for (int i = 1; i < n; ++i)
    {
        g = gcd(a[i] - a[i - 1], g);
    }
    for (int i = 0; i + 1 < n; ++i)
    {
        ans += (a[n - 1] - a[i]) / g;
        assert((a[n - 1] - a[i]) % g == 0);
    }
    set<int> st;
    for (int i = 0; i < n; ++i)
        st.insert(a[i]);
    int x = a[n - 1];
    int cnt = 0;
    // cerr << "x = " << x << endl;
    while (st.count(x) == 1)
    {
        cnt++;
        x -= g;
    }
    ans += cnt;

    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}