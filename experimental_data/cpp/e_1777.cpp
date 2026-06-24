#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int t;

int n, m;

struct node {int y, w;};

vector<node> a[maxn];

vector<int> b[maxn];

int deg[maxn];

bool p[maxn];

int dfn[maxn], low[maxn];

int cnt, tot;

stack<int> st;

int diao[maxn];

void dfs(int x) {

	p[x] = 1; st.push(x);

	dfn[x] = low[x] = ++cnt;

	for (int i = 0; i < b[x].size(); i++) {

		int y = b[x][i];

		if (!dfn[y]) {dfs(y); low[x] = min(low[x], low[y]);}

		else if (p[y]) low[x] = min(low[x], dfn[y]);

	}

	if (low[x] == dfn[x]) {

		tot++;

		while (!st.empty()) {

			int u = st.top(); st.pop();

			diao[u] = tot; p[u] = 0;

			if (u == x) break;

		}

	}

}

bool check(int k) {

    for (int i = 1; i <= n; i++) b[i].clear();

    for (int i = 1; i <= n; i++)

        for (int j = 0; j < a[i].size(); j++) {

            int x = a[i][j].y, w = a[i][j].w;

            b[i].push_back(x);

            if (w <= k) b[x].push_back(i);

        }

    while (!st.empty()) st.pop();

    for (int i = 1; i <= n; i++) p[i] = dfn[i] = low[i] = deg[i] = diao[i] = 0;

    cnt = tot = 0;

    for (int i = 1; i <= n; i++)

        if (!dfn[i]) dfs(i);

    // cout << "黑哥 ";

    // for (int i = 1; i <= n; i++) cout << diao[i] << ' ';

    // cout << endl;

    for (int i = 1; i <= n; i++)

        for (int j = 0; j < b[i].size(); j++) {

            int x = b[i][j];

            if (diao[i] != diao[x]) deg[diao[x]]++;

        }

    int res = 0;

    for (int i = 1; i <= tot; i++) res += (deg[i] == 0);

    return res <= 1;

}

void work() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) a[i].clear();

    for (int i = 1; i <= m; i++) {

        int x, y, w; cin >> x >> y >> w;

        a[x].push_back((node){y, w});

    }

    // cout << check(30000) << endl;

    int l = -1, r = 1e9 + 1;

    while (l + 1 < r) {

        int mid = l + r >> 1;

        if (check(mid)) r = mid;

        else l = mid;

    }

    if (r == 1e9 + 1) cout << -1 << '\n';

    else cout << r << '\n';

}

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> t;

    while (t--) work();

    return 0;

}