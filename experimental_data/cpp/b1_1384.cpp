#include <iostream>

#include <vector>

#include <set>

#include <string>

#include <cstring>

#include <algorithm>

#include <deque>

#include <stack>

#include <unordered_set>

#include <unordered_map>

#include <map>

#include <cmath>

#include<queue>

#include <algorithm>

#include <iomanip>

#define MAX(a, b) if(a < b) swap(a, b)

#define MIN(a, b) if(b < a) swap(a, b)

#define sz(a) ((int32_t)(a).size())

#define _ << " " << 

#pragma GCC optimize("Ofast")

#pragma optimize("O3")

#define int long long

using namespace std;



const int MAXN = 201, INF = 1e15, MAXA = 1e6 + 100, base = 31;

const double eps = 1e-9;

int n, m, a[MAXN], k, l;

bool used[MAXN][MAXN];

void solve()

{

    cin >> n >> k >> l;

    memset(used, 0, sizeof(used));

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> t;

    for (int i = 0; i <= k; i++) t.push_back(i);

    for (int i = k - 1; i > 0; i--) t.push_back(i);

    queue<pair<int, int>> q;

    for (int i = 0; i < 2 * k; i++) {

        int val = a[1] + t[i];

        if (val <= l) q.push(make_pair(1, i));

    }

    while (!q.empty()) {

        auto cur = q.front();

        q.pop();

        if (cur.first == n) {

            cout << "YES\n";

            return;

        }

        for (int i = 1; i <= 2 * k; i++) {

            int tt = cur.second + i;

            tt %= 2 * k;

            int nlvl = a[cur.first + 1] + t[tt];

            if (a[cur.first] + t[(cur.second + i - 1) % (2 * k)] > l) break;

            if (nlvl > l) continue;

            if (used[cur.first + 1][tt]) continue;

            used[cur.first+1][tt] = true;

            q.push(make_pair(cur.first + 1, tt));

        }

    }

    cout << "NO\n";

}

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    std::cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int t = 1;

    cin >> t;

    while (t--)

    {

        solve();

    }

}