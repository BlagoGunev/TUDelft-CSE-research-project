#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int find(int x)
{
    return p[x] == x ? x : find(p[x]);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto &x : a)
            cin >> x;

        for(auto &x : a)
            x--;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += a[a[i]] == i;
            p[find(i)] = find(a[i]);
        }
        assert(cnt % 2 == 0);
        cnt /= 2;

        int mx = 0;
        for(int i = 0; i < n; i++)
            mx += find(i) == i;
        cout << (cnt ? mx - cnt + 1 : mx) << " " << mx << endl;
    }

    return 0;
}