#include <algorithm>

#include <bitset>

#include <cassert>

#include <chrono>

#include <cmath>

#include <deque>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <random>

#include <set>

#include <string>

#include <vector>

typedef long long ll;

typedef long double ld;

using namespace std;



vector<int> siz;

vector<vector<int> > g;

void dfs(int u)

{

    siz[u] = 1;

    for (int v : g[u]) dfs(v), siz[u] += siz[v];

}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int t;

    cin >> t;

    while (t--)

    {

        int n;

        cin >> n;

        vector<int> a(n), p(n);

        vector<int> out(n + 1, -1); // cisla z ktorych existuje cesta von

        g.assign(n, {});

        siz.assign(n, 0);

        for (int i = 0; i < n; i++)

        {

            cin >> a[i];

            p[i] = i + a[i];

            if (p[i] < 0 || p[i] >= n) p[i] = n;

            else g[p[i]].push_back(i);

        }

        out[n] = 1;

        for (int i = 0; i < n; i++) if (out[i] == -1)

        {

            vector<int> v;

            int j = i;

            while (out[j] == -1)

            {

                v.push_back(j);

                out[j] = 0;

                j = p[j];

            }

            if (out[j] == 1)

            {

                for (int j : v) out[j] = 1;

            }

        }

        int bad = count(out.begin(), out.end(), 0);

        vector<int> v;

        int j = 0;

        while (out[j] != -1 && j != n)

        {

            out[j] = -1;

            v.push_back(j);

            j = p[j];

        }

        ll ans = 0;

        if (j == n)

        {

            dfs(v.back());

            ans = (n - v.size()) * 1ll * (2 * n + 1);

        }

        for (int i = 0; i < v.size(); i++)

        {

            int bad2 = bad + siz[v[i]];

            ans += 2 * n + 1 - bad2;

        }

        //cout << "               ";

        cout << ans << "\n";

    }

    return 0;

}