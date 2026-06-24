#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e5 + 5;
int t, n, q, a[N];
i64 sum[N];
struct node
{
    int mx;
} st[N << 2];
#define lc cur << 1
#define rc cur << 1 | 1
void build(int cur, int l, int r)
{
    if (l == r)
    {
        st[cur].mx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    st[cur].mx = max(st[lc].mx, st[rc].mx);
}
int find1(int cur, int l, int r, int a, int b, int x)
{
    if (a > r || b < l || st[cur].mx <= x)
        return a - 1;
    if (l == r)
        return l;
    int mid = l + r >> 1;
    if (a <= l && r <= b)
    {
        if (st[rc].mx > x)
            return find1(rc, mid + 1, r, a, b, x);
        return find1(lc, l, mid, a, b, x);
    }
    return max(find1(lc, l, mid, a, b, x), find1(rc, mid + 1, r, a, b, x));
}
int find2(int cur, int l, int r, int a, int b, int x)
{
    if (a > r || b < l || st[cur].mx <= x)
        return b + 1;
    if (l == r)
        return l;
    int mid = l + r >> 1;
    if (a <= l && r <= b)
    {
        if (st[lc].mx > x)
            return find2(lc, l, mid, a, b, x);
        return find2(rc, mid + 1, r, a, b, x);
    }
    return min(find2(lc, l, mid, a, b, x), find2(rc, mid + 1, r, a, b, x));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum[i] = sum[i - 1] + a[i];
        build(1, 1, n);
        vector<int> ans(n + 2);
        for (int i = 1; i <= n; i++)
        {
            int l = i, r = i;
            i64 cur = a[i];
            while (l > 1 && cur < 1e9)
            {
                bool done = false;
                if (l > 1)
                {
                    int pos = find1(1, 1, n, 1, l - 1, cur);
                    if (pos + 1 < l)
                    {
                        done = true;
                        cur += sum[l - 1] - sum[pos];
                        l = pos + 1;
                    }
                }
                if (r < n && !done)
                {
                    int pos = find2(1, 1, n, r + 1, n, cur);
                    if (r + 1 < pos)
                    {
                        int ll = r + 1, rr = pos - 1, mid = ll;
                        while (ll < rr)
                        {
                            mid = ll + rr >> 1;
                            if (sum[mid] - sum[r] + cur >= a[l - 1])
                                rr = mid;
                            else
                                ll = mid + 1;
                        }
                        done = true;
                        cur += sum[mid] - sum[r];
                        r = mid;
                    }
                }
                if (!done)
                    break;
            }
            if (cur < 1e9 && l > 1)
                continue;
            ans[r]++;
            cur += sum[l - 1], l = 1;
            if (r < n && cur < 1e9)
            {
                while (r < n && cur < 1e9)
                {
                    bool done = false;
                    if (r < n)
                    {
                        int pos = find2(1, 1, n, r + 1, n, cur);
                        if (r + 1 < pos)
                        {
                            done = true;
                            cur += sum[pos - 1] - sum[r];
                            r = pos - 1;
                        }
                    }
                    if (!done)
                        break;
                }
                if (cur >= 1e9 || r == n)
                    ans[n + 1]--;
                else
                    ans[r + 1]--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            ans[i] += ans[i - 1];
            cout << ans[i] << " \n"[i == n];
        }
    }
}
/*
1
11 1
1 2 3 1 1 9 3 2 4 1 3
*/