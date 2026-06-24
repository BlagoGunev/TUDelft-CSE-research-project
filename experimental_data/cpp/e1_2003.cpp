#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l + r) >> 1)
#define lch (rt << 1)
#define rch (rt << 1 | 1)

using namespace std;

using i64 = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i,0,m-1)
    {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    vector<int> a(n, n), b(n, -1);
    rep(i,0,m-1) 
    {
        a[l[i]] = l[i];
        b[l[i]] = r[i];
    }
    repd(i,n-1,1)
    {
        a[i - 1] = min(a[i - 1], a[i]);
    }
    rep(i,0,n-2)
    {
        b[i + 1] = max(b[i + 1], b[i]);
    }

    vector<int> c(n);
    rep(i,0,m-1) c[l[i]] = 1;
    rep(i,0,n-1)
    {
        if (b[i] > a[i]) c[i] = 1;
    }
    rep(i,0,m-1)
        if (c[r[i] - 1])
        {
            cout << "-1\n";
            return;
        }
    int ans = 0, now = n;
    vector<int> p;
    set<int> st;
    rep(i,0,n-1)
    {
        if (c[i]) ans += i, now--;
        else if (b[i] <= i) p.push_back(i);
        else if (c[i - 1]) st.insert(i);
    }
    vector<bool> R(n);
    rep(i,0,m-1) R[r[i] - 1] = true;
    int mx = 0;
    mx = ans + now * (now - 1) / 2;
    while (p.size() || st.size())
    {
        if (!p.size() || (st.size() && p.back() < *st.rbegin()))
        {
            int x = *st.rbegin();
            st.erase(x);
            if (R[x]) continue;
            st.insert(x + 1);
            ans += x, now--;
        }
        else
        {
            int x = p.back();
            p.pop_back();
            ans += x, now--;
        }
        mx = max(mx, ans + now * (now - 1) / 2);
    }
    cout << mx << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}